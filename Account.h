
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"utility.h"


void creatAccountSTD();
void creatAccountAD();
pswrd LoginSTD();
int ExistSTD(pswrd x);
int LoginAD();
int ExistAD(pswrd x);




pswrd LoginSTD(){
pswrd x ;

int i=0;
 while(1){
    printf("enter your username \n");
    scanf(" %[^\n]s",x.usrname);
    printf("enter your password \n");
    scanf(" %[^\n]s",x.password);
    if(ExistSTD(x)==1){
        printf("login successful \n");
        return x ;
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
            return x ;
        }else{
            printf("thank you for using our service \n");
            strcpy(x.usrname, "None");
            return x ;
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
                        strcpy(x.usrname, "None");
                        return x ;
        }}
    printf("enter your password \n");
    scanf(" %[^\n]s",x.password);
    if(ExistSTD(x)==1){
        printf("login successful \n");
        return x ;
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
    FILE *ptr=fopen("DataAD.bin","rb");
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
    scanf(" %[^\n]s",x.usrname);
    printf("enter your password \n");
    scanf(" %[^\n]s",x.password);
    if(ExistAD(x)==1){
        printf("login successful \n");
        return 1;
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
    scanf(" %[^\n]s",x.password);
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
    scanf(" %[^\n]s",y.acccount.usrname);
   while(fread(&x,sizeof(student),1,ptr)==1){
    if(strcmp(y.acccount.usrname,x.acccount.usrname)==0 ){
        flog=1 ;
        printf("username Already Exsist");
   }
   if(strcmp(y.acccount.usrname,"None")==0){
    flog=1 ;
    printf("you can't use this username ! \n");
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
    scanf(" %[^\n]s",y.acccount.password);
    printf("re enter your account password\n");
    scanf(" %[^\n]s",temp);
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
    scanf(" %[^\n]s",y.profile.fname);
    printf("enter your last name \n");
    scanf(" %[^\n]s",y.profile.lname);
    printf("enter your ID \n");
    scanf("%d",&y.profile.ID);
    getchar();
    printf("enter your faculty \n");
    scanf(" %[^\n]s",y.profile.faculty);
    y.pret=0 ;
    int k ;
    for(k=0 ; k<10 ; k++){
        y.booklist[k].bookID=0000;
        y.booklist[k].startdate.d=00;
        y.booklist[k].startdate.y=0000;
        y.booklist[k].startdate.m=00;
        y.booklist[k].endate.d=00;
        y.booklist[k].endate.y=0000;
        y.booklist[k].endate.m=00;
        y.booklist[k].stdID=0000;
        strcpy(y.booklist[k].title,"Plqvmtx");
        strcpy(y.booklist[k].author,"Plqvmtx");
    }
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
        printf("error opening file DAta AD\n");
        exit(1);
    }
    do{
        flog=0 ;
    printf("enter your account username \n");
    scanf(" %[^\n]s",y.usrname);
   while(fread(&x,sizeof(student),1,ptr)==1){
    if(strcmp(y.usrname,x.usrname)==0){
        flog=1 ;
        printf("username Already Exsist");
   }
    if(strcmp(y.usrname,"None")==0){
        flog=1 ;
        printf("U can't use this username ! \n");
   }
   }
    }while(flog==1);
    fclose(ptr);
    ptr=fopen("DataAD.bin","ab");
    if(ptr==NULL){
        printf("error opening file DAta AD\n");
        exit(1);
    }
        do{
                printf("enter your account password \n");
                scanf(" %[^\n]s",y.password);
                printf("re enter your account password\n");
                scanf(" %[^\n]s",temp);
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
