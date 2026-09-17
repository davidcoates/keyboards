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
  static bool special_held        = false;
  static bool special_used        = false;

  switch (keycode) {
    case SPECIAL:
      if (record->event.pressed) {
        if (one_shot_layer != -1) {
          layer_off(one_shot_layer);
          one_shot_layer = -1;
        }
        if (get_mods() & MOD_MASK_SHIFT) {
          layer_on(_CONTROL);
          unregister_mods(MOD_MASK_SHIFT);
        } else {
          special_held = true;
          special_used = false;
          layer_on(SPECIAL_LAYER);
        }
      } else {
        if (IS_LAYER_ON(_CONTROL)) {
          layer_off(_CONTROL);
        } else if (special_held) {
          special_held = false;
          if (special_used) {
            layer_off(SPECIAL_LAYER);
          } else {
            one_shot_layer = SPECIAL_LAYER;
          }
        }
      }
      return false;
  }

  if (special_held && record->event.pressed) {
    special_used = true;
  }

  if (IS_QK_ONE_SHOT_LAYER(keycode)) {
    if (record->event.pressed) {
      one_shot_layer = QK_ONE_SHOT_LAYER_GET_LAYER(keycode);
    }
  } else if (one_shot_layer != -1 && !special_held) {
    bool delay_unregister = IS_QK_BASIC(keycode) || IS_QK_MODS(keycode);
    if (record->event.pressed) {
      if (delay_unregister) {
        register_code16(keycode);
        return false;
      }
    } else {
      int layer_to_close = one_shot_layer;
      one_shot_layer = -1;
      if (layer_to_close == SPECIAL_LAYER) {
        layer_off(SPECIAL_LAYER);
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
