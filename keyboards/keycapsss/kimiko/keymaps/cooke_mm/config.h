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

#define OLED_FONT_H "keyboards/keycapsss/kimiko/keymaps/cooke/glcdfont.c"
// #define OLED_FONT_WIDTH 5
// #define OLED_FONT_HEIGHT 7

//#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TERM 175 //default is 200, 175 to make hold keys act a little faster
#define TAPPING_TERM_PER_KEY
  
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_VAL 22

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_HUE_STEP 7
#   define RGBLIGHT_SAT_STEP 7
#   define RGBLIGHT_VAL_STEP 7
#   define RGBLIGHT_SLEEP       /* the RGB lighting will be switched off when the host goes to sleep */
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#define ANALOG_JOYSTICK_X_AXIS_PIN F0
#define ANALOG_JOYSTICK_Y_AXIS_PIN F1
#define ANALOG_JOYSTICK_SPEED_REGULATOR 10
 
