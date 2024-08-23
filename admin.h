#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utility.h"
#include <windows.h>
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delete ( int bookid ){
    book a;
    FILE *f = fopen("booksInfo", "rb");
    FILE *f2 = fopen("AfterDeleting", "wb");
    while( fread( &a, sizeof(book), 1, f) == 1 ){
        if( a.bookID != bookid )
        fwrite( &a, sizeof(book), 1, f2);
    } fclose(f);fclose(f2);
    remove("booksInfo");
    rename("AfterDeleting","booksInfo");
}
void update ( int bookid ){
    book a ;
    int found = 0 , choice;
    FILE *f = fopen("booksInfo", "rb");
    FILE *f2 = fopen("AfterUpdating", "wb");
    if (f == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    while( fread( &a, sizeof(book), 1, f) == 1 ){
        if( a.bookID == bookid ){
            found = 1;
            do{
            printf("What do you want to update?\n 1) Quantity\n 2) Price\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                printf("Enter the new quantity: ");
                scanf("%d",&a.quant);
                break;
                case 2:
                printf("Enter the new price:");
                scanf("%f",&a.price);
                break;
                default:
                printf("Invalid choice! Try again\n");
                break;
            }
            }while( choice < 1 || choice > 2 );
            fwrite( &a, sizeof(book), 1, f2);
        }
        else{
            fwrite( &a, sizeof(book), 1, f2);
        } 
    }
    fclose(f2);
    fclose(f);

    if (found) {
        if (remove("booksInfo") != 0) {
            perror("Error removing booksInfo");
        } else if (rename("AfterUpdating", "booksInfo") != 0) {
            perror("Error renaming AfterUpdating to booksInfo");
        } else {
            printf("Book information updated successfully.\n");
        }
    } else {
        printf("The book doesn't exist.\n");
        if (remove("AfterUpdating") != 0) {
            perror("Error removing AfterUpdating");
        }
    }
}
void search(){
    FILE *f = fopen("booksInfo", "rb");
    book a; int choice = 0,found = 0;
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }else{
        int bookid;
        printf("Input the ID of the book you're looking for\n");
        scanf("%d",&bookid);
        while( fread( &a, sizeof(book), 1, f) == 1 ){
            if ( a.bookID == bookid ) {
                found = 1;
                printf(" 1) Update the book's informations\n 2) Delete the book from the library\n");
                scanf("%d", &choice);
                do{
                    switch (choice) {
                    case 1:
                    fclose(f);
                    update(bookid);
                    break;
                    case 2:
                    fclose(f);
                    delete(bookid);
                    break;
                    default:
                    printf("Invalid choice! Try again\n");
                    break;
                }
                }while( choice != 1 && choice != 2 );
        }
    }
    if ( !found )
    printf("The book doesn't exist.\n");
    fclose(f);
}}
void Displaybooks(){
    FILE *f = fopen("booksInfo", "rb");
    book a; int i = 1;
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }else{
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
        gotoxy(135,0);
        printf("Quantity");
        gotoxy(155,0);
        printf("Price");
        gotoxy(0, 1);
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------");
        while( fread( &a, sizeof(book), 1, f) == 1 ){
            gotoxy(0, i+1);
            printf("%d", a.bookID);
            gotoxy(20, i+1);
            printf("%s",a.title);
            gotoxy(50, i+1);
            printf("%s",a.author);
            gotoxy(80, i+1);
            printf("%s",a.genre);
            gotoxy(105, i+1);
            printf("%d",a.year);
            gotoxy(135,i+1);
            printf("%d",a.quant);
            gotoxy(155,i+1);
            printf("%.2f DA",a.price);
            i++;
        }
    }
    fclose(f);
}
void Addabook(){
    book a,b; int exist = 0;
    FILE *f = fopen("booksInfo","rb");
    printf("Enter the book ID\n");
    scanf("%d",&a.bookID);
    if ( f == NULL ){
        printf("Error opening file!\n");
        exit(1);
    }else{
        while( fread( &b, sizeof(book), 1, f) == 1 ){
            if (a.bookID == b.bookID){
                printf("This ID is already taken!\n");
                exist = 1;
                fclose(f);
            }
    }fclose(f);
    if ( !exist ){
    do{
        printf("Enter the book's title\n");
        scanf(" %[^\n]s",a.title);
        printf("Enter the book's author\n");
        scanf(" %[^\n]s",a.author);
        if ( strcmp(a.title,"Plqvmtx")==0 && strcmp(a.author,"Plqvmtx")==0 )
        printf("The book's title and the author's name can't be 'Plqvmtx' \n\nTry again\n");
    }while( strcmp(a.title,"Plqvmtx")==0 && strcmp(a.author,"Plqvmtx")==0 );
    printf("Enter the book's genre\n");
    scanf(" %[^\n]s",a.genre);
    printf("Enter the book's price\n");
    scanf("%f",&a.price);
    printf("Enter the book's quantity\n");
    scanf("%d",&a.quant); 
    printf("Enter the book's publishing year\n");
    scanf("%d",&a.year);
    f= fopen("booksInfo", "ab");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
        }else{
            fwrite( &a, sizeof(book), 1, f);
            fclose(f);
        }
    }
    }
}

