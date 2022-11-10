#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
//function for add user
int addUser(char * filename, user U)
{
    FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
//function for modify user
int updateUser( char * filename,int CI,user nouvL )
{
    int tr=0;
    user U;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",&U.CI,&U.name,&U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,&U.phoneNumber,&U.role,&U.email)!=EOF)
        {
            if(U.CI== CI)
            {
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",nouvL.CI,nouvL.name,nouvL.firstName,nouvL.d.day,nouvL.d.month,nouvL.d.year,nouvL.gender,nouvL.phoneNumber,nouvL.role,nouvL.email);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt",filename);
    return tr;

}
//function for search
user searchUser(char * filename, int CI)
{
    user U;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",&U.CI,&U.name,&U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,&U.phoneNumber,&U.role,&U.email)!=EOF)
        {
            if(U.CI== CI)
                tr=1;

        }
    }
    fclose(f);
    if(tr==0)
        U.CI=-1;
    return U;

}
//function for delete
int deleteUser(char * filename, int CI)
{
    int tr=0;
    user U;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",&U.CI,&U.name,&U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,&U.phoneNumber,&U.role,&U.email)!=EOF)
        {
            if(U.CI== CI)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

