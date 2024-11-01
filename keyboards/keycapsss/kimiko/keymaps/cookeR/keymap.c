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
#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni_trackball.h"
#endif

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _PROCREATE,
    _MAUS,
};

enum custom_keycodes {
    SCRSHT = SAFE_RANGE,
    QMKCOMPILE,
};

#define KC_WINDX LALT(KC_TAB)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define FIND LCTL(KC_F)
#define PROFS LGUI(KC_0)
#define PROPER LGUI(KC_SCLN)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define PROCREATE TG(_PROCREATE)
#define MAUS TG(_MAUS)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------.                    ,----------------------------------------------.
 * |   ESC      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `        
 * |---------+------+------+------+------+---------|                    |------+------+------+------+------+-----------|
 * |   Tab      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+---------|                    |------+------+------+------+------+-----------|
 * |LShift/CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  RShift/' |
 * |---------+------+------+------+------+---------|  F13  |    |  F14  |------+------+------+------+------+-----------|
 * | LCTRL/[    |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  RCTRL/]  |
 * `-------------------------------------------|   LOWER  /     \RAISE \-----------------------------------------------'
 *              |PROCREATE|  F16 | LGUI | LAlt |  /Space /       \Enter \ RAlt/BackSP| Delete | MAUS |F18|
 *              `---------------------------------------'           '------------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_ESC,          KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,          KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    LSFT_T(KC_CAPS), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
    LCTL_T(KC_LBRC), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_F13,              KC_F14,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_RBRC),
                     PROCREATE, KC_F16,  KC_LGUI, KC_LALT, LT(LOWER,KC_SPC), LT(RAISE,KC_ENT), RALT_T(KC_BSPC), KC_DEL, MAUS, KC_F18
),
/* RAISE
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |  1   |  2   |  3   |  4   |  5   |-------.    ,-------|  6   |  7   |  8   |  9   |   0  | F12  |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |   !  |   @  |   #  |   $  |   %  |-------|    |-------|   ^  |   &  |   *  |   (  |   )  |      |
 * `-------------------------------------------| LOWER  /     \RAISE \----------------------------------------'
 *               |      |      | LGUI | LAlt |  /Space /       \Enter \ RAlt/BackSP| Delete |    |   |
 *                 `----------------------------------'         '------------------------------------'
 */

[_RAISE] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* LOWER
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |       |                    |   +  |   =  |      | Enter| Calc |      |
 * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      |      |  Up  |      |      |       |                    |   -  |   7  |   8  |   9  |   |  |      |
 * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      | Left | Down | Right| FIND |SCRNSHT|-------.    ,-------|   *  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+-------|       |    |       |------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|       |-------|    |-------|   /  |   1  |   2  |   3  |      |      |
 * `------------------------------------------/LOWER  /     \RAISE \\----------------------------------------'
 *                |   |      | LGUI | LAlt |  /Space /       \Enter \ RAlt/BSP| . |  0  |       |
 *                `---------------------------------'         '---------------------------------'
 */

[_LOWER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PPLS,        KC_EQL,  XXXXXXX, KC_PENT, KC_CALC, XXXXXXX,
    _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                     KC_KP_MINUS,    KC_7,    KC_8,    KC_9,    KC_BSLS, XXXXXXX,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, FIND,    SCRSHT,                      KC_KP_ASTERISK, KC_4,    KC_5,    KC_6,    _______, XXXXXXX,
    _______, UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,  _______, _______,  KC_KP_SLASH,    KC_1,    KC_2,    KC_3,    _______, XXXXXXX,
                      _______, _______, _______, _______,  _______, _______,  _______,        KC_DOT,  KC_0,     _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |RGB ON |      |      |      |      |SLEEP |                    | WAKE |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGB P | HUE+ | SAT+ | VAL+ |      |      |                    | PREV | PLAY | NEXT |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGB G | HUE- | SAT- | VAL- |      |      |-------.    ,-------| VOL+ | MUTE | VOL- |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------|    |-------| QMK  |      |      |      |      |      |
 * `-----------------------------------------/ LOWER  /     \RAISE \-----------------------------------------'
 *               |    |      | LGUI | LAlt |  /Space /       \Enter \  RAlt/BackSP| Delete |   |   |
 *                `----------------------------------'        '------------------------------------'
 */

[_ADJUST] = LAYOUT(
    RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,                   KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_M_P, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_M_G, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QMKCOMPILE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
  ),
  /* PROCREATE
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |       |CMD+; |CMD+0 |   E  |  [   |  ]   |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSHFT |   A  |  S   |   D  |  F   |  L   |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  LGUI |   Z  |  X   |   C  |  V   |  B   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/ LOWER  /     \RAISE \-----------------------------------------'
 *          |PROCREATE|      | LGUI | LAlt |  /Space /       \Enter \  RAlt/BackSP| Delete |   |   |
 *          `---------------------------------------'        '------------------------------------'
 */

