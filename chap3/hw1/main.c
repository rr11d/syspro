#include <stdio.h>
#include <string.h>
#include "copy.h"

int main(){
    char lines[5][MAXLINE];
    char temp[MAXLINE];
    int lengths[5];
    int i, j;

    for(i = 0; i < 5; i++) {
        if(fgets(lines[i], MAXLINE, stdin) == NULL){
            return 1;
        }
        lengths[i] = strlen(lines[i]);
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4 - i; j++){
            if(lengths[j] < lengths[j+1]){
                int temp_len = lengths[j];
                lengths[j] = lengths[j+1];
                lengths[j+1] = temp_len;

                copy(lines[j], temp);
                copy(lines[j+1], lines[j]);
                copy(temp, lines[j+1]);
            }
        }
    }
    for(i = 0; i < 5; i++){
        printf("%s", lines[i]);
	}

    return 0;
}

