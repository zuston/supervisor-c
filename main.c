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

void t_dblist(char *dbname){
	DB_list(dbname);
}

void t_dballlist(){
	DB_all_list();
}


int main(int argc,char **argv){
    // t_dbwrite();
    // t_dblist("test");
    t_dballlist();
    return 0;
}


