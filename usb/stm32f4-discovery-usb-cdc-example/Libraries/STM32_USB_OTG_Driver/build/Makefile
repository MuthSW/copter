LIB = STM32_USB_OTG_Driver.a

CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
RANLIB = arm-none-eabi-ranlib

CFLAGS = -Wall -O2 -mlittle-endian -mthumb
CFLAGS += -mcpu=cortex-m4 -ffreestanding -nostdlib
CFLAGS += -I../inc -I../inc/device_support -I../inc/core_support
# --- different to direcs:
# CFLAGS += -I../../Device/STM32F4xx/Include
# CFLAGS += -I../../CMSIS/Include
# ---

SRCS = \
../src/usb_core.c \
../src/ usb_dcd_int.c \
../src/ usb_dcd.c

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
