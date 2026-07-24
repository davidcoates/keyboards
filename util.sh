set -euo pipefail

if [ $# -ne 1 ]; then
    echo "expected keymap name"
    exit 1
fi

mkdir -p bin

keymap_source=${1%/}
keymap_name="davidcoates"
userspace_dir="$(pwd)"
cache_dir="${XDG_CACHE_HOME:-$HOME/.cache}/keymaps"

if [ "$keymap_source" == "nyquist" ]; then

  firmware_path="$cache_dir/qmk"
  firmware_remote="https://github.com/qmk/qmk_firmware.git"
  firmware_commit="f0e090f67a90f9b653faeddbf5a1c4f75e24e91a"
  keyboard_name="keebio/nyquist/rev5"
  firmware_target="keebio_nyquist_rev5_$keymap_name.uf2"

elif [ "$keymap_source" == "planck" ]; then

  firmware_path="$cache_dir/zsa"
  firmware_remote="git@github.com:zsa/qmk_firmware.git"
  firmware_commit="5456d00fd858d746df47b1f30e456075c6a4ba24" # firmware24 branch
  keyboard_name="zsa/planck_ez/glow"
  firmware_target="zsa_planck_ez_glow_$keymap_name.bin"

else
  echo "Unrecognized keymap: $keymap_source"
  exit 1
fi

function ensure_firmware {
  echo "Checking firmware..."
  if [ ! -d "$firmware_path" ]; then
    mkdir -p "$cache_dir"
    git clone --recurse-submodules "$firmware_remote" "$firmware_path"
  fi
  (cd "$firmware_path" && git fetch origin "$firmware_commit" && git checkout "$firmware_commit" && git submodule sync --recursive && git submodule update --init --recursive)
}

function docker_make {
  docker run --rm \
    "$@" \
    -w /qmk_firmware \
    -v "$firmware_path":/qmk_firmware:z \
    -v "$userspace_dir":/qmk_userspace:z \
    -e QMK_USERSPACE=/qmk_userspace \
    -e SKIP_GIT=yes \
    -e PYTHONUNBUFFERED=1 \
    ghcr.io/qmk/qmk_cli \
    bash -c "pip install -q -r requirements.txt && make '$keyboard_name:$keymap_name$target_suffix' && chown -R $(id -u):$(id -g) /qmk_firmware /qmk_userspace/$firmware_target"
}

function build {
  ensure_firmware
  echo "Building..."
  target_suffix=""
  docker_make
  mv "$userspace_dir/$firmware_target" bin/
  echo "Built target: $firmware_target"
}

function flash {
  ensure_firmware
  echo "Building and flashing..."
  target_suffix=":flash"
  docker_make --privileged -v /dev:/dev -v "/media/$USER":"/media/$USER":rslave -e USER="$USER"
  mv "$userspace_dir/$firmware_target" bin/
  echo "Flashed!"
}
