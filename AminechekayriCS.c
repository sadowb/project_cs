#include <stdio.h>
#include <string.h>

struct login //structing the elements we need into one function
{
    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
}
int main()
{
    int user_input;

    printf("To Sign up, press 1");
    printf("To Login, press 2");
    scanf("%d",&user_input);
    if(choice == 1)
        {
            sign_up();
    
    }else 

    if(choice == 2)
        {
            login();
        }
}

sign_up()
{
    FILE *log; //to access the database.txt
    log=fopen("database.txt", "w");
        struct login l; 

    printf ("First Name: ");
    scanf("%s", l.fname);
    printf("Last Name: ");
    scanf("%s", l.lname);

    printf("Username:"); 
    scanf("%s",l.username);
    printf("Password:");
    scanf("%s",l.password);

    fwrite(&l, sizeof(l), log); //sizeof is used in order to compute the size of the data type we are using
    fclose(log);

    printf("Please login:\n In order to move on 'Press any Key ");
    getch(); //used in order to accept any key entered by the user to move on
    login();

}

login()
{
    char username[200], password[200];
    FILE *log; //to access the database.txt
    log=fopen("database.txt", "w");
        struct login l; 
    printf("User Identification: ");
    scanf("%s", &username);

    printf("Password: ");
    scanf("%s", &password);

    while (fread(&l, sizeof(l),l,log)) //the function fread is used to read & write from the file we're opening using 'fopen'
    {
        if (strcmp(username, l.username)==0 && strcmp(password,l.password)==0) //strcmp string was used to compare the two usernames & passwords the user has entered to see if they match what we have in the database
        {
            printf("Signed In");
        }else{
            printf("Wrong credentials");
        }
        fclose(log);
    } 
}
