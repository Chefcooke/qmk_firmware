#include QMK_KEYBOARD_H
#include "keydefs.h"
#include "handlers.h"

//CODES:
//ALT A,  CMD G,  CONTROL C, SHIFT S, C+A LCA, ALGR (for Windows), LWIN, H (hyper)


//Definition of those shortcuts that perform the same action using different
//key combinations accordint to the OS. Currently: {OSX, Windows}
static const uint16_t osKeys[][NUMBER_OF_OS] PROGMEM = {
	//CMD_OS
	{ KC_LCMD, KC_LCTL},
	//CTR_OS
	{ KC_LCTL, KC_LWIN},
	//CUT
	{ G(KC_X), C(KC_X) },
	//COPY
	{ G(KC_C), C(KC_C) },
	//PASTE
	{ G(KC_V), C(KC_V) },
	//PLAIN_PASTE
	{ G(A(S(KC_V))), C(S(KC_V)) },
	//PASTE_IN_PLACE
	{ G(S(KC_V)), C(S(KC_V)) },
	//UNDO
	{ G(KC_Z), C(KC_Z) },
	//REDO
	{ G(S(KC_Z)), C(S(KC_Z)) },
	//SCRSHT1
	{ G(S(C(KC_4))), LWIN(S(KC_S)) },
	//SCRSHT2
	{ G(S(KC_5)), KC_PSCR },
	//EURO
	{ A(KC_E), ALGR(KC_E) },
	//REFRESH
	{ G(S(KC_R)), C(KC_F5) },
	//SAVE
	{ G(KC_S), C(KC_S) },
	//SELECT
	{ G(KC_A), C(KC_A) },
	//MUTE
	{ KC_MUTE, KC_MUTE },
	//VOL_UP
	{ KC_VOLU, KC_VOLU },
	//VOL_DOWN
	{ KC_VOLD, KC_VOLD },
	//CLS_APPS
	{ A(G(KC_ESC)), C(A(KC_DEL)) },
	//BR_UP
	{ KC_BRMU, KC_BRIU },
	//BR_DOWN
	{ KC_BRMD, KC_BRID },
	//W_LEFT
	{ A(KC_LEFT), A(KC_LEFT) },
	//W_RIGHT
	{ A(KC_RIGHT), A(KC_RIGHT) },
	//Z_IN
	{ G(KC_PLUS), C(KC_PLUS)},
	//Z_OUT
	{ G(KC_MINS), C(KC_MINS)},
	//TOP
	{ G(KC_UP), G(KC_HOME)}, //{ G(KC_HOME), G(KC_HOME)},
	//BOTTOM
	{ G(KC_DOWN), G(KC_END)}, //{ G(KC_END), G(KC_END)},
	//FIRST
	{ G(KC_LEFT), KC_HOME},
	//LAST
	{ G(KC_RIGHT), KC_END},
	//MINMZ
	{ G(KC_H), LWIN(KC_DOWN)},
	//CLS_W
	{ G(KC_W), A(KC_F4)},
	//SEARCH
	{ G(KC_F), C(KC_F)},
	//SRCH_NX
	{ G(KC_G), C(KC_G)},
	//SRCH_PR
	{ G(S(KC_G)), C(S(KC_G))},
	//RPLC
	{ A(G(KC_F)), C(KC_H)},
	//SPOTL
	{ G(KC_SPC), LWIN(KC_S)},
	//SM_APP
	{ G(KC_GRV), KC_END},
	//EMOJI
	{ G(C(KC_SPC)), LWIN(KC_DOT)},
	//LOCK
	{ G(C(KC_Q)), LWIN(KC_L)},
	//DEL_W
	{ A(KC_BSPC), C(KC_BSPC)},
	//SNG_PR
	{ KC_F7, KC_MEDIA_PREV_TRACK},
	//SNG_NX
	{ KC_F9, KC_MEDIA_NEXT_TRACK},
	//PLAY
	{ KC_F8, KC_MEDIA_PLAY_PAUSE},
	//REBOOT
	//{ C(KC_POWER), C(KC_POWER)},
	//POWER
	//{ C(KC_POWER), KC_POWER},
	//WIN_L
	{ C(G(S(KC_L))), LWIN(KC_LEFT)},
	//WIN_R
	{ C(G(S(KC_R))), LWIN(KC_RIGHT)},
	//MAXMZ
	{ C(G(S(KC_M))), LWIN(KC_UP)},
	//RESTORE
	{ C(G(S(KC_U))), KC_NO},
	//CLS_APP
	{ G(KC_Q), A(KC_F4)},
	//WIN_CTR
	{ KC_LCTL, KC_LWIN},
	//DEL_LN
	{ G(KC_BSPC), C(S(KC_K))},
	//TRASH
	{ G(KC_BSPC), KC_DEL},
	//REMOVE
	{ A(G(KC_BSPC)), S(KC_DEL)},
	//NEWTAB
	{ G(KC_T), C(KC_T)},
	//LBCMD
	{ G(KC_LBRC), C(KC_LBRC)},
	//RBCMD
	{ G(KC_RBRC), C(KC_RBRC)},
	//CLS_WIN
	{ G(KC_W), C(KC_W)},

};

//returns the extendend shortcut keycode according to the current OS
static uint16_t getOSKey(uint16_t keyName ){
	return pgm_read_word( &( osKeys[ keyName - FIRST_OS_INDEX -1 ][ os ] ) );
};
