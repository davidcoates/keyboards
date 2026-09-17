#pragma once

#include "quantum.h"

// The layer scheme shared by every keyboard: layer names, the macros used on
// the control layer, and (in layers.c) the handlers that implement the
// scheme. Each keymap.c supplies only its keymaps[] array and, on RGB boards,
// which key to light per layer.

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
  LAYER_COUNT,
};

#ifdef RGB_MATRIX_ENABLE
// Matrix position of the key lit while each layer is active (the letter that
// names the layer). Defined per keyboard, since right-hand matrix rows differ
// between boards. NO_INDICATOR lights nothing.
#define NO_INDICATOR { .row = 255, .col = 255 }
extern const keypos_t layer_indicator_keys[LAYER_COUNT];
#endif
