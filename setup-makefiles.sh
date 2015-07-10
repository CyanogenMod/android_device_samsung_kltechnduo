#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=kltechnduo
./../../$VENDOR/klte-common/setup-makefiles.sh $@
