#include <stdio.h>
#include <string.h>
#include <dirent.h> 
#include "report.h"
void report(char files[][100],int changes[],int cnt){
    for (int i = 0; i < cnt; i++){
            if(strcmp(files[i],"")!= 0)
                printf("%s\t%i\n",files[i],changes[i]);
    }
}