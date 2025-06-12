# #getting the kernal version 
KVER := $(shell uname -r)
# #including the names file for name access
MODULE_NAME=usbDriver
MODULE_PATH=/lib/modules/$(uname -r)/kernel/drivers/acpi
MODULE_LOAD_DIR=/etc/modules-load.d

BUILD_DIR=build
SRC=src

obj-m := $(MODULE_NAME).o

all: 
	make -C /lib/modules/$(KVER)/build M=$(PWD) modules
	sudo cp $(MODULE_NAME).ko /lib/modules/$(KVER)/kernel/drivers/acpi/
	sudo depmod -a
	sudo modprobe $(MODULE_NAME)
uninstall:
	sudo rm -f /lib/modules/$(KVER)/kernal/drivers/acpi/$(MODULE_NAME).ko
	sudo depmod -a
	sudo modprobe -r $(MODULE_NAME)
clean:
	make -C /lib/modules/$(KVER)/build  M=$(PWD) clean
   
