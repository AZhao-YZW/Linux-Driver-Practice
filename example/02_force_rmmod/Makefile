MODULE_NAME := force_rmmod
#MODCFLAGS:=-O2 -Wall -DMODULE -D__KERNEL__ -DLINUX -std=c99
#EXTRA_CFLAGS  += $(MODULE_FLAGS) $(CFG_INC) $(CFG_INC)
EXTRA_CFLAGS  += -g -std=gnu99  -Wfatal-errors 



ifneq ($(KERNELRELEASE),)  # kernelspace

obj-m := $(MODULE_NAME).o

else                        # userspace


CURRENT_PATH ?= $(shell pwd)
LINUX_KERNEL_PATH ?= /home/azhao/MyFile/Linux/code/linux-source-5.15.0

CURRENT_PATH := $(shell pwd)

modules:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

modules_install:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules_install


clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
	rm -f modules.order Module.symvers Module.markers

.PHNOY:
	modules modules_install clean



endif