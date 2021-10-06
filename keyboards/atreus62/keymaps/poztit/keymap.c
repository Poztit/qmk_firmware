#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
        KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER,   KC_DEL,  KC_SPC,   KC_ENT, KC_BSPC, RAISE,   KC_ALGR, KC_EQL,  KC_LBRC, KC_RBRC
    ),

    [_RAISE] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,  _______, KC_UP,   _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_DEL,  KC_SPC,   KC_ENT, KC_BSPC, RAISE,   KC_ALGR, _______, _______, _______
    ),

    [_LOWER] = LAYOUT(
        KC_ESC,  _______, _______, _______, _______, _______,                   _______, _______, _______, KC_LBRC, KC_RBRC, _______,
        KC_TAB,  _______, KC_VOLU, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        XXXXXXX, _______, KC_VOLD, KC_MPLY, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_DEL,  KC_SPC,   KC_ENT, KC_BSPC, RAISE,   KC_ALGR, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
