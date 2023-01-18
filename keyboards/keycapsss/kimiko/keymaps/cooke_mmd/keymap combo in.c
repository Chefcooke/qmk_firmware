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

#define PROFS LGUI(KC_0)              //PROCR8 fullscreen
#define PROPER LGUI(KC_SCLN)          // PROCR8 perspective guide

#define QWERTY      DF(_QWERTY)
#define COLEMAK     DF(_COLEMAK_DH)
#define RAISE       MO(_SHIFT)        // hold for num nav layer
#define LOWER       MO(_NUMPAD)       // hold for macro layer
#define LOWERR      OSL(_NUMPAD)      // One shot macro layer
#define SYMBOL      MO(_SYMBOL)       // hold for symbol layer
#define MAUSS       MO(_MAUS)         // hold for mouse layer *currently not using*
#define MAUS        TG(_MAUS)         // toggle mouse layer
#define PROCR8      TG(_PROCR8)       // toggle PROCR8 layer on ipad

#define LOWSPC      LT(LOWER,KC_SPC)
#define RASENT      LT(RAISE,KC_ENT)
#define SYMBSP      LT(SYMBOL, KC_BSPC)
#define TABFUN      KC_TAB

#include "combo_config.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
 [_QWERTY] = LAYOUT(   
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    XXXXXXX, 
     XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    XXXXXXX,
     SPOTL,   KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H,   KC_J,   KC_K,    KC_L,   KC_QUOT, KC_COLN, 
     XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC,  SWAP_OS, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
           PROCR8, XXXXXXX, KC_ESC, TABFUN, LOWSPC,   RASENT,  SYMBSP, KC_DEL, XXXXXXX, XXXXXXX                                    
  ),

// COLEMAK
 [_COLEMAK_DH] = LAYOUT(  
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    XXXXXXX,
     XXXXXXX, KC_Q, KC_W, KC_F, KC_P, KC_B,                      KC_J,   KC_L,   KC_U,    KC_Y,   KC_QUOT, XXXXXXX,
     SPOTL,   KC_A, KC_R, KC_S, KC_T, KC_G,                      KC_M,   KC_N,   KC_E,    KC_I,   KC_O,    KC_COLN,
     XXXXXXX, KC_Z, KC_X, KC_C, KC_D, KC_V,   KC_BSPC,  SWAP_OS, KC_K,   KC_H,   KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
             PROCR8, XXXXXXX, KC_ESC, TABFUN, LOWSPC,   RASENT,  SYMBSP, KC_DEL, XXXXXXX, XXXXXXX                                      
  ),


// SHIFT is NUMNAV of Miryoku layout
 [_SHIFT] = LAYOUT(
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PLUS,                      KC_ASTR, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_MINS,                      KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, 
     _______, KC_DOT,  KC_7,    KC_8,    KC_9,    XXXXXXX, _______,    _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
                      _______, _______,  _______, KC_EQL,  _______,    _______, _______, _______, _______, _______
  ),

// NUMPAD is the Macros of Miryouku Layouts
 [_NUMPAD] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, CLS_W,   Z_IN,    REFRESH, NEWTAB,                      REDO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
     XXXXXXX, SELECT,  SAVE,    Z_OUT,   SEARCH,  RPLC,                        SCRSHT1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     
     XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   PST_CLEAN, _______, _______, SCRSHT2, BRACES,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                       XXXXXXX, XXXXXXX, _______, _______,   _______, _______, _______, _______, _______, _______                                                 
  ),

// SYMBOL
 [_SYMBOL] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX,                       XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,    
     XXXXXXX, KC_GRV,  KC_SCLN, KC_LPRN, KC_RPRN, XXXXXXX,                       XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX,    
     XXXXXXX, KC_BSLS, KC_CIRC, KC_LCBR, KC_RCBR, XXXXXXX, _______,     _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX,   
                       _______, _______, _______, KC_UNDS, _______,     _______, _______, _______, _______, _______                                                 
  ),

// ADJUST (Press NUMPAD and SHIFT together)
 [_ADJUST] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_SLEP,                     XXXXXXX,    KC_MNXT, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, KC_ASON,  QWERTY,  XXXXXXX,                     XXXXXXX,    KC_MPRV, KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, KC_ASOFF, COLEMAK, XXXXXXX, _______,   _______, QMKCOMPILE, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, _______, _______, _______, _______,   _______, _______,    _______, _______, _______
  ),

