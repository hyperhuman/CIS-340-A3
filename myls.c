#include <stdlib.h>
#include "myls.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "stringout.h"

const char** myls(char dirname[]){
    char* oneFileBuff = (char *)malloc(sizeof(char)*NAME_MAX);
    char* buffer = (char *)malloc(sizeof(char)*1024);
    int locInBuffer = 0;
    int size;
    int sizeOfBuffer = 1024;
    int numFiles = 0;
    DIR *dir_ptr;
    const char ** sa = malloc(sizeof(char *)*1024);
    struct dirent *directp;
    if((dir_ptr = opendir(dirname)) == NULL){
        printf("Cannot open specified directory\n");
        exit(0);
    }else{
        while((directp = readdir(dir_ptr)) != NULL){
            oneFileBuff = directp->d_name;
            if((strcmp(oneFileBuff, ".") != 0) && strcmp(oneFileBuff, "..") != 0) {
                size = strlen(oneFileBuff);
                if (locInBuffer + size > 1023) {
                    sizeOfBuffer += 1024;
                    char *buffer = realloc(buffer, sizeOfBuffer);
                }
                for (int i = 0; i < size; i++) {
                    buffer[(locInBuffer + i)] = oneFileBuff[i];
                }
                sa[numFiles] = &buffer[locInBuffer];
                numFiles++;
                locInBuffer += (size + 1);
                strcat(buffer, "\0");
            }
        }
        closedir(dir_ptr);
        return sa;
    }
}

int main(int argc, char* argv[]){
    if(argc > 3){
        printf("Too many arguments given\n");
        exit(0);
    }else if(argc == 3){
        stringout(myls(argv[1]), argv[2]);
    }else if(argc == 2){
        if((strncmp(argv[1], "-f", 2) == 0) || (strncmp(argv[1], "-b", 2) == 0)){
            stringout(myls("."), argv[1]);
        }else{
            stringout(myls(argv[1]),"\0");
        }
    }else{
        stringout(myls("."), "\0");
    }
}
