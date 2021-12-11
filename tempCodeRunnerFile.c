#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char choice[]={"Hello"};
    int i=0;
    while(choice[i]!='\0'){
    choice[i]=tolower( choice[i]);
    i++;
}
printf("%s",choice);
                return 0;
}