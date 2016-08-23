#include "zdb.h"
#include "zstr.h"
#include "zdebug.h"

int DB_checkpath(char *path){
    char pathprefix[] = ZDB_PATH;
    char *absoultPath = zstrcat(pathprefix,path);
    
    printf("the absolutpath is %s",absoultPath);
    printf("%c\n", '2');
    return 1;
    if(_access(absoultPath,0)!=-1){
        printf("the file or floder exists;");
        return IO_SUCCESS;
    }
    return IO_FAIL;
}

char *DB_read(char *db_name,char *db_table){
    if(DB_checkpath(db_name)){
        SUCCESS;
        // printf("%s\n", "read success");
    }else{
        ERROR; 
        // printf("%s\n", "read error");
    }
    return NULL;
}

void testMain(){
    printf("%s\n", "hello zuston");
}


int DB_write(char *db_name,char *db_table,char *content){
    return 1;
}



