#include QMK_KEYBOARD_H
#include "layers.h"

// A perfect 3x5 per hand holds all 26 letters plus , and . once shift and the
// arrow layer take the two bottom corners. Colemak-DH is intact except for Z,
// which takes the right pinky top; ' and / are the two characters that lose
// their homes to make room. The palm keys (edge-of-hand) are escape / enter.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Base layer (Colemak Mod-DH, with Z moved)

  [_BASE] = LAYOUT(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_Z,
    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,
    OSM(MOD_LSFT),  KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         MO(_ARROW),
                    KC_LEFT_CTRL,   KC_SPACE,       SPECIAL,                                        OSL(_NUMPAD),   KC_BSPC,        KC_TAB,
    KC_ESCAPE,                                                                                                                                      KC_ENTER
  ),

  // Symbol layer

  // Every ASCII punctuation character except , and . which are on the base layer.
  // Placed by mnemonic against the base-layer letter underneath:
  //
  //   ?  '  /  *  `      +  \  :  -  "
  //   _  &  {  }  [      ]  (  )  =  ;
  //   ~  !  %  $  |      ^  #  <  >  @
  //
  [_SYMBOL] = LAYOUT(
    KC_QUES,        KC_QUOTE,       KC_SLASH,       KC_ASTR,        KC_GRAVE,       KC_PLUS,        KC_BSLS,        KC_COLN,        KC_MINUS,       KC_DQUO,
    KC_UNDS,        KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_SCLN,
    KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_PIPE,        KC_CIRC,        KC_HASH,        KC_LABK,        KC_RABK,        KC_AT,
                    KC_TRNS,        KC_NO,          KC_TRNS,                                        KC_NO,          KC_DELETE,      UM(EN_DASH),
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  // Numpad layer
  //
  //  7  8  9
  //  4  5  6  0
  //  1  2  3  .

  [_NUMPAD] = LAYOUT(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_0,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_DOT,
                    KC_TRNS,        KC_NO,          KC_NO,                                          KC_TRNS,        KC_NO,          KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  // Navigation layers

  [_ARROW] = LAYOUT(
    KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
                    KC_TRNS,        KC_NO,          KC_NO,                                          MO(_WINDOW),    KC_NO,          MO(_MOUSE),
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_MOUSE] = LAYOUT(
    MS_WHLU,        MS_BTN2,        MS_UP,          MS_BTN1,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    MS_WHLD,        MS_LEFT,        MS_DOWN,        MS_RGHT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_TRNS,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_TRNS,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_WINDOW] = LAYOUT(
    KC_NO,          LCTL(KC_DOWN),  KC_TAB,         LCTL(KC_UP),    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          LCTL(KC_LEFT),  LSFT(KC_TAB),   LCTL(KC_RIGHT), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_TRNS,        KC_NO,          KC_NO,                                          KC_TRNS,        KC_NO,          KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  // Control / misc layer (shift + symbol key)
  //
  // Left hand: media, system and layout switching. Right hand: function keys
  // in the numpad's grid:
  //
  //  F7  F8  F9  F10
  //  F4  F5  F6  F11
  //  F1  F2  F3  F12

  [_CONTROL] = LAYOUT(
    TO(_QWERTY),    KC_WIN_SEL,     KC_VOLU,        KC_MPLY,        QK_BOOT,        KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
    KC_SCR_SHOT,    KC_MPRV,        KC_VOLD,        KC_MNXT,        KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,
                    KC_NO,          KC_NO,          KC_TRNS,                                        KC_NO,          KC_NO,          KC_NO,
    KC_NO,                                                                                                                                          KC_NO
  ),

  // Qwerty layer (for games / applications, not typing)

  [_QWERTY] = LAYOUT(
    TO(_BASE),      KC_Q,           KC_W,           KC_E,           KC_R,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_LEFT_CTRL,   KC_SPACE,       KC_NO,                                          KC_NO,          KC_NO,          KC_NO,
    KC_ESCAPE,                                                                                                                                      KC_NO
  ),

};
