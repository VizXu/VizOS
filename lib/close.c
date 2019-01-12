/*
 *  viz/lib/close.c
 *
 *  (C) 2019  VizXu
 */

#define __LIBRARY__
#include <unistd.h>

_syscall1(int,close,int,fd)
