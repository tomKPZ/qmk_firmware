#include QMK_KEYBOARD_H
#include "keycodes.h"

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

#define OS_SYM OSL(_SYMBOL)
#define OS_NAV OSL(_NAVIGATION)
#define OS_FUNC OSL(_FUNCTION)

#define APT DF(_APT)
#define QWERTY DF(_QWERTY)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Template
    // [X] = LAYOUT(
    //                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                   XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX,
    //                            XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
    //                            XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX),

    [_QWERTY] = LAYOUT_default(
                      KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_1,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_0,
                      KC_MINS, KC_EQL,                                          KC_LBRC, KC_RBRC,
                               KC_BSPC, OS_LSFT, OS_SYM,      KC_ENT,  KC_SPC,  OS_NAV,
                               OS_LALT, REPEAT,  KC_ESC,      OS_LGUI, OS_LCTL, KC_UNDS),

    [_APT] = LAYOUT_default(
                      KC_SCLN, KC_EQL,  KC_SLSH, KC_TAB,      KC_DEL,  KC_ASTR, KC_RPRN, KC_LPRN,
    KC_LBRC, KC_X,    KC_C,    KC_D,    KC_L,    KC_V,        KC_MINS, KC_F,    KC_O,    KC_U,    KC_Q,    KC_RBRC,
    KC_LT,   KC_R,    KC_S,    KC_T,    KC_H,    KC_K,        KC_P,    KC_N,    KC_E,    KC_I,    KC_A,    KC_GT,
    KC_BSLS, KC_W,    KC_G,    KC_B,    KC_M,    KC_J,        KC_Z,    KC_Y,    KC_QUOT, KC_COMM, KC_DOT,  KC_PIPE,
                      KC_LCBR, KC_RCBR,                                         KC_DQT,  KC_COLN,
                               KC_BSPC, OS_LSFT, OS_SYM,      KC_ENT,  KC_SPC,  OS_NAV,
                               OS_LALT, REPEAT,  KC_ESC,      OS_LGUI, OS_LCTL, KC_UNDS),

    [_SYMBOL] = LAYOUT_default(
                      _______, _______, _______, _______,     _______, _______, _______, _______,
    _______, _______, KC_2,    KC_3,    KC_4,    XXXXXXX,     _______, KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
    _______, KC_1,    KC_AT,   KC_HASH, KC_DLR,  KC_5,        KC_6,    KC_AMPR, KC_GRV,  KC_TILD, KC_0,    _______,
    _______, KC_EXLM, KC_QUES, KC_PLUS, KC_PERC, XXXXXXX,     XXXXXXX, KC_CIRC, _______, _______, _______, _______,
                      _______, _______,                                         _______, _______,
                               OS_FUNC, OS_LSFT, XXXXXXX,     XXXXXXX, OS_LSFT, OS_FUNC,
                               OS_LALT, OS_LCTL, OS_LGUI,     OS_LGUI, OS_LCTL, OS_LALT),

    [_NAVIGATION] = LAYOUT_default(
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX,
                               XXXXXXX, OS_LSFT, OS_FUNC,     OS_FUNC, OS_LSFT, XXXXXXX,
                               OS_LALT, OS_LCTL, OS_LGUI,     OS_LGUI, OS_LCTL, OS_LALT),

    [_FUNCTION] = LAYOUT_default(
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  APT,     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  XXXXXXX,     XXXXXXX, KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX,
                               XXXXXXX, OS_LSFT, XXXXXXX,     XXXXXXX, OS_LSFT, XXXXXXX,
                               OS_LALT, OS_LCTL, OS_LGUI,     OS_LGUI, OS_LCTL, OS_LALT),

    [_MOUSE] = LAYOUT_default(
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, KC_WH_U,     _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_D,     _______, _______, _______, _______, _______, _______,
    XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,     _______, _______, _______, _______, _______, _______,
                      XXXXXXX, XXXXXXX,                                         _______, _______,
                               OS_NAV,  OS_LSFT, OS_SYM,      OS_SYM,  OS_LSFT, OS_NAV,
                               OS_LALT, OS_LCTL, OS_LGUI,     OS_LGUI, OS_LCTL, OS_LALT),
};
// clang-format on
