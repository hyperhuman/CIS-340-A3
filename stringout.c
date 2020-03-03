#include "stringout.h"
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void stringout(const char* string[], const char *flag){
    if(strcmp(flag, "\0") == 0){ //if supposed to be unsorted, output without any sorting
        int i = 0;
        while(string[i] != NULL){
            printf("%s\n",string[i]);
            i = i + 1;
        }
    }else if(strcmp(flag, "-f") == 0){ //if -f flag, sort in ascending order
        int i = 0;
        int j = 0;
        while(string[i] != NULL){
            j = 0;
            while(string[j] != NULL && string[j+1] != NULL){ //use bubble sort to sort
                if(strcmp(string[j], string[j+1]) > 0){
                    const char* temp = malloc(sizeof(char *));
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
    else if(strcmp(flag, "-b") == 0){ //if -b flag, sort in descending order
        int i = 0;
        int j = 0;
        while(string[i] != NULL){
            j = 0;
            while(string[j] != NULL && string[j+1] != NULL){ //use bubble sort to sort
                if(strcmp(string[j], string[j+1]) < 0){
                    const char* temp = malloc(sizeof(char *));
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