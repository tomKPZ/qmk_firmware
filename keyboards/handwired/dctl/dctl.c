#include "dctl.h"
#include "keycodes.h"
#include "repeat.h"

// Auto-trigger the mouse layer after this many mouse events.
#define N_EVENTS 32
// Disable the mouse layer after draining to this many mouse events.
#define N_IDLE_EVENTS 4
// Only consider events within this time window.
#define EVENT_WINDOW_MS 100
// Suppress mouse motion this long after clicking.
#define MOUSE_MOTION_INHIBIT_MS 80
// Suppress the mouse layer this long after a right keypress.
#define MOUSE_LAYER_INHIBIT_MS 250
// Ideally a power of 2 to avoid division.
#define MOVE_SENSITIVITY 16
// Ideally a power of 2 to avoid division.
#define SCROLL_SENSITIVITY 16

static bool     inhibit_mouse_layer;
static uint16_t last_right_press;

static bool     inhibit_mouse_move;
static uint8_t  button_state;
static uint16_t btn1_changed;

static bool     auto_mouse_enabled;
static uint8_t  events_size;
static uint8_t  events_start;
static uint16_t events_timers[N_EVENTS];

static int16_t rem_dx = 0;
static int16_t rem_dy = 0;

static bool scroll_pressed = false;

static void add_event(uint16_t now) {
    events_timers[(events_start + events_size) % N_EVENTS] = now;
    if (events_size == N_EVENTS) {
        events_start++;
    } else {
        events_size++;
    }
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!mouse_report.x && !mouse_report.y) {
        return mouse_report;
    }

    add_event(timer_read());

    rem_dx += mouse_report.x;
    rem_dy += mouse_report.y;
    if (inhibit_mouse_move) {
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        int16_t sens = scroll_pressed ? SCROLL_SENSITIVITY : MOVE_SENSITIVITY;
        int16_t dx   = rem_dx / sens;
        int16_t dy   = rem_dy / sens;
        if (scroll_pressed) {
            mouse_report.x = 0;
            mouse_report.y = 0;
            mouse_report.h = dx;
            mouse_report.v = -dy;
        } else {
            mouse_report.x = dx;
            mouse_report.y = dy;
        }
        rem_dx -= sens * dx;
        rem_dy -= sens * dy;
    }

    return mouse_report;
}

void matrix_scan_user(void) {
    uint16_t now = timer_read();
    while (events_size && now >= events_timers[events_start % N_EVENTS] + EVENT_WINDOW_MS) {
        events_start++;
        events_size--;
    }
    if (!auto_mouse_enabled) {
        // Don't enable the layer if not necessary since it will interrupt mouse drags.
        if (!inhibit_mouse_layer && events_size == N_EVENTS) {
            layer_on(_MOUSE);
            auto_mouse_enabled = true;
        }
    } else if (!button_state && events_size <= N_IDLE_EVENTS) {
        layer_off(_MOUSE);
        auto_mouse_enabled = false;
    }
    if (inhibit_mouse_move && now >= btn1_changed + MOUSE_MOTION_INHIBIT_MS) {
        inhibit_mouse_move = false;
    }
    if (inhibit_mouse_layer && now >= last_right_press + MOUSE_LAYER_INHIBIT_MS) {
        inhibit_mouse_layer = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_repeat_key(keycode, record);

    uint16_t now = timer_read();
    uint8_t  row = record->event.key.row;
    if (record->event.pressed && row >= 6 && row <= 10) {
        inhibit_mouse_layer = true;
        last_right_press    = now;
        if (auto_mouse_enabled) {
            layer_off(_MOUSE);
            auto_mouse_enabled = false;
        }
    }

    if (keycode == KC_BTN1) {
        btn1_changed       = now;
        inhibit_mouse_move = true;
    }

    if (keycode >= KC_BTN1 && keycode <= KC_BTN5) {
        uint8_t button_mask = 1 << (keycode - KC_BTN1);
        if (record->event.pressed) {
            button_state |= button_mask;
        } else {
            button_state &= ~button_mask;
        }
    }

    if (keycode == USCROLL) {
        scroll_pressed = record->event.pressed;
    }

    return true;
}
