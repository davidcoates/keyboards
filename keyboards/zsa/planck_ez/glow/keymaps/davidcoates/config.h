#pragma once

#define HOLD_ON_OTHER_KEY_PRESS

// Generous, because the one combo is a deliberate chord on a layer rather than
// something that could be triggered by a roll: - followed by / would need two
// separate one-shot taps, so there is nothing to misfire against.
#define COMBO_TERM 60

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 600000

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 15

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10