void DisplayAllAccounts(){
    FILE *f = fopen("DataAD.bin", "rb");
    pswrd a;int i = 2;
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
        }else{
            system("cls");
            gotoxy(0,0);
            printf("Username");
            gotoxy(20,0);
            printf("Password");
            gotoxy(0,1);
            printf("-------------------------------");
            while (fread(&a, sizeof(pswrd), 1, f) == 1 ){
                gotoxy(0, i);
                printf("%s",a.usrname);
                gotoxy(20,i);
                printf("%s",a.password);
                i++;
            }fclose(f);
        }
}


void ModifyAcc(){
    pswrd a , b;
    int choix , correct = 0, usernameFound = 0;
    char ps[45],pss[45];
    printf("Enter your username\n");
    scanf(" %[^\n]s",a.usrname);

    FILE *f = fopen("DataAD.bin","rb"), *new = fopen("new","wb");

    if (f== NULL) {
        printf("Error opening file!\n");
        exit(1);
        }else{
            while( fread( &b, sizeof(pswrd), 1, f) == 1 ){
                if(strcmp(b.usrname,a.usrname)==0){
                    usernameFound = 1;
                    do{
                        printf("Enter your old password\n");
                        scanf(" %[^\n]s",a.password);
                        if(strcmp(a.password,b.password)==0){
                        do{
                            printf("Enter your new password\n");
                            scanf(" %[^\n]s",ps);
                            printf("Re-enter your new password\n");
                            scanf(" %[^\n]s",pss);
                            if(strcmp(ps,pss)==0){
                                strcpy(a.password, ps);
                                correct = 1;
                            }else
                            printf("Passwords don't match. Try again\n");
                        }while(!correct);
                        printf("Do you want to change or keep the username?\n");
                        printf(" 1) Change the username\n");
                        printf(" 2) Keep the old one\n");
                        scanf("%d",&choix);
                        while(choix!= 1 && choix!= 2){
                            printf("Invalid choice. Try again\n");
                            scanf("%d",&choix);
                        }
                        if(choix==1){
                            printf("Enter your new username\n");
                            scanf("%s",a.usrname);
                            printf("Your username and password have been successfully changed.\n");
                        }else if(choix==2){
                            printf("Your password has been successfully changed.\n");
                        }
                        fwrite(&a, sizeof(pswrd), 1, new);
                    }else{
                        printf("The password is wrong. Please try again\n");
                    }
                    }while( !correct );
                }else{
                    fwrite( &b, sizeof(pswrd), 1, new);
                }
            }
            if ( !usernameFound )
            printf("The username you have entered doesn't exist.\n");

            fclose(f);fclose(new);
            remove("DataAD.bin");
            rename("new","DataAD.bin");
}}

