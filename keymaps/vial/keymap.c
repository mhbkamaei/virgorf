#include QMK_KEYBOARD_H
#include "keymaps/vial/common/songs.h"

#define KC__	KC_TRNS
#define QK_LD	QK_LEAD
#define TG_NUM	0x5263 // TG(6)

bool is_leader_pressed = false;
bool is_capswd_pressed = false;
// Left-hand home row mods
#define HM_A	LGUI_T(KC_A)
#define HM_S	LALT_T(KC_S)
#define HM_D	LCTL_T(KC_D)
#define HM_F	LSFT_T(KC_F)

#define OO_SPC	LT(NAV, KC_SPC)
#define OO_BSPC	LT(FUN, KC_BSPC)
#define OO_TAB	LT(NUM, KC_TAB)

#define OO_ENT	LT(SYM, KC_ENT)
#define OO_ESC	LT(MEDIA, KC_ESC)
#define OO_DEL	LT(MOUSE, KC_DEL)
// Right-hand home row mods
#define HM_J	RSFT_T(KC_J)
#define HM_K	RCTL_T(KC_K)
#define HM_L	RALT_T(KC_L)
#define HM_O	RGUI_T(KC_SCLN)

enum layers { BASE, NAV, FUN, NUM, SYM, MOUSE, MEDIA,};
enum custom_keycodes {
	MCR0 = SAFE_RANGE,
	MCR1,
	MCR2,
	MCR3,
	tttt,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
		KC_Q,	KC_W,	KC_E,	KC_R,	TG(3),			KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
		HM_A,	HM_S,	HM_D,	HM_F,	KC_G,			KC_H,	HM_J,	HM_K,	HM_L,	HM_O,
		KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,			KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_SLASH,
						OO_BSPC,OO_SPC,	OO_TAB,			OO_ESC,	OO_ENT,	OO_DEL),

	[NAV] = LAYOUT(
		KC_CAPS, KC_NO,   QK_BOOT,    MCR0, MCR1,       KC_INS,  KC_HOME,   KC_PGUP,  KC_NO,    KC_NO,
		KC_LGUI, KC_LALT, KC_LCTL,  KC_LSFT, MCR2,       KC_LEFT, KC_DOWN,   KC_UP,    KC_RGHT, KC_NO,
		CW_TOGG,   QK_LD,   KC_NO,    KC_NO, MCR3,       KC_DEL,  KC_END,    KC_PGDN,  KC_NO,    KC_NO,
							KC__,     KC__,     KC__,        KC__,    KC__,      KC__),

	[FUN] = LAYOUT(
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,
		KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,       KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
                        	KC__,     KC__,     KC__,        KC__,    KC__,      KC__),

    [NUM] = LAYOUT(
		KC_NO,    KC_NO,    KC_E,	  KC_R,     KC_NO,       KC_ASTR,  KC_7, KC_8, KC_9, KC_MINS,
		KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,       KC_SLSH,  KC_4, KC_5, KC_6, KC_PLUS,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_3,        KC_DOT,   KC_1, KC_2, KC_3, KC_EQL,
                        	KC__,     KC__,     KC__,        KC__,     KC__, KC_0),

    [SYM] = LAYOUT(
		KC_TILD,  KC_CIRC, KC_QUOT, KC_DQUO,  KC_LBRC,        KC_RBRC, KC_NO,   KC_NO,   KC_DLR,  KC_PIPE,
		KC_HASH,  KC_AT,   KC_EXLM, KC_MINS,  KC_LPRN,        KC_RPRN, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
		KC_AMPR,  KC_ASTR, KC_PERC, KC_UNDS,  KC_LCBR,        KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    	   KC__,    KC__,     KC__,           KC__,    KC__,    KC__),

    [MOUSE] = LAYOUT(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                		KC__,  KC__,  KC__,     KC__,  KC__,    KC__),

    [MEDIA] = LAYOUT(
		QK_LD, KC_NO, TG_NUM, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
		CW_TOGG, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
		MCR0, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
            			KC__,  KC__,  KC__,     KC__,  KC__,    KC__),

};

void leader_start_user(void) {
    // Do something when Leader key activates.
	writePinLow(C13); // Turn LED on.
    PLAY_SONG(leader_on_song);
    is_leader_pressed = true;
}

void leader_end_user(void) {
    // Do something when Leader key deactivates.
    bool did_leader_succeed = false;
    if (leader_sequence_one_key(KC_R)) {

        tap_code16(TG_NUM);


		SEND_STRING("DONE");
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_B)) {
        tap_code16(KC_W);
        did_leader_succeed = true;
    }
    if (did_leader_succeed) {
        writePinHigh(C13); // Turn LED off.!!! TODO
    } else {
        writePinHigh(C13); // Turn LED off.!!! TODO
    }
    PLAY_SONG(leader_off_song);
    is_leader_pressed = false;
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        writePinLow(C13); // Turn LED on.
        PLAY_SONG(caps_word_on_song);
        is_capswd_pressed = true;
    } else {
        // Do something when Caps Word deactivates.
        writePinHigh(C13); // Turn LED off.
        PLAY_SONG(caps_word_off_song);
        is_capswd_pressed = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      if (record->event.pressed) {
        writePinLow(C13); // Turn LED on.
      } else if (!is_leader_pressed && !is_capswd_pressed) { // Do not turn LED off if key is leader or caps word.
        writePinHigh(C13); // Turn LED off.
      }

	    switch (keycode) {
    case MCR0:  // Types [] to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("[]");
		tap_code(KC_LEFT);
      }
      break;
	
	case MCR1:  // Types () to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("()");
		tap_code(KC_LEFT);
      }
      break;
	
	case MCR2:  // Types {} to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("{}");
		tap_code(KC_LEFT);
      }
      break;
	
	case MCR3:  // Types <> to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("<>");
		tap_code(KC_LEFT);
      }
      break;
	case tttt:  // Types <> to go up a directory on the shell.
      if (record->event.pressed) {
		tap_code16(TG_NUM);
      }
      break;
  }

      return true; // Process all other keycodes normally
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}