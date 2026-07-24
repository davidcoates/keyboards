set -euo pipefail

if [ $# -ne 1 ]; then
    echo "expected keymap name"
    exit 1
fi

if [ ! -d "firmware/src" ]; then
  mkdir -p "firmware/src"
fi

if [ ! -d "firmware/bin" ]; then
  mkdir -p "firmware/bin"
fi

keymap_source=${1%/}
keymap_name="davidcoates"

if [ "$keymap_source" == "nyquist" ]; then

  firmware_path="firmware/src/qmk"
  keyboard_name="keebio/nyquist/rev5"
  keymap_path="$firmware_path/keyboards/keebio/nyquist/keymaps/$keymap_name"
  firmware_target="keebio_nyquist_rev5_$keymap_name.uf2"
  flash_function="flash_RP2040"
  if [ ! -d "$firmware_path" ]; then
    git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git $firmware_path
  fi

elif [ "$keymap_source" == "planck" ]; then

  firmware_path="firmware/src/zsa"
  keyboard_name="planck/ez/glow"
  keymap_path="$firmware_path/keyboards/planck/ez/glow/keymaps/$keymap_name"
  firmware_target="planck_ez_glow_$keymap_name.bin"
  flash_function="flash_planck"
  if [ ! -d "$firmware_path" ]; then
    git clone --recurse-submodules --single-branch --branch firmware23 git@github.com:zsa/qmk_firmware.git $firmware_path
    (cd $firmware_path && git apply ../../../zsa.patch)
  fi

else
  echo "Unrecognized keymap: $keymap_source"
  exit 1
fi

function build {
  mkdir "$keymap_path"
  trap 'rm -r -- "$keymap_path"' EXIT
  cp "$keymap_source"/* "$keymap_path"/
  echo "Building..."
  (cd $firmware_path && ./util/docker_build.sh "$keyboard_name:$keymap_name")
  mv "$firmware_path/$firmware_target" firmware/bin/
  echo "Built target: $firmware_target"
}

function flash_RP2040 {
  echo "Waiting for device..."
  local dir="/media/$USER/RPI-RP2"
  while ! mountpoint -q "$dir"; do
    sleep 0.2
  done
  echo "Flashing..."
  sudo cp "firmware/bin/$firmware_target" "$dir"/
  sync
  echo "Flashed!"
}

function flash_planck {
  echo "Waiting for device..."
  local device='0483:DF11'
  while ! lsusb | grep -iq "$device"; do
    sleep 0.2
  done
  echo "Flashing..."
  sudo dfu-util -a 0 -d "$device" -s 0x8000000:leave -D "firmware/bin/$firmware_target"
  echo "Flashed!"
}

function flash {
  if [ ! -f "firmware/bin/$firmware_target" ]; then
    echo "Target $firmware_target not found, building..."
    build
  fi
  sudo -v
  $flash_function
}
