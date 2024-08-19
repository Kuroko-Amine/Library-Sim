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




void updateSTD(student etu){
   FILE *op=fopen("DataSTD.bin","rb");
    if(op==NULL){
        printf("Error opening file\n");
        return ;
    }
    FILE *temp=fopen("temp.bin","wb");
    if(temp==NULL){
        printf("Error opening file\n");
        return ;
    }
    student x ;
    while(fread(&x,sizeof(student),1,op)==1){
        if(x.profile.ID!=etu.profile.ID){
        fwrite(&x,sizeof(student),1,temp);
     }else{
        fwrite(&etu,sizeof(student),1,temp);
     }
    }
    fclose(temp);
    fclose(op);
    remove("DataSTD.bin");
    rename("temp.bin","DataSTD.bin");
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
            printf("1)Display Info about the book \n2)Would you like to borrow the book?");
            int choice ;
            do{
                scanf("%d",&choice);
                if(choice<1 || choice>2){
                    printf("Invalid choice\n");
                }
            }while(choice<1 || choice > 2);
            if(choice==1){
                printf("Title: %s\n",x.title);
                printf("Author: %s\n",x.author);
                printf("Genre : %s\n",x.genre);
                printf("prix : %.2f\n",x.price);
                printf("ID : %d\n",x.bookID);
                printf("quantity : %d\n",x.quant);
                printf("Year : %d\n",x.year);
        }else{
            if(etu.pret>10){
                printf("Sorry you have already borrowed 10 books\n");
            }else{
                if(x.quant>0){
                    printf("Book borrowed successfully\n");
                    x.quant=x.quant-1 ;
                    etu.booklist[etu.pret].startdate=getCurrentDate();
                    strcpy(etu.booklist[etu.pret].author,x.author);
                    etu.booklist[etu.pret].bookID=x.bookID;
                    etu.booklist[etu.pret].stdID=etu.profile.ID;
                    strcpy(etu.booklist[etu.pret].title,x.title);
                    etu.booklist[etu.pret].endate=addWeeksToDate(getCurrentDate(),3);
                    etu.pret=etu.pret+1 ;
                    updateSTD(etu);
            }else{
                printf("Sorry this book is not available\n");
            }

            }
        }
}
}

