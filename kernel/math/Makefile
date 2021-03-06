#
# Makefile for the FREAX-kernel character device drivers.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#

include ../../Makefile.header

CFLAGS	+= -finline-functions -nostdinc -I../../include
CPP	+= -I../../include

.c.s:
	@$(CC) $(CFLAGS) \
	-S -o $*.s $<
.s.o:
	@$(AS) -o $*.o $<
.c.o:
	@$(CC) $(CFLAGS) \
	-c -o $*.o $<

OBJS  = math_emulate.o error.o convert.o ea.o get_put.o \
	add.o mul.o div.o compare.o
#OBJS  = math_emulate.o error.o convert.o ea.o get_put.o \
#	add.o mul.o div.o compare.o

math.a: $(OBJS)
	@$(AR) rcs math.a $(OBJS)
	@sync

clean:
	@rm -f core *.o *.a tmp_make
	@for i in *.c;do rm -f `basename $$i .c`.s;done

dep:
	@sed '/\#\#\# Dependencies/q' < Makefile > tmp_make
	@(for i in *.c;do echo -n `echo $$i | sed 's,\.c,\.s,'`" "; \
		$(CPP) -M $$i;done) >> tmp_make
	@cp tmp_make Makefile

### Dependencies:
add.s add.o: add.c ../../include/viz/math_emu.h ../../include/viz/sched.h \
 ../../include/viz/head.h ../../include/viz/fs.h \
 ../../include/sys/types.h ../../include/viz/mm.h \
 ../../include/viz/kernel.h ../../include/signal.h \
 ../../include/sys/param.h ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
compare.s compare.o: compare.c ../../include/viz/math_emu.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/sys/types.h \
 ../../include/viz/mm.h ../../include/viz/kernel.h \
 ../../include/signal.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
convert.s convert.o: convert.c ../../include/viz/math_emu.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/sys/types.h \
 ../../include/viz/mm.h ../../include/viz/kernel.h \
 ../../include/signal.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
div.s div.o: div.c ../../include/viz/math_emu.h ../../include/viz/sched.h \
 ../../include/viz/head.h ../../include/viz/fs.h \
 ../../include/sys/types.h ../../include/viz/mm.h \
 ../../include/viz/kernel.h ../../include/signal.h \
 ../../include/sys/param.h ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
ea.s ea.o: ea.c ../../include/stddef.h ../../include/viz/math_emu.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/sys/types.h \
 ../../include/viz/mm.h ../../include/viz/kernel.h \
 ../../include/signal.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h ../../include/asm/segment.h
error.s error.o: error.c ../../include/signal.h ../../include/sys/types.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/viz/mm.h \
 ../../include/viz/kernel.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
get_put.s get_put.o: get_put.c ../../include/viz/math_emu.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/sys/types.h \
 ../../include/viz/mm.h ../../include/viz/kernel.h \
 ../../include/signal.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h ../../include/asm/segment.h
math_emulate.s math_emulate.o: math_emulate.c ../../include/viz/math_emu.h \
 ../../include/viz/sched.h ../../include/viz/head.h \
 ../../include/viz/fs.h ../../include/sys/types.h \
 ../../include/viz/mm.h ../../include/viz/kernel.h \
 ../../include/signal.h ../../include/sys/param.h \
 ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h ../../include/asm/segment.h
mul.s mul.o: mul.c ../../include/viz/math_emu.h ../../include/viz/sched.h \
 ../../include/viz/head.h ../../include/viz/fs.h \
 ../../include/sys/types.h ../../include/viz/mm.h \
 ../../include/viz/kernel.h ../../include/signal.h \
 ../../include/sys/param.h ../../include/sys/time.h ../../include/time.h \
 ../../include/sys/resource.h
