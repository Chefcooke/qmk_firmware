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
extern rgblight_config_t rgblight_config;

enum layers {
    _QWERTY,
    _NUMPAD,
    _SHIFT,
    _ADJUST,
    _PROCREATE,
    _MAUS,
    _GAMING,
 };

enum custom_keycodes {
    SCRSHT = SAFE_RANGE,    // for taking screenshots on pc
    QMKCOMPILE,             // for quick compile in qmk msys
 };

#define FIND LCTL(KC_F)    //windows find
#define PROFS LGUI(KC_0)   //procreate fullscreen
#define PROPER LGUI(KC_SCLN) // procreate perspective guide

#define RAISE MO(_SHIFT)
#define LOWER MO(_NUMPAD)
#define PROCREATE TG(_PROCREATE) // for procreate layer on ipad
#define MAUS TG(_MAUS)           // for mouse layer


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------.                      ,----------------------------------------------.
 * |   ESC      |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  |           
 * |---------+------+------+------+------+---------|                      |------+------+------+------+------+-----------|
 * |   Tab      |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+---------|                      |------+------+------+------+------+-----------|
 * |LShift/CAPS |   A  |   S  |   D  |   F  |   G  |---------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  RShift/' |
 * |---------+------+------+------+------+---------|  Lead   |    |   `   |------+------+------+------+------+-----------|
 * | LCTRL/[    |   Z  |   X  |   C  |   V  |   B  |---------|    |-------|   N  |   M  |   ,  |   .  |   /  |  RCTRL/]  |
 * `-----------------------------------------------|  LOWER  /     \RAISE \-----------------------------------------------'
 *              | PROCREATE | ESC  | LGUI |Lalt(AT)| /Space /       \Enter \Alt(BackSP)| Delete | MAUS |  F18 |
 *              `------------------------------------------'         '----------------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_ESC,          KC_1, KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6, KC_7, KC_8,    KC_9,   KC_0,    XXXXXXX,
    KC_TAB,          KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_MINS,
    LSFT_T(KC_CAPS), KC_A, KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, RSFT_T(KC_QUOT),
    LALT_T(KC_LBRC), KC_Z, KC_X,    KC_C,    KC_V,    KC_B, KC_LEAD,                           KC_GRV, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RALT_T(KC_RBRC),
                         PROCREATE, KC_ESC, KC_LGUI, LCTL_T(KC_DEL), LT(LOWER,KC_SPC), LT(RAISE,KC_ENT), RCTL_T(KC_BSPC), RGUI_T(KC_DEL), MAUS, KC_F18
  ),
/* SHIFT
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

[_SHIFT] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* NUMPAD
 * ,-------------------------------------------.                    ,------------------------------------------.
 * |       |      |      |      |      |       |                    |      |      |      |      |      |       |
 * |-------+------+------+------+------+-------|                    |------+------+------+------+------+-------|
 * |       | Home |  Up  | End  |      |       |                    |   +  |   7  |   8  |   9  |   |  | Calc  |
 * |-------+------+------+------+------+-------|                    |------+------+------+------+------+-------|
 * |       | Left | Down | Right| FIND |       |-------.    ,-------|   -  |   4  |   5  |   6  |  =   | Enter |
 * |-------+------+------+------+------+-------|       |    |   /   |------+------+------+------+------+-------|
 * |       |      |      |      |      |SCRNSHT|-------|    |-------|   *  |   1  |   2  |   3  |      |       |
 * `------------------------------------------/LOWER  /     \RAISE \\-----------------------------------------'
 *                |   |      | LGUI | LAlt |  /Space /       \Enter \ RAlt/BSP| . |  0  |       |
 *                `---------------------------------'         '---------------------------------'
 */

[_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_HOME, KC_UP,   KC_END,  XXXXXXX, _______,                            KC_KP_PLUS,         KC_7,         KC_8,         KC_9, KC_BSLS, KC_CALC,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, FIND,    _______,                           KC_KP_MINUS, KC_4, KC_5, KC_6,  KC_EQL, KC_PENT,
    _______, _______, _______, _______, _______,  SCRSHT,  _______, KC_KP_SLASH, KC_KP_ASTERISK,         KC_1,         KC_2,         KC_3, _______, _______,
                      _______, _______, _______, _______,  _______,     _______, _______,        KC_DOT, KC_0,    _______
  ),
/* ADJUST (Press NUMPAD and SHIFT together)
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGBON | HUE+ | SAT+ | VAL+ |      |SLEEP |                    | WAKE | NEXT | VOL+ |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGB P | HUE- | SAT- | VAL- |      |      |-------.    ,-------|      | PREV | VOL- |      |      |      |
 * |-------+------+------+------+------+------|GUICTRL|    |CTRLGUI|------+------+------+------+------+------|
 * | RGB G |      |      |      |      |      |-------|    |-------| QMK  | PLAY | MUTE |      |      |      |
 * `-----------------------------------------/ LOWER  /     \RAISE \-----------------------------------------'
 *               |    |      | LGUI | LAlt |  /Space /       \Enter \  RAlt/BackSP| Delete |   |   |
 *                `----------------------------------'        '------------------------------------'
 */

[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_SLEP,                   KC_WAKE, KC_MNXT, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX,
    RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX,
    RGB_M_G, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_SWAP, CG_NORM, QMKCOMPILE, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
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
/* MAUS
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
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  KC_BTN3, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  KC_BTN4, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, _______, KC_WH_R,  KC_BTN5, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
 };

const rgblight_segment_t PROGMEM my_default_both[] = RGBLIGHT_LAYER_SEGMENTS(
    {}
 );

const rgblight_segment_t PROGMEM my_numpad[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_AZURE},{11,1,HSV_AZURE},{12,1,HSV_AZURE},{23,1,HSV_AZURE},{24,1,HSV_AZURE},
    {54,1,HSV_AZURE},{53,1,HSV_AZURE},{42,1,HSV_AZURE},{41,1,HSV_AZURE},{30,1,HSV_AZURE}
 );

const rgblight_segment_t PROGMEM my_shift[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_ORANGE},{11,1,HSV_ORANGE},{12,1,HSV_ORANGE},{23,1,HSV_ORANGE},{24,1,HSV_ORANGE},
    {54,1,HSV_ORANGE},{53,1,HSV_ORANGE},{42,1,HSV_ORANGE},{41,1,HSV_ORANGE}, {30,1,HSV_ORANGE}
 );

const rgblight_segment_t PROGMEM my_adjust[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_CORAL},{11,1,HSV_CORAL},{12,1,HSV_CORAL},{23,1,HSV_CORAL},{24,1,HSV_CORAL},
    {54,1,HSV_CORAL},{53,1,HSV_CORAL},{42,1,HSV_CORAL},{41,1,HSV_CORAL}, {30,1,HSV_CORAL}
 );

const rgblight_segment_t PROGMEM my_procreate[] = RGBLIGHT_LAYER_SEGMENTS(
    {24,1,HSV_CYAN},
    {54,1,HSV_CYAN}
 );

const rgblight_segment_t PROGMEM my_maus[] = RGBLIGHT_LAYER_SEGMENTS(
    {54,1,HSV_TEAL},{53,1,HSV_TEAL},{42,1,HSV_TEAL},{41,1,HSV_TEAL}, {30,1,HSV_TEAL}
 );

const rgblight_segment_t PROGMEM my_effect_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {}
 );

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {24,1,HSV_RED},{25,1,HSV_RED},{26,1,HSV_RED},
    {54,1,HSV_RED},{55,1,HSV_RED},{56,1,HSV_RED}
 );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_default_both,
    my_numpad,
    my_shift,
    my_adjust, 
    my_procreate,
    my_maus,
    my_effect_layer
 );  

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_mode(22);
    rgblight_sethsv(HSV_OFF);
   };

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
 };

//order of layers above is important to match layer number in this set
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SHIFT, _NUMPAD, _ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SHIFT));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _PROCREATE));
    rgblight_set_layer_state(6, layer_state_cmp(state, _MAUS));
    if (layer_state_cmp(state, _GAMING)) {   //didn't use this, but leaving code in case of future experimentation
        rgblight_set_layer_state(0, true);
        rgblight_mode_noeeprom(14);
    }
    return state;
 };

// capslock indicator for OLED
void render_caps_lock(void) { 
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR("CAPSS"), false);
     } else {
         oled_write_P(PSTR("     "), false);
   }   
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

void render_layer_state(void) {
    if(layer_state_is(_ADJUST)) {
        oled_write_P(PSTR("Vol&L"), false);
    } else if(layer_state_is(_NUMPAD)) {
        oled_write_P(PSTR("# Pad"), false);
    } else if(layer_state_is(_SHIFT)) {
        oled_write_P(PSTR("Shift"), false);
    } else if(layer_state_is(_PROCREATE)) {
        oled_write_P(PSTR("Pro C"), false);
    } else if(layer_state_is(_MAUS)) {
        oled_write_P(PSTR("Maus "), false);
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),     ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  }, // both hands: arrow keys
    [_NUMPAD] =  { ENCODER_CCW_CW(KC_TAB, KC_TAB),    ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, // right hand: volume
    [_SHIFT] =  { ENCODER_CCW_CW(LSFT(LCTL(KC_TAB)), (LCTL(KC_TAB))),   ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  }, // left hand: browser tab change
    //[_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(RGB_HUI, RGB_HUD) },
    [_PROCREATE] =  { ENCODER_CCW_CW(LCTL(KC_LBRC),LCTL(KC_RBRC)),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  }, // left hand: adjust brush size in procreate
    [_MAUS] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) }, // right hand: scroll up, scroll down
 };
#endif // ENCODER_MAP_ENABLE 

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
        SEND_STRING("qmk compile -kb keycapsss/kimiko -km cooke");
        return false;
      }
      break;
  }
  return true;
 };

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_THREE_KEYS(KC_Q, KC_M, KC_K) {
      // Anything you can do in a macro.
      SEND_STRING("qmk compile -kb keycapsss/kimiko -km cooke"); // compile qmk
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c")); // select all and copy
    }
    SEQ_TWO_KEYS(KC_C, KC_C) {
      SEND_STRING("chefcooke@gmail.com"); // enter email address
    }
    SEQ_TWO_KEYS(KC_A, KC_S) { // I don't like this one, but have to look at what register code means for future leaders
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}