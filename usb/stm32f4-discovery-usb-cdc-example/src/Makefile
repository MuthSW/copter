EXECUTABLE=CDC.elf
BIN_IMAGE=CDC.bin

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-g -O2 -mlittle-endian -mthumb
CFLAGS+=-mcpu=cortex-m4
CFLAGS+=-ffreestanding -nostdlib

# defines
CFLAGS+=-DUSE_STM32F4_DISCOVERY=1
CFLAGS+=-DSTM32F4XX=1
CFLAGS+=-DUSE_STDPERIPH_DRIVER=1
CFLAGS+=-DUSE_USB_OTG_FS=1

# to run from FLASH
CFLAGS+=-Wl,-T,stm32_flash.ld

# includes
CFLAGS+=-I./
CFLAGS+=-I../Libraries/CMSIS/Include
CFLAGS+=-I../Libraries/Device/STM32F4xx/Include
CFLAGS+=-I../Libraries/STM32_USB_Device_Library/Class/cdc/inc
CFLAGS+=-I../Libraries/STM32_USB_Device_Library/Core/inc
CFLAGS+=-I../Libraries/STM32_USB_OTG_Driver/inc
CFLAGS+=-I../Libraries/STM32F4xx_StdPeriph_Driver/inc
CFLAGS+=-I../Utilities/STM32F4-Discovery

# alt von mir CFLAGS+=-I../Libraries/STM32F4xx_StdPeriph_Driver/inc/device_support
# alt von mir CFLAGS+=-I../Libraries/STM32F4xx_StdPeriph_Driver/inc/core_support


# fehlt:			<listOptionValue builtIn="false" value="&quot;D:/stm32f4-projects/atollic workspace/stm32f4-discovery-usb-cdc-example/Utilities/STM32_EVAL&quot;"/>
# müsste jetzt dieser sein: CFLAGS+=-I../Libraries/STM32F4xx_StdPeriph_Driver/inc

all: $(BIN_IMAGE)

$(BIN_IMAGE): $(EXECUTABLE)
	$(OBJCOPY) -O binary $^ $@

$(EXECUTABLE): main.c system_stm32f4xx.c stm32f4_discovery.c startup_stm32f4xx.s stm32f4xx_it.c system_stm32f4xx.c \
	usb_bsp.c usbd_desc.c usbd_usr.c usbd_cdc.c
#	../Libraries/STM32_USB_OTG_Driver/src/usb_dcd_int.c \
#	../Libraries/STM32_USB_OTG_Driver/src/usb_dcd.c \
#	../Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c \
#	../Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c \
#	../Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c \
#	../Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_core.c


# org:		
#	$(CC) $(CFLAGS) $^ -o $@  -L../Libraries/STM32F4xx_StdPeriph_Driver/build -lSTM32F4xx_StdPeriph_Driver -L../Libraries/STM32F_USB_OTG_Driver/build
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(BIN_IMAGE)

.PHONY: all clean
