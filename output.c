#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    FILE *fp;
    fp = fopen("test.txt","r");
    char SingleLine[300];
    while (!feof(fp)) // feof is file end of file this while tells the computer to run until it reaches the end of the file
    {
        fgets(SingleLine,300,fp);
        puts(SingleLine);
        strl
    }
    
    fclose(fp);
    printf("this is a test");
    return 0;
}