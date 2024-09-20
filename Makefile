obj-m := sleep_test.o

KERNEL_SRC := /home/ghofman/svn/svn_edaqII/Microchip/linux-at91
CROSS_COMPILE := /usr/bin/arm-linux-gnueabihf-
ARCH := arm

all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNEL_SRC) M=$(PWD) modules

clean:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNEL_SRC) M=$(PWD) clean
