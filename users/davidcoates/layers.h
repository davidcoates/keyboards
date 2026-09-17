#pragma once

#include "quantum.h"

// The layer scheme shared by every keyboard: layer names, the custom keys and
// macros that drive them, and (in layers.c) the handlers that implement them.
// Each keymap.c supplies only its keymaps[] array and, on RGB boards, which
// key to light per layer.

#define KC_SCR_SHOT LCTL(LSFT(KC_PSCR))
#define KC_WIN_SEL LALT(LCTL(KC_DOWN))

enum layer_names {
  _BASE,
  _SYMBOL,
  _NUMPAD,
  _FUNCTION,
  _ARROW,
  _MOUSE,
  _WINDOW,
  _CONTROL,
  _QWERTY,
  LAYER_COUNT,
};

enum unicode_names {
  EN_DASH,
};

enum custom_keycodes {
  // Hold for the board's SPECIAL_LAYER (defined in the keymap's config.h);
  // released without use it acts as a one-shot. Shift + hold gives _CONTROL.
  SPECIAL = SAFE_RANGE,
};

#ifdef RGB_MATRIX_ENABLE
// Matrix position of the key lit while each layer is active (the letter that
// names the layer). Defined per keyboard, since right-hand matrix rows differ
// between boards. NO_INDICATOR lights nothing.
#define NO_INDICATOR { .row = 255, .col = 255 }
extern const keypos_t layer_indicator_keys[LAYER_COUNT];
#endif
