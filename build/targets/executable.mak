#current directory
CURDIR-$(TARGET) := $(SELF_DIR)

# Variable mangling
OBJDIR-$(TARGET) := $(abspath $(addprefix $(CURDIR-$(TARGET))/,$(OBJDIR)))
SRCDIR-$(TARGET) := $(abspath $(addprefix $(CURDIR-$(TARGET))/,$(SRCDIR)))

# C compiler flags
CFLAGS-$(TARGET) := $(CFLAGS)
CFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
CFLAGS-$(TARGET) += $(foreach middleware, $(MIDDLEWARES), $(addprefix -I, $(INCLUDES-$(middleware))))
CFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# C++ compiler flags
CXXFLAGS-$(TARGET) := $(CXXFLAGS)
CXXFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
CXXFLAGS-$(TARGET) += $(foreach middleware, $(MIDDLEWARES), $(addprefix -I, $(INCLUDES-$(middleware))))
CXXFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# Assembler flags
ASFLAGS-$(TARGET) := $(ASFLAGS)
ASFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
ASFLAGS-$(TARGET) += $(foreach middleware, $(MIDDLEWARES), $(addprefix -I, $(INCLUDES-$(middleware))))
ASFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# LD flags
LDFLAGS-$(TARGET) := $(LDFLAGS)

# Determinte objects to be created
OBJECTS-$(TARGET) := $(ASOURCES:%.S=%.o)
OBJECTS-$(TARGET) := $(ASOURCES:%.s=%.o)
OBJECTS-$(TARGET) += $(CCSOURCES:%.c=%.o)
OBJECTS-$(TARGET) += $(CXXSOURCES:%.cpp=%.o)

# Build lib search directories
LIBS-$(TARGET) := $(LIBS)

# Build dependency list of libraries
LIBDEPS-$(TARGET) := $(LIBS)

# A name to reference tis target
BINARY-$(TARGET) := $(OBJDIR-$(TARGET))/$(TARGET).bin

# build a list of middleware objects to be compiled
# they are going to end up in our objdir/middlewares/<middlewarename>/...
MIDDLEWARE-OBJECTS-$(TARGET) := \
	$(foreach middleware, $(MIDDLEWARES), \
		$(addprefix $(OBJDIR-$(TARGET))/middlewares/$(middleware)/, $(OBJECTS-$(middleware))) \
)

# Main targets
all: $(BINARY-$(TARGET))
$(TARGET): $(BINARY-$(TARGET))

$(OBJDIR-$(TARGET))/$(TARGET).bin: $(OBJDIR-$(TARGET))/$(TARGET).elf
	$(call cmd_msg,OBJCOPY,$^ -> $(@))
	$(Q)$(OBJCOPY) -O binary $< $@

$(OBJDIR-$(TARGET))/$(TARGET).elf: LDFLAGS := $(LDFLAGS-$(TARGET))
$(OBJDIR-$(TARGET))/$(TARGET).elf: $(addprefix $(OBJDIR-$(TARGET))/,$(OBJECTS-$(TARGET))) $(MIDDLEWARE-OBJECTS-$(TARGET)) $(LIBDEPS-$(TARGET))
	$(call cmd_msg,LINK,$(@))
	$(Q)$(CC) $(LDFLAGS) -o $@ -Wl,--start-group -lc -lm $^ -Wl,--end-group

# Cleaning
clean: clean-$(TARGET)
clean-$(TARGET): clean-% :
	$(Q)$(RM) -f $(CURDIR-$*)/*.map
	$(Q)$(RM) -rf $(OBJDIR-$*)

# Instantiate the compilation rules for the current project
$(eval $(call create-compilation-rules, $(OBJDIR-$(TARGET)),$(SRCDIR-$(TARGET))))

# Instantiate the compilation rules for all the used middlewares
$(foreach middleware, $(MIDDLEWARES), \
	$(eval $(call create-compilation-rules,$(OBJDIR-$(TARGET))/middlewares/$(middleware),$(SRCDIR-$(middleware)))) \
)

#include jtag adapter rules
include $(ROOT)/build/jtag_adapters/$(JTAG_ADAPTER).mak


.PHONY: clean-$(TARGET) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)
ifneq ($(MAKECMDGOALS),clean-$(TARGET))
-include $(addprefix $(OBJDIR-$(TARGET))/, $(OBJECTS-$(TARGET):%.o=%.d))
-include $(MIDDLEWARE-OBJECTS-$(TARGET):%.o=%.d)
endif
endif
endif
