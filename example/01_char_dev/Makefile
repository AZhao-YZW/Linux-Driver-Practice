KERNEL_DIR = /home/azhao/MyFile/Linux/code/linux-source-5.15.0
CURRENT_PATH := $(shell pwd)
obj-m += mydev.o

all:
	make -C $(KERNEL_DIR) M=$(CURRENT_PATH) modules

clean:
	make -C $(KERNEL_DIR) M=$(CURRENT_PATH) modules clean
	rm -rf modules.order