void deleteAcc( char username[45] ){
    pswrd a;char choix;
    int found = 0;
    FILE *f = fopen("DataAD.bin","rb");
    FILE *temp = fopen("temp","wb");
    if ( f == NULL ){
        printf("Error opening file!\n");
        exit(1);
    }else{
        while( fread( &a, sizeof(pswrd), 1, f) == 1 ){
            if( !strcmp(a.usrname, username) ){
                found = 1;
                printf("Are you sure you want to delete this account? (y/n) \n");
                scanf(" %c",&choix);
                do{
                    if(choix=='y' || choix=='Y')
                    printf("The account has been successfully deleted.\n");
                    else if(choix=='n' || choix=='N'){
                        printf("The account has not been deleted.\n");
                        fwrite(&a,sizeof(pswrd),1,temp);
                    }else{
                        printf("Invalid input. Please try again.\n");
                    }
                }while( choix != 'y' && choix != 'Y' && choix != 'n' && choix != 'N');
        }else{
            fwrite(&a,sizeof(pswrd),1,temp);
        }
    }fclose(f);fclose(temp);
    if ( found ){
        remove("DataAD.bin");
        rename("temp","DataAD.bin");
    }else{
        printf("The account you have entered doesn't exist.\n");
        remove("temp");
    }
}
}
void displayStudents(){
    student s;
    int i = 2;
    FILE *f = fopen("DataSTD.bin","rb");
    if ( f == NULL ){
        printf("Error opening file!\n");
        exit(1);
        }else{
            system("cls");
            gotoxy(0,0);
            printf("ID");
            gotoxy(20,0);
            printf("Last Name");
            gotoxy(40,0);
            printf("First Name");
            gotoxy(60,0);
            printf("Faculty");
            gotoxy(80,0);
            printf("Username");
            gotoxy(100,0);
            printf("Password");
            gotoxy(0,1);
            printf("----------------------------------------------------------------------------------");
            while( fread( &s, sizeof(student), 1, f) == 1 ){
                gotoxy(0,i);
                printf("%d",s.profile.ID);
                gotoxy(20,i);
                printf("%s",s.profile.lname);
                gotoxy(40,i);
                printf("%s",s.profile.fname);
                gotoxy(60,i);
                printf("%s",s.profile.faculty);
                gotoxy(80,i);
                printf("%s",s.acccount.usrname);
                gotoxy(100,i);
                printf("%s",s.acccount.password);
                i++;
            }fclose(f);
        }
}
void borrowedBooks(){
    student a;
    int choix;
    do{
        printf("Would you like to see the borrowed books of all students or just those of a specific student?\n");
        printf("1. Display borrowed books of all students.\n2. Display borrowed books of a specific student.\n");
        scanf("%d",&choix);
        if ( choix == 1 ){
            system("cls");
            gotoxy(0,0);
            printf("ID");
            gotoxy(20,0);
            printf("Full Name");
            gotoxy(60,0);
            printf("Book Titles");
            gotoxy(100,0);
            printf("Borrow Date");
            gotoxy(120,0);
            printf("Due Date");
            gotoxy(0,1);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------");
            FILE *f = fopen("DataSTD.bin","rb");
            if ( f == NULL ){
                printf("Error opening file!\n");
                exit(1);
            }else{
                int i = 2;
                while(fread(&a,sizeof(student),1,f)==1){
                    gotoxy(0,i);
                    printf("%d",a.profile.ID);
                    gotoxy(20,i);
                    printf("%s %s",a.profile.lname,a.profile.fname);
                    gotoxy(60,i);
                    for ( int j=0; j<(a.pret); j++ ){
                        printf("%s\n",a.booklist[j].title);
                        gotoxy(100,i);
                        printf("%d.%d.%d",a.booklist[j].startdate.d, a.booklist[j].startdate.m, a.booklist[j].startdate.y);
                        gotoxy(120,i);
                        printf("%d.%d.%d",a.booklist[j].endate.d, a.booklist[j].endate.m, a.booklist[j].endate.y);
                        i++;
                        gotoxy(60,i);
                    }
                    i++;
                    gotoxy(0,i);
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------");
                    i++;
                }fclose(f);
            }
    }else if ( choix==2 ){
        int id , found = 0;
        printf("Enter the student's ID\n");
        scanf("%d",&id);
        FILE *f = fopen("DataSTD.bin","rb");
            if ( f == NULL ){
                printf("Error opening file!\n");
                exit(1);
            }else{
                while(fread(&a,sizeof(student),1,f)==1 ){
                    if ( a.profile.ID == id ){
                        found = 1;
                        system("cls");
                        gotoxy(0,0);
                        printf("ID");
                        gotoxy(20,0);
                        printf("Full Name");
                        gotoxy(60,0);
                        printf("Book Titles");
                        gotoxy(0,1);
                        printf("-------------------------------------------------------------------------------------------------------------------------------------------");
                        gotoxy(0,2);
                        printf("%d",a.profile.ID);
                        gotoxy(20,2);
                        printf("%s %s",a.profile.lname,a.profile.fname);
                        gotoxy(60,2);
                        int i = 2;
                        for ( int j=0; j<(a.pret); j++ ){
                        printf("%s\n",a.booklist[j].title);
                        gotoxy(100,i);
                        printf("%d.%d.%d",a.booklist[j].startdate.d, a.booklist[j].startdate.m, a.booklist[j].startdate.y);
                        gotoxy(120,i);
                        printf("%d.%d.%d",a.booklist[j].endate.d, a.booklist[j].endate.m, a.booklist[j].endate.y);
                        i++;
                        gotoxy(60,i);
                        }
                    }
                } if ( !found ) printf("Student not found!\n");
            }
}else{
    printf("Invalid choice! Try again\n");
}
}while( choix != 1 && choix != 2);
}

