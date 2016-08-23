#ifndef __zdb_h__
#define __zdb_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZDB_PATH "/usr/local/zdb/"


#define IO_SUCCESS 1
#define IO_FAIL 0

char *DB_read(char *db_name,char *db_table);
int DB_write(char *db_name,char *db_table,char *content);
int DB_find(char *db_name,char *db_table,char *findcontent);
void DB_list(char *db_name);
void DB_all_list();

void testMain();

int DB_checkpath(char *path);


#endif
