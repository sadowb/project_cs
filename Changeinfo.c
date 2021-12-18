#include <stdio.h>
#include <string.h>

int main()
{
    char change_fname[50], change_lname[50], change_password1[50], change_password2[50], change_email[50], change_bankid[50];
    printf("Change information: ");
    
    printf("Change First Name:");
    scanf("%c", change_fname);

    printf("Change Last Name: ");
    scanf("%c", change_lname);

    printf("Change Password: ");
    scanf("%c", change_password1);

    printf("Re-enter Password: ")
    scanf("%c", change_password2);

    if (change_password1 != change_password2){
        printf("Password does not match:");
        printf("Please Enter a Matching Password: ")
    }else{

    printf("Change email: ");
    scanf("%c", change_email);

    printf("Change Bank Account: ");
    scanf("%c", change_bankid);

    strcpy(new_lname, change_fname);
    strcpy(new_fname, change_lname);
    strcpy(new_password, change_email);
    strcpy(bank_account, change_bankid);


}