#include "zdb.h"
#include "zstr.h"

int main(int argc,char **argv){
    // char *name = DB_read("jell","da");
    // printf("%s\n", "main");
    char **res = zstrsplit("zuston||sdjdj",'|');
    // printf("%s\n", *res);
    while(*res!=NULL){
    	printf("%s\n", *res);
    	*res++;
    }
    return 0;
}
