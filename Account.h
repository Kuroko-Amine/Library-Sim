#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"utility.h"


void creatAccountSTD();
void creatAccountAD();
int LoginSTD();
int ExistSTD(pswrd x);
int LoginAD();
int ExistAD(pswrd x);



int LoginSTD(){
pswrd x ;

int i=0;
 while(1){
    printf("enter your username \n");
    gets(x.usrname);
    printf("enter your password \n");
    gets(x.password);
    if(ExistSTD(x)==1){
        printf("login successful \n");
        return 1 ;
    }else if(ExistSTD(x)==-1){
        printf("your account dosent exist\n");
        printf("Do u want to creat one ? \n");
        printf("1)yes \n 2)No\n");
        int choice ;
        do {
            scanf("%d",&choice);
            if(choice<1 || choice >2){
                printf("wrong choice \n");
                }
            }while(choice<1 || choice >2);
        if(choice ==1){
            creatAccountSTD();
            return 1 ;
        }else{
            printf("thank you for using our service \n");
            return -1 ;
        }
    }else{

        while(1){
        printf("wrong password ! \n");
        i++;
        if(i>3){
            printf("do u want to exit ?\n");
            printf("1)yes \n2)No\n");
            int choice ;
            do {
                scanf("%d",&choice);
                if(choice<1 || choice >2){
                    printf("wrong choice \n");
                    }
                    }while(choice<1 || choice >2);
                    if(choice ==1){
                        return -1 ;
        }}
    printf("enter your password \n");
    gets(x.password);
    if(ExistSTD(x)==1){
        printf("login successful \n");
        return 1 ;
    }

 }
}
}
}


int ExistSTD(pswrd x){
    student y ;
    FILE *ptr=fopen("DataSTD.bin","rb");
    if(ptr==NULL){
        printf("error opening data file \n");
        exit(1);
    }
    while(fread(&y,sizeof(student),1,ptr)==1){
        if(strcmp(y.acccount.usrname,x.usrname)==0 && strcmp(y.acccount.password,x.password)==0){
            return 1 ;
        }else{
        if(strcmp(y.acccount.usrname,x.usrname)==0){
            return -2;
        }
      }
    }
fclose(ptr);
return -1 ;
}


int ExistAD(pswrd x){
    pswrd y ;
    FILE *ptr=fopen("C:\\Users\\Aminos\\Desktop\\lib\\DataAD.bin","rb");
    if(ptr==NULL){
        printf("error opening data file \n");
        exit(1);
    }
    while(fread(&y,sizeof(pswrd),1,ptr)==1){
        if(strcmp(y.usrname,x.usrname)==0 && strcmp(y.password,x.password)==0){
            return 1 ;
        }else{
        if(strcmp(y.usrname,x.usrname)==0){
            return -2;
        }
      }
    }
fclose(ptr);
return -1 ;
}


int LoginAD(){
pswrd x ;

int i=0;
 while(1){
    printf("enter your username \n");
    gets(x.usrname);
    printf("enter your password \n");
    gets(x.password);
    if(ExistAD(x)==1){
        printf("login successful \n");
        return 1 ;
    }else if(ExistAD(x)==-1){
        printf("your account dosent exist\n");
        printf("Do u want to creat one ? \n");
        printf("1)yes \n2)No\n");
        int choice ;
        do {
            scanf("%d",&choice);
            if(choice<1 || choice >2){
                printf("wrong choice \n");
                }
            }while(choice<1 || choice >2);
        if(choice ==1){
            creatAccountAD();
            return 1 ;
        }else{
            printf("thank you for using our service \n");
            return -1 ;
        }
    }else{

        while(1){
        printf("wrong password ! \n");
        i++;
        if(i>3){
            printf("do u want to exit ?\n");
            printf("1)yes \n2)No\n");
            int choice ;
            do {
                scanf("%d",&choice);
                if(choice<1 || choice >2){
                    printf("wrong choice \n");
                    }
                    }while(choice<1 || choice >2);
                    if(choice ==1){
                        return -1 ;
        }}
    printf("enter your password \n");
    gets(x.password);
    if(ExistAD(x)==1){
        printf("login successful \n");
        return 1 ;
    }
 }
}
}
}


void creatAccountSTD(){
   
    student y ;
    student x ;
    char temp[45];
    int flg=0 ;
    int flog=0 ;
    FILE *ptr=fopen("DataSTD.bin","rb");
    if(ptr==NULL){
        printf("error opening file DAta STD\n");
        exit(1);
    }
    do{
        flog=0 ;
    printf("enter your account username \n");
    gets(y.acccount.usrname);
   while(fread(&x,sizeof(student),1,ptr)==1){
    if(strcmp(y.acccount.usrname,x.acccount.usrname)==0){
        flog=1 ;
        printf("username Already Exsist");
   }
   }
    }while(flog==1);
    fclose(ptr);
    ptr=fopen("DataSTD.bin","ab");
    if(ptr==NULL){
        printf("error opening file DAta STD\n");
        exit(1);
    }
    do{
    printf("enter your account password \n");
    gets(y.acccount.password);
    printf("re enter your account password\n");
    gets(temp);
    if(strcmp(temp,y.acccount.password)==0){
        flg=1 ;
    }else{
        printf("password not match \n");
        getchar();
        system("cls");
    }
    system("cls");
    }while(flg==0);
    printf("enter your first name \n");
    gets(y.profile.fname);
    printf("enter your last name \n");
    gets(y.profile.lname);
    printf("enter your ID \n");
    scanf("%d",&y.profile.ID);
    getchar();
    printf("enter your faculty \n");
    gets(y.profile.faculty);
    y.pret=0 ;
    printf("Account created Succefuly ! \n");
    fwrite(&y,sizeof(student),1,ptr);
    fclose(ptr);
}

void creatAccountAD(){
    pswrd y ;
    pswrd x ;
    char temp[45];
    int flg=0 ;
    int flog=0 ;
    FILE *ptr=fopen("DataAD.bin","rb");
    if(ptr==NULL){
        printf("error opening file DAta STD\n");
        exit(1);
    }
    do{
        flog=0 ;
    printf("enter your account username \n");
    gets(y.usrname);
   while(fread(&x,sizeof(student),1,ptr)==1){
    if(strcmp(y.usrname,x.usrname)==0){
        flog=1 ;
        printf("username Already Exsist");
   }
   }
    }while(flog==1);
    fclose(ptr);
    ptr=fopen("DataAD.bin","ab");
    if(ptr==NULL){
        printf("error opening file DAta STD\n");
        exit(1);
    }
        do{
                printf("enter your account password \n");
                gets(y.password);
                printf("re enter your account password\n");
                gets(temp);
            if(strcmp(temp,y.password)==0){
                    flg=1 ;
                }else{
                        printf("password not match \n");
                        getchar();
                        system("cls");
                    }
                    system("cls");
        }while(flg==0);
   printf("Account created Succefuly ! \n");
   fwrite(&y,sizeof(pswrd),1,ptr);

   fclose(ptr);
}
