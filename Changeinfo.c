#include <stdio.h>
#include <string.h>

int main()
{
    char change_fname[50], change_lname[50], change_password1[50], change_password2[50]; 
    char change_email[50], change_bankid[50], yes_no[5];
    char name_changes[5], password_changes[5], email_changes[5], bankid_changes[5];

        printf("Would you Like to Change information? 1 = Yes | 2 = No ");
        scanf("%c", yes_no);

    if (yes_no[5] == 1)
    {
        printf("Do You Want to Change your Name? 1=Yes| 2= No");
        scanf("%c", name_changes);
    
    if (name_changes == 1)
    {
        printf("Change First Name:");
        scanf("%c", change_fname);
        printf("Change Last Name: ");
        scanf("%c", change_lname);
    }else 

    if (name_changes == 2)
        printf("Do You Want to Change your Name? 1=Yes| 2= No");
        scanf("%c", password_changes);

    if (password_changes == 1)
    {    
        printf("Change Password: ");
        scanf("%c", change_password1);
        printf("Re-enter Password: ");
        scanf("%c", change_password2);
    

    if (change_password1 != change_password2)
    {
        printf("Password does not match:");
        printf("Please Enter a Matching Password: ");
    }
    if (password_changes == 2)
        printf("Do You Want to Change your Name? 1=Yes| 2= No");
        scanf("%c", email_changes);
    if (email_changes == 1)
    {
        printf("Change email: ");
        scanf("%c", change_email);
    
    if (email_changes == 2)
        printf("Do You Want to Change your Name? 1=Yes| 2= No");
        scanf("%c", bankid_changes);
    
    }else
    if (bankid_changes==1){
        printf("Change Bank Account: ");
        scanf("%c", change_bankid);
    }
    }else 
    if (bankid_changes ==2)
        strcpy(new_lname, change_fname);
        strcpy(new_fname, change_lname);
        strcpy(new_password, change_email);
        strcpy(bank_account, change_bankid);
}else{
    return 0;
    
}
