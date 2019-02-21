#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ARROWS 3
#define _MOUSE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM fn_actions[] = {
      [0] = ACTION_LAYER_TAP_KEY(_ARROWS, KC_F),    //Hold for momentary Arrows layer, Tap for F,
      [1] = ACTION_LAYER_TAP_KEY(_MOUSE, KC_D)     //Hold for momentary Mouse layer, Tap for D,
   };

#define F_ARWS FUNC(0)
#define D_MSE FUNC(1)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
enum combos {
  JK_ENT,
  MCOMM_TAB
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JK_ENT] = COMBO(jk_combo, KC_ENT),
  [MCOMM_TAB] = COMBO(mcomm_combo, KC_TAB),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------.                      .-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5 |                      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-----+                      +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T |                      |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-----+                      -------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G |                      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+-----+                      |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B |                      |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+-----+                      +------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Alt  |Lower |Space|                      |Space |Raise | Bksp | Bksp | Lead |Enter |
 * `----------------------------------------'                      ------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                KC_6,           KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                KC_Y,           KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    D_MSE,   F_ARWS, KC_G,                KC_H,           KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                KC_N,           KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, LOWER,  CMD_T(KC_SPC),       SFT_T(KC_SPC),  RAISE, KC_BSPC, KC_BSPC, KC_LEAD, KC_ENT \
),

/* Lower
 * ,---------------------------------------- .                     ------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                     |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------                     -------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                     |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+                     -------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |                     |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------+                     |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |                     |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+                     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |                     | Bksp |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------                     ------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,              KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,             KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, _______, KC_ENT, \
  _______, _______, _______, _______, _______, _______,            KC_BSPC, KC_BSPC,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY \
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* ARROWS
 * ,----------------------------------------.                 .-----------------------------------------.
 * |      |      |      |      |      |     |                 |      |      |      |      |      |      |
 * |------+------+------+------+------+-----+                 +------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |      | HOME | PgUp |      |      |      |
 * |------+------+------+------+------+-----+                 -------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+-----+                 |------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |      | END  | PgDw |      |      |      |
 * |------+------+------+------+------+-----+                 +------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |      |      |      |      |      |      |
 * `----------------------------------------'                 ------------------------------------------'
 */
[_ARROWS] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, KC_HOME, KC_PGUP,   XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,     KC_RIGHT, XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, KC_END,  KC_PGDOWN, XXXXXXX,  XXXXXXX,  XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX \
),

/* MOUSE
 * ,----------------------------------------.                 .-----------------------------------------.
 * |      |      |      |      |      |     |                 |      |      |      |      |      |      |
 * |------+------+------+------+------+-----+                 +------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |      | WhlU |      |      |      |      |
 * |------+------+------+------+------+-----+                 -------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |  MsL | MsDn | MsUp |  MsR |      |      |
 * |------+------+------+------+------+-----+                 |------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |      | WhlD |      |      |      |      |
 * |------+------+------+------+------+-----+                 +------+------+------+------+------+------|
 * |      |      |      |      |      |     |                 |LClick|RClick|      |      |      |      |
 * `----------------------------------------'                 ------------------------------------------'
 */
[_MOUSE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  XXXXXXX,  XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,      KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_2) {
      SEND_STRING("yannick.novella@gmail.com");
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("transaction: options.transaction");
    }
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("Je suis sur que peux pas tapper aussi vite que ca, meme apres des années d'entrainement !!");
    }
    SEQ_TWO_KEYS(KC_G, KC_S) {
      SEND_STRING("git status");
    }
    SEQ_TWO_KEYS(KC_G, KC_C) {
      SEND_STRING("git commit -am '");
    }
    SEQ_TWO_KEYS(KC_G, KC_P) {
      SEND_STRING("git push");
    }
    SEQ_TWO_KEYS(KC_G, KC_F) {
      SEND_STRING("git push --force-with-lease");
    }
  }
}
