#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "text.h"
void text(int len,char target[],FILE* fp,int count,int changes[]){
        printf("%s\n","called");
        char rep[len+1];
        for(int i = 0;i<len;i++){
            rep[i] = toupper(target[i]);
        }
        int counter = 0;
        char temp; 
        char word[len+1];
        int wordLen = (sizeof word)/sizeof word[0];
        int j = 0;
        do {
            temp = fgetc(fp);
                if((isspace(temp) != 0)||temp == EOF){
                    if(strcmp(word,target) == 0){
                        if(temp == EOF){
                            counter++;
                            fseek(fp,-(len),SEEK_CUR);
                            fputs(rep,fp);
                            fseek(fp,len,SEEK_SET);
                        }else{
                            counter++;
                            fseek(fp,-(len+1),SEEK_CUR);
                            fputs(rep,fp);
                            fseek(fp,0,SEEK_SET);
                        }
                    }
                    for(int i = 0;i<len;i++){
                        word[i] = ' ';
                    }
                    word[wordLen] = '\0';
                    j = 0;
                    continue;
                }
            word[j] = temp;
            j++;
        } while (temp != EOF);
        changes[count] = counter;
}