// PROCR8
 [_PROCR8] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, _______, _______, _______, _______, _______,
     KC_LCTL, PROPER,  PROFS,   KC_E,    KC_LBRC, KC_RBRC,                      _______, _______, _______, _______, _______, _______,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_L,                         _______, _______, _______, _______, _______, _______,
     KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______,  KC_ESC,  KC_LGUI, _______,    _______, _______, _______, _______, _______
  ),

// MAUS
 [_MAUS] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______,                      KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______, _______, _______, _______,    _______, KC_WH_D, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX,
                       _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2, KC_BTN3, _______, _______
  )               
 };


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SHIFT, _NUMPAD, _ADJUST); 
     return state;
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

/*
// define combo names
enum combos {
    COMBO_LBRCKT,
    COMBO_RBRCKT,
    COMBO_MOUSE,
    COMBO_CAPSLK,
    COMBO_MACROS,
    COMBO_LSHIFT,
    COMBO_LCTRL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_RSHIFT,
    COMBO_RCTRL,
    COMBO_RGUI,
    COMBO_RALT,
    COMBO_LGUISHFT,
    COMBO_LCTRLSHFT,
    COMBO_RGUISHFT,
    COMBO_RCTRLSHFT,
    COMBO_AMPR,
    COMBO_AT,
    COMBO_EXLM,
    COMBO_DELW,
    COMBO_DELLN,
    //COMBO_,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
//const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
//const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
// mod combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ef_combo[] = {KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sdv_combo[] = {KC_S, KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM mkl_combo[] = {KC_M, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END};
// del+key combos
const uint16_t PROGMEM jsym_combo[] = {KC_J, SYMBSP, COMBO_END};
const uint16_t PROGMEM ksym_combo[] = {KC_K, SYMBSP, COMBO_END};
const uint16_t PROGMEM lsym_combo[] = {KC_L, SYMBSP, COMBO_END};
const uint16_t PROGMEM msym_combo[] = {KC_M, SYMBSP, COMBO_END};
const uint16_t PROGMEM dotsym_combo[] = {KC_DOT, SYMBSP, COMBO_END};
//const uint16_t PROGMEM _combo[] = {KC_, KC_, COMBO_END};
// more here...

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LBRCKT] = COMBO(we_combo, LBCMD),
    [COMBO_RBRCKT] = COMBO(er_combo, RBCMD),
    //[COMBO_] = COMBO(ui_combo, ),
    //[COMBO_ ] = COMBO(io_combo,  ),
    [COMBO_MOUSE] = COMBO(yu_combo, MAUS),
    [COMBO_CAPSLK] = COMBO(vb_combo, KC_CAPS),
    [COMBO_MACROS] = COMBO(xcv_combo, LOWERR),
    //mod combos
    [COMBO_LSHIFT] = COMBO(ef_combo, KC_LSFT),
    [COMBO_LCTRL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LGUI] = COMBO(ds_combo, KC_LGUI),
    [COMBO_LALT] = COMBO(fs_combo, KC_LALT),
    [COMBO_RSHIFT] = COMBO(ji_combo, KC_RSFT),
    [COMBO_RCTRL] = COMBO(jk_combo, KC_RCTL),
    [COMBO_RGUI] = COMBO(kl_combo, KC_RGUI),
    [COMBO_RALT] = COMBO(jl_combo, KC_RALT),
    [COMBO_LGUISHFT] = COMBO(sdv_combo, LGUI(KC_LSFT)),
    [COMBO_LCTRLSHFT] = COMBO(dv_combo, LCTL(KC_LSFT)),
    [COMBO_RGUISHFT] = COMBO(mkl_combo, RGUI(KC_RSFT)),
    [COMBO_RCTRLSHFT] = COMBO(mk_combo, RCTL(KC_RSFT)),
    //enter+key combos
    [COMBO_AMPR] = COMBO(jsym_combo, KC_AMPR),
    [COMBO_AT] = COMBO(ksym_combo, KC_AT),
    [COMBO_EXLM] = COMBO(lsym_combo, KC_EXLM),
    [COMBO_DELW] = COMBO(msym_combo, DEL_W),
    [COMBO_DELLN] = COMBO(dotsym_combo, DEL_LN),
    //[COMBO_] = COMBO(_combo, ),
    // more here...
};

*/