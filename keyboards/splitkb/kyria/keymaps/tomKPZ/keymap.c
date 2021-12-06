/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
     _______, KC_X,  KC_C,  KC_D,   KC_L,   KC_V,                                        KC_MINS,   KC_F,  KC_O,   KC_U,  KC_Q, _______,
     _______, KC_R,  KC_S,  KC_T,   KC_H,   KC_K,                                        KC_P,   KC_N,  KC_E,   KC_I,  KC_A,_______,
     _______, KC_W,  KC_G,  KC_B,   KC_M,   KC_J, _______,_______,     _______, _______, KC_Z,   KC_Y,KC_QUOT, KC_COMM,KC_DOT, _______,
                     OSM(MOD_LCTL), OSM(MOD_LSFT), KC_BSPC, _______, _______,       _______, _______,KC_SPC, _______, _______
    ),
};
