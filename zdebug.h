#ifndef __zdebug_h__
#define __zdebug_h__

#include <stdio.h>
#include <stdlib.h>


#define SUCCESS fprintf(stderr,"[SUCCESS] %s:%d ",__FILE__,__LINE__)
#define ERROR fprintf(stderr,"[ERROR] %s:%d ",__FILE__,__LINE__)


#endif
