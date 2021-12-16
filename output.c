/* 
fopen is used for opening a file 
fclose is to close the file 
getc we read a character from a file
putc write a carachter into a file
getw is to read an integer from a file
putw write an integer
fprintf prints formated outout into a file
fscanf formated iput from a file
fgets read a string of characters from a filef
fputs write a string of characters into a file
feof reads until we reached the end of line character

*/



#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct user
{
    char email[MAX];
    char fname[MAX];
    char lname[MAX];
    char password[MAX];
    char bank[MAX];
    char balance[MAX];
    char secret[MAX];
    char answer[MAX];
    


}
user;

int main ()
{   char t[MAX][MAX];
    char y[MAX];
    int i = 4;
    int num;
     user input;
    FILE *fp; // this is for declaring a file pointer so that means that righ now it points to a file
    fp = fopen("database.txt","r");
    
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
     
    // read file contents till end of file
    while(fscanf(fp,"%s %s %s %s %s %s %s %s",input.email, input.fname, input.lname,input.password,input.bank,input.balance,input.secret,input.answer)!=EOF)
        printf ("email = %s fname = %s lname = %s password is %s bank_account is %s balance is %s secret_question is %s the answer is %s\n", input.email, input.fname, input.lname,input.password,input.bank,input.balance,input.secret,input.answer);
 
    // close file
    fclose (fp);
    ;// r is for just reading the file W is for openig the file and writing over it 
  //  printf("%s",fgets(y,100,fp));
  // fread(fp,user,&num);
   /* fclose(fp);
    fp = fopen("test.txt","r");
   */ 
   
    /*while (getw(fp)!= EOF)
    {
        num = getw(fp);
        printf("data test.txt is file is %d \n",num);
    }
    */
   //char SingleLine[300];
   // fprintf(fp,"%s","hi my name is jambo");
/*
    while (!feof(fp)) // feof is file end of file this while tells the computer to run until it reaches the end of the file
    {   
        fgets(SingleLine,300,fp);
        puts(SingleLine);
        // still working towards it
    }

    */
    /*fclose(fp);
    printf("here is the number %d",num);
    */
    return 0;
}