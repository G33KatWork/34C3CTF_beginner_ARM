TARGET = cmsis

# List C source files here.
CCSOURCES = 

# List C++ source files here.
CXXSOURCES =

# List Files to be assembled here
ASOURCES = 

# Additional include paths to consider
INCLUDES =	$(ROOT)/middlewares/cmsis/Include

# Folder for sourcecode
SRCDIR = Src

include $(ROOT)/build/targets/middleware.mak
