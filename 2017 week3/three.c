#include<stdio.h>
int main ()
{
    int nt,nd,tt,td;
    int str=0;
    scanf("%d %d %d %d",&nt,&nd,&tt,&td);
    if(tt==10)
    {
        scanf("%d",&str);
        printf("%d",nt+nd+tt+td+str);
    }
     else if(td==10)
    {
        scanf("%d",&str);
        printf("%d",nt+nd+tt+td+str);
    }
    else printf("%d",nt+nd+tt+td+str);
}
