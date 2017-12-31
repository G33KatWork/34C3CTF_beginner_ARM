debug-$(TARGET): $(OBJDIR-$(TARGET))/$(TARGET).elf
	$(error Debugging is not supported with STM32 serial loader)

upload-$(TARGET): $(OBJDIR-$(TARGET))/$(TARGET).bin
	$(call cmd_msg,STM32LOADER,$<)
	$(Q)$(ROOT)/misc/tools/stm32loader.py -p $(STM32LOADER_SERIALPORT) -evw $<

.PHONY: upload-$(TARGET) debug-$(TARGET)
