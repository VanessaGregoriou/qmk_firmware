#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FL 1
#define _ML 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,---------------------------.          ,------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|          |  7|  8|  9|  0|  -|  =|Backsp |Enc |
   * |---------------------------'        ,--------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|          |  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |---------------------------.        `--------------------------------------|
   * |Esc/FN |  A|  S|  D|  F|  G|          |  H|  J|  K|  L|  ;|  '|Return |Hme |
   * |----------------------------.         `------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|          |  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------|          |-----------------------------------|
   * |Ctrl |Ctrl |Alt |Gui | Space|          |Space|Space|MN  |Ctrl |Lef|Dow|Rig |
   * `----------------------------'          `-----------------------------------'
   */
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, _______, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
    LT(_FL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END, \
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI,KC_SPC,                              KC_SPC, KC_SPC,  MO(_ML) , KC_RCTL, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Keymap _FL: Function Layer
   * ,---------------------------.          ,------------------------------------.
   * |`   |F1| F2| F3| F4| F5| F6|          | F7| F8| F9|F10|F11|F12|Del    |Enc |
   * |---------------------------'        ,--------------------------------------|
   * |     |McL|MsU|McR|LC(b)|  |          |  |   |SDn|SUp|   |   |   | Ins |PgU |
   * |---------------------------.        `--------------------------------------|
   * |       |Msl|MsD|MsR|   |   |          |<- |Dn |Up | ->|   |   |       |PgD |
   * |----------------------------.         `------------------------------------|
   * |        |   |   |   |   |   |          |   |Hme|End|   |   |      |   |    |
   * |----------------------------|          |-----------------------------------|
   * |     |   |    |    |  Enter |          | Bsp | Bsp |    |     |   |   |    |
   * `----------------------------'          `-----------------------------------'
   */
  [_FL] = LAYOUT_65(
    KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,  _______, \
    _______, KC_BTN1, KC_MS_U, KC_BTN2, LCTL(KC_B), _______,                   _______, _______, KC_MS_WH_DOWN, KC_MS_WH_UP, _______, _______, _______, KC_INS, KC_PGUP, \
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, KC_PGDN, \
    _______, _______, _______, _______, _______, _______,                   _______, KC_HOME, KC_END, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_ENT,                             KC_BSPC, KC_BSPC, _______, _______, _______, _______, _______, _______
  ),
  /* Keymap _ML: Media Layer
   * ,---------------------------.          ,------------------------------------.
   * |Swp |  |   |   |   |   |   |          |   |   |   |   |   |   |       |Enc |
   * |---------------------------'        ,--------------------------------------|
   * |     |   |   |   |   |   |          |   |   |   |   |   |Prv|Nxt| Play|    |
   * |---------------------------.        `--------------------------------------|
   * |       |   |   |   |   |   |          |   |   |   |   |   |   |       |    |
   * |----------------------------.         `------------------------------------|
   * |        |   |   |   |   |   |          |   |   |VU-|VU+|Mut|      |   |    |
   * |----------------------------|          |-----------------------------------|
   * |     |   |    |    |        |          |     |     |    |     |   |   |    |
   * `----------------------------'          `-----------------------------------'
   */
  [_ML] = LAYOUT_65(
    AG_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK , KC_MEDIA_PLAY_PAUSE, _______, \
    _______, _______, _______, _______, _______,_______,_______, _______, _______, _______,_______,_______,        _______, _______, \
    _______, _______,_______,_______,_______,_______,_______, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, KC_TRNS, _______, _______, _______, _______, _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
