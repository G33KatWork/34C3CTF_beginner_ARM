DEVICES_F1 := 100xb 100xe 101x6 101xb 101xe 101xg 102x6 102xb 103x6 103xb 103xe 103xg 105xc 107xc

define DEVICE_INSTANCE_F1
TARGET = stm32f1_device_$(device)
CCSOURCES = Templates/system_stm32f1xx.c
ASOURCES = Templates/gcc/startup_stm32f$(device).s
INCLUDES =	$(ROOT)/middlewares/stm32f1_devices/Include
SRCDIR = Source
include $(ROOT)/build/targets/middleware.mak
endef

$(foreach device, $(DEVICES_F1), $(eval $(DEVICE_INSTANCE_F1)))
