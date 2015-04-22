$(call inherit-product, vendor/cm/config/common_full_phone.mk)

$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

$(call inherit-product, device/samsung/kltechnduo/full_kltechnduo.mk)

PRODUCT_DEVICE := kltechnduo
PRODUCT_NAME := cm_kltechnduo
