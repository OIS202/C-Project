#include <stdio.h>

int main()
{
    int x;            
    int *p;           
    p = &x;          
    printf("Please enter a number: ");
    scanf( "%d", &x );          /* Put a value in x, we could also use p here */
    printf( "%d\n", *p ); /* Note the use of the * to get the value */
    return 0;
}