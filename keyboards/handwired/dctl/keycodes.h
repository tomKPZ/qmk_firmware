#pragma once

#include "quantum/keycodes.h"

enum custom_keycodes {
    // it can be called REP if you want but "REPEAT" is clearer and still fits
    // under the 8 char "limit"
    REPEAT = QK_USER,
};

enum layers {
    _QWERTY     = 0,
    _APT        = 1,
    _SYMBOL     = 2,
    _NAVIGATION = 3,
    _FUNCTION   = 4,
    _MOUSE      = 5,
};
