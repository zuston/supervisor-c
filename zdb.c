#include "zdb.h"
#include "zstr.h"
#include "zdebug.h"
// #include "direct.h"

int DB_checkpath(char *path){
    char pathprefix[] = ZDB_PATH;
    char *absoultPath = zstrcat(pathprefix,path);

    if(!access(absoultPath,0)){
        log_info("the file or floder exist");
        return IO_SUCCESS;
    }
    return IO_FAIL;
}

char *directPath(char *db_name,char *db_table){
    return zstrcat(db_name,zstrcat("/",zstrcat(db_table,ZDB_PREFIX)));
}
char *absoultPath(char *db_name,char *db_table){
    return zstrcat(ZDB_PATH,directPath(db_name,db_table));
}

// 读取文件最后一行进行处理
char *DB_read(char *db_name,char *db_table){
    char *direct_Path = directPath(db_name,db_table);

    debug_info2string(direct_Path);

    char *absoult_Path = absoultPath(db_name,db_table);
    debug_info2string(absoult_Path);
    if(DB_checkpath(direct_Path)){
        FILE *file = fopen(absoult_Path,"r");
        check(file,"the file cannot open");

        int i = -2;
        // 确定最后一行的上一行的分隔符指针
        while(fgetc(file)!='\n'){
            fseek(file,i,SEEK_END);
            i--;
        }
        char string[1024];
        int count = 0;
        while(!feof(file)){
            string[count] = fgetc(file);
            if(string[count]=='\n'){break;}
            count++;
        }
        debug_info2string(string);
        fclose(file);

        return string;
    }else{
        goto error; 
    }
error:
    return NULL;
}

// 换行写入一行
int DB_write(char *db_name,char *db_table,char *content){
    char *direct_Path = directPath(db_name,db_table);

    debug_info2string(direct_Path);

    char *absoult_Path = absoultPath(db_name,db_table);
    debug_info2string(absoult_Path);

    if(!DB_checkpath(db_name)){mkdir(zstrcat(ZDB_PATH,db_name),0777);}
    // if(!DB_checkpath(direct_Path)){}

    FILE *file = fopen(absoult_Path,"at+");
    check(file,"the write file error cannot open it");

    char *ncontent = zstrcat(content,"\n");
    fputs(ncontent,file);
    rewind(file);
    char ch = fgetc(file);
    while(ch!=EOF){
        putchar(ch);
        ch=fgetc(file);
    }
    fclose(file);

    return IO_SUCCESS;
error:
    return -1;
}

void DB_list(char *dbname){

}

void DB_all_list(){

}

int DB_find(char *db_name,char *db_table,char *findcontent){
    return IO_SUCCESS;
}


