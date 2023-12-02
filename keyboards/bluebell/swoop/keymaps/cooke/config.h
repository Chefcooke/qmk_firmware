/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once

#include "config_common.h"

/* RGB matrix support. 
#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES

// Startup values.
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 175
#    define RGB_MATRIX_DEFAULT_VAL 64

// Rainbow swirl as startup mode.
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_SAT

// Slow swirl at startup.
#    define RGB_MATRIX_DEFAULT_SPD 32

#    ifndef __arm__
// Disable control of RGB matrix by keycodes (must use firmware implementation
// to control the feature).
#        define RGB_MATRIX_DISABLE_KEYCODES
#    else // __arm__
// Enable all animations on ARM boards since they have plenty of memory
// available for it.
#        define ENABLE_RGB_MATRIX_ALPHAS_MODS
#        define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#        define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        define ENABLE_RGB_MATRIX_BREATHING
#        define ENABLE_RGB_MATRIX_BAND_SAT
//#        define ENABLE_RGB_MATRIX_BAND_VAL
//#        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#        define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#        define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#        define ENABLE_RGB_MATRIX_CYCLE_ALL
//#        define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#        define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#        define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
//#        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#        define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#        define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//#        define ENABLE_RGB_MATRIX_DUAL_BEACON
//#        define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//#        define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#        define ENABLE_RGB_MATRIX_RAINDROPS
//#        define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#        define ENABLE_RGB_MATRIX_HUE_BREATHING
//#        define ENABLE_RGB_MATRIX_HUE_PENDULUM
//#        define ENABLE_RGB_MATRIX_HUE_WAVE
//#        define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#        define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#        define ENABLE_RGB_MATRIX_SPLASH
//#        define ENABLE_RGB_MATRIX_MULTISPLASH
//#        define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#        define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    endif // !__arm__
#endif
*/

//#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TERM 175 //default is 200, 175 to make hold keys act a little faster
#define TAPPING_TERM_PER_KEY

// Combos
#undef COMBO_TERM
#define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger
#define COMBO_ONLY_FROM_LAYER 0 // All combos are specified from the base layer, saves space

// Auto Shift
#define AUTO_SHIFT_TIMEOUT 150

#define CAPS_WORD_TOGGLE_KEY
