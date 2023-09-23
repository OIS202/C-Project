#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include <ctype.h>
#include "traversal.h"
#include "report.h"
int main(int argc, char* argv[]){
    if(argc > 1){
        int len = strlen(argv[1]);
        printf("\n%i\n",len);
        printf("%c\n",argv[1][0]);
        char word[len+1];
        for(int i = 0;i<len;i++){
            word[i] = argv[1][i];
        }
        printf("%s\n",word);
        char files[100][100];
        int changes[100];
        int ctn[1];
        traversal(".",len,word,files,changes,ctn);
        int cnt = ctn[0];
        report(files,changes,cnt);
        
    }
    return 0;
}