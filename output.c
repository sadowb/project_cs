#include <stdio.h>
int main ()
{
    FILE *fp;
    fp = fopen("test2.txt","W");
    printf("this is a test");
    return 0;
}