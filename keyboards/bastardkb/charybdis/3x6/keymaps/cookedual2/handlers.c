//inspiration source code https://github.com/alvaro-prieto/corne

//#include QMK_KEYBOARD_H
#include "handlers.h"
#include "keydefs.h"
#include "charybdis.h"

//(OSX / WINDOWS) this variable is used to stablish the host OS. OSX by default
enum OS os = OSX;

//Returns Command / Control depending on the OS
uint16_t os_cmd_key(void){;
  return (  os == OSX ? KC_LCMD: KC_LCTL );
}

//══════════════════════════════════════════════════════════════

//Hold down an OS dependent key
void register_os_dependent_key( uint16_t key ){
  uint16_t code = getOSKey( key );
  if( code ) register_code16( code );
}

//Releases an OS dependent key
void unregister_os_dependent_key( uint16_t key ){
  uint16_t code = getOSKey( key );
  if( code ) unregister_code16( code );
}

//Tap an OS dependent key
void tap_os_dependent_key( uint16_t key ){
  uint16_t code = getOSKey( key );
  if( code ) tap_code16( code );
}


//═══════════════════════════════════════════════════════════════
//   KEY EVENT HANDLER
//═══════════════════════════════════════════════════════════════

/*
  Whenever a key is pressed / released, this function is called.
  Keycode could be an uint8_t / uint16_t code, depending on whether it is
  a basic or extended code. Extedend codes can come preboiled with
  modifiers, such as S(KC_A) which is Shift + A. Custom keycodes in this
  keymap are all extended.  The record structure holds information about the
  keystroke as follows:
  keyrecord_t record {
	keyevent_t event {
	  keypos_t key {
		uint8_t col
		uint8_t row
	  }
	  bool     pressed
	  uint16_t time
	}
  }
*/


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool down = record->event.pressed;
 // if( !before_key_handler(keycode, down, record) ) return false;

//In this switch we are going to group in categories different keys, such as standar keys,
  //mod keys, sequence keys, os keys, tap dances, custom managed keys, etc.
  switch (keycode) {

	//────────────────── OS DEPENDENT KEYS ──────────────────
      case FIRST_OS_INDEX ... LAST_OS_INDEX:
        if(down){
        clear_mods();
        register_os_dependent_key( keycode );
        }else{
        unregister_os_dependent_key( keycode );
        }
        return false;

        //════════════════ CUSTOM HANDLED KEYS ══════════════
      case SWIN_OS:
            if (record->event.pressed) {
                clear_mods();
                os = WINDOWS;

                #ifdef OLED_DRIVER_ENABLE
                    oled_os_notification(os);
                #endif
            }
            break;

        case SMAC_OS:
            if (record->event.pressed) {
                clear_mods();
                os = OSX;

                #ifdef OLED_DRIVER_ENABLE
                    oled_os_notification(os);
                #endif
            }
            break;

        return false;

      case SCRSHT:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("S"))); //Windows Key + Shift + S = Screencap
            return false;
          }
          break; 
      case QMKCOM:
          if (record->event.pressed) {
            SEND_STRING("qmk compile -kb bastardkb/charybdis/3x6/v2/splinky_3 -km cooke");
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
      
  }
