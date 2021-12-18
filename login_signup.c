/*
this program is a login and signup system 
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>       // this is for using strlwr
char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
                                            // this is to define stlwr for clang compilers 
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}
void zak(int id);
    char new_lname[100],new_fname[100], new_password[50], new_email[100], new_bankaccount[30];
    char address[30];
    char passcode[30]; // this is the the arrays that we are using to compare with 
    char email[2][50];
    char fname[2][50];
    char lname[2][50];
    char password[2][50];
    char bank_account[2][50];
    int  balance[100];
    char secret_question[2][50];
    char reply[2][50];
    char Address[30];//+++
    char Passcode[30]; // this is the the arrays that we are using to compare with 
    char Email[50][50];
    char Fname[50][50];
    char Lname[50][50];
    char Password[50][50];
    char Bank_account[50][50];
    int  Balance[100];
    char Secret_question[50][50];
    char Reply[50][50];
    char sign[7];
int main(){
    
    int count = 0;
    int i  = 0;
    int id , found = 0; // found is a sentinal value
                        // id is to keep track of the persons that we have 
    FILE *file;
    file = fopen("output.txt","r");
    while (!feof(file)){ 
    fscanf(file, "%s %s %s %s %s %d %s %s"  , email[i],fname[i],lname[i],password[i],bank_account[i],
    &balance[i],secret_question[i],reply[i]);
    i++;
    count++;
    }
    fclose(file);
    printf("Do you want to sign in or sign up? ");
    scanf("%[^\n]",sign);
if (strcmp(sign,"sign in")==0)
{
    printf("\nEnter your email: ");
    scanf("%s",address);
    FILE *data;
    data=fopen("output.txt","r");
    for(int i = 0 ; i < count ; i++)
    {
    if(strcmp(email[i],address)== 0||strcmp(Email[i],address)==0)
    {
        found = 1;
        id = i;
        break;
        
    }//keklf,dsd,fsqdk,f project\testme.c
    
    }
    fclose(data);
    if (found == 1)
    {
        printf("Enter a password: ");
    scanf("%s",passcode);
    if(strcmp(password[id],passcode)==0 && strcmp(Password[id],passcode))
    {
        printf("Succesfully logged in! ");
        zak(id);
    }
    else if(found == 0)
    {
            printf("User does not exist!");
    }
    }
}
else if(strcmp(sign,"sign up")==0){
    printf("Enter Your First Name\t");
    scanf("%s", new_fname);
    printf("Enter Your last Name\t");
    scanf("%s", new_lname);
    printf("Enter Your Password\t");
    scanf("%s", new_password);
    printf("Enter Your Email\t");
    scanf("%s", new_email);
    printf("Enter Bank Account Number");
    scanf("%s", new_bankaccount);
    }
    for(int i=0;i<count;i++){
        if (strcmp(new_email,email[i])==0 || strcmp(new_bankaccount,bank_account[i])==0)//checks with the arrays if the arrays
        {
        printf("\nYou already have an existant account, Please login");
        break;
    }
        else if(strcmp(new_email,email[i])!=0 || strcmp(new_bankaccount,bank_account[i])!=0 || strcmp(new_email,Email[i])!=0 || strcmp(new_bankaccount,Bank_account[i])!=0)
    {
        FILE *fptr=fopen("output.txt","w");
        fprintf(fptr,"%s %s %s %s %s",new_email,new_bankaccount,new_lname,new_fname,new_password);
        fclose(fptr);
        printf("Succesfully signed up");
        printf("\nLog in again");
        break;
        }
    }
}

void zak(int id){
    int  total_amount=0;
    int  amount[5]={0},result[5]={0};
    char word[8];
    char answer[]={"yes"},choice[10];
    char menu[5][20]={{"Book"}
        ,{"Skin Care"}
        ,{"Watch"}
        ,{"Desk"}
        ,{"Laptop"}
    };
    int price[5]={200,700,1000,4000,7000};
printf("\nWelcome, if you want to make an order, type 'order'; if you want to change your information,type 'change': ");
    scanf("%s",word);
    strlwr(word);
        if(strcmp(word,"order") == 0){
            printf("Here is the menu:\n");
            for(int i=0;i<5;i++){
                printf("%s for %d MAD\t",menu[i],price[i]);
            }
            while(strcmp(answer,"yes")==0){
                printf("\nType what you want to buy based on the menu: ");
                getchar();
                gets(choice);
                strlwr(choice);
                if(strcmp(choice,"book")==0 || strcmp(choice,"book ")==0 )
                {
                int i=0;
                while(choice[i]!='\0')
                {
                choice[i]=tolower( choice[i]);
                i++;
                }
                if(strcmp(choice,"book")==0){
                    printf("How many books do you want? ");
                    scanf("%d",&amount[0]);
                    result[0]=amount[0]*200;
                }
                else if(strcmp(choice,"skin care")==0 || strcmp(choice,"skin care ")==0){
                    printf("How many skin care do you want? ");
                    scanf("%d",&amount[1]);
                    result[1]=amount[1]*700;
                }
                else if(strcmp(choice,"watch")==0 || strcmp(choice,"watch ")==0){
                    printf("How many watches do you want? ");
                    scanf("%d",&amount[2]);
                    result[2]=amount[2]*1000;
                }
                else if(strcmp(choice,"desk")==0 || strcmp(choice,"desk ")==0){
                    printf("How many desks do you want? ");
                    scanf("%d",&amount[3]);
                    result[3]=amount[3]*4000;
                }
                else if(strcmp(choice,"laptop")==0 || strcmp(choice,"laptop")==0){
                    printf("How many laptops do you want? ");
                    scanf("%d",&amount[4]);
                    result[4]=amount[4]*6000;
                }
                for(int i=0;i<5;i++){
                total_amount+=result[i];
            }
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)\n");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
            if(balance[id]>total_amount){
                balance[id]-=total_amount;
                printf("\nCongrats %s you have purchased this item you still have %d MAD",fname[id],balance[id]);
            }
            else if(balance[id]<total_amount){
                printf("You do not have enough balance consider change your bank info");
                scanf("%s",&bank_account[id][id]);
            }
            }
        }
else if(strcmp(word,"change")==0){
}
}
