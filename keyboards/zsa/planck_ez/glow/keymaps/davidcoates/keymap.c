#include QMK_KEYBOARD_H
#include "layers.h"

// Matches the Nyquist keymap, except where the hardware forces a difference:
//
//   - The 2u space means there is no switch at row 3, column 6, so the right
//     thumb has only symbol and numpad. Backspace therefore lives at row 0,
//     column 11 (where the Nyquist has delete) and delete moves to the symbol
//     layer.
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_BSPC,
    KC_MINUS,       KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SCLN,
    OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(_ARROW),
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_SPACE,       KC_NO,          OSL(_SYMBOL),   OSL(_NUMPAD),   KC_NO,          KC_NO,          KC_ENTER
  ),

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_EN_DASH,     KC_GRAVE,       KC_NO,          KC_PIPE,        KC_ASTR,        KC_NO,          KC_NO,          KC_BSLS,        KC_CIRC,        KC_NO,          KC_DQUO,        KC_DELETE,
    KC_UNDS,        KC_AT,          KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_PLUS,        KC_COLN,
    KC_NO,          KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_NO,          KC_NO,          KC_HASH,        KC_LABK,        KC_RABK,        KC_QUES,        KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_TRNS
  ),

  [_NUMPAD] = LAYOUT_ortho_4x12(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_0,           KC_NO,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_DOT,         KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    KC_NO,          KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
    KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          MO(_WINDOW),    MO(_MOUSE),     KC_NO,          KC_NO,          KC_TRNS
  ),

  [_WINDOW] = LAYOUT_ortho_4x12(
    KC_NO,          KC_NO,          LCTL(KC_DOWN),  KC_TAB,         LCTL(KC_UP),    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          LCTL(KC_LEFT),  LSFT(KC_TAB),   LCTL(KC_RIGHT), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_TRNS
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    KC_NO,          MS_WHLU,        MS_BTN2,        MS_UP,          MS_BTN1,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          MS_WHLD,        MS_LEFT,        MS_DOWN,        MS_RGHT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS
  ),

  [_CONTROL] = LAYOUT_ortho_4x12(
    KC_NO,          TO(_QWERTY),    KC_WIN_SEL,     KC_VOLU,        KC_MPLY,        QK_BOOT,        KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
    KC_NO,          KC_SCR_SHOT,    KC_MPRV,        KC_VOLD,        KC_MNXT,        KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_QWERTY] = LAYOUT_ortho_4x12(
    TO(_BASE),      KC_Q,           KC_W,           KC_E,           KC_R,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_SPACE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

};

// The right half of this board is matrix rows 4-7 (the Nyquist's is 5-8), so
// the right-hand coordinates differ from the Nyquist keymap.
const keypos_t layer_indicator_keys[LAYER_COUNT] = {
  [_BASE]    = NO_INDICATOR,
  [_SYMBOL]  = { .row = 1, .col = 3 },
  [_NUMPAD]  = { .row = 5, .col = 1 },
  [_ARROW]   = { .row = 1, .col = 1 },
  [_WINDOW]  = { .row = 0, .col = 2 },
  [_MOUSE]   = { .row = 5, .col = 0 },
  [_CONTROL] = { .row = 2, .col = 3 },
  [_QWERTY]  = { .row = 0, .col = 1 },
};
