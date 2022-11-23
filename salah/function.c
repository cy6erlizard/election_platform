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
        fprintf(f,"%d %s %s %d %d %d %d %s %d %s %d\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email,-1);
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
        while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s",&U.CI,U.name,U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,U.phoneNumber,&U.role,U.email,&U.vote)!=EOF)
        {
            if(U.CI== CI)
            {
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",nouvL.CI,nouvL.name,nouvL.firstName,nouvL.d.day,nouvL.d.month,nouvL.d.year,nouvL.gender,nouvL.phoneNumber,nouvL.role,nouvL.email);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email,U.vote);
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
        while(tr==0&& fscanf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",&U.CI,U.name,U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,U.phoneNumber,&U.role,U.email,&U.vote)!=EOF)
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
        while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s\n\n",&U.CI,U.name,U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,U.phoneNumber,&U.role,U.email,U.vote)!=EOF)
        {
            if(U.CI== CI)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %d %s\n\n",U.CI,U.name,U.firstName,U.d.day,U.d.month,U.d.year,U.gender,U.phoneNumber,U.role,U.email,U.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
// taux de participation des hommes et des femmes 
void TPHF(char * filename, float * W,float * M)
{
	user U;
	int nbEvote=0,nbEvoteH=0,nbEvoteF=0;
	FILE * f=fopen(filename, "r");
        if(f!=NULL)
        {
	
	while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s %d\n\n",&U.CI,U.name,U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,U.phoneNumber,&U.role,U.email,&U.vote)!=EOF)
        {
		
            if(U.vote != -1)
        {	nbEvote=nbEvote+1;
		switch(U.gender)
		{case 0:{nbEvoteF=nbEvoteF+1;
			break;}
		case 1:{nbEvoteH=nbEvoteH+1;
			break;}	
		}
	}
	*W=(float)nbEvoteF/nbEvote;
	*M=(float)nbEvoteH/nbEvote;
    }
    fclose(f);
}
} 

float age_moy(char * filename)
{
    int nbr_elec1=0,nbr_elec2=0,nbr_elec3=0,nbr_elec4=0;
    int nbrT;
    user U;
    int age,s1=0,s2=0,s3=0,s4=0;
    float moyage1,moyage2,moyage3,moyage4,moy;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d %d %s %d %s %d\n\n",&U.CI,U.name,U.firstName,&U.d.day,&U.d.month,&U.d.year,&U.gender,U.phoneNumber,&U.role,U.email,&U.vote)!=EOF)
        {
            if(U.role==1){
                age=2022-U.d.year;
                if(age>=18 && age<30)
                {
                    nbr_elec1++;
                    s1+=age;
                }
                if(age>=30 && age<45)
                {
                    nbr_elec2++;
                    s2+=age;
                }
                if(age>=45 && age<60)
                {
                    nbr_elec3++;
                    s3+=age;
                }
                if(age>=60)
                {
                    nbr_elec4++;
                    s4+=age;
                }
            } 
        }
		nbrT=nbr_elec1+nbr_elec2+nbr_elec3+nbr_elec4;
            moyage1=(float)nbr_elec1/nbrT;
            moyage2=(float)nbr_elec2/nbrT;
            moyage3=(float)nbr_elec3/nbrT;
            moyage4=(float)nbr_elec4/nbrT;
            printf("l'age moy between 18 et 30 = %f\n",moyage1);
            printf("l'age moy between 30 et 45 = %f\n",moyage2);
            printf("l'age moy between 45 et 60 = %f\n",moyage3);
            printf("l'age moy between 60   = %f\n",moyage4);
	    moy=(s1+s2+s3+s4)/nbrT;
    }
    fclose(f);
    return moy;
}

