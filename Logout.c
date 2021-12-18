#include <stdio.h>
#include <string.h>
#include <conio.h> 


void logout()
{
    char log_out, a=1, logout_verification;
    printf("Would you like to Log out 1 = Yes | 2= No or Continue?");
    scanf("%c", logout_verification);

    if (logout_verification == 1){
    printf("****Confirm one more time to Log out****");
    scanf("%c", log_out);
    if (log_out ==1)
    {
       logout(); 
    
    }else{
        if (logout_verification == 2)
        {
            //replace with function it will proceed to before or after log out  
        }
}
