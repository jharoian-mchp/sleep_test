obj-m := sleep_test.o

KERNEL_SRC := /home/ghofman/svn/svn_edaqII/Microchip/linux-at91
CROSS_COMPILE := /usr/bin/arm-linux-gnueabihf-
ARCH := arm

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

