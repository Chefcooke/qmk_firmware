/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#define PROFS       LGUI(KC_0)       //PROCR8 fullscreen
#define PROPER      LGUI(KC_SCLN)    // PROCR8 perspective guide

#define LCOLEMAK        DF(COLEMAK_DH)
#define LQWERTY         DF(QWERTY)
#define LNUMNAV         MO(NUMNAV)      // hold for num nav layer
#define LMACRO          MO(MACRO)       // hold for macro layer
#define LLAYER_POINTER  MO(LAYER_POINTER)
#define LSETTINGS       TG(SETTINGS)

#define THMBLL      LT(LMACRO,KC_BSPC)
#define THMBLR      LT(LLAYER_POINTER,KC_TAB)
#define THMBRL      LT(LSETTINGS,KC_ENT)
#define THMBRR      LT(LNUMNAV,KC_SPC)

#define THGLL      LT(LMACRO,KC_BSPC)
#define THGLR      LT(LLAYER_POINTER,KC_TAB)
#define THGRL      LT(LSETTINGS,KC_ENT)
#define THGRR      LT(LNUMNAV,KC_SPC)

#define DPI_RMOD    POINTER_DEFAULT_DPI_REVERSE
#define S_D_MOD     POINTER_SNIPING_DPI_FORWARD
#define S_D_RMOD    POINTER_SNIPING_DPI_REVERSE
#define SNIPING     SNIPING_MODE
#define SNP_TOG     SNIPING_MODE_TOGGLE
#define DRGSCRL     DRAGSCROLL_MODE
#define DRG_TOG     DRAGSCROLL_MODE_TOGGLE


#include "combo_config.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// COLEMAK HANDS DOWN TITANIUM
 [COLEMAK_DH] = LAYOUT_charybdis_3x6(  
     KC_VOLU, TD(CT_JZK), TD(CT_GQK), KC_M, KC_P, KC_V, TD(CT_HAT),  TD(CT_DC),  TD(CT_SLP), TD(CT_DQE),  TD(CT_QQ),XXXXXXX,
     KC_VOLD, KC_C, KC_S, KC_N, KC_T, KC_K,             TD(CT_CSC),  KC_A,       KC_E,       KC_I,        KC_H,     XXXXXXX,
     XXXXXXX, KC_X, KC_F, KC_L, KC_D, KC_W,             TD(CT_MP),   KC_U,       KC_O,       KC_Y,        KC_B,     XXXXXXX,
                    THMBLL, XXXXXXX, THMBLR,            THMBRL, THMBRR                                           
  ), 

// QWERTY
 [QWERTY] = LAYOUT_charybdis_3x6(   
     KC_VOLU, KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    XXXXXXX,
     KC_VOLD, KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H,   KC_J,    KC_K,    KC_L,   KC_QUOT, XXXXXXX, 
     XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
                    THGRL, XXXXXXX, THGRR,       THGLL, THGLR                                     
  ),

// NUMNAV
 [NUMNAV] = LAYOUT_charybdis_3x6(
     _______, XXXXXXX, KC_4,  KC_5, KC_6, KC_PLUS,   KC_ASTR, KC_PGDN, KC_UP,   KC_PGUP, XXXXXXX, XXXXXXX,
     _______, KC_0,    KC_1,  KC_2, KC_3, KC_MINS,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, 
     _______, KC_DOT,  KC_7,  KC_8, KC_9, KC_EQL,    XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
                       _______, _______, _______,    _______, _______
  ),

// MACRO
 [MACRO] = LAYOUT_charybdis_3x6(
     KC_SLEP, PROFS,  CLS_WIN, Z_IN,  REFRESH, NEWTAB,     EMOJI,   XXXXXXX, WIN_L,   WIN_R,   XXXXXXX, XXXXXXX,   
     QMKCOM,  SELECT, SAVE,    Z_OUT, SEARCH,  RPLC,       SCRSHT1, BRACES,  MINMZ,   MAXMZ,   XXXXXXX, XXXXXXX,     
     REDO,    UNDO,   CUT,     COPY,  PASTE,   PST_CLN,    SCRSHT2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                            _______, _______,  _______,    _______, _______                                                
  ),

// MOUSE POYNTR
 [LAYER_POINTER] = LAYOUT_charybdis_3x6(
     _______, DRG_TOG, S_D_RMOD, S_D_MOD, DPI_MOD, DPI_RMOD,  _______, _______, _______, _______, _______, _______,  
     SNIPING, DRGSCRL, KC_BTN3,  KC_BTN2, KC_BTN1, KC_ENT,    _______, _______, _______, _______, _______, _______,      
     SNP_TOG, XXXXXXX, XXXXXXX,  KC_BSPC, KC_TAB,  KC_ESC,    _______, _______, _______, _______, _______, _______,  
                                _______, _______, _______,    _______, _______                                               
  ),

// SETTINGS
 [SETTINGS] = LAYOUT_charybdis_3x6(
     _______, _______, _______, _______, _______, _______,    _______, KC_F4, KC_F5, KC_F6, KC_F10, SWIN_OS,  
     _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,    KC_BSPC, KC_F1, KC_F2, KC_F3, KC_F11, _______,    
     _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,    _______, KC_F7, KC_F8, KC_F9, KC_F12, SMAC_OS, 
                               _______, _______,  _______,    _______, _______                                                
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