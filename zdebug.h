#ifndef __zdebug_h__
#define __zdebug_h__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define NDEBUG 1

#define SUCCESS fprintf(stderr,"[SUCCESS]\t%s:%d\n",__FILE__,__LINE__)
#define ERROR fprintf(stderr,"[ERROR]\t%s:%d\n",__FILE__,__LINE__)

#define check(condition,message) if(!condition){log_error(message);errno=0;goto error;}

#define log_error(message) fprintf(stderr, "[LOG_ERROR]\t%s:%d\tM:%s\n",__FILE__,__LINE__,message)
#define log_info(message) fprintf(stderr, "[LOG_INFO]\t%s:%d\tMsg:%s\n",__FILE__,__LINE__,message)

#define debug_info2string(message) if(NDEBUG){fprintf(stderr, "[DEBUG_INFO]\t%s:%d\tMsg:%s\n", __FILE__,__LINE__,message);}
#define debug_info2int(message) if(NDEBUG){fprintf(stderr, "[DEBUG_INFO]\t%s:%d\tMsg:%d\n", __FILE__,__LINE__,message);}
#define debug_info2char(message) if(NDEBUG){fprintf(stderr, "[DEBUG_INFO]\t%s:%d\tMsg:%c\n", __FILE__,__LINE__,message);}

#endif
