#include <stdio.h>
int main()
{
    int i=0,ii=0,a=0,b=0,z=0;
    scanf(" %d",&a);scanf(" %d",&b);
    int m[a][b];
    for(i=0;i<a;i++)
    {
        for(ii=0;ii<b;ii++)
        {
            scanf("%d",&m[i][ii]);

        }
    }
    for(i=0;i<a;i++)
    {
        for(ii=0;ii<b;ii++)
        {
            if(i==0&&ii==0) continue;
            else if(i==0&&ii==b-1) continue;
            else if(ii==0&&i==a-1) continue;
            else if(i==0&&ii!=b-1) m[i][ii+1]+=m[i][ii];
            else if(ii==0&&i!=a-1) m[i+1][ii]+=m[i][ii];
            else
            {
                if(m[i-1][ii]>m[i][ii-1]) m[i][ii]+=m[i][ii-1];
                else m[i][ii]+=m[i-1][ii];
            }

        }

    }

   printf("%d",m[a-1][b-1]);
 for(i=0;i<a;i++)
    {
        for(ii=0;ii<b;ii++)
        {
            printf("%d ",m[i][ii]);
        }
        printf("\n");
    }
}


