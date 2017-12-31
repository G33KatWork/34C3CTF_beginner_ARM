#current directory
CURDIR-$(TARGET) := $(SELF_DIR)

# Variable mangling
OBJDIR-$(TARGET) := $(abspath $(addprefix $(CURDIR-$(TARGET))/,$(OBJDIR)))
SRCDIR-$(TARGET) := $(abspath $(addprefix $(CURDIR-$(TARGET))/,$(SRCDIR)))

# C compiler flags
CFLAGS-$(TARGET) := $(CFLAGS)
CFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
CFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# C++ compiler flags
CXXFLAGS-$(TARGET) := $(CXXFLAGS)
CXXFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
CXXFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# Assembler flags
ASFLAGS-$(TARGET) := $(ASFLAGS)
ASFLAGS-$(TARGET) += $(addprefix -I,$(INCLUDES))
ASFLAGS-$(TARGET) += $(GLOBAL_DEFINES) $(DEFINES)

# Determinte objects to be created
OBJECTS-$(TARGET) := $(ASOURCES:%.S=%.o)
OBJECTS-$(TARGET) := $(ASOURCES:%.s=%.o)
OBJECTS-$(TARGET) += $(CCSOURCES:%.c=%.o)
OBJECTS-$(TARGET) += $(CXXSOURCES:%.cpp=%.o)

# define a name for linking against this lib
BINARY-$(TARGET) := $(OBJDIR-$(TARGET))/$(TARGET).a

# Main targets
all: $(BINARY-$(TARGET))
$(TARGET): $(BINARY-$(TARGET))

$(OBJDIR-$(TARGET))/$(TARGET).a: $(addprefix $(OBJDIR-$(TARGET))/, $(OBJECTS-$(TARGET)))
	$(call cmd_msg,AR,$(@))
	$(Q)$(AR) rcs $@ $^

# Cleaning
clean: clean-$(TARGET)
clean-$(TARGET): clean-% :
	$(Q)$(RM) -rf $(OBJDIR-$*)

# Instantiate the compilation rules for the current project
$(eval $(call create-compilation-rules,$(OBJDIR-$(TARGET)),$(SRCDIR-$(TARGET))))

.PHONY: clean-$(TARGET) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)
ifneq ($(MAKECMDGOALS),clean-$(TARGET))
-include $(addprefix $(OBJDIR-$(TARGET))/, $(OBJECTS-$(TARGET):%.o=%.d))
endif
endif
endif
