#include "zdb.h"
#include "zstr.h"
#include "zdebug.h"
#include <dirent.h> 
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
    // 将文本string放入文件，并将指针移动到文件头部
    rewind(file);
    fclose(file);

    return IO_SUCCESS;
error:
    return -1;
}

int DB_list(char *dbname){
    DIR *dir = opendir(zstrcat(ZDB_PATH,dbname));
    check(dir,"the dir dont exist");
    struct dirent *direntp;
    if(dir!=NULL){
        np(1);
        printf("库名:\t%s\t\n", dbname);
        while(1){
            direntp = readdir(dir);
            if(direntp==NULL){break;}
            if(direntp->d_name[0]!='.'){
                char *tablename = direntp->d_name;
                // debug_info2string(tablename);
                // char **splitarray = zstrsplit("zu-ds",'-');
                // debug_info2int(zstrlen("asdsad"));
                printf("表名:\t%s\t\n", tablename);
            }
        }
        np(1);
        closedir(dir);
        return IO_SUCCESS;
    }
error:
    return IO_FAIL;

}

int DB_all_list(){
    DIR *dir = opendir(ZDB_PATH);
    check(dir,"the zdb_path donot exist");
    struct dirent *dirstr;
    while(1){
        dirstr = readdir(dir);
        if(dirstr==NULL){break;}
        if(dirstr->d_name[0]!='.'){
            debug_info2string(dirstr->d_name);
            DB_list(dirstr->d_name);
        }
    }
    return IO_SUCCESS;
error:
    return IO_FAIL;
}

int DB_find(char *db_name,char *db_table,char *findcontent){

    return IO_SUCCESS;
}




