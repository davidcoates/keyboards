# Shannon

A 38-key, split, ortholinear, columnar keyboard with a dedicated palm key per
hand. `hardware/` holds the Ergogen config, KiCad project and fab orders;
`firmware/` holds the QMK keyboard and keymap.

## Building

Requires Docker. One firmware image serves both hands:

    ./build     # bin/shannon_davidcoates.uf2
    ./flash     # build and flash

The firmware assumes a Pro Micro RP2040 pinout and USB plugged into the left
hand.
