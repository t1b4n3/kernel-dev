obj-m += hello.o


all:
	# Custom linux kernel
	$(MAKE) -C ../../linux M=$(PWD) modules
	
	#$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
clean:
	$(MAKE) -C ../../linux M=$(PWD) clean

	#$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
