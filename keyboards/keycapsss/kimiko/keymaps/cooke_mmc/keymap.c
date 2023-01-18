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

enum layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _NUMPAD,
    _SYMBOL,
    _SHIFT,
    _ADJUST,
    _PROCR8,
    _MAUS,
    _MACMACROS, 
 };

enum custom_keycodes {
    SCRSHT = SAFE_RANGE,    // screenshots on pc
    QMKCOMPILE,             // quick compile in qmk msys
    BRACES,
 };

#define PROFS LGUI(KC_0)              //PROCR8 fullscreen
#define PROPER LGUI(KC_SCLN)          // PROCR8 perspective guide

#define QWERTY      DF(_QWERTY)
#define COLEMAK     DF(_COLEMAK_DH)
#define RAISE       MO(_SHIFT)        // hold for num nav layer
#define LOWER       MO(_NUMPAD)       // hold for macro layer
#define LOWERR      OSL(_NUMPAD)      // One shot macro layer
#define SYMBOL      MO(_SYMBOL)       // hold for symbol layer
#define MAUSS       MO(_MAUS)         // hold for mouse layer
#define MAUS        TG(_MAUS)         // toggle mouse layer
#define PROCR8      TG(_PROCR8)       // toggle PROCR8 layer on ipad
#define MMCRS        MO(_MACMACROS)    // hold for Mac Macros

#define LOWSPC      LT(LOWER,KC_SPC)
#define RASENT      LT(RAISE,KC_ENT)
#define SYMBSP      LT(SYMBOL, KC_BSPC)
#define TABFUN      LT(MMCRS, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
 [_QWERTY] = LAYOUT(   
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    XXXXXXX, 
     XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    XXXXXXX,
     XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H,   KC_J,   KC_K,    KC_L,   KC_QUOT, KC_COLN, 
     XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC,  XXXXXXX, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
           PROCR8, XXXXXXX, KC_ESC, TABFUN, LOWSPC,   RASENT,  SYMBSP, KC_DEL, XXXXXXX, XXXXXXX                                    
  ),

// COLEMAK
 [_COLEMAK_DH] = LAYOUT(  
     XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    XXXXXXX,
     XXXXXXX, KC_Q, KC_W, KC_F, KC_P, KC_B,                      KC_J,   KC_L,   KC_U,    KC_Y,   KC_QUOT, XXXXXXX,
     XXXXXXX, KC_A, KC_R, KC_S, KC_T, KC_G,                      KC_M,   KC_N,   KC_E,    KC_I,   KC_O,    KC_COLN,
     XXXXXXX, KC_Z, KC_X, KC_C, KC_D, KC_V,   KC_BSPC,  XXXXXXX, KC_K,   KC_H,   KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
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
     XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T),                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
     XXXXXXX, LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G),                          XXXXXXX, SCRSHT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     
     XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), _______,        _______, XXXXXXX, BRACES,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                             XXXXXXX,  XXXXXXX,  _______,     _______,    _______,        _______, _______, _______, _______, _______                                                 
  ),

// MACMACROS 
 [_MACMACROS] = LAYOUT(
     XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, LCMD(KC_Q), LCMD(KC_W), LCMD(KC_E), LCMD(KC_R), LCMD(KC_T),                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
     XXXXXXX, LCMD(KC_A), LCMD(KC_S), LCMD(KC_D), LCMD(KC_F), LCMD(KC_G),                          XXXXXXX, SCRSHT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     
     XXXXXXX, LCMD(KC_Z), LCMD(KC_X), LCMD(KC_C), LCMD(KC_V), LCMD(KC_B), _______,        _______, XXXXXXX, BRACES,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
                             XXXXXXX,  XXXXXXX,  _______,     _______,    _______,        _______, _______, _______, _______, _______                                                 
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

#ifdef OLED_ENABLE
 oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
 }

