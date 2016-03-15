#!/system/bin/sh
export PATH=/system/xbin:$PATH

device=`getprop ro.product.device`

if [ "$device" = "klteduosctc" ]; then
    stop ril-daemon2
    start ril-daemon2-09w
fi

