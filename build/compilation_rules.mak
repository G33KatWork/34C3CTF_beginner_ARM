define create-compilation-rules
#FIXME: remove the specific header dependency file generation rules and
#let the CC and CXX rules do the header dependency generation while compiling code
$(1)/%.d: CFLAGS := $$(CFLAGS-$(TARGET))
$(1)/%.d: $(2)/%.c
#	$$(call cmd_msg,DEPENDS,$$@)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CC) $$(CFLAGS) -MM -MG -MP -MT '$$(@:%.d=%.o)' $$< > $$@

$(1)/%.d: CXXFLAGS := $$(CXXFLAGS-$(TARGET))
$(1)/%.d: $(2)/%.cpp
#	$$(call cmd_msg,DEPENDS,$$@)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CXX) $$(CXXFLAGS) -MM -MG -MP -MT '$$(@:%.d=%.o)' $$< > $$@

$(1)/%.o: CFLAGS := $$(CFLAGS-$(TARGET))
$(1)/%.o: $(2)/%.c
	$$(call cmd_msg,CC,$$<)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CC) $$(CFLAGS) -c $$< -o $$@

$(1)/%.d: CXXFLAGS := $$(CXXFLAGS-$(TARGET))
$(1)/%.o: $(2)/%.cpp
	$$(call cmd_msg,CXX,$$<)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CXX) $$(CXXFLAGS) -c $$< -o $$@

$(1)/%.o: ASFLAGS := $$(ASFLAGS-$(TARGET))
$(1)/%.o: $(2)/%.S
	$$(call cmd_msg,AS,$$<)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CC) -c $$(ASFLAGS) -o $$@ $$<

$(1)/%.o: ASFLAGS := $$(ASFLAGS-$(TARGET))
$(1)/%.o: $(2)/%.s
	$$(call cmd_msg,AS,$$<)
	$$(Q)$$(MKDIR) -p $$(dir $$@)
	$$(Q)$$(CC) -c $$(ASFLAGS) -o $$@ $$<
endef
