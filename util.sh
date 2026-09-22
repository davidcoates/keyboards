set -euo pipefail

mkdir -p bin

keyboard_name="shannon"
keymap_name="davidcoates"
firmware_target="${keyboard_name}_$keymap_name.uf2"
repo_dir="$(pwd)"
cache_dir="${XDG_CACHE_HOME:-$HOME/.cache}/keyboards"

firmware_path="$cache_dir/qmk"
firmware_remote="https://github.com/qmk/qmk_firmware.git"
firmware_commit="f0e090f67a90f9b653faeddbf5a1c4f75e24e91a"

function ensure_firmware {
  echo "Checking firmware..."
  if [ ! -d "$firmware_path" ]; then
    mkdir -p "$cache_dir"
    git clone --recurse-submodules "$firmware_remote" "$firmware_path"
  fi
  (cd "$firmware_path" && git fetch origin "$firmware_commit" && git checkout "$firmware_commit" && git submodule sync --recursive && git submodule update --init --recursive)
}

# QMK only finds keyboards under qmk_firmware/keyboards.
function docker_make {
  docker run --rm \
    "$@" \
    -w /qmk_firmware \
    -v "$firmware_path":/qmk_firmware:z \
    -v "$repo_dir/firmware":"/qmk_firmware/keyboards/$keyboard_name":z \
    -e SKIP_GIT=yes \
    -e PYTHONUNBUFFERED=1 \
    ghcr.io/qmk/qmk_cli \
    bash -c "pip install -q -r requirements.txt && make '$keyboard_name:$keymap_name$target_suffix' && chown -R $(id -u):$(id -g) /qmk_firmware"
}

function build {
  ensure_firmware
  echo "Building..."
  target_suffix=""
  docker_make
  mv "$firmware_path/$firmware_target" bin/
  echo "Built target: $firmware_target"
}

function flash {
  ensure_firmware
  echo "Building and flashing..."
  target_suffix=":flash"
  docker_make --privileged -v /dev:/dev -v "/media/$USER":"/media/$USER":rslave -e USER="$USER"
  mv "$firmware_path/$firmware_target" bin/
  echo "Flashed!"
}
