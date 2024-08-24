#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"utility.h"


void searchLiv(char name[30],student etu);
date getCurrentDate() ;
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
date addWeeksToDate(date d, int weeks);
void updateSTD(student etu);
void verifybooks(student etu) ;
int ended(student etu);
student StdPro(pswrd acc);
void Updatebk(stubook bk);
void Updatebok(book bk);



date getCurrentDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    date current_date;
    current_date.d = tm->tm_mday;
    current_date.m = tm->tm_mon + 1;
    current_date.y = tm->tm_year + 1900;
    return current_date;
}


int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; 
    }
}


date addWeeksToDate(date d, int weeks) {
    int daysToAdd = weeks * 7;
    d.d += daysToAdd;


    while (d.d > getDaysInMonth(d.m, d.y)) {
        d.d -= getDaysInMonth(d.m, d.y);
        d.m++;
        if (d.m > 12) {
            d.m = 1;
            d.y++;
        }
    }

    return d;
}


void updateSTD(student etu) {
    FILE *op = fopen("DataSTD.bin", "rb");
    if (op == NULL) {
        printf("Error opening file DataSTD.bin\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Error opening file temp.bin\n");
        fclose(op);
        return;
    }

    student x;
    while (fread(&x, sizeof(student), 1, op) == 1) {
        if (x.profile.ID != etu.profile.ID) {
            fwrite(&x, sizeof(student), 1, temp);
        } else {
            fwrite(&etu, sizeof(student), 1, temp);
        }
    }

    fclose(op);fclose(temp);
    temp = fopen("temp.bin", "rb");
    op = fopen("DataSTD.bin", "wb");
    if ( temp == NULL ){
        printf("Error opening file\n");
        exit(1);
    }
    while(fread(&x,sizeof(student),1,temp)==1){
        fwrite(&x,sizeof(student),1,op);
    }fclose(temp);fclose(op);

    if (remove("temp.bin") != 0) {
        printf("Error deleting original file\n");
    }

    /*if (rename("temp.bin", "DataSTD.bin") != 0) {
        printf("Error renaming temp file\n");
    }*/
    
}

    

void searchLiv(char name[30],student etu){
    FILE *fp=fopen("booksInfo","rb");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(1);
        }
        book temp ;
        book x ;
        int flg=0 ;
        while(flg==0 && fread(&temp,sizeof(book),1,fp)==1){
            if(strcmp(temp.title,name)==0){
                flg=1 ;
                x=temp ;
        }
        }
        fclose(fp);
        if(flg==0){
            printf("Sorry Book not found\n");
        }else{
            printf("Book found \n");
            printf("1)Display Info about the book \n2)Would you like to borrow the book?\n");
            int choice ;
            do{
                scanf("%d",&choice);
                if(choice<1 || choice>2){
                    printf("Invalid choice\n");
                }
            }while(choice<1 || choice > 2);
            if(choice==1){
                system("cls");
                gotoxy(0, 0);
                printf("ID");
                gotoxy(20, 0);
                printf("Title");
                gotoxy(50, 0);
                printf("Author");
                gotoxy(80, 0);
                printf("Genre");
                gotoxy(105, 0);
                printf("Publishing year");
                gotoxy(130,0);
                printf("Quantity");
                gotoxy(150,0);
                printf("Price");
                gotoxy(0,1);
                printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------");
                gotoxy(0, 2);
                printf("%d",x.bookID);
                gotoxy(20, 2);
                printf("%s",x.title);
                gotoxy(50, 2);
                printf("%s",x.author);
                gotoxy(80, 2);
                printf("%s",x.genre);
                gotoxy(105, 2);
                printf("%d",x.year);
                gotoxy(135,2);
                printf("%d",x.quant);
                gotoxy(155,2);
                printf("%.2f DA",x.price);
                gotoxy(0,1);
                
        }else{
            if(etu.pret>10){
                printf("Sorry you have already borrowed 10 books\n");
            }else{
                if(ended(etu)){
                if(x.quant>0){
                    printf("Book borrowed successfully\n");
                    x.quant=x.quant-1 ;
                    etu.booklist[etu.pret].startdate=getCurrentDate();
                    strcpy(etu.booklist[etu.pret].author,x.author);
                    etu.booklist[etu.pret].bookID=x.bookID;
                    etu.booklist[etu.pret].stdID=etu.profile.ID;
                    strcpy(etu.booklist[etu.pret].title,x.title);
                    etu.booklist[etu.pret].endate=addWeeksToDate(getCurrentDate(),3);
                    etu.pret=etu.pret+1;
                    updateSTD(etu);
                    Updatebok(x);
            }else{
                printf("Sorry this book is not available\n");
            }
            }else{printf("You need to return one of your books; you have exceeded the due date u can't borrow a book\n");
            printf("%d\n",ended(etu));
            }
            }
        }
}
}

