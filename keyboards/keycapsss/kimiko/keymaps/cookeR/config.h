/* Copyright 2019 MechMerlin
 * Copyright 2020 @ben_roe (keycapsss.com)
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

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
//#define POINTING_DEVICE_ROTATION_90 	//(Optional) Rotates the X and Y data by 90 degrees.
#define POINTING_DEVICE_ROTATION_180 	//(Optional) Rotates the X and Y data by 180 degrees.
//#define POINTING_DEVICE_ROTATION_270 	//(Optional) Rotates the X and Y data by 270 degrees.
#define POINTING_DEVICE_INVERT_X 	//(Optional) Inverts the X axis report.
#define POINTING_DEVICE_INVERT_Y 	//(Optional) Inverts the Y axis report.
#define PIMORONI_TRACKBALL_INTERVAL_MS 8 //change update rate for trackball, from testing update rate seems to be limited to around 250. Updating more frequently will slow down the keyboard.
#define PIMORONI_TRACKBALL_SCALE 5 //5 is default, I personally prefer 3 which feels a little smoother.
#define PIMORONI_TRACKBALL_DEBOUNCE_CYCLES 20 //number of cycles to stop motion after clicking. 20 x 8 (INTERVAL) so 160ms.
#define PIMORONI_TRACKBALL_ERROR_COUNT 10 //stops trying to read from the pimoroni after this many faults.

/* mousekey stuff */
#define MOUSEKEY_INTERVAL           20
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        60
#define MOUSEKEY_MAX_SPEED          8
#define MOUSEKEY_WHEEL_DELAY        85
#define MOUSEKEY_WHEEL_MAX_SPEED    4
#define MOUSEKEY_WHEEL_TIME_TO_MAX  50
#define MOUSEKEY_WHEEL_INTERVAL     40

#define PIMORONI_SCROLL_ACCEL 0.4
#define PIMORONI_MOUSE_ACCEL 1.5
#define PIMORONI_MOUSE_POWER 2.2
#define PIMORONI_ACCEL_PERMANENT 1

#define OLED_FONT_H "keyboards/keycapsss/kimiko/keymaps/cooke/glcdfont.c"
// #define OLED_FONT_WIDTH 5
// #define OLED_FONT_HEIGHT 7

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 8
#   define RGBLIGHT_SLEEP       /* the RGB lighting will be switched off when the host goes to sleep */
// #   define RGBLIGHT_MODE_STATIC_LIGHT
/*== all animations enable ==*/
// #   define RGBLIGHT_ANIMATIONS
/*== or choose animations to save space ==*/
// #   define RGBLIGHT_EFFECT_BREATHING
// #   define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #   define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #   define RGBLIGHT_EFFECT_SNAKE
// #   define RGBLIGHT_EFFECT_KNIGHT
// #   define RGBLIGHT_EFFECT_CHRISTMAS
#   define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #   define RGBLIGHT_EFFECT_RGB_TEST
// #   define RGBLIGHT_EFFECT_ALTERNATING
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:

// #define SPLIT_USB_DETECT

// #define NO_USB_STARTUP_CHECK
