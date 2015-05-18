#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_PGDN, KC_PGUP, KC_FN2, KC_FN1, KC_BSPC, KC_FN3, KC_FN4,     \
         KC_SPC, KC_FN0, KC_FN5, KC_QUOT, KC_ENT),                     \

  /* 1: punctuation and fn keys -- momentarily toggled with FN0 */
  KEYMAP(SHIFT(KC_EQUAL), SHIFT(KC_1), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_2), \
         SHIFT(KC_BSLS), KC_F1, KC_F2, KC_F3, KC_F4,       \
         SHIFT(KC_8), SHIFT(KC_3), SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_4), \
         KC_GRAVE, KC_F5, KC_F6, KC_F7, KC_F8,       \
         KC_EQUAL, SHIFT(KC_5), KC_LBRC, KC_RBRC, SHIFT(KC_6), \
         SHIFT(KC_7), KC_F9, KC_F10, KC_F11, KC_F12,       \
         KC_PGDN, KC_PGUP, KC_FN2, KC_FN1, KC_BSPC, KC_FN3, KC_FN4,     \
         KC_SPC, KC_FN0, KC_FN5, SHIFT(KC_GRAVE), KC_BSLS),                     \
         

  /* 2: numbers and arrows/movement -- "sticky toggled" with FN1 */
  KEYMAP(SHIFT(KC_EQUAL), KC_7, KC_8, KC_9, KC_MINS,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO, \
         SHIFT(KC_8),     KC_4, KC_5, KC_6, KC_SLSH,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO, \
         KC_EQUAL,        KC_1, KC_2, KC_3, KC_DOT,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_FN7, \
         KC_0, KC_0, KC_FN6, KC_FN1, KC_BSPC, KC_FN3, KC_FN4,     \
         KC_SPC, KC_FN0, KC_FN5, KC_QUOT, KC_ENT)
  
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // momentary to Fn1 overlay
  [1] = ACTION_LAYER_TOGGLE(2),     // toggle for Fn2 overlay
  [2] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_TAB),
  [3] = ACTION_MODS_ONESHOT(MOD_LSFT),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_MINS),
  [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DOT ),
  [7] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
