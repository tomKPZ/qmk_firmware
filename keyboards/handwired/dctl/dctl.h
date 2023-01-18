#pragma once

#include "quantum.h"

// clang-format off
#define LAYOUT( \
	          L02, L03, L04, L05,    R00, R01, R02, R03, \
	L10, L11, L12, L13, L14, L15,    R10, R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24, L25,    R20, R21, R22, R23, R24, R25, \
	L30, L31, L32, L33, L34, L35,    R30, R31, R32, R33, R34, R35, \
	          L42, L43,                        R42, R43, \
			       LT5, LT0, LT4,    RT0, RT1, RT3, \
				   LT2, LT3, LT1,    RT2, RT5, RT4) \
	{ \
		{KC_NO, KC_NO, L02, L03, L04, L05}, \
		{KC_NO, KC_NO, L12, L13, L14, L15}, \
		{L10, L11, L22, L23, L24, L25}, \
		{L20, L21, L32, L33, L34, L35}, \
		{L30, L31, L42, L43, KC_NO, KC_NO}, \
		{LT0, LT1, LT2, LT3, LT4, LT5}, \
		{R00, R01, R02, R03, KC_NO, KC_NO}, \
		{R10, R11, R12, R13, KC_NO, KC_NO}, \
		{R20, R21, R22, R23, R14, R15}, \
		{R30, R31, R32, R33, R24, R25}, \
		{KC_NO, KC_NO, R42, R43, R34, R35}, \
		{RT0, RT1, RT2, RT3, RT4, RT5}, \
	}
// clang-format on
