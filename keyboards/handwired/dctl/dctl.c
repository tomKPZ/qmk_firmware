#include "dctl.h"
#include "keycodes.h"
#include "repeat.h"

#define MOTION_IDLE_TIME 250

// Auto-trigger the mouse layer after this many motion events.
#define N_MOTION_TIMINGS 32
// Only consider events within this many milliseconds ago.
#define MOTION_WINDOW_MS 300
// Time to suppress mouse events after clicking.
#define MOUSE_INHIBIT_MS 80

// Ideally a power of 2 to avoid division.
#define SENS 4

static uint8_t  button_state;
static uint16_t btn1_changed;

static bool     auto_mouse_enabled;
static uint16_t last_mouse;

static uint8_t  motion_size;
static uint8_t  motion_start;
static uint8_t  motion_end;
static uint16_t motion_timers[N_MOTION_TIMINGS];

static int16_t rem_dx = 0;
static int16_t rem_dy = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!mouse_report.x && !mouse_report.y) return mouse_report;

    last_mouse = timer_read();

    rem_dx += mouse_report.x;
    rem_dy += mouse_report.y;
    mouse_report.x = rem_dx / SENS;
    mouse_report.y = rem_dy / SENS;
    rem_dx -= SENS * mouse_report.x;
    rem_dy -= SENS * mouse_report.y;
    if (!mouse_report.x && !mouse_report.y) return mouse_report;

    motion_timers[motion_end] = last_mouse;
    if (motion_size == N_MOTION_TIMINGS)
        motion_start = (motion_start + 1) % N_MOTION_TIMINGS;
    else
        motion_size++;
    motion_end = (motion_end + 1) % N_MOTION_TIMINGS;

    while (motion_size && timer_elapsed(motion_timers[motion_start]) > MOTION_WINDOW_MS) {
        motion_start = (motion_start + 1) % N_MOTION_TIMINGS;
        motion_size--;
    }
    // Don't enable the layer if not necessary since it will interrupt mouse drags.
    if (motion_size == N_MOTION_TIMINGS && !IS_LAYER_ON(_MOUSE)) {
        layer_on(_MOUSE);
        auto_mouse_enabled = true;
    }

    if (timer_elapsed(btn1_changed) < MOUSE_INHIBIT_MS) {
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_mouse_enabled && !button_state && (timer_elapsed(last_mouse) > MOTION_IDLE_TIME)) {
        layer_off(_MOUSE);
        auto_mouse_enabled = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_repeat_key(keycode, record);
    switch (keycode) {
        case KC_BTN1 ... KC_BTN5: {
            if (keycode == KC_BTN1) btn1_changed = timer_read();
            uint8_t button_mask = 1 << (keycode - KC_BTN1);
            if (record->event.pressed) {
                button_state |= button_mask;
            } else {
                button_state &= ~button_mask;
                last_mouse = timer_read();
            }
        }
    }
    return true;
}
