#include "../../lily58.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

enum layer_number {
  _DEFAULT = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
      KC_ESC , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
      KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                 KC_LALT, LOWER,   KC_LGUI, KC_SPC,  KC_ENT,  KC_BSPC, RAISE,   KC_ALGR
    ),

    [_RAISE] = LAYOUT(
      KC_F1,   KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12,
      KC_TAB , _______, KC_UP  , _______, _______, _______,                   _______, _______, _______, _______, _______, KC_MINS,
      KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_EQL,
      KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,
                                 KC_LALT, LOWER,   KC_LGUI, KC_SPC,  KC_ENT,  KC_DEL,  RAISE,   KC_ALGR
    ),

    [_LOWER] = LAYOUT(
      KC_ESC , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      KC_TAB , _______, KC_VOLU, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      KC_LCTL, _______, KC_VOLD, KC_MPLY, _______, _______,                   _______, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_LALT, LOWER,   KC_DEL,  KC_SPC,  KC_ENT,  KC_DEL,  RAISE,   KC_ALGR
    ),

    [_ADJUST] = LAYOUT(
      RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 KC_LALT, LOWER,   KC_LGUI, KC_SPC,  KC_ENT,  KC_DEL,  RAISE,   KC_ALGR
    )
};

//
// Rotate OLED display
//
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;
    else
        return rotation;
}


//
// OLED display rendering
//
void oled_task_user(void) {
    /*
    if (is_keyboard_master()) {
        render_anim();
    } else {
        oled_write(read_logo(), false);
    }
    */
}
