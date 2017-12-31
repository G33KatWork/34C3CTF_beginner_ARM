define include-subdir
SELF_DIR := $(SELF_DIR)/$(SUBDIR)
include $(abspath $(SELF_DIR)/target.mak)
SELF_DIR := $(abspath $(SELF_DIR)/..)
endef

define include-subdirs
$(foreach SUBDIR,$(SUBDIRS),$(eval $(value include-subdir)))
endef
