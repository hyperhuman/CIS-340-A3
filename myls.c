#include <stdlib.h>
#include "myls.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "stringout.h"

char* myls(char* dirname[]){
    DIR *dir_ptr; //directory stream
	struct dirent *directp; //hold one entry
    int size = 0;
    while((directp = readdir(dirname)) != NULL){
            size = size + 1;
        }
    char* files[size];
    rewinddir(dir_ptr);
	if((dir_ptr  = opendir(dirname)) == NULL){
		printf("Cannot open %s\n", dirname);
        return dirname;
	}else{
        int i = 0;
		while((directp = readdir(dirname)) != NULL){
           files[i] = (char*)malloc(sizeof(directp->d_name) + 1);
           strncpy(files[size], directp->d_name, directp->d_namlen);
           strcat(files[size], '\0');
           i = i + 1;
           if(i == size){
               break;
           }
		}
		close(dir_ptr);
	}
    return files;
}

int main(int argc, char* argv[]){
    if(argc <= 0){
        printf("Error no directory provided.");
        exit;
    }
    if(argc == 1){
        stringout(myls(argv[0]), '\0');
    }
    if(argc == 2){
        stringout(myls(argv[0]), argv[1]);
    }
    if(argc > 2){
        printf("Too many arguments given.");
        exit;
    }
}
