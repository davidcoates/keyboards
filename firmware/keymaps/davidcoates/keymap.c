#include QMK_KEYBOARD_H

#define KC_SCR_SHOT LCTL(LSFT(KC_PSCR))
#define KC_WIN_SEL LALT(LCTL(KC_DOWN))
#define KC_EN_DASH UC(0x2013)

enum layer_names {
  _BASE,
  _SYMBOL,
  _NUMPAD,
  _ARROW,
  _WINDOW,
  _MOUSE,
  _CONTROL,
  _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Base layer (Colemak Mod-DH, with Z moved)

  [_BASE] = LAYOUT(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_Z,
    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,
    OSM(MOD_LSFT),  KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         MO(_ARROW),
                    KC_LEFT_CTRL,   KC_SPACE,       KC_BSPC,                                        OSL(_NUMPAD),   OSL(_SYMBOL),   KC_TAB,
    KC_ESCAPE,                                                                                                                                      KC_ENTER
  ),

  // Symbol layer
  //
  // Every ASCII punctuation character except , and . which are on the base layer.
  //
  //   @  !  {  }  #      \  *  ~  `  +
  //   "  '  (  )  ;      &  /  -  _  :
  //   =  %  [  ]  $      ^  ?  <  >  |
  //
  [_SYMBOL] = LAYOUT(
    KC_AT,          KC_EXLM,        KC_LCBR,        KC_RCBR,        KC_HASH,        KC_BSLS,        KC_ASTR,        KC_TILD,        KC_GRAVE,       KC_PLUS,
    KC_DQUO,        KC_QUOTE,       KC_LPRN,        KC_RPRN,        KC_SCLN,        KC_AMPR,        KC_SLASH,       KC_MINUS,       KC_UNDS,        KC_COLN,
    KC_EQUAL,       KC_PERC,        KC_LBRC,        KC_RBRC,        KC_DLR,         KC_CIRC,        KC_QUES,        KC_LABK,        KC_RABK,        KC_PIPE,
                    KC_TRNS,        KC_EN_DASH,     KC_NO,                                          KC_NO,          KC_TRNS,        KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_NUMPAD] = LAYOUT(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_0,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_DOT,
                    KC_TRNS,        KC_NO,          KC_NO,                                          KC_TRNS,        KC_NO,          KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_ARROW] = LAYOUT(
    KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
                    KC_TRNS,        KC_NO,          KC_NO,                                          MO(_MOUSE),     MO(_WINDOW),    KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_WINDOW] = LAYOUT(
    KC_NO,          LCTL(KC_DOWN),  KC_TAB,         KC_F10,         LCTL(KC_B),     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          LCTL(KC_LEFT),  LSFT(KC_TAB),   LCTL(KC_RIGHT), LCTL(KC_T),     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_TRNS,        KC_NO,          KC_F4,                                          KC_NO,          KC_TRNS,        KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_MOUSE] = LAYOUT(
    MS_WHLU,        MS_BTN2,        MS_UP,          MS_BTN1,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    MS_WHLD,        MS_LEFT,        MS_DOWN,        MS_RGHT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_TRNS,        KC_NO,          KC_NO,                                          KC_TRNS,        KC_NO,          KC_NO,
    KC_TRNS,                                                                                                                                        KC_TRNS
  ),

  [_CONTROL] = LAYOUT(
    TO(_QWERTY),    KC_WIN_SEL,     KC_VOLU,        KC_MPLY,        QK_BOOT,        KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
    KC_SCR_SHOT,    KC_MPRV,        KC_VOLD,        KC_MNXT,        KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,
                    KC_NO,          KC_TRNS,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,
    KC_NO,                                                                                                                                          KC_NO
  ),

  [_QWERTY] = LAYOUT(
    TO(_BASE),      KC_Q,           KC_W,           KC_E,           KC_R,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                    KC_LEFT_CTRL,   KC_SPACE,       KC_NO,                                          KC_NO,          KC_NO,          KC_NO,
    KC_ESCAPE,                                                                                                                                      KC_NO
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  clear_oneshot_mods();
  if (layer_state_cmp(state, _WINDOW)) {
    register_code(KC_LALT);
  } else {
    unregister_code(KC_LALT);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Shift + space enters the control layer (every thumb key is spoken for).
  if (keycode == KC_SPACE) {
    if (record->event.pressed) {
      if ((get_mods() & MOD_MASK_SHIFT) && !layer_state_is(_QWERTY)) {
        unregister_mods(MOD_MASK_SHIFT);
        layer_on(_CONTROL);
        return false;
      }
    } else if (IS_LAYER_ON(_CONTROL)) {
      layer_off(_CONTROL);
      return false;
    }
  }

  // Layer keys are held, not tapped; one-shot only makes a fast tap-then-key
  // robust. When a key press consumes the one-shot layer, QMK releases that
  // key immediately (do_release_oneshot in action.c), so it cannot be held.
  // Register it here instead so it stays down until physically released.
  if (is_oneshot_layer_active() && (IS_QK_BASIC(keycode) || IS_QK_MODS(keycode))) {
    if (record->event.pressed) {
      register_code16(keycode);
    } else {
      unregister_code16(keycode);
    }
    return false;
  }
  return true;
}
