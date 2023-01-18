#pragma once

#include "quantum.h"

enum custom_keycodes {
    // it can be called REP if you want but "REPEAT" is clearer and still fits under the 8 char "limit"
    REPEAT = SAFE_RANGE,
};

enum layers {
    _APT        = 0,
    _QWERTY     = 1,
    _SYMBOL     = 2,
    _NAVIGATION = 3,
    _FUNCTION   = 4,
    _MOUSE      = 5,
};