int ended(student etu){
    int i;
    date Today =getCurrentDate() ;
    for(i=0;i<10;i++){
     if(Today.y>etu.booklist[i].endate.y && strcmp(etu.booklist[i].title,"Plqvmtx")!=0&&strcmp(etu.booklist[i].author,"Plqvmtx")!=0){
            return 0;
    }else{
        if(Today.m>etu.booklist[i].endate.m && Today.y==etu.booklist[i].endate.y && strcmp(etu.booklist[i].title,"Plqvmtx")!=0&&strcmp(etu.booklist[i].author,"Plqvmtx")!=0)
        {
            return 0 ;
        }else{
if(Today.d>etu.booklist[i].endate.d&&Today.m==etu.booklist[i].endate.m&&Today.y==etu.booklist[i].endate.y&&strcmp(etu.booklist[i].title,"Plqvmtx")!=0&&strcmp(etu.booklist[i].author,"Plqvmtx")!=0 ){
                return 0 ;
            }
        }
    }
}
return 1 ;
}


void verifybooks(student etu){
     int choix;
    int flg = 0;
    int i;
    for(i=0;i<10;i++){
if(ended(etu)==0){
            printf("The due date for the book %s has passed !\n",etu.booklist[i].title);
            printf("Do you want to :\n1) Return the book\n2) Extend the due date by 3 weeks\n");
            do{
                scanf("%d",&choix);
                if(choix<1 || choix>2){
                    printf("wrong choice , choose 1 or 2\n");
                }
            }while(choix<1 || choix>2);
            if(choix==2){
                etu.booklist[i].endate=addWeeksToDate(etu.booklist[i].endate,3);
                
            }else{
                Updatebk(etu.booklist[i]);
                for(int k=i ; k<10;k++){
                    etu.booklist[k]=etu.booklist[k+1];
                    
                }
                etu.pret-- ;
            }
            updateSTD(etu);
            flg = 1;
    }
    }
    if ( flg == 0 )
    printf("The due date for none of your books has passed\n");

}



void Updatebk(stubook bk){
    book x ;
    FILE *f=fopen("booksInfo","rb");
    if(f==NULL){
        printf("error opening file\n");
    }
    FILE *fp=fopen("temp.bin","wb");
    if(fp==NULL){
        printf("error opening file\n");
    }
    while(fread(&x,sizeof(book),1,f)==1){
       
        if(x.bookID==bk.bookID && strcmp(x.title,bk.title)==0 && strcmp(x.title,bk.author)==0){
            x.quant++;
            fwrite(&x,sizeof(book),1,fp);
        }else{
        fwrite(&x,sizeof(book),1,fp);}
    }
    fclose(f);
    fclose(fp);
    remove("booksInfo");
    rename("temp.bin","booksInfo");
}

void Updatebok(book bk){
    book x ;
    FILE *f=fopen("booksInfo","rb");
    if(f==NULL){
        printf("error opening file\n");
    }
    FILE *fp=fopen("temp.bin","wb");
    if(fp==NULL){
        printf("error opening file\n");
    }
    while(fread(&x,sizeof(book),1,f)==1){
        if(x.bookID==bk.bookID && strcmp(x.author,bk.author)==0 && strcmp(x.title,bk.title)==0){
            fwrite(&bk,sizeof(book),1,fp);
        }else{
        fwrite(&x,sizeof(book),1,fp);}
    }
    fclose(f);
    fclose(fp);
    remove("booksInfo");
    rename("temp.bin","booksInfo");
}


student StdPro(pswrd acc){
    student etu,temp ;
    int flg=0 ;
    FILE *fp=fopen("DataSTD.bin","rb");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while(flg==0 && fread(&etu,sizeof(student),1,fp)==1){
        if(strcmp(acc.usrname,etu.acccount.usrname)==0 && strcmp(acc.password,etu.acccount.password)==0){
            flg=1 ;
            temp=etu ;
        }
    }fclose(fp);
return temp ;
}

void returnabook(student bk){
    if(bk.pret!=0){
    book x ;
    int i;
    printf("choose a book to return\n");
    for(i=0;i<=bk.pret-1;i++){
        printf("%d) %s\n",i+1,bk.booklist[i].title);
    }
    int choix;
    do{
        scanf("%d",&choix);
        if(choix<0 || choix>bk.pret){
            printf("wrong choice");
        }
    }while(choix<0 || choix>bk.pret);

    FILE *f=fopen("booksInfo","rb");
    if(f==NULL){
        printf("error opening file\n");
    }
    while(fread(&x,sizeof(book),1,f)==1){
        if(x.bookID==bk.booklist[choix-1].bookID && strcmp(x.title,bk.booklist[choix-1].title)==0 && strcmp(x.author,bk.booklist[choix-1].author)==0){
            x.quant++ ;
        }
    }
    fclose(f);
    
    for(i=choix-1;i<10;i++){
        bk.booklist[i]=bk.booklist[i+1];
    }
    bk.booklist[9].bookID=0000;
    bk.booklist[9].startdate.d=00;
    bk.booklist[9].startdate.y=0000;
    bk.booklist[9].startdate.m=00;
    bk.booklist[9].endate.d=00;
    bk.booklist[9].endate.y=0000;
    bk.booklist[9].endate.m=00;
    bk.booklist[9].stdID=0000;
    strcpy(bk.booklist[9].title,"Plqvmtx");
    strcpy(bk.booklist[9].author,"Plqvmtx");
    bk.pret--;
    updateSTD(bk);
    Updatebok(x);
    }else{
        printf("you don't have any book borrowed\n");
    }
}
