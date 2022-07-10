#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct structura{
    char name[50];
    char phone[50];
    char acc[50];//case of forgetting passord
    char password[50];
    float balance;
}S;
int main()
{
    S nw,r;
    char phone[50],password[50],acc[50],name[50];
    FILE *fw,*fr;
    int opt;
    float w,cash;
    printf("Hello!\nWelcome to Andrei's bank if you want to register a new account please press 1, if you have an account press 2.\n");
    printf("If you forgot your password please press 3!\n");
    scanf("%d",&opt);
    if(opt==1)
        {
            system("clear");
            printf("What is your name?\n");
            scanf("%s",nw.name);
            printf("Please let us know your phone number!\n");
            scanf("%s",nw.phone);
            fr=fopen(nw.phone,"rb");
                if(fr!=NULL)
                {
                    printf("This phone number is already associated with an existing account!\n");
                    exit(0);
                }
            printf("What is your account number?\n");
            scanf("%s",nw.acc);
            printf("Please write down your new password!\n");
            scanf("%s",nw.password);
            nw.balance=0;
            fw=fopen(nw.phone,"wb");
            fwrite(&nw,sizeof(nw),1,fw);
            if(fwrite != 0)
			    printf("Succesfully registered");
			fclose(fr);
			fclose(fw);
        }
    else if(opt==2)
                {
                    system("clear");
                    printf("Phone number:");
                    scanf("%s",phone);
                    printf("Password:");
                    scanf("%s",password);
                    fr=fopen(phone,"rb");
                    if(fr==NULL)
                        printf("User not register!\n");
                    else
                        {
                            fread(&r,sizeof(S),1,fr);
                            if(strcmp(password,r.password)==0)
                            {    
                                printf("Welcome %s !\n",r.name);
                                do{
                                    printf("If you want to exit press 0!\n");
                                    printf("For checking the balance press 1!\n");
                                    printf("For adding found press 2!\n");
                                    printf("For cash withdraw press 3!\n");
                                    printf("For quick transfeer press 4!\n");
                                    printf("For changing your password press 5!\n");
                                    scanf("%d",&opt);
                                    switch(opt)
                                    {
                                        case 0:
                                            exit(0);
                                        case 1: 
                                            system("clear");
                                            printf("Your current balance is %f.\n",r.balance);
                                        break;
                                        case 2:
                                            system("clear");
                                            printf("How many cash do you want to add?\n");
                                            scanf("%f",&cash);
                                            r.balance+=cash;
                                            fw=fopen(phone,"w");
                                            fwrite(&r,sizeof(r),1,fw);
                                            if(fwrite!=0)
                                                printf("Your current balance is %f.\n",r.balance);
                                            else printf("Operation failed!\n");
                                        break;
                                        case 3:
                                            system("clear");
                                            printf("How much money do you want to withdraw?\n");
                                            scanf("%f",&w);
                                            if(r.balance<w)
                                                printf("Insufficient funds\n");
                                            else{
                                                r.balance-=w;
                                                printf("Your withdraw was Succesfully done!\n");
                                            }
                                            fw=fopen(phone,"w");
                                            fwrite(&r,sizeof(r),1,fw);
                                            if(fwrite!=0)
                                                printf("Your current balance is %f.\n",r.balance);
                                            else printf("Operation failed!\n");
                                        break;
                                        case 4:
                                            system("clear");
                                            printf("Please write down the phone number of the person you want to transfer the money!\n");
                                            scanf("%s",phone);
                                            printf("Enter the amount to transfer:  ");
    						                scanf("%f",&cash);
                                            if(cash>r.balance)
                                                printf("We are sorry,you have insufficent balance!\n");
                                            else
                                                {
                                                    
                                                    fw=fopen(phone,"r");
                                                    if(fw==NULL) 
                                                        printf("Number not registered!\n");
                                                    else
                                                        {
                                                            fread(&nw,sizeof(S),1,fw);
                                                            fclose(fw);
                                                            nw.balance+=cash;
                                                            fw=fopen(phone,"wb");
                                                            fwrite(&nw,sizeof(nw),1,fw);
                                                            if(fwrite!=0)
                                                            {
                                                                printf("You have transfered %f to %s.\n",cash,nw.name);
                                                                fclose(fw);
                                                                r.balance-=cash;
                                                                fw=fopen(r.phone,"wb");
                                                                fwrite(&r,sizeof(r),1,fw);
                                                                fclose(fw);
                                                            }
                                                        }
                                                }
                                        break;
                                        case 5:
                                            system("clear");
                                            printf("Please write your current password!\n");
                                            scanf("%s",password);
                                            if(strcmp(password,r.password)==0)
                                                {
                                                    printf("Write your new password!\n");
                                                    scanf("%s",password);
                                                    strcpy(r.password,password);
                                                    fw=fopen(r.phone,"wb");
                                                    fwrite(&r,sizeof(r),1,fw);
                                                    fclose(fw);
                                                    printf("Password Succesfully changed!\n");
                                                }
                                            else 
                                                printf("Your password is incorrect!\n");
                                        break;
                                    }
                                   }while(1);
                            } 
                            else printf("User not registered.\n");
                        }
                
                }else if(opt==3)
                        {
                            system("clear");
                            printf("Please write down your phone number!\n");
                            scanf("%s",phone);
                            fr=fopen(phone,"rb");
                            if(fr==NULL)
                                printf("User not register!\n");
                            else
                            {
                                fread(&r,sizeof(S),1,fr);
                                printf("We will change your password if you answer fair at this questions!\n\n");
                                printf("Please let us know what is your account number.\n ");
                                scanf("%s",acc);
                                printf("Please let us know your name.\n");
                                scanf("%s",name);
                                if(strcmp(r.acc,acc)==0 && strcmp(r.name,name)==0)
                                    {
                                        printf("Welcome %s,please write down your new password!\n",r.name);
                                        fclose(fr);
                                        scanf("%s",r.password);
                                        fw=fopen(phone,"w");
                                        fwrite(&r,sizeof(r),1,fw);
                                        fclose(fw);
                                    }
                                else printf("You haven't answer correct!\n");
                            }
                        }
                else printf("You must choose one valid option!\n");
    return 0;
}



