#include "stringout.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringout(char* list[], char* flag){
    int i = 0;
    int j = 1;
    int size, store;
    int *temp[] = (int*)malloc(sizeof(list));
    temp[0] = 0;
    while(list[i+1] != '\0'){
        if(list[i] = NULL && list[i+1] != NULL){
            temp[j] = i + 1;
            j = j + 1;
            i = i + 1;
        }
        while(list[i] != '\0'){
            i = i + 1;
        }
    }
    size = j;
    if(flag == "-f"){
        for(i = 0; i < size; i = i + 1){
            for(j = 0; j < size - 1; j = j + 1){
                if(strcmp(list[temp[j]], list[temp[j+1]]) > 0){
                    store = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = store;
                }
            }
        }
        for(i = 0; i < size; i = i + 1){
            printf("%s", list[temp[i]]);
        }
    }
    else if(flag == "-b"){
        for(i = 0; i < size; i = i + 1){
            for(j = 0; j < size - 1; j = j + 1){
                if(strcmp(list[temp[j]], list[temp[j+1]]) < 0){
                    store = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = store;
                }
            }
        }
        for(i = 0; i < size; i = i + 1){
            printf("%s", list[temp[i]]);
        }
    }
    else{
        for(i = 0; i < size; i = i + 1){
            printf("%s", list[temp[i]]);
        }
    }
}
