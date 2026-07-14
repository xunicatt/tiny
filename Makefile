NAME    := tiny
VERSION := 0
PATCH   := 1

TARGET := $(NAME)-v$(VERSION).$(PATCH).ihx
BUILD  := build

CC    := sdcc
FLASH := stm8flash

CSTD    := --std=c23
CFLAGS   = -mstm8 --opt-code-size
CFLAGS  += $(CSTD) -I.
CFLAGS  += --disable-warning 126 # unreachable code
CFLAGS  += --disable-warning 190 # empty translation unit
LDFLAGS := --out-fmt-ihx

CFILES = core/main.c

OBJFILES := $(patsubst %.c, $(BUILD)/%.rel, $(CFILES))

.PHONY: all clean

all: $(BUILD)/$(TARGET)

$(BUILD)/%.rel: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "CC: $@"

$(BUILD)/$(TARGET): $(OBJFILES)
	@$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^
	@echo "LD: $@"

clean:
	@rm -rf $(BUILD)

flash: $(BUILD)/$(TARGET)
	@$(FLASH) -c stlinkv2 -p stm8s103?3 -w $<
