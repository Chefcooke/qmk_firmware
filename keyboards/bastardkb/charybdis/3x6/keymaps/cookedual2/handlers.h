#pragma once

typedef struct Keypress{
	//enum modifier mod;
	short mask;
	uint8_t layer;
	uint16_t skipTime;
	uint16_t keycode;
	uint16_t alternativeKeycode;
	uint16_t osKeycode;
	uint16_t alternativeOsKeycode;
	bool (*downHandler)( struct Keypress *);
	void (*upHandler)( struct Keypress *);
	bool down;
	bool interrupted;
	uint16_t time;
	struct Keypress *next;

} Keypress;