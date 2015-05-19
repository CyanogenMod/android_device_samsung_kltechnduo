# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common klte
-include device/samsung/klte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := kltexx,klte,kltechnduo,klteduoszn,klteduoszm

#Dual SIM
SIM_COUNT := 2
TARGET_GLOBAL_CFLAGS += -DANDROID_MULTI_SIM
TARGET_GLOBAL_CPPFLAGS += -DANDROID_MULTI_SIM

# Kernel
TARGET_KERNEL_VARIANT_CONFIG := msm8974pro_sec_klte_chnduo_defconfig

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm
TARGET_LIBINIT_DEFINES_FILE := device/samsung/klte/init/init_klte.c
TARGET_UNIFIED_DEVICE := true

# NFC
BOARD_NFC_CHIPSET := pn547

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 13631488
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 15728640
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2548039680
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12442369024 # 12442385408 - 16384

# inherit from the proprietary version
-include vendor/samsung/kltechnduo/BoardConfigVendor.mk