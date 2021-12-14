#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    FILE *fp;
    fp=fopen("database.txt","r");
    int total_amount=0;
    int amount[5]={0},result[5]={0};
    char word[7];
    char answer[]={"yes"},choice[10];
    char menu[5][20]={{"Book"}
        ,{"Skin Care"}
        ,{"Watch"}
        ,{"Desk"}
        ,{"Laptop"}
    };
    int price[5]={200,700,1000,4000,7000};
    printf("Welcome, if you want to make an order, type 'order'; if you want to change your information,type 'change': ");
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
                if(strcmp(choice,"book")==0 || strcmp(choice,"book ")==0 ){
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
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
            }
            
            if(strcmp(word,"change") == 0){
                char c;
                c = fgetc(fp);
                while(c!=EOF){
                    printf("%s",c);
                    c = fgetc(fp);
                }
            }
return 0;
        }