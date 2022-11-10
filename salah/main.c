#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main()
{
    user u= {20,"mohamed","salah",17,12,1999,2,"28021325",3,"medsalah@gmail.com"};
    user u2= {75,"med","salah",17,12,1999,2,"28021325",3,"medsalah@gmail.com"},u3;
    int x ;


/* x=addUser("user.txt",u2);

    if(x==1)
        printf("\nadd user successfuly !!!!!!!!!");
    else
        printf("\nfailed add !!!!!!");
*/






/*
    
    x=updateUser("user.txt",75,u);
    if(x==1)
        printf("\nmodified user successfully!!!!!!!!!");
    else
        printf("\nfailed modify!!!!!!!!!!!");
   */ 
    


/*
    u3=searchUser("user.txt",20);
    if(u3.CI==-1)
    {
        printf("\nnot found!!!!!!!");
    }
    else if (u3.CI!=-1)
     {
         printf("found it !!!!!!!!!!!!\n");
    }

*/

    
   

    x=deleteUser("user.txt",20);
    if(x==1)
        printf("\ndelete user successfully!!!");
    else
        printf("\failed delete !!!!!!");
    
    return 0;
}

