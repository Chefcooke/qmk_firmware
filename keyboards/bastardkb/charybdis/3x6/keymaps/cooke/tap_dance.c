
#include "keymap_introspection.h"
#include "tap_dance.h"

// Tap dance finished function (same logic for all tap dances)
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
    #ifndef PERMISSIVE_HOLD
            && !state->interrupted
    #endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

// Tap dance reset function (same logic for all tap dances)
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

// Define your tap dance actions for 5 keys (tap-hold behavior)
tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_SIZE] = {
    [CT_CSC] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, KC_SCLN), //tap comma, hold semicolon
    [CT_DC] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),   //tap period, hold colon
    [CT_HAT] = ACTION_TAP_DANCE_TAP_HOLD(KC_HASH, KC_AT),   // hashtag, at 
    [CT_MP] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_PLUS),  // minus, plus
    [CT_DQE] = ACTION_TAP_DANCE_TAP_HOLD(KC_DQUO, KC_EXLM), // double quote, exclamation
    [CT_QQ] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, KC_QUES),  // quote, question
    [CT_SLP] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_PAST), // slash, asterik
    [CT_JZK] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, KC_Z),       // j, z
    [CT_GQK] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, KC_Q),       // g, q
};


// Function to process key events, similar for all tap dances

/* commenting out the process record user and moving code to handlers.c

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;


    switch (keycode) {
        case TD(CT_CSC):  // Add cases for other tap dance keys
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
*/