[_PROCREATE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                _______, _______, _______, _______,  _______, _______,
    XXXXXXX, PROPER,  PROFS,   KC_E,    KC_LBRC, KC_RBRC,                   _______, _______, _______, _______,  _______, _______,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_L,                    _______, _______, _______, _______,  _______, _______,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  _______, _______, _______, _______, _______, _______,  _______, _______,
                  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* PROCREATE
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/ LOWER  /     \RAISE \-----------------------------------------'
 *          |         |      |      |      |  /Space /       \Enter \       |       |      |      |
 *          `---------------------------------------'        '------------------------------------'
 */

[_MAUS] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, KC_BTN4, KC_BTN3, KC_BTN5,  _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  KC_ACL2, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  KC_ACL1, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, _______, KC_WH_R,  KC_ACL0, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

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
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // 
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x9e, 0x9f, 0x20, 0x9e, 0x9f,
        0xbe, 0xbf, 0x20, 0xbe, 0xbf,
        0xde, 0xdf, 0x20, 0xde, 0xdf, 0};
    static const char PROGMEM raise_layer[] = {
        0x9c, 0x9d, 0x52, 0x9c, 0x9d,
        0xbc, 0xbd, 0x20, 0xbc, 0xbd,
        0xdc, 0xdd, 0x20, 0xdc, 0xdd, 0};
    static const char PROGMEM lower_layer[] = {
        0x9a, 0x9b, 0x20, 0x9a, 0x9b,
        0xba, 0xbb, 0x4c, 0xba, 0xbb,
        0xda, 0xdb, 0x20, 0xda, 0xdb, 0};
    static const char PROGMEM adjust_layer[] = {
        0x98, 0x99, 0x20, 0x98, 0x99,
        0xb8, 0xb9, 0x41, 0xb8, 0xb9,
        0xd8, 0xd9, 0x20, 0xd8, 0xd9, 0};
    static const char PROGMEM procreate_layer[] = {
        0x96, 0x97, 0x50, 0x96, 0x97,
        0xb6, 0xb7, 0x52, 0xb6, 0xb7,
        0xd6, 0xd7, 0x4f, 0xd6, 0xd7, 0};
    static const char PROGMEM maus_layer[] = {
        0x96, 0x97, 0x4D, 0x96, 0x97,
        0xb6, 0xb7, 0x41, 0xb6, 0xb7,
        0xd6, 0xd7, 0x55, 0xd6, 0xd7, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_PROCREATE)) {
        oled_write_P(procreate_layer, false);
    } else if(layer_state_is(_MAUS)) {
        oled_write_P(maus_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

// void render_caps_lock(void) { 
//     if(SS_TAP(KC_CAPS)) {
//         oled_write_P(PSTR("CAP"), false);
//     } else {
//         oled_write_P(PSTR("   "), false);
//     }   
//  }

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
}

void render_status_secondary(void) {
    render_logo();
    render_space();
    render_space();
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),     ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_TAB, RGB_HUI),    ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),   ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(RGB_HUI, RGB_HUD) },
};
#endif // ENCODER_MAP_ENABLE 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case SCRSHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LSFT("S")));
        return false;
      }
      break;
    case QMKCOMPILE:
      if (record->event.pressed) {
        SEND_STRING("qmk compile -kb keycapsss/kimiko -km cooke");
        return false;
      }
      break;
  }
  return true;
};



void keyboard_post_init_user(void) {
  pimoroni_trackball_set_rgbw(255,0,0,0);
}
