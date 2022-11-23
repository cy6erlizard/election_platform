#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main()
{
    user u4= {20,"mohaaamed","salah",17,12,1999,2,"28021325",3,"medsalah@gmail.com"};
    user u2= {75,"med","salah",17,12,1999,2,"28021325",3,"medsalah@gmail.com"},u3;
    int x ;
    float W,M,age;

/* x=addUser("user.txt",u4);

    if(x==1)
        printf("\nadd user successfuly !!!!!!!!!");
    else
        printf("\nfailed add !!!!!!");

*/

/*
  u3=searchUser("user.txt",75);
    if(u3.CI==-1)
    {
        printf("\nnot found!!!!!!!");
    }
    else if (u3.CI!=-1)
     {
         printf("found it !!!!!!!!!!!!\n");
    }

    
  x=updateUser("user.txt",75,u);
    if(x==1)
        printf("\nmodified user successfully!!!!!!!!!");
    else
        printf("\nfailed modify!!!!!!!!!!!");
*/
 

 /* x=deleteUser("user.txt",20);
    if(x==1)
        printf("\ndelete user successfully!!!");
    else
        printf("\nfailed delete !!!!!!");*/
/*
	TPHF("user.txt",&W,&M);
	printf("female participation rate = %f",W); 
	printf("male participation rate = %f",M); 
  */


	age = age_moy("user.txt");
	printf("moy = %f\n",age);
	  
    return 0;


}

