#include "stringout.h"
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void stringout(const char* string[], const char *flag){
    if(strcmp(flag, "\0") == 0){
        int i =0;
        while(string[i] != NULL){
            printf("%s\n",string[i]);
            i++;
        }
    }else if(strcmp(flag, "-f") == 0){
        int i =0;
        int j=0;
        const char* temp = malloc(sizeof(char *));
        while(string[i] != NULL){
            j=i;
            while(string[j] != NULL && string[j+1] != NULL){
                if(strcmp(string[j], string[j+1]) > 0){
                    temp = string[j];
                    string[j] = string[j+1];
                    string[j+1] = temp;
                }
                j++;
            }
            i++;
        }
        i = 0;
        while(string[i] != NULL){
            printf("%s\n",string[i]);
            i++;
        }
    }
}