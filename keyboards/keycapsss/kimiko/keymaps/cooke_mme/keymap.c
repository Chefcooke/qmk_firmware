/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
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

#include QMK_KEYBOARD_H
#include "keydefs.c"
#include "handlers.c"
#include "oled.c"

#define PROFS       LGUI(KC_0)       //PROCR8 fullscreen
#define PROPER      LGUI(KC_SCLN)    // PROCR8 perspective guide

#define QWERTY      DF(_QWERTY)
#define COLEMAK     DF(_COLEMAK_DH)
#define RAISE       MO(_SHIFT)        // hold for num nav layer
#define LOWER       MO(_NUMPAD)       // hold for macro layer
#define LOWERR      OSL(_NUMPAD)      // One shot macro layer
#define MAUS        TG(_MAUS)         // toggle mouse layer
#define PROCR8      TG(_PROCR8)       // toggle PROCR8 layer on ipad

#define LOWSPC      LT(LOWER,KC_SPC)
#define RASENT      LT(RAISE,KC_ENT)
#define SYMBSP      KC_BSPC
#define TABFUN      KC_TAB

#include "combo_config.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
 [_QWERTY] = LAYOUT(   
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    XXXXXXX, 
     KC_VOLU, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_ASON,
     KC_VOLD, KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H,   KC_J,    KC_K,    KC_L,   KC_QUOT, XXXXXXX, 
     SWAP_OS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC,  SWAP_OS, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ASOFF,
         XXXXXXX, XXXXXXX, XXXXXXX, TABFUN, LOWSPC,   RASENT,  SYMBSP, XXXXXXX, XXXXXXX, XXXXXXX                                    
  ),

// COLEMAK
 [_COLEMAK_DH] = LAYOUT(  
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    XXXXXXX,
     KC_VOLU, KC_Q, KC_W, KC_F, KC_P, KC_B,                      KC_J,   KC_L,    KC_U,    KC_Y,   KC_QUOT, KC_ASON,
     KC_VOLD, KC_A, KC_R, KC_S, KC_T, KC_G,                      KC_M,   KC_N,    KC_E,    KC_I,   KC_O,    XXXXXXX,
     SWAP_OS, KC_Z, KC_X, KC_C, KC_D, KC_V,   KC_BSPC,  SWAP_OS, KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_ASOFF,
           XXXXXXX, XXXXXXX, XXXXXXX, TABFUN, LOWSPC,   RASENT,  SYMBSP, XXXXXXX, XXXXXXX, XXXXXXX                                      
  ),


// SHIFT is NUMNAV of Miryoku layout
 [_SHIFT] = LAYOUT(
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PLUS,                      KC_ASTR, KC_PGDN, KC_UP,   KC_PGUP, XXXXXXX, XXXXXXX,
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_MINS,                      KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, 
     _______, KC_DOT,  KC_7,    KC_8,    KC_9,    KC_EQL,  _______,    _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
                      _______, _______,  _______, _______, _______,    _______, _______, _______, _______, _______
  ),

// NUMPAD is the Macros of Miryouku Layouts
 [_NUMPAD] = LAYOUT(
     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_SLEP,    PROFS,   CLS_WIN, Z_IN,    REFRESH, NEWTAB,                      EMOJI,   XXXXXXX, WIN_L,   WIN_R,   XXXXXXX, XXXXXXX,   
     QMKCOMPILE, SELECT,  SAVE,    Z_OUT,   SEARCH,  RPLC,                        SCRSHT1, BRACES,  MINMZ,   MAXMZ, XXXXXXX, XXXXXXX,     
     REDO,       UNDO,    CUT,     COPY,    PASTE,   PST_CLEAN, _______, _______, SCRSHT2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                       XXXXXXX, XXXXXXX, _______, _______,   _______, _______, _______, _______, _______, _______                                                 
  ),


// PROCR8
 [_PROCR8] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, _______, _______, _______, _______, _______,
     KC_LCTL, PROPER,  PROFS,   KC_E,    KC_LBRC, KC_RBRC,                      _______, _______, _______, _______, _______, _______,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_L,                         _______, _______, _______, _______, _______, _______,
     KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______,  _______, KC_LGUI, _______,    _______, _______, _______, _______, _______
  ),

// MAUS
 [_MAUS] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______,                      KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______, _______,    _______, KC_WH_D, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX,
                       _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2, _______, _______, _______
  )               
 };


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 40;
        case RGUI_T(KC_QUOT):
            return TAPPING_TERM + 40;
        case RGUI_T(KC_O):
            return TAPPING_TERM + 40;
        //case LT(1, KC_GRV):
        //    return 130;
        default:
            return TAPPING_TERM;
    }
}