#pragma once

#define CUSTOM_CODES_BASE_INDEX SAFE_RANGE
#define NUMBER_OF_OS 2

enum layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _NUMPAD,
    _SYMBOL,
    _SHIFT,
    _ADJUST,
	_SETTNG,
    _MAUS,
 };

enum OS {
	OSX = 0,
	WINDOWS
};

extern enum OS os;  //it holds the OS mode of the keyboard. OSX by default

//═══════════════════════════════════════════════════════════════
//   KEYCODE DECLARATIONS
//═══════════════════════════════════════════════════════════════
//most keycodes (except the ones manually handled) are order dependent. If you are
//going to add new codes, add them at the bottom of each section and use them in the
//same order when handling them in handlers.c

enum custom_keycodes {

	//────────────── NULL KEY ──────────────
	//used when no action is required
	NULL_KEY = CUSTOM_CODES_BASE_INDEX, //SAFE_RANGE = 23849

	//────────────── OS DEPENDENT KEYS ──────────────
	FIRST_OS_INDEX,
	CMD_OS,
	CTR_OS,
	CUT,
	COPY,
	PASTE,
	PST_CLEAN,
	PST_PLACE,
	UNDO,
	REDO,
	SCRSHT1,
	SCRSHT2,
	EURO,
	REFRESH,
	SAVE,
	SELECT,
	MUTE,
	VOL_UP,
	VOL_DOWN,
	CLS_APPS,
	BR_UP,
	BR_DOWN,
	W_LEFT,
	W_RIGHT,
	MONITOR,
	Z_IN,
	Z_OUT,
	TOP,
	BOTTOM,
	FIRST,
	LAST,
	MINMZ,
	CLS_W,
	SEARCH,
	SRCH_NX,
	SRCH_PR,
	RPLC,
	SPOTL,
	SM_APP,
	EMOJI,
	LOCK,
	DEL_W,
	SNG_PR,
	SNG_NX,
	PLAY,
	//REBOOT,
	//POWER,
	WIN_L,
	WIN_R,
	MAXMZ,
	RESTORE,
	CLS_APP,
	WIN_CTR,
	DEL_LN,
	TRASH,
	REMOVE,
	NEWTAB,
	LBCMD,
	RBCMD,
	CLS_WIN,
	LAST_OS_INDEX,

	//────────────── CUSTOM HANDLED KEYS ──────────────
	FIRST_CUSTOM_INDEX,
	APPLE_F1,
	APPLE_F2,
	APPLE_F3,
	APPLE_F4,
	APPLE_F5,
	APPLE_F6,
	APPLE_F7,
	APPLE_F8,
	APPLE_F9,
	APPLE_F10,
	APPLE_F11,
	APPLE_F12,
	SWAP_OS,
	SCRSHT,				    // screenshots on pc
    QMKCOMPILE,             // quick compile in qmk msys
    BRACES,
};

// original :: static uint16_t getOSKey(uint16_t keyName );
static uint16_t getOSKey(uint16_t keyName );