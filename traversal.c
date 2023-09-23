#include <stdio.h>
#include <string.h>
#include <dirent.h> 
#include "traversal.h"
#include "text.h"
#include "report.h"
int count = 0;
void traversal(char basePath[],int len,char target[],char files1[][100],int changes1[],int ctn1[])
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    char extension[4];
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            int filelen = strlen(dp->d_name);
            extension[0] = dp->d_name[filelen-4];
            extension[1] = dp->d_name[filelen-3];
            extension[2] = dp->d_name[filelen-2];
            extension[3] = dp->d_name[filelen-1];
            if((extension[0] == '.')&&(extension[1] == 't'||extension[1] == 'T')&&(extension[2] == 'x'||extension[2] == 'X')&&(extension[3] == 't'||extension[3] == 'T')){
                char filePath[100];
                strcpy(filePath,basePath);
                strcat(filePath,"/");
                strcat(filePath,dp->d_name);
                strcpy(files1[count],filePath);
                printf("%i\n",count);
                FILE *fp;
                fp = fopen(filePath, "r+");
                text(len,target,fp,count,changes1);
                fclose(fp);
                count++;
                
            }
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            traversal(path,len,target,files1,changes1,ctn1);
        }
    }
    closedir(dir);
    ctn1[0] = count;
}
