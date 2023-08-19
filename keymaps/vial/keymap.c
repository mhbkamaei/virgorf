#include QMK_KEYBOARD_H

#define KC__ KC_TRNS

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define OO_SPC LT(NAV, KC_SPC)
#define OO_BSPC LT(FUN, KC_BSPC)
#define OO_TAB LT(NUM, KC_TAB)

#define OO_ENT LT(SYM, KC_ENT)
#define OO_ESC LT(MOUSE, KC_ESC)
#define OO_DEL LT(MEDIA, KC_DEL)
// Right-hand home row mods
#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

enum layers { BASE, NAV, FUN, NUM, SYM, MOUSE, MEDIA,BUTTON };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		HM_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,
                      OO_BSPC, OO_SPC,  OO_TAB,     OO_ESC,  OO_ENT,  KC_DEL),

	[NAV] = LAYOUT(
		KC_CAPS, KC_NO,   KC_NO,    KC_NO,    KC_NO,       KC_INS,  KC_HOME,   KC_PGUP,  KC_NO,    KC_NO,
		KC_LGUI, KC_LALT, KC_LCTL,  KC_LSFT,  KC_NO,       KC_LEFT, KC_DOWN,   KC_UP,    KC_RGHT, KC_NO,
		KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,       KC_DEL,  KC_END,    KC_PGDN,  KC_NO,    KC_NO,
                      KC__,     KC__,     KC__,        KC__,    KC__,      KC__),

	[FUN] = LAYOUT(
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,
		KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,       KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
                        KC__,     KC__,     KC__,        KC__,    KC__,      KC__),

    [NUM] = LAYOUT(
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_ASTR,  KC_7, KC_8, KC_9, KC_MINS,
		KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,       KC_SLSH,  KC_4, KC_5, KC_6, KC_PLUS,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_DOT,   KC_1, KC_2, KC_3, KC_EQL,
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
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC__,  KC__,  KC__,     KC__,  KC__,    KC__),
};
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}