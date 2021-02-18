#include<stdio.h>
int main()
{
    int m=0,n=0,o=0,p=0,i=0,ii=0,temp=0,x=0,xx=0,re=0;
    scanf(" %d %d %d %d",&m,&n,&o,&p);
    int a[m][n],b[o][p],c[m][p];
    if(o==n){
    for(i=0;i<m;i++)
    {
        for(ii=0;ii<n;ii++)
        {
            scanf(" %d",&a[i][ii]);
        }
    }

    for(i=0;i<o;i++)
    {
        for(ii=0;ii<p;ii++)
        {
            scanf(" %d",&b[i][ii]);

        }
    }

   for(i=0;i<m;i++)
   {
       for(ii=0;ii<p;ii++)
       {
         re=0;
         x=i;xx=ii;
         for(x=0;x<n;x++)
        {
            re+=a[i][x]*b[x][ii];
        }
        c[i][ii]=re;
       }
   }
    for(i=0;i<m;i++)
   {
       for(ii=0;ii<p;ii++)
       {
         printf("%d ",c[i][ii]);;
       }
        printf("\n");
   }
    }

    else printf("Error");

}

