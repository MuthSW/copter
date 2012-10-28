# ../src/usb_dcd_int.c:361:5: warning: dereferencing type-punned pointer will break strict-aliasing rules

LIB = libSTM32_USB_OTG_Driver.a

CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
RANLIB = arm-none-eabi-ranlib

CFLAGS = -Wall -O2 -mlittle-endian -mthumb
CFLAGS += -mcpu=cortex-m4 -ffreestanding -nostdlib

#usb_conf.h
CFLAGS+=-DUSE_USB_OTG_FS=1
CFLAGS += -I../inc
# for stm32f4xx.h
CFLAGS += -I../../Device/STM32F4xx/Include
# for core_cm4.h
CFLAGS += -I../../CMSIS/Include
# for usb_conf.h
CFLAGS += -I../../../src
# for stm32f4xx_gpio.h
CFLAGS+=-I../../STM32F4xx_StdPeriph_Driver/inc


SRCS = \
../src/usb_core.c \
../src/usb_dcd_int.c \
../src/usb_dcd.c

OBJS = $(SRCS:.c=.o)

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) -r $(LIB) $(OBJS)
	$(RANLIB) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	-rm -f $(OBJS)
	-rm -f $(LIB)

.PHONY: all clean
