//A version of ls that Wang gave in class

#include <stdio.h>
#include <sys/types.h>
#include <direct.h>
#define HERE "."
void ls(char ||);
int main(int argc, char *argv[]){
	int i = 1;
	if(i == argc){
		ls(HERE);
	}else{
		//for each command line argument, display contents
		while(i<argc){
			printf("%s:\n", argv[i]);
			ls(argv[i]);
			i++;
		}
	}
}
void ls(char dirname||){
	DIR *dir_ptr; //directory stream
	struct direct *directp; //hold one entry
	if((dir_ptr = opendir(dirname)) == NULL){
		fprintf(strderr,"Cannot_open_%s\n");
	}else{
		while((directp = readdir(dir_ptr)) != NULL){
			printf("%s\n", directp->d_name);
		}
		close(dir_ptr);
	}
}