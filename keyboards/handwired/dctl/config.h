/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define MATRIX_ROWS 12
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS \
    { D4, B4, B5, E6, D7, C6 }
#define MATRIX_COL_PINS \
    { F4, F0, F5, B6, F7, F6 }
#define MATRIX_ROW_PINS_RIGHT \
    { F4, F5, F7, B6, F6, F0 }
#define MATRIX_COL_PINS_RIGHT \
    { D7, C6, D4, E6, B4, B5 }

#define SPLIT_HAND_PIN B7

#define DIODE_DIRECTION COL2ROW

// Use hardware communication between halves.
#define USE_I2C

// Allow using one side at a time.
#define SPLIT_MAX_CONNECTION_ERRORS 10

// 1000Hz polling
#define USB_POLLING_INTERVAL_MS 1

// Increase debounce window from the default of 5ms.  This does not increase
// key press or release latency since the debounce algorithm is eager.
#define DEBOUNCE 20

// Enabling NKRO in rules.mk isn't enough?
#define FORCE_NKRO

#define PMW33XX_CS_PIN F1
#define POINTING_DEVICE_INVERT_X
#define PMW3389_CPI 4000
#define POINTING_DEVICE_MOTION_PIN C7

// Double tap a key to lock it.
#define ONESHOT_TAP_TOGGLE 2

// One shot mods are active for 1 second.
#define ONESHOT_TIMEOUT 1000

// 200ms for a tap to become a hold
#define TAPPING_TERM 200
// Allow quicker usage of mod-tap keys
#define PERMISSIVE_HOLD
// Allow rolling mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
// Disable key-repeat for mod-taps by double tapping
// #define TAPPING_FORCE_HOLD
