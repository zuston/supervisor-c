#include "zdb.h"
#include "zdebug.h"
#include "zstr.h"

void t_zstrsplit(char *string,char splitflag){
	char **res = zstrsplit(string,splitflag);
	printf("%s\n", **res);
    while(*res!=NULL){
    	printf("%s\n", *res);
    	*res++;
    }
}

void t_dbpath(char *dbname,char *dbtable){
	char *name = DB_read(dbname,dbtable);
	// debug_info2string(name);
}
void t_dbwrite(){
	DB_write("zuston","sad","hahhahahh");
}


int main(int argc,char **argv){
    t_dbwrite();
    return 0;
}


