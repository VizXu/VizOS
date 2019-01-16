include ../Makefile.header

LDFLAGS	+= -Ttext 0
CPP_DISPLAY	+= -I../include

## target: all
all: bootsect

bootsect.s: bootsect.S ../include/viz/config.h
	$(CPP_DISPLAY) -traditional bootsect.S -o bootsect.s
	
bootsect: bootsect.s
	$(AS86) -o bootsect.o bootsect.s
	$(LD86) -s -o bootsect bootsect.o
	
setup.s: setup.S ../include/viz/config.h
	$(CPP_DISPLAY) -traditional setup.S -o setup.s
	
setup: setup.s
	$(AS86) -o setup.o setup.s
	$(LD86) -s -o setup setup.o

head.o: head.s
	@$(AS) -o head.o head.s
	
#### clear ####
clean:
	@rm -f bootsect bootsect.o bootsect.s setup setup.o setup.s head.o

