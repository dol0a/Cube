TARGET	:= cube

CC	:= clang
CXX	:= clang++
LD	:= $(CXX)

BUILD		:= build
INCLUDE	:= include
SOURCE	:= src \
	src/Compiler \
	src/Evaluater \
	src/IO_Wrapper \
	src/Lexer \
	src/Parser \
	src/Types \
	src/Utils \
	src/VM

COMMONFLAGS	:= -O1
CFLAGS			:= $(COMMONFLAGS) $(INCLUDES) -Wno-switch $(INCLUDES)
CXXFLAGS		:= $(CFLAGS) -std=c++20
LDFLAGS			:= -Wl,--gc-sections

%.o: %.c
	@echo $(notdir $<)
	@$(CC) -MMD -MP -MF $*.d $(CFLAGS) -c -o $@ $<

%.o: %.cc
	@echo $(notdir $<)
	@$(CXX) -MMD -MP -MF $*.d $(CXXFLAGS) -c -o $@ $<

ifneq ($(notdir $(CURDIR)), $(BUILD))

export VPATH	= $(foreach dir,$(SOURCE),$(CURDIR)/$(dir))
export OUTPUT	= $(CURDIR)/$(TARGET)
export INCLUDES	= $(foreach dir,$(INCLUDE),-I$(CURDIR)/$(dir))

CFILES		= $(notdir $(foreach dir,$(VPATH),$(wildcard $(dir)/*.c)))
CXXFILES	= $(notdir $(foreach dir,$(VPATH),$(wildcard $(dir)/*.cc)))

export OBJECTS	= $(CFILES:.c=.o) $(CXXFILES:.cc=.o)

.PHONY: $(BUILD) debug clean all re

all: $(BUILD)

$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $@ -f $(CURDIR)/Makefile

debug:
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	@$(MAKE) --no-print-directory COMMONFLAGS="-g -O0" -C $(BUILD) -f $(CURDIR)/Makefile

clean:
	@rm -rf $(BUILD) $(TARGET)

re: clean all

else

DEPENDS	= $(OBJECTS:.o=.d)

$(OUTPUT): $(OBJECTS)
	@echo linking...
	@$(LD) $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

endif