#include<stdio.h>

int main()
{
    int m=0,n=0,o=0,p=0,i=0,ii=0,temp=0;
    scanf(" %d %d %d %d",&m,&n,&o,&p);
    int *a[m][n],*b[o][p],c[m][p];
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
          c[i][ii]=cal(i,ii,a,b,m,n,o,p);
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
int cal(int x,int xx,int aa,int bb,int m,int n,int o,int p)
{i
    (*(aa+x*1+i))*(*(bb+))
    int (*a)[n]=aa,(*b)[p]=bb;
    int i=0,ii=0,re=0;

    for(i=0;i<n;i++)
     {
         re+=a[x][i]*b[i][xx];
     }

  return re;
}
