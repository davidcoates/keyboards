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
  SUP_0,
  SUP_1,
  SUP_2,
  SUP_3,
  SUP_4,
  SUP_5,
  SUP_6,
  SUP_7,
  SUP_8,
  SUP_9,
  SUP_MINUS,
  SUB_0,
  SUB_1,
  SUB_2,
  SUB_3,
  SUB_4,
  SUB_5,
  SUB_6,
  SUB_7,
  SUB_8,
  SUB_9,
  EN_DASH,
  EM_DASH,
};

const uint32_t unicode_map[] PROGMEM = {
  [SUP_0]     = 0x2070, // ⁰
  [SUP_1]     = 0x00B9, // ¹
  [SUP_2]     = 0x00B2, // ²
  [SUP_3]     = 0x00B3, // ³
  [SUP_4]     = 0x2074, // ⁴
  [SUP_5]     = 0x2075, // ⁵
  [SUP_6]     = 0x2076, // ⁶
  [SUP_7]     = 0x2077, // ⁷
  [SUP_8]     = 0x2078, // ⁸
  [SUP_9]     = 0x2079, // ⁹
  [SUP_MINUS] = 0x207B, // ⁻
  [SUB_0]     = 0x2080, // ₀
  [SUB_1]     = 0x2081, // ₁
  [SUB_2]     = 0x2082, // ₂
  [SUB_3]     = 0x2083, // ₃
  [SUB_4]     = 0x2084, // ₄
  [SUB_5]     = 0x2085, // ₅
  [SUB_6]     = 0x2086, // ₆
  [SUB_7]     = 0x2087, // ₇
  [SUB_8]     = 0x2088, // ₈
  [SUB_9]     = 0x2089, // ₉
  [EN_DASH]   = 0x2013, // –
  [EM_DASH]   = 0x2014, // —
};

enum planck_layers {
  _BASE,
  _QWERTY,
  _SYMBOL,
  _NUMPAD,
  _SUB,
  _SUP,
  _CONTROL,
  _ARROW,
  _MOUSE,
  _FUNCTION,
  _WINDOW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_BSPC,
    KC_MINUS,       KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SCLN,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(_ARROW),
    KC_ESCAPE,      TO(_QWERTY),    KC_LEFT_ALT,    KC_LEFT_CTRL,   OSL(_SYMBOL),   KC_SPACE,       KC_SPACE,       OSL(_NUMPAD),   KC_LEFT_GUI,    ST_MACRO_0,     ST_MACRO_1,     KC_ENTER
  ),

  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_SCR_SHOT,    KC_GRAVE,       UC(EN_DASH),    KC_PIPE,        KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,        KC_CIRC,        UC(EM_DASH),    KC_DQUO,        KC_TRANSPARENT,
    KC_UNDS,        KC_AT,          KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_PLUS,        KC_COLN,
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_HASH,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(_CONTROL),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(_SUP),       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(_SUB),       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_DOT,         MO(_FUNCTION),
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_CONTROL),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SUB] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUB_7),      UC(SUB_8),      UC(SUB_9),      UC(SUB_0),      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUB_4),      UC(SUB_5),      UC(SUB_6),      UC(SUB_0),      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUB_1),      UC(SUB_2),      UC(SUB_3),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SUP] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUP_7),      UC(SUP_8),      UC(SUP_9),      UC(SUP_0),      KC_TRANSPARENT,
    UC(SUP_MINUS),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUP_4),      UC(SUP_5),      UC(SUP_6),      UC(SUP_0),      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(SUP_1),      UC(SUP_2),      UC(SUP_3),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_CONTROL] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_WINDOW),    KC_TRANSPARENT, KC_TRANSPARENT, MO(_MOUSE),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, QK_MOUSE_WHEEL_UP,   QK_MOUSE_BUTTON_2,    QK_MOUSE_CURSOR_UP,   QK_MOUSE_BUTTON_1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),           KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,
    KC_CAPS_LOCK,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_WINDOW] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_UP)), LGUI(KC_UP),    LALT(LCTL(KC_DOWN)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LEFT),     LGUI(KC_DOWN),  LGUI(KC_RIGHT),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

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
  if ((keycode & QK_ONE_SHOT_LAYER) == QK_ONE_SHOT_LAYER) {
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
  static const uint8_t rgb_matrix_split[2] = RGB_MATRIX_SPLIT;
  if (is_keyboard_left() == (index < rgb_matrix_split[0])) // TODO: figure out why this is needed...
  {
    rgb_matrix_set_color(index, 0xff, 0xff, 0xff);
  }
}

bool rgb_matrix_indicators_user(void) {

  static int last_layer = -1;
  int layer = get_highest_layer(layer_state);
  if (last_layer != layer)
  {
    rgb_matrix_set_color_all(0, 0, 0);
  }
  last_layer = layer;

  switch (layer) {
    case _SYMBOL:
      highlight_key(1, 3);
      break;
    case _NUMPAD:
      highlight_key(6, 1);
      break;
    case _SUB:
      highlight_key(6, 1);
      highlight_key(1, 3);
      break;
    case _SUP:
      highlight_key(6, 1);
      highlight_key(0, 3);
      break;
    case _CONTROL:
      highlight_key(2, 3);
      break;
    case _QWERTY:
      highlight_key(0, 1);
      break;
    case _ARROW:
      highlight_key(1, 1);
      break;
    case _MOUSE:
      highlight_key(6, 0);
      break;
    case _FUNCTION:
      highlight_key(0, 3);
      break;
    case _WINDOW:
      highlight_key(0, 2);
      break;
  }

  return true;
}
