#include "layers.h"

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
  rgb_matrix_mode(0);
  rgb_matrix_sethsv(0, 0, 0);
  rgb_matrix_enable();
  rgb_matrix_set_color_all(0, 0, 0);
}
#endif

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
