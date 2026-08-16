#include QMK_KEYBOARD_H

enum planck_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
};

#define KC_SCR_SHOT LCTL(LSFT(KC_PSCR))

void keyboard_post_init_user(void) {
  set_unicode_input_mode(UNICODE_MODE_LINUX);
  rgb_matrix_mode(0);
  rgb_matrix_sethsv(0, 0, 0);
  rgb_matrix_enable();
  rgb_matrix_set_color_all(0, 0, 0);
}

enum unicode_names {
  EN_DASH,
};

const uint32_t unicode_map[] PROGMEM = {
  [EN_DASH]   = 0x2013, // –
};

enum planck_layers {
  _BASE,
  _QWERTY,
  _SYMBOL,
  _NUMPAD,
  _CONTROL,
  _ARROW,
  _MOUSE,
  _FUNCTION,
  _WINDOW,
};

// Reduced to 38 keys. Columns 5 and 6 are gone (taking the 2u space with them),
// so each hand sits one column further out than before: the left hand is now
// columns 0-4 and the right hand columns 7-11, pinky through index-inner.
//
//   X X X X X      X X X X X
//   X X X X X      X X X X X
//   S X X X X      X X X X S
//   P   T T T      T T T   P
//
// S = shift (left) / arrow layer (right), T = thumb, P = palm, KC_NO = removed.
//
// A perfect 3x5 per hand holds all 26 letters plus , and . once shift and the
// arrow layer take the two bottom corners. Colemak-DH is intact except for Z,
// which takes the right pinky top; ' and / are the two characters that lose
// their homes to make room.
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_NO,          KC_NO,          KC_J,           KC_L,           KC_U,           KC_Y,           KC_Z,
    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_NO,          KC_NO,          KC_M,           KC_N,           KC_E,           KC_I,           KC_O,
    OSM(MOD_LSFT),  KC_X,           KC_C,           KC_D,           KC_V,           KC_NO,          KC_NO,          KC_K,           KC_H,           KC_COMMA,       KC_DOT,         MO(_ARROW),
    KC_ESCAPE,      KC_NO,          KC_LEFT_CTRL,   OSL(_SYMBOL),   KC_SPACE,       KC_NO,          KC_NO,          KC_BSPC,        OSL(_NUMPAD),   KC_TAB,         KC_NO,          KC_ENTER
  ),

  // Nothing but WASD, sitting on the F R S T keys so that it lands where the
  // hand already rests. Everything else falls through to the base layer.
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
    TO(_BASE),      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  // Every ASCII punctuation character except , and . which are on the base
  // layer. Placed by mnemonic against the base-layer letter underneath:
  //
  //   Q question   W .          F forward slash  P pointer      B backtick
  //   A at         R reference  S { T }          G [            I is
  //   X exclamation  C percent  D dollar         V vertical bar
  //   L lambda     U underscore  M ] N ( E )     H hash
  //
  // The rest have no letter behind them: < and > sit over , and . ; the quotes
  // take the top right pair, with ' on the better of the two since it is far
  // more common than " in prose; + sits next to = as it does on a staggered
  // board; : and ; share the one free column; and - ~ ^ go by frequency alone.
  //
  //   ?  -  /  *  `      :  \  _  '  "
  //   @  &  {  }  [      ]  (  )  =  +
  //   ~  !  %  $  |      ;  #  <  >  ^
  //
  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_QUES,        KC_MINUS,       KC_SLASH,       KC_ASTR,        KC_GRAVE,       KC_NO,          KC_NO,          KC_COLN,        KC_BSLS,        KC_UNDS,        KC_QUOTE,       KC_DQUO,
    KC_AT,          KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_NO,          KC_NO,          KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_PLUS,
    KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_PIPE,        KC_NO,          KC_NO,          KC_SCLN,        KC_HASH,        KC_LABK,        KC_RABK,        KC_CIRC,
    TO(_BASE),      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_DELETE,      MO(_CONTROL),   KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_ortho_4x12(
  // The operators sit where a physical numpad puts them, / * - reading down the
  // column, with + taking the last free key:
  //
  //   /  7  8  9  +
  //   *  4  5  6  0
  //   -  1  2  3  .
  //
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_PLUS,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_0,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_DOT,
    TO(_BASE),      KC_NO,          MO(_FUNCTION),  MO(_CONTROL),   KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_GUI,    KC_NO,          KC_TRANSPARENT
  ),

  [_CONTROL] = LAYOUT_ortho_4x12(
    KC_SCR_SHOT,    KC_NO,          KC_AUDIO_VOL_UP,     KC_MEDIA_PLAY_PAUSE, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,
    KC_NO,          KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    OSM(MOD_LALT),  KC_NO,          KC_NO,               KC_NO,               KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TO(_BASE),      KC_NO,          TO(_QWERTY),         KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TO(_BASE),      KC_NO,          KC_TRANSPARENT, MO(_WINDOW),    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, MO(_MOUSE),     KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    QK_MOUSE_WHEEL_UP,   QK_MOUSE_BUTTON_2,    QK_MOUSE_CURSOR_UP,   QK_MOUSE_BUTTON_1,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    QK_MOUSE_WHEEL_DOWN, QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT,      KC_NO,                KC_NO,                KC_NO,                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TO(_BASE),           KC_NO,                KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_ortho_4x12(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,
    KC_CAPS_LOCK,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,
    TO(_BASE),      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

  [_WINDOW] = LAYOUT_ortho_4x12(
    KC_NO,          LALT(LCTL(KC_UP)), LGUI(KC_UP),    LALT(LCTL(KC_DOWN)), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          LGUI(KC_LEFT),     LGUI(KC_DOWN),  LGUI(KC_RIGHT),      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,             KC_NO,          KC_NO,               KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TO(_BASE),      KC_NO,             KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),

};

// En dash, chorded from - and / on the symbol layer (the W and F keys). Those
// two keycodes never appear together on any other layer, so this can only fire
// where it is meant to and needs no combo_should_trigger guard.
const uint16_t PROGMEM en_dash_combo[] = {KC_MINUS, KC_SLASH, COMBO_END};

combo_t key_combos[] = {
  COMBO(en_dash_combo, UC(EN_DASH)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_RIGHT))));
    }
    break;
  }
  static int one_shot_layer = -1;
  // Must be a range check, not a mask test: OSM keycodes sit just above the OSL
  // range and share its high bits, so a mask would match one-shot shift too.
  if (IS_QK_ONE_SHOT_LAYER(keycode)) {
    if (record->event.pressed) {
      one_shot_layer = QK_ONE_SHOT_LAYER_GET_LAYER(keycode);
    }
  } else if (one_shot_layer != -1) {
    bool delay_unregister = IS_QK_BASIC(keycode) || IS_QK_MODS(keycode);
    if (record->event.pressed) {
      if (delay_unregister) {
        register_code16(keycode);
        return false;
      }
    } else {
      one_shot_layer = -1;
      if (delay_unregister) {
        unregister_code16(keycode);
        return false;
      }
    }
  }
  return true;
}

void highlight_key(uint8_t row, uint8_t col)
{
  uint8_t index = g_led_config.matrix_co[row][col];
  rgb_matrix_set_color(index, 0xff, 0xff, 0xff);
}

bool rgb_matrix_indicators_user(void) {

  static int last_layer = -1;
  int layer = get_highest_layer(layer_state);
  if (last_layer != layer)
  {
    rgb_matrix_set_color_all(0, 0, 0);
  }
  last_layer = layer;

  // Highlights the key whose letter matches the layer name. Every key moved one
  // column outward with the reduction, so these coordinates all shifted too.
  // _QWERTY uses G (for game), since Q is no longer on the board.
  switch (layer) {
    case _SYMBOL:
      highlight_key(1, 2);
      break;
    case _NUMPAD:
      highlight_key(5, 2);
      break;
    case _CONTROL:
      highlight_key(2, 2);
      break;
    case _QWERTY:
      highlight_key(1, 4);
      break;
    case _ARROW:
      highlight_key(1, 0);
      break;
    case _MOUSE:
      highlight_key(5, 1);
      break;
    case _FUNCTION:
      highlight_key(0, 2);
      break;
    case _WINDOW:
      highlight_key(0, 1);
      break;
  }

  return true;
}
