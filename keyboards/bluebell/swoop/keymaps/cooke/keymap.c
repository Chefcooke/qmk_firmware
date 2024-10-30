/* Copyright 2022 James White <jamesmnw@gmail.com>
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

#include "keymap_introspection.h"
#include QMK_KEYBOARD_H
#include "keydefs.c"
#include "handlers.c" 
#include "tap_dance.h" 

#define LHDTI           DF(HD_TI)
#define LQWERTY         DF(QWERTY)
#define LNUMNAV         MO(NUMNAV)      // hold for num nav layer
#define LMACRO          MO(MACRO)       // hold for macro layer
#define LLAYER_POINTER  MO(LAYER_POINTER)
#define LFUN            MO(FUNCTION)
#define LSETTINGS       MO(SETTINGS)

#define THMBLL      KC_BSPC
#define THMBLR      LT(LMACRO,KC_R)
#define THMBRL      LT(LNUMNAV,KC_SPC)
#define THMBRR      LT(LFUN,KC_ENT)

#include "combo_config.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// HANDS DOWN TITANIUM
 [HD_TI] = LAYOUT_split_3x5_3(  
    TD(CT_JZK), TD(CT_GQK), KC_M, KC_P, KC_V,                      TD(CT_HAT),  TD(CT_DC),    TD(CT_SLP), TD(CT_DQE),  TD(CT_QQ),
    LGUI_T(KC_C), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), KC_K,  TD(CT_CSC),  RSFT_T(KC_A), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_H),     
    KC_X, KC_F, KC_L, KC_D, KC_W,  TD(CT_MP),                       KC_U, KC_O, KC_Y, KC_B,     
                     KC_ESC, THMBLL, THMBLR,                        THMBRL, THMBRR, XXXXXXX                                         
  ), 

// QWERTY
 [QWERTY] = LAYOUT_split_3x5_3(   
     KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    
     KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H,   KC_J,    KC_K,    KC_L,   KC_QUOT, 
     KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,
          XXXXXXX, THMBLL,  THMBLR,       THMBRL, THMBRR, XXXXXXX                                     
  ),

// NUMNAV
 [NUMNAV] = LAYOUT_split_3x5_3(
     XXXXXXX, KC_4,  KC_5, KC_6, KC_LCBR,                              KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     LGUI_T(KC_0), LALT_T(KC_1), LCTL_T(KC_2), LSFT_T(KC_3), KC_LPRN,  KC_RPRN, LSFT_T(KC_LEFT), LCTL_T(KC_UP), LALT_T(KC_DOWN), LGUI_T(KC_RGHT),
     KC_DOT, KC_7, KC_8, KC_9, KC_LBRC,                                KC_RBRC, KC_HOME, KC_PGUP, KC_PGDN, KC_END,
              _______, _______, KC_EQL,                                _______, _______, _______  
  ),

// MACRO
 [MACRO] = LAYOUT_split_3x5_3(
     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, EMOJI,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
     REDO,     SAVE,    XXXXXXX, SEARCH,  SCRSHT1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
     UNDO,     CUT,     COPY,    PASTE,   PST_CLN,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                        _______, _______, _______,   _______, _______, _______                                                  
  ),

// FUNCTION
 [FUNCTION] = LAYOUT_split_3x5_3(
     KC_F11, KC_F4, KC_F5, KC_6, _______,       _______, _______, _______, _______, _______,   
     KC_F10, KC_F1, KC_F2, KC_3, _______,       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,    
     KC_F12, KC_F7, KC_F8, KC_9, _______,       _______, _______, _______, _______, _______, 
               _______, _______, _______,       _______, _______, _______                                                
  ),

// SETTINGS
 [SETTINGS] = LAYOUT_split_3x5_3(
     KC_SLEP, _______, _______, _______, _______,    _______, _______, _______, _______, _______,  
     QMKCOM,  _______, _______, _______, SWIN_OS,    SMAC_OS, _______, _______, _______, _______,    
     _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, 
                       _______, _______, _______,    _______, _______, _______                                                
  ),
};
// clang-format on

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