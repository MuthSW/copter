EXECUTABLE=main.elf
BIN_IMAGE=main.bin

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-g -O2 -mlittle-endian -mthumb
CFLAGS+=-mcpu=cortex-m4
CFLAGS+=-ffreestanding -nostdlib

# for usb_conf.h: Use Full speed (FS) on USB
CFLAGS+=-DUSE_USB_OTG_FS=1

# to run from FLASH
CFLAGS+=-Wl,-T,stm32_flash.ld

CFLAGS+=-I./

# Default C stuff
CFLAGS+=-I/opt/local/arm-none-eabi/include
LDFLAGS+=-L/opt/local/arm-none-eabi/lib

# STM32F4 StdPeriph Driver (lib) stuff
CFLAGS+=-I../lib/inc
CFLAGS+=-I../lib/inc/device_support
CFLAGS+=-I../lib/inc/core_support 
LDFLAGS+=-L../lib/build -lSTM32F4xx_StdPeriph_Driver

# USB stuff
CFLAGS+=-I../lib/STM32_USB_Device_Library/Class/cdc/inc
CFLAGS+=-I../lib/STM32_USB_Device_Library/Core/inc
CFLAGS+=-I../lib/STM32_USB_OTG_Driver/inc
# for COM1 definition:
CFLAGS+=-I../lib/Utilities/STM32F4-Discovery


all: $(BIN_IMAGE)

$(BIN_IMAGE): $(EXECUTABLE)
	$(OBJCOPY) -O binary $^ $@

$(EXECUTABLE): main.c system_stm32f4xx.c startup_stm32f4xx.s stm32f4xx_it.c \
	usb_bsp.c usbd_desc.c usbd_usr.c usb_core.c  usbd_cdc_if_template.c \
	../lib/Utilities/STM32F4-Discovery/stm32f4_discovery.c \
	../lib/Utilities/printf.c
				
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(BIN_IMAGE)

.PHONY: all clean
