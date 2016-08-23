#include "zstr.h"

int zstrlen(char *string){
	int count = 0;
	while(*string!='\0'){
		count++;
		string++;
	}
	return count;
}
char *zstrcat(char *rootstring,char *catstring){
	int rootstring_count = zstrlen(rootstring);
	int catstring_count = zstrlen(catstring);

	int need_count = rootstring_count+catstring_count;
	int tmparray[need_count];

	strcpy(tmparray,rootstring);
	strcat(tmparray,catstring);

	return tmparray;
}

