#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "admin.h"
#include "utility.h"
#include "Account.h"
#include "Student.h"

void Admin();
void Studentt();


int main(){
int choice , run=1;
while(run){
    system("cls");
 printf("1) Admin menu\n2) Student menu\n3) Exit\n");
    do{
        scanf("%d",&choice);
        if (choice < 1 || choice > 3){
            printf("Wrong choice, Choose 1 or 2 or 3\n");
        }
    }while( choice < 1 || choice > 3);
system("cls");
if(choice==1){
    printf("1) Login as an Admin\n");
    printf("2) Create an Admin account\n");
    printf("3) Go back\n");
    int c;
    do{
        scanf("%d",&c);
        if ( c < 1 || c > 3 )
        printf("Wrong choice, Please try again\n");
    }while( c < 1 || c > 3);


    if(c==1){
        system("cls");
        if(LoginAD()==1){
            Admin();
        }
    }else if(c==2){
        system("cls");
        creatAccountAD();
        printf("Please login to your account to continue.\n");
        if(LoginAD()==1){
            Admin();
        }
    }

}else if(choice==2){
    system("cls");
   printf("1) Login as a Student\n");
   printf("2) Create an Student account\n");
   printf("3) Go back\n");
   int h ;
    do{
        scanf("%d",&h);
        if ( h < 1 || h > 3 )
        printf("Wrong choice, Please try again\n");
    }while( h < 1 || h > 3);
    if(h==1){
        system("cls");
        pswrd a = LoginSTD();
        if ( strcmp( a.usrname, "None") !=0 ){
            Studentt(a);
        }
    }else{ if(h==2){
        system("cls");
        creatAccountSTD();
        printf("Please login to your account to continue.\n");
        pswrd a = LoginSTD();
        if(strcmp(a.usrname,"None")!=0){
            Studentt(a);
        }
    }
    }
}else{
    system("cls");
    run=0;
    printf("Thank u for using our service\n");
    
}


}
return 0;
}












void Admin(){
    
    int true = 1;
    do{
    int choix; char ch,c;int n;
    printf("\n\nPress any key to continue\n");
    scanf(" %c",&c);
    system("cls");
    printf("1) Display all Books\n");
    printf("2) Check the borrowed books\n");
    printf("3) Add Books\n");
    printf("4) Search for a Book to update its informations or delete it\n");
    printf("5) Display all Students\n");
    printf("6) Display all admin accounts\n");
    printf("7) Modify an account's info\n");
    printf("8) Exit\n");
    do{
        scanf("%d",&choix);
        if ( choix < 1 || choix > 8)
        printf("Wrong choice, Try again\n"); 
    }while( choix < 1 || choix > 8);
    switch(choix){
        case 1:
        Displaybooks();
        break;
        case 2:
        borrowedBooks();
        break;
        case 3:
        
        printf("How many books would you like to add?\n");
        do{
            scanf("%d",&n);
        }while( n < 0);
        for ( int i = 0; i < n; i++ ){
            system("cls");
            Addabook();
        }
        
        break;
        case 4:
        search();
        break;
        case 5:
        displayStudents();
        break;
        case 6:
        DisplayAllAccounts();
        break;
        case 7:
        ModifyAcc();
        break;
        case 8:
        true =0;
        break;
    }
    if ( true != 0){
    printf("\n\nPress any key to continue...\n");
    scanf(" %c",&ch);
    system("cls");
    printf("Do you want to exit or go back to the admin menu?\n");
    printf("1) Go back to the admin menu\n2) Go back\n");
    int c;
    do{
        scanf("%d",&c);
        if ( c < 1 || c > 2)
        printf("Invalid choice, Please try again\n");
    }while( c < 1 || c > 2 );
    if ( c == 2 ){
        true = 0;
    }
    }
    }while(true);
}



void Studentt(pswrd a){
int run=1 ;char c;

while(run){
    printf("\n\nPress any key to continue\n");
    scanf(" %c",&c);
    system("cls");
    printf("1) Display all available Books\n");
    printf("2) Search for a book to display its infos or to borrow it\n");
    printf("3) Check if you have to return a book you have already borrowed\n");
    printf("4) Return a book\n");
    printf("5) Go back\n");
    int choix;
    do{
        scanf("%d",&choix);
        if(choix<1 || choix>5){
            printf("Invalid choice! Try again\n");
        }
    }while(choix<1 || choix>5);
    switch(choix){
        case 1:
        system("cls");
        Displaybooks();
        break;
        case 2:
        system("cls");
         char titre[30];
        printf("Enter the title of the book you're looking for\n");
        scanf(" %[^\n]s", titre);
        searchLiv(titre, StdPro(a));
        break;
        case 3:
        system("cls");
        verifybooks(StdPro(a));
        break ;
        case 4:
        returnabook(StdPro(a));
        break;
        case 5 :
        system("cls");
        run=0;
        break ;
    }

}
}