#!/bin/bash
set -euo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd "$DIR"

qmk flash -c -kb bastardkb/charybdis/4x6/v2/splinky_3 -km flo

cd - >/dev/null
