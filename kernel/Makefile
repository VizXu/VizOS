#
# Makefile for the FREAX-kernel.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#

include ../Makefile.header

LDFLAGS	+= -r

# NOTE!: do not try to add -On to CFLAGS with gcc4.x, which will optimize the
# memcpy function a lot to let the kernel not work, for fixing this problem,
# please refer to glibc and rewrite the memcpy in include/string.h, or just not
# use any -On options with gcc 4.x when compiling it. in fact, we only can not
# use -On with gcc4.x to compile fork.c, but after that you need to isolate the
# compling procedure of it, it's not good too. for playing with viz-0.11, we
# just have fun, have no much concerning about the performance.

CFLAGS	+= -finline-functions -nostdinc -I../include	
CPP	+= -I../include

.c.s:
	@$(CC) $(CFLAGS) \
	-S -o $*.s $<
.s.o:
	@$(AS) -o $*.o $<
.c.o:
	@$(CC) $(CFLAGS) \
	-c -o $*.o $<

OBJS  = sched.o sys_call.o traps.o asm.o fork.o panic.o printk.o vsprintf.o sys.o exit.o signal.o mktime.o
	#sched.o sys_call.o traps.o asm.o fork.o panic.o printk.o vsprintf.o sys.o exit.o signal.o mktime.o	
kernel.o: $(OBJS)
	@$(LD) $(LDFLAGS) -o kernel.o $(OBJS)
	@sync

clean:
	@rm -f core *.o *.a tmp_make keyboard.s
	@for i in *.c;do rm -f `basename $$i .c`.s;done
	@for i in chr_drv blk_drv math; do make clean -C $$i; done

dep:
	@sed '/\#\#\# Dependencies/q' < Makefile > tmp_make
	@(for i in *.c;do echo -n `echo $$i | sed 's,\.c,\.s,'`" "; \
		$(CPP) -M $$i;done) >> tmp_make
	@cp tmp_make Makefile
	@for i in chr_drv blk_drv math; do make dep -C $$i; done

### Dependencies:
exit.s exit.o: exit.c ../include/errno.h ../include/signal.h \
 ../include/sys/types.h ../include/sys/wait.h ../include/viz/sched.h \
 ../include/viz/head.h ../include/viz/fs.h ../include/viz/mm.h \
 ../include/viz/kernel.h ../include/sys/param.h ../include/sys/time.h \
 ../include/time.h ../include/sys/resource.h ../include/viz/tty.h \
 ../include/termios.h ../include/asm/segment.h
fork.s fork.o: fork.c ../include/errno.h ../include/viz/sched.h \
 ../include/viz/head.h ../include/viz/fs.h ../include/sys/types.h \
 ../include/viz/mm.h ../include/viz/kernel.h ../include/signal.h \
 ../include/sys/param.h ../include/sys/time.h ../include/time.h \
 ../include/sys/resource.h ../include/asm/system.h
mktime.s mktime.o: mktime.c ../include/time.h
panic.s panic.o: panic.c ../include/viz/kernel.h ../include/viz/sched.h \
 ../include/viz/head.h ../include/viz/fs.h ../include/sys/types.h \
 ../include/viz/mm.h ../include/signal.h ../include/sys/param.h \
 ../include/sys/time.h ../include/time.h ../include/sys/resource.h
printk.s printk.o: printk.c ../include/stdarg.h ../include/stddef.h \
 ../include/viz/kernel.h
sched.s sched.o: sched.c ../include/viz/sched.h ../include/viz/head.h \
 ../include/viz/fs.h ../include/sys/types.h ../include/viz/mm.h \
 ../include/viz/kernel.h ../include/signal.h ../include/sys/param.h \
 ../include/sys/time.h ../include/time.h ../include/sys/resource.h \
 ../include/viz/sys.h ../include/viz/fdreg.h ../include/asm/system.h \
 ../include/asm/io.h
signal.s signal.o: signal.c ../include/viz/sched.h ../include/viz/head.h \
 ../include/viz/fs.h ../include/sys/types.h ../include/viz/mm.h \
 ../include/viz/kernel.h ../include/signal.h ../include/sys/param.h \
 ../include/sys/time.h ../include/time.h ../include/sys/resource.h \
 ../include/asm/segment.h ../include/errno.h
sys.s sys.o: sys.c ../include/errno.h ../include/viz/sched.h \
 ../include/viz/head.h ../include/viz/fs.h ../include/sys/types.h \
 ../include/viz/mm.h ../include/viz/kernel.h ../include/signal.h \
 ../include/sys/param.h ../include/sys/time.h ../include/time.h \
 ../include/sys/resource.h ../include/viz/config.h \
 ../include/asm/segment.h ../include/sys/times.h ../include/sys/utsname.h \
 ../include/string.h
traps.s traps.o: traps.c ../include/viz/head.h ../include/viz/sched.h \
 ../include/viz/fs.h ../include/sys/types.h ../include/viz/mm.h \
 ../include/viz/kernel.h ../include/signal.h ../include/sys/param.h \
 ../include/sys/time.h ../include/time.h ../include/sys/resource.h \
 ../include/asm/system.h ../include/asm/segment.h ../include/asm/io.h
vsprintf.s vsprintf.o: vsprintf.c ../include/stdarg.h ../include/string.h
