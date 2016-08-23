#ifndef __zdebug_h__
#define __zdebug_h__

#include <stdio.h>
#include <stdlib.h>


#define SUCCESS fprintf(stderr,"[SUCCESS] %s:%d \n",__FILE__,__LINE__)
#define ERROR fprintf(stderr,"[ERROR] %s:%d \n",__FILE__,__LINE__)


#endif
