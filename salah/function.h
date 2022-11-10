#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct birthday{
int day;
int month;
int year;
} dateB;
//struct liste
typedef struct User{
int CI;
char name[30];
char firstName[30];
dateB d;
int gender;
char phoneNumber[30];
int role;
char email[50];
}user;
//les fonctions

int addUser(char * filename, user U);
int updateUser( char * filename,int CI,user nouvL );
int deleteUser(char * filename, int CI);
user searchUser(char * filename, int CI);


#endif // FUNCTION_H_INCLUDE

