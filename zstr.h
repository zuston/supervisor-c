#ifndef __zstr_h__
#define __zstr_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 80

int zstrlen(char *string);
char *zstrcat(char *rootstring,char *catstring);
char **zstrsplit(char *string,char splitflag);

char **zstrsplit2str(char *string,char *splitstring);

#endif
