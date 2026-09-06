#include "layers.h"

const uint32_t unicode_map[] PROGMEM = {
  [EN_DASH]   = 0x2013, // –
};

void keyboard_post_init_user(void) {
  set_unicode_input_mode(UNICODE_MODE_LINUX);
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_mode(0);
  rgb_matrix_sethsv(0, 0, 0);
  rgb_matrix_enable();
  rgb_matrix_set_color_all(0, 0, 0);
#endif
}

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
  static int  one_shot_layer      = -1;
  static bool sym_ctrl_symbol_held = false;
  static bool sym_ctrl_symbol_used = false;

  switch (keycode) {
    case SYM_CTRL:
      if (record->event.pressed) {
        if (one_shot_layer != -1) {
          layer_off(one_shot_layer);
          one_shot_layer = -1;
        }
        if (get_mods() & MOD_MASK_SHIFT) {
          layer_on(_CONTROL);
          unregister_mods(MOD_MASK_SHIFT);
        } else {
          sym_ctrl_symbol_held = true;
          sym_ctrl_symbol_used = false;
          layer_on(_SYMBOL);
        }
      } else {
        if (IS_LAYER_ON(_CONTROL)) {
          layer_off(_CONTROL);
        } else if (sym_ctrl_symbol_held) {
          sym_ctrl_symbol_held = false;
          if (sym_ctrl_symbol_used) {
            layer_off(_SYMBOL);
          } else {
            one_shot_layer = _SYMBOL;
          }
        }
      }
      return false;
  }

  if (sym_ctrl_symbol_held && record->event.pressed) {
    sym_ctrl_symbol_used = true;
  }

  if (IS_QK_ONE_SHOT_LAYER(keycode)) {
    if (record->event.pressed) {
      one_shot_layer = QK_ONE_SHOT_LAYER_GET_LAYER(keycode);
    }
  } else if (one_shot_layer != -1 && !sym_ctrl_symbol_held) {
    bool delay_unregister = IS_QK_BASIC(keycode) || IS_QK_MODS(keycode);
    if (record->event.pressed) {
      if (delay_unregister) {
        register_code16(keycode);
        return false;
      }
    } else {
      int layer_to_close = one_shot_layer;
      one_shot_layer = -1;
      if (layer_to_close == _SYMBOL) {
        layer_off(_SYMBOL);
      }
      if (delay_unregister) {
        unregister_code16(keycode);
        return false;
      }
    }
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
  static int last_layer = -1;
  int layer = get_highest_layer(layer_state);
  if (last_layer != layer) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
  last_layer = layer;

  keypos_t key = layer_indicator_keys[layer];
  if (key.row != 255) {
    uint8_t index = g_led_config.matrix_co[key.row][key.col];
    rgb_matrix_set_color(index, 0xff, 0xff, 0xff);
  }
  return true;
}
#endif
