ROOT := $(PWD)
include $(ROOT)/build/base.mak

FIRMWARE ?= $(DEFAULT_FIRMWARE)

STARTTIME := $(shell date +%s)
# Main targets
all:
	$(call cmd_msg,NOTICE,Build completed in $$(($$(date +%s)-$(STARTTIME))) seconds)

upload: upload-$(FIRMWARE)
debug: debug-$(FIRMWARE) 

SUBDIRS = middlewares apps
SELF_DIR = $(abspath $(ROOT))
$(call include-subdirs)

.PHONY: all clean upload debug
