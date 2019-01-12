/*
 *  viz/lib/setsid.c
 *
 *  (C) 2019  VizXu
 */

#define __LIBRARY__
#include <unistd.h>

_syscall0(pid_t,setsid)
