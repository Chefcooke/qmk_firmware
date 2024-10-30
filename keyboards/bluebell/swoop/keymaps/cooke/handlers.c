//inspiration source code https://github.com/alvaro-prieto/corne

//#include QMK_KEYBOARD_H
#include "handlers.h"
#include "keydefs.h"
#include "tap_dance.h"


//(OSX / WINDOWS) variable for the host OS, OSX by default
enum OS os = OSX;

// Returns Command / Control depending on the OS
uint16_t os_cmd_key(void){
    return (os == OSX ? KC_LCMD : KC_LCTL);
}

// Hold down an OS dependent key
void register_os_dependent_key(uint16_t key) {
    uint16_t code = getOSKey(key);
    if (code) register_code16(code);
}

// Releases an OS dependent key
void unregister_os_dependent_key(uint16_t key) {
    uint16_t code = getOSKey(key);
    if (code) unregister_code16(code);
}

// Tap an OS dependent key
void tap_os_dependent_key(uint16_t key) {
    uint16_t code = getOSKey(key);
    if (code) tap_code16(code);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    bool down = record->event.pressed;

    switch (keycode) {
        // OS DEPENDENT KEYS
        case FIRST_OS_INDEX ... LAST_OS_INDEX:
            if (down) {
                clear_mods();
                register_os_dependent_key(keycode);
            } else {
                unregister_os_dependent_key(keycode);
            }
            return false;

        // CUSTOM HANDLED KEYS
        case SWIN_OS:
            if (record->event.pressed) {
                clear_mods();
                os = WINDOWS;
                #ifdef OLED_DRIVER_ENABLE
                    oled_os_notification(os);
                #endif
            }
            return false;

        case SMAC_OS:
            if (record->event.pressed) {
                clear_mods();
                os = OSX;
                #ifdef OLED_DRIVER_ENABLE
                    oled_os_notification(os);
                #endif
            }
            return false;

        case SCRSHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("S"))); // Windows Key + Shift + S = Screencap
            }
            return false;

        case QMKCOM:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb bluebell/swoop -km cooke -e CONVERT_TO=elite_pi");
            }
            return false;

        case BRACES:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            return false;

        // TAP DANCE KEYS
        case TD(CT_CSC):
        case TD(CT_DC):
        case TD(CT_HAT):
        case TD(CT_MP):
        case TD(CT_DQE):
        case TD(CT_QQ):
        case TD(CT_SLP):
        case TD(CT_JZK):
        case TD(CT_GQK):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
    }
    return true;
}




  
