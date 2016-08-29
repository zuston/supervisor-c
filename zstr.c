#include "zstr.h"
#include "zdebug.h"

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
	int *tmparray = malloc(need_count+1);

	strcpy(tmparray,rootstring);
	strcat(tmparray,catstring);

	return tmparray;
}

char **zstrsplit(char *string,char splitflag){
	char **splitarray;
	char **lastres = splitarray;
	char *split = string;
	while(*split!='\0'){
		int count = 0;
		char tmpstring[80];

		if(*split=='\0'){
			break;
		}
		while(*split!=splitflag&&*split!='\0'){
			tmpstring[count] = *split;
			split++;
			count++;
		}
		if(count==0){
			split++;
			continue;
		}
		tmpstring[count] = '\0';
		char *tmparray = malloc(count+1);
		strcpy(tmparray,tmpstring);
		// char *tmarr = zstrcat(tmparray,"\0");
		*splitarray = tmparray;
		// debug_info2string(tmparray);
		splitarray++;
		continue;
	}
	*splitarray = NULL;
	return lastres;
}


char **zstrsplit2str(char *string,char *splitstring){
	return NULL;
}
