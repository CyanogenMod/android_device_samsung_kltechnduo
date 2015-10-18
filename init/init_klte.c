/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
    property_set("ro.telephony.ril.config", "newDialCode");
}

void cdma_properties(char default_cdma_sub[], char operator_numeric[],
        char operator_alpha[])
{
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", "10");
    property_set("ro.telephony.ril.config", "newDriverCallU,newDialCode");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G9006W")) {
        /* klteduoszn */
        property_set("ro.build.fingerprint", "samsung/klteduoszn/klteduoszn:5.0/LRX21T/G9006WZNU1BOC2:user/release-keys");
        property_set("ro.build.description", "klteduoszn-user 5.0 LRX21T G9006WZNU1BOC2 release-keys");
        property_set("ro.product.model", "SM-G9006W");
        property_set("ro.product.device", "klteduoszn");
        gsm_properties();
    } else if (strstr(bootloader, "G9008W")) {
        /* klteduoszm */
        property_set("ro.build.fingerprint", "samsung/klteduoszm/klteduoszm:5.0/LRX21T/G9008WZMU1BOC2:user/release-keys");
        property_set("ro.build.description", "klteduoszm-user 5.0 LRX21T G9008WZMU1BOC2 release-keys");
        property_set("ro.product.model", "SM-G9008W");
        property_set("ro.product.device", "klteduoszm");
        gsm_properties();
    } else if (strstr(bootloader, "G9009W")) {
        /* klteduosctc */
        property_set("ro.build.fingerprint", "samsung/klteduosctc/klte:5.0/LRX21T/G9009WKEU1BOI2:user/release-keys");
        property_set("ro.build.description", "klteduosctc-user 5.0 LRX21T G9009WKEU1BOI2 release-keys");
        property_set("ro.product.model", "SM-G9009W");
        property_set("ro.product.device", "klteduosctc");
        cdma_properties("0", "46003", "中国电信");
    } 

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}

