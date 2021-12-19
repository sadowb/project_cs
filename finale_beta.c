/*
this program is a login and signup system 
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdbool.h>
      // this is for using strlwr
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
void output(int);
void sign_up(int );
void sign_in(int );
void login();
void zak(int id,int counter);
    
    char min;
    int tempo;
    char temp [50];
    char new_lname[100],new_fname[100], new_password[50], new_email[100], new_bankaccount[30],question[100],new_reply[100];
    int  new_balance[100];
    char address[30];
    char passcode[30]; // this is the the arrays that we are using to compare with 
    char email[50][50];
    char fname[50][50];
    char lname[50][50];
    char password[50][50];
    char bank_account[50][50];
    int  balance[100]={0};
    char secret_question[50][50];
    char reply[50][50];
    char sign[7];
int main(){
    
    int count = 0;
    int i  = 0;
    int id,found=0; // found is a sentinal value
    // id is to keep track of the persons that we have 
    FILE *file;
    file = fopen("database.txt","r");
    while (!feof(file)){ 
    fscanf(file, "%s %s %s %s %s %d %s %s" , email[i],fname[i],lname[i],password[i],bank_account[i],
    &balance[i],secret_question[i],reply[i]);
    i++;
    count++;
    }
    fclose(file);
    printf("Do you want to sign in or sign up? ");
    scanf("%[^\n]",sign);
if (strcmp(sign,"sign in")==0)
{
    sign_in(count);
}
else if(strcmp(sign,"sign up")==0){
    sign_up(count);
}

}
void zak(int id,int counter)
{
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
printf("Welcome, if you want to make an order, type 'order'; if you want to change your information,type 'change' or do you want to delete your account'delete': ");
    scanf("%s",word);
        if(strcmp(word,"order") == 0){
            printf("Here is the menu:\n");
            for(int i=0;i<5;i++){
                printf("%s for %d MAD\t",menu[i],price[i]);
            }
            while(strcmp(answer,"yes")==0){
                printf("\nType what you want to buy based on the menu: ");
                scanf("%s",choice);
                for(int i=0;i<7;i++){
                tolower(choice[i]);
                }
                if(strcmp(choice,"book")==0){
                    printf("How many books do you want? ");
                    scanf("%d",&amount[0]);
                    result[0]=amount[0]*200;
                }
                else if(strcmp(choice,"skincare")==0){
                    printf("How many skin care do you want? ");
                    scanf("%d",&amount[1]);
                    result[1]=amount[1]*700;
                }
                else if(strcmp(choice,"watch")==0){
                    printf("How many watches do you want? ");
                    scanf("%d",&amount[2]);
                    result[2]=amount[2]*1000;
                }
                else if(strcmp(choice,"desk")==0){
                    printf("How many desks do you want? ");
                    scanf("%d",&amount[3]);
                    result[3]=amount[3]*4000;
                }
                else if(strcmp(choice,"laptop")==0){
                    printf("How many laptops do you want? ");
                    scanf("%d",&amount[4]);
                    result[4]=amount[4]*6000;
                }
                for(int i=0;i<5;i++){
            total_amount+=result[i];
            }
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
            if(balance[id]>total_amount){
                balance[id]-=total_amount;
                printf("\nCongrats %s you have purchased this item you still have %d MAD",fname[id],balance[id]);
                FILE *file;
                file = fopen("database.txt","w");
                
                int i;
                
                for(i=0;i<counter;i++){ 
                fprintf(file, "%s %s %s %s %s %d %s %s\n" , email[i],fname[i],lname[i],password[i],bank_account[i],
                balance[i],secret_question[i],reply[i]);
                }
                fclose(file);
                printf("\nDo you want to log out? yes or no");
                scanf("%s",answer);
                for(;;){
                if(strcmp(answer,"yes")==0){
                    output(counter);
                    break;
                }
                else if(strcmp(answer,"no")==0){
                    printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)");
                    scanf("%s",answer);
                    zak(id,counter);
                }
                }
                }
                
            else if(balance[id]<total_amount){
                printf("\nYou do not have enough balance consider change your bank info");
                scanf("%s",&bank_account[id]);
            }
        }
else if(strcmp(word,"change")==0){
    for(int j=3;j>0;j--){
    printf("Type your password: ");
    scanf("%s",passcode);
    if(strcmp(password[id],passcode)==0){
    int number;
    printf("Your email : %s \n Your first name: %s\n Your last name: %s \nYour password: %s\n Your bank account: %s\n Your balance: %d\n Your secret question: %s\n Your answer: %s" , email[id],fname[id],lname[id],password[id],bank_account[id],
    balance[id],secret_question[id],reply[id]);
    printf("\nIf you want to change your first name press 1, press 2 for last name, press 3 for email, press 4 for bank account");
    scanf("%d",&number);
    if(number==1){
        printf("\nType a first name: ");
        scanf("%s",&fname[id]);
    }
    else if(number==2){
        printf("\nType a last name: ");
        scanf("%s",&lname[id]);
    }
    else if(number==3){
        printf("\nType a new email: ");
        scanf("%s",&email[id]);
    }
    else if(number==4){
        printf("\nType a bank account: ");
        scanf("%s",&bank_account[id]);
        printf("What is the balance: ");
        scanf("%d",&balance[id]);
    }
    FILE *file;
    file = fopen("database.txt","w");
    int i;
    for(i=0;i<counter;i++){ 
    fprintf(file, "%s %s %s %s %s %d %s %s\n" , email[i],fname[i],lname[i],password[i],bank_account[i],
    balance[i],secret_question[i],reply[i]);
    }
    fclose(file);
    printf("Information saved, please log in again");
    break;
    }
    else 
    printf("Wrong password, try again you still have %d times\n",j);
    }
}
else if(strcmp(word,"delete")==0){
    printf("Type your password: ");
    scanf("%s",passcode);
    if(strcmp(password[id],passcode)==0){
    FILE *file,*temp;
    char buffer[1024];
    int delete_line=0;

    delete_line=id+1;
    file=fopen("database.txt","r");
    temp=fopen("temp_database.txt","w");
bool keep_reading = true;
int current_line = 1;
do{
    fgets(buffer,1024,file);
    if(feof(file)) keep_reading=false;
    else if(current_line!=delete_line)
    fputs(buffer,temp);
    current_line++;
}
while(keep_reading);
fclose(file);
fclose(temp);
remove("database.txt");
rename("temp_database.txt","database.txt");
printf("Account deleted successfully");
}
else {
    printf("\nWrong password you have been logged out");
}
}
}

void sign_up(int count){
	int B = 0;	
    printf("Enter Your First Name\t");
    scanf("%s", new_fname);
    printf("Enter Your last Name\t");
    scanf("%s", new_lname);
    printf("Enter Your Password\t");
    scanf("%s", new_password);
    printf("Enter Your Email\t");
    scanf("%s", new_email);
    printf("Enter Bank Account Number \t");
    scanf("%s", new_bankaccount);
    printf("What is your balance ? \t");
    scanf("%d",&new_balance[B]);
    printf("Enter the serecet question \t");
    scanf("%s",question);
    printf("Enter an answer: \t");
    scanf("%s",new_reply);
    for(int i=0;i<count;i++){
        if (strcmp(new_email,email[i])==0 || strcmp(new_bankaccount,bank_account[i])==0)//checks with the arrays if the arrays
        {
        printf("\nYou already have an existant account, Please login");
        break;
    }
    else if(strcmp(new_email,email[i])!=0 && strcmp(new_bankaccount,bank_account[i])!=0)
    {   int B = 0;
        FILE *fptr=fopen("database.txt","a");
        fprintf(fptr,"%s %s %s %s %s %d %s %s\n",new_email,new_fname,new_lname,new_password,new_bankaccount,new_balance[B],question,new_reply);
        fclose(fptr);
        printf("Succesfully signed up");
        printf("\nLog in again");
        break;
        }
    }
}

void sign_in(int count)
{
    int id,found=0;
printf("\nEnter your email: ");
    scanf("%s",address);
    for(int i = 0 ; i < count ; i++)
    {
    	        if(strcmp(email[i],address)== 0)
    			{
						found = 1;
                        id = i;
						break;
						
    			}
    }
    if(found == 0)
    		{
            printf("User does not exist!");
    		}
    else if (found == 1)
    {
						printf("Enter a password: ");
				scanf("%s",passcode);
				if(strcmp(password[id],passcode)==0)
    		{
						printf("Succesfully logged in! ");
						zak(id,count);
    		}
    	
    }
   
}
void output(int counter)
{
    for (int i = 2; i < counter ; i++)
    {
        min = i;
    for (int j = i; j < counter; j++)
    {
        
    if( lname[min][0] > lname[j][0] || ( lname[min][0] == lname[j][0] && lname[min][1] > lname[j][1] ) )
        min = j;
        
        strcpy(temp, lname[i] );
        strcpy(lname[i] , lname[min] );
        strcpy( lname[min] , temp);
            
        strcpy(temp ,  fname[i] );
        strcpy(fname[i] , fname[min] );
        strcpy(fname[min] , temp );
            
            
        
        strcpy(temp ,  email[i] );        
        strcpy(  email[i] , email[min]);
        strcpy(  email[min] , temp);
            
            

            
        strcpy(  temp ,  password[i]);
        strcpy( password[i] , password[min] );
        strcpy( password[min] , temp);
            
              
        strcpy( temp ,  bank_account[i] );
        strcpy( bank_account[i] , bank_account[min]);
        strcpy( bank_account[min] , temp );
              
              

        tempo =  balance[i];
        balance[i] = balance[min];
        balance[min] = tempo;

            
        strcpy(temp ,  secret_question[i]);
        strcpy(secret_question[i] , secret_question[min]);
        strcpy(secret_question[min] , temp );

        
        strcpy(temp ,  reply[i] );
        strcpy(reply[i] , reply[min] );
        strcpy(reply[min] , temp );
    }  
    
    }
    FILE *fout=fopen("output.txt","w");
    for (int i = 2 ;i<counter ; i++)
    {
    fprintf(fout,"Email: %s First name %s Last name %s Password %s here is the Bank account %s Balance %d Secret question %s Answer %s \n"
    ,email[i],fname[i],lname[i],password[i],bank_account[i],balance[i],secret_question[i],reply[i]);
    } 
    fclose(fout);

}
