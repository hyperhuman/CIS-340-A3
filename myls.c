#include <stdlib.h>
#include "myls.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "stringout.h"

const char** myls(char dirname[]){
    char* oneFileBuff = (char *)malloc(sizeof(char)*NAME_MAX); //store one file name
    char *buffer = (char *)malloc(sizeof(char)*1024); //buffer to store files
    int locInBuffer = 0; 
    int size;
    int sizeOfBuffer = 1024;
    int numFiles = 0;
    DIR *dir_ptr;
    const char ** sa = malloc(sizeof(char *)*1024); //array of pointers to locations in the buffer of strings
    struct dirent *directp;
    if((dir_ptr = opendir(dirname)) == NULL){ //error case: bad directory
        printf("Cannot open specified directory\n");
        exit(0);
    }else{
        while((directp = readdir(dir_ptr)) != NULL){ //as long as files are in the directory,
            oneFileBuff = directp->d_name;
            if((strcmp(oneFileBuff, ".") != 0) && strcmp(oneFileBuff, "..") != 0) { //discard . and ..
                size = strlen(oneFileBuff);
                if (locInBuffer + size > 1023) { //if buffer is too small to store the string, realloc another KB
                    sizeOfBuffer += 1024;
                    char *newBuffer = (char *)realloc(buffer, sizeOfBuffer);
                    buffer = newBuffer;
                } 
                for (int i = 0; i < size; i++) { //place the string in the buffer
                    buffer[(locInBuffer + i)] = oneFileBuff[i];
                }
                sa[numFiles] = &buffer[locInBuffer]; //create pointer to location in buffer
                numFiles++;
                locInBuffer += (size + 1);
                strcat(buffer, "\0");
            }
        }
        closedir(dir_ptr); //close directory
        return sa;
    }
}

int main(int argc, char* argv[]){ //Handles Input
    if(argc > 3){ //Error case > 3 arguements
        printf("Too many arguments given\n");
        exit(0);
    }else if(argc == 3){ //Sort and use given directory
        printf("Sorted: \n");
        stringout(myls(argv[1]), argv[2]);
    }else if(argc == 2){
        if((strncmp(argv[1], "-f", 2) == 0) || (strncmp(argv[1], "-b", 2) == 0)){ //Sort but use current directory
            printf("Sorted: \n");
            stringout(myls("."), argv[1]);
        }else{ //Use given directory, but do not sort
            stringout(myls(argv[1]),"\0"); 
        }
    }else{ //Use current directory, and do not sort
        stringout(myls("."), "\0");
    }
}
