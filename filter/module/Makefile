ifneq ($(KERNELRELEASE),)
ccflags-y += -fno-pic -fno-stack-protector
obj-m	:= dsfilter.o
dsfilter-objs := dsmain.o  dsdebug.o dscore.o
else
#KDIR 替换为本机内核编译输出目录 
KDIR	:= /lib/modules/$(shell uname -r)/build
#/home/ds/tx2/64_TX2/Linux_for_Tegra/sources/kernel/kernel-4.4/OUTPUT
PWD	:= $(shell pwd)
default:
	#cp -f dscore.a dscore.o
	$(MAKE) -C $(KDIR) M=$(PWD) modules
.PHONY:
clean:
	rm -rf .??* *.o* *.o.* *.ko* *.ko.* *.mod.* Module.* modules.*
endif
