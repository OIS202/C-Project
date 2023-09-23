#include <stdio.h>
int main(){
    static char *s[] = {"black","white","pink","violet"};
    char **ptr[] = {s+3,s+2,s+1,s};
    char ***p;
    p = ptr;
    //++p;
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n",**(p+i));
    }
    
}