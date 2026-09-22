#pragma once

#define MASTER_LEFT

// One firmware image for both hands. TRRS ring 2 is pad P21 on both PCBs, but
// the right hand's MCU is flipped, so that pad is GP29 on the left and GP2 on
// the right. The RP2040 PIO serial driver only ever uses this define as a
// runtime value (pio_init(tx_pin, ...), 1U << pin), and handedness is settled
// in split_pre_init() before the transport is initialised, so it can be picked
// per hand at runtime.
#ifndef __ASSEMBLER__
#    include <stdbool.h>
bool is_keyboard_left(void);
#    define SERIAL_USART_TX_PIN (is_keyboard_left() ? GP29 : GP2)
#endif

#define HOLD_ON_OTHER_KEY_PRESS
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_DELAY 15
#define MOUSEKEY_MAX_SPEED 10
