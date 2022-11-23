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
int vote;
}user;
//les fonctions

int addUser(char * filename, user U);
int updateUser( char * filename,int CI,user nouvL );
int deleteUser(char * filename, int CI);
user searchUser(char * filename, int CI);
float age_moy(char * filename);
void TPHF(char * filename, float * fe,float * h);


#endif // FUNCTION_H_INCLUDE

