#ifndef __zdb_h__
#define __zdb_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZDB_PATH "/usr/local/zdb/"
#define ZDB_PREFIX ".log"

#define IO_SUCCESS 1
#define IO_FAIL 0

// 直接api函数，整合select * from db_name;
char *DB_read(char *db_name,char *db_table);
int DB_write(char *db_name,char *db_table,char *content);
int DB_find(char *db_name,char *db_table,char *findcontent);
int DB_list(char *db_name);
int DB_all_list();

int DB_checkpath(char *path);
char *directPath(char *db_name,char *db_table);
char *absoultPath(char *db_name,char *db_table);


#endif
