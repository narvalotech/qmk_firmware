#include QMK_KEYBOARD_H

#define ____ KC_TRNS

enum nv0_layers {
    _BASE,
    _UPPER,
};

enum custom_keycodes {
  KC__START = SAFE_RANGE,
  KC_RAISE,
  KC_LOWER,
};

#define MD_LCTL MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_UPPER] = LAYOUT(
  QK_BOOT,QK_RBT, ____,    ____,    ____,    ____,             ____,    ____,    ____,  KC_LBRC, KC_RBRC,  ____,
  KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,   KC_F12,
  KC_ESC, ____,   ____,    ____,    ____,    ____,             KC_INS,  ____,    ____,  ____,    ____,     ____,
  ____,   ____,   ____,    ____,    ____,    ____,             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____,     ____,
                  ____,    ____,    ____,    ____,             ____,    ____,    ____,  ____
),

[_BASE] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,          KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,          KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
  MD_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,     KC_G,          KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,          KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                    KC_LALT, KC_LSFT, KC_LOWER, KC_ENT,        KC_SPC,  KC_LSFT,  KC_BSPC, KC_DEL
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_UPPER);
            }
            else {
                layer_off(_UPPER);
            }
            return false;
    }

    return true;
}
