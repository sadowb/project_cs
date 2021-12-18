#include <stdio.h>
#include <string.h>

int main()
{
    char change_fname[50], change_lname[50], change_password1[50], change_password2[50]; 
    char change_email[50], change_bankid[50], yes_no[5], info_check[40];

        printf("Would you Like to Change information? Yes | No: ");
        scanf("%c", info_check[40]);

    if (info_check[5] == 1)
    {
        printf("To Change your First Name Press | 1"\n);
        printf ("To Change your Last Name Press | 2\n");
        printf("To Change your Password Press | 3\n");
        printf ("To Change your Email Press | 4\n");
        printf("To Change your Bank Account Press | 5");
        scanf("%c", yes_no); 
    
    switch (yes_no)
    {
    case '1' : 
        printf("Change First Name:");
        scanf("%c", change_fname);
    case '2' : 
        printf("Change Last Name: ");
        scanf("%c", change_lname);
    case '3' : 
        printf("Change Password: ");
        scanf("%c", change_password1);
        printf("Re-enter Password: ");
        scanf("%c", change_password2);
            if (change_password1 != change_password2)
            {
                printf("Password does not match:");
                printf("Please Enter a Matching Password: ");
            }
            else 
                if (change_password1 == change_password2)
                {
                    printf("*********Correct**Password**Input*********");
                } 
    case '4' : 
        printf("Change email: ");
        scanf("%c", change_email);
    case '5' : 
        printf("Change Bank Account: ");
        scanf("%c", change_bankid);
    
    
    }else
    if (info_check == 2)
    {
        strcpy(new_lname, change_fname);
        strcpy(new_fname, change_lname);
        strcpy(new_password, change_email);
        strcpy(bank_account, change_bankid);
    }
    return 0;
    
}
