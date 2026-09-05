# keyboards

Everything related to my keyboards.

## Keymaps

QMK "external userspace" layout: keymap sources live under
`keyboards/<keyboard>/keymaps/davidcoates`. Requires Docker.

```
./build nyquist   # compile only, output in bin/
./flash nyquist   # compile (if needed) and flash
```

shannon is defined in this repo (rather than in qmk_firmware) -- see
`keyboards/shannon/readme.md`. One image serves both hands:

```
./build shannon
./flash shannon
```
