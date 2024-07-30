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
#include QMK_KEYBOARD_H
#include "keydefs.c"
#include "handlers.c"   

#define PROFS       LGUI(KC_0)       //PROCR8 fullscreen
#define PROPER      LGUI(KC_SCLN)    // PROCR8 perspective guide

#define LCOLEMAK        DF(COLEMAK_DH)
#define LQWERTY         DF(QWERTY)
#define LNUMNAV         MO(NUMNAV)      // hold for num nav layer
#define LMACRO          MO(MACRO)       // hold for macro layer
#define LLAYER_POINTER  MO(LAYER_POINTER)
#define LSETTINGS       TG(SETTINGS)

#define THMBLL      LT(LMACRO,KC_SPC)
#define THMBLR      LT(LLAYER_POINTER,KC_TAB)
#define THMBRL      LT(LSETTINGS,KC_BSPC)
#define THMBRR      LT(LNUMNAV,KC_ENT)

#define DPI_MOD     POINTER_DEFAULT_DPI_FORWARD
#define DPI_RMOD    POINTER_DEFAULT_DPI_REVERSE
#define S_D_MOD     POINTER_SNIPING_DPI_FORWARD
#define S_D_RMOD    POINTER_SNIPING_DPI_REVERSE
#define SNIPING     SNIPING_MODE
#define SNP_TOG     SNIPING_MODE_TOGGLE
#define DRGSCRL     DRAGSCROLL_MODE
#define DRG_TOG     DRAGSCROLL_MODE_TOGGLE

#define DRAGSCROLL_PADDING 6

#include "combo_config.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// COLEMAK
 [COLEMAK_DH] = LAYOUT_charybdis_3x6(  
     KC_VOLU, KC_Q, KC_W, KC_F, KC_P, KC_B,       KC_J,   KC_L,    KC_U,    KC_Y,   KC_QUOT, KC_ASON,
     KC_VOLD, KC_A, KC_R, KC_S, KC_T, KC_G,       KC_M,   KC_N,    KC_E,    KC_I,   KC_O,    XXXXXXX,
     XXXXXXX, KC_Z, KC_X, KC_C, KC_D, KC_V,       KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_ASOFF,
                    THMBLL, XXXXXXX, THMBLR,      THMBRL, THMBRR                                           
  ), 

// QWERTY
 [QWERTY] = LAYOUT_charybdis_3x6(   
     KC_VOLU, KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_ASON,
     KC_VOLD, KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H,   KC_J,    KC_K,    KC_L,   KC_QUOT, XXXXXXX, 
     XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ASOFF,
                    THMBLL, XXXXXXX, THMBLR,       THMBRL, THMBRR                                     
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

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 800); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;
    scroll_buffer_x -= left_report.x;
    scroll_buffer_y -= left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    left_report.h = 0;
    left_report.v = 0;
    if (abs(scroll_buffer_x) > DRAGSCROLL_PADDING) {
        left_report.h   = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
    }
    if (abs(scroll_buffer_y) > DRAGSCROLL_PADDING) {
        left_report.v   = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
#ifdef POINTING_DEVICE_INVERT_X
    right_report.x = -right_report.x;
#endif // POINTING_DEVICE_INVERT_X
#ifdef POINTING_DEVICE_INVERT_Y
    right_report.y = -right_report.y;
#endif // POINTING_DEVICE_INVERT_Y
    return pointing_device_combine_reports(left_report, right_report);
}


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