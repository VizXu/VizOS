/*
 *  viz/lib/execve.c
 *
 *  (C) 2019  VizXu
 */

#define __LIBRARY__
#include <unistd.h>

_syscall3(int,execve,const char *,file,char **,argv,char **,envp)
