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

char **zstrsplit(char *string,char splitflag){
	char **splitarray;
	char **lastres = splitarray;
	char *split = string;
	while(*split!='\0'){
		// static int fl = 1;
		int count = 0;
		char tmpstring[80];
		while(*split!=splitflag&&*split!='\0'){
			tmpstring[count] = *split;
			split++;
			count++;

		}
		if(count==0){
			// printf("%c\n", *split);
			split++;
			continue;
		}
		char tmparray[count];
		strcpy(tmparray,tmpstring);
		// printf("%s\n", tmparray);

		strcpy(*splitarray,tmparray);
		// printf("%s\n", *lastres);
		*splitarray++;
		// free(tmpstring);
		continue;
		// fl++;
	}
	*splitarray = NULL;

	return lastres;
}

