/*
 *  viz/lib/write.c
 *
 *  (C) 2019  VizXu
 */

#define __LIBRARY__
#include <unistd.h>

_syscall3(int,write,int,fd,const char *,buf,off_t,count)
