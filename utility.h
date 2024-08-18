#ifndef MY_HEADER_H
#define MY_HEADER_H

typedef struct
{
 char usrname[30];
 char password[45]; 
}pswrd;


typedef struct{
    int d;
    int m ;
    int y ;
}date;



typedef struct {
int ID ;
char fname[30];
char lname[30];
char faculty[45];
}stdprofile;


typedef struct{

char title[30];
int bookID ;
char author[30];
float price ;
int quant ;
int stock ;
int year ;
char genre[40];

}book;


typedef struct{

int bookID;
int stdID;
char title[30];
char author[30];
date startdate;
date endate;

} stubook;


typedef struct{

pswrd acccount;
stdprofile profile;
stubook booklist[10];
int pret ;

}student;



#endif  //MY_HEADER_H