//OLED Stuff
 void render_space(void) {
    oled_write_P(PSTR("     "), false);
 }

 void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
 }

 void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
 }

 void render_logo(void) {
    oled_write_P(PSTR("Jenis"), false);
    static const char PROGMEM jenis_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(jenis_logo, false);
 }

 void render_icecream(void) {
    static const char PROGMEM ice_cream[] = {
        0x9e, 0x9f, 0x20, 0x9e, 0x9f,
        0xbe, 0xbf, 0x20, 0xbe, 0xbf,
        0xde, 0xdf, 0x20, 0xde, 0xdf, 0};
    oled_write_P(ice_cream, false);
 }

 void render_layer_state(void){ 
    switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWRTY"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("COLMK"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("ADJST"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("W Roh"), false);
                break;
            case _SYMBOL:
                oled_write_P(PSTR("SYMBL"), false);
                break;
            case _SHIFT:
                oled_write_P(PSTR("# Nav"), false);
                break;
            case _PROCR8:
                oled_write_P(PSTR("PCR8T"), false);
                break;
            case _MAUS:
                oled_write_P(PSTR("MAUS "), false);
                break;
            case _MACMACROS:
                oled_write_P(PSTR("M Roh"), false);
                break;
            default:
                oled_write_P(PSTR("     "), false);
        }
 }

 void render_caps_lock(void) {               // capslock indicator for OLED
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR("CAPSS"), false);
     } else {
         oled_write_P(PSTR("     "), false);
   }   
 }

 void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_caps_lock();
    render_icecream();
 }

 void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_caps_lock();
    render_icecream();
 }

 bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }

    return false;
 }

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SHIFT, _NUMPAD, _ADJUST); 
     return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case SCRSHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LSFT("S"))); //Windows Key + Shift + S = Screencap
        return false;
      }
      break;
    case QMKCOMPILE:
      if (record->event.pressed) {
        SEND_STRING("qmk compile -kb keycapsss/kimiko -km cooke_mmc");
        return false;
      }
      break; 
    case BRACES:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
        return false;
      }
      break;
  }
  return true;
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


// define combo names
enum combos {
    COMBO_LBRCKT,
    COMBO_RBRCKT,
    COMBO_LBRCMD,
    COMBO_RBRCMD,
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
    //COMBO_,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
// mod combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sdv_combo[] = {KC_S, KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM mkl_combo[] = {KC_M, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END};
// enter+key combos
const uint16_t PROGMEM jsym_combo[] = {KC_J, SYMBSP, COMBO_END};
const uint16_t PROGMEM ksym_combo[] = {KC_K, SYMBSP, COMBO_END};
const uint16_t PROGMEM lsym_combo[] = {KC_L, SYMBSP, COMBO_END};
//const uint16_t PROGMEM _combo[] = {KC_, KC_, COMBO_END};
// more here...

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LBRCKT] = COMBO(we_combo, LCTL(KC_LBRC)),
    [COMBO_RBRCKT] = COMBO(er_combo, LCTL(KC_RBRC)),
    [COMBO_LBRCMD] = COMBO(ui_combo, LCMD(KC_LBRC)),
    [COMBO_RBRCMD] = COMBO(io_combo, LCMD(KC_RBRC)),
    [COMBO_MOUSE] = COMBO(yu_combo, MAUS),
    [COMBO_CAPSLK] = COMBO(vb_combo, KC_CAPS),
    [COMBO_MACROS] = COMBO(xcv_combo, LOWERR),
    //mod combos
    [COMBO_LSHIFT] = COMBO(cv_combo, KC_LSFT),
    [COMBO_LCTRL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LGUI] = COMBO(ds_combo, KC_LGUI),
    [COMBO_LALT] = COMBO(fs_combo, KC_LALT),
    [COMBO_RSHIFT] = COMBO(mcom_combo, KC_RSFT),
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
    //[COMBO_] = COMBO(_combo, ),
    // more here...
};