
#include "quantum.h"
#include "keymap_introspection.h"

// tap_dance.h
#define TAP_DANCE_ACTIONS_SIZE 9  // Adjust this to match the number of elements you have.
extern tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_SIZE];


#ifndef TAP_DANCE_H
#define TAP_DANCE_H

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

enum {
    CT_CSC = 0,
    CT_DC,
    CT_HAT,
    CT_MP,
    CT_DQE,
    CT_QQ,
    CT_SLP,
    CT_JZK,
    CT_GQK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);


#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

#endif // TAP_DANCE_H

