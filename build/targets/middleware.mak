#current directory
CURDIR-$(TARGET) := $(SELF_DIR)

# Determine absolute source file directory
SRCDIR-$(TARGET) := $(abspath $(addprefix $(CURDIR-$(TARGET))/,$(SRCDIR)))

# Determinte sources to be created
OBJECTS-$(TARGET) := $(ASOURCES:%.S=%.o)
OBJECTS-$(TARGET) := $(ASOURCES:%.s=%.o)
OBJECTS-$(TARGET) += $(CCSOURCES:%.c=%.o)
OBJECTS-$(TARGET) += $(CXXSOURCES:%.cpp=%.o)

# Include paths to be added to CFLAGS later in executable
INCLUDES-$(TARGET) := $(INCLUDES)
