#include<stdio.h>
void storebit(int *tt,int a)
{int (*t)[5]=tt;
    int b=1000,i=0,times=4,aa=a;
    while(times>=1)
    {
        t[aa][times]=a/b;
        a=a%b;
        b/=10;
        times--;
    }
}
void judgesup(int *tt,int z)
{
    int (*t)[5]=tt,i=1,ii=0;
    //printf("b");
    int flag=0;
    for(i=1;i<=4;i++)
    {
        for(ii=i;ii<=4;ii++)
        {
            if((t[z][i]==t[z][ii])&&i!=ii) flag=1;
        }
    }
    if(flag==1) t[z][0]=0;
}
int judgeAB(int *tt,int *in,int a,int b,int i)
{    int (*t)[5]=tt;
    int aa=0,bb=0,re=0;
    int fuck=4,shit=4;
    for(fuck=4;fuck>=1;fuck--)
    {
        for(shit=4;shit>=1;shit--)
        {
            if(t[i][fuck]==in[shit]) bb++;
        }
    }
    for(fuck=4;fuck>=1;fuck--)
    {
        if(t[i][fuck]==in[fuck]) aa++;
    }
    bb-=aa;
    re=10*aa+bb;
   // printf("%d,\n",re);
    return re;

}
int main()
{
    int t[10000][5],in[5];
    int i=0,ii=0,input=0,a=0,b=0,re=0;
    for(i=0;i<=9999;i++)
    {
        t[i][0]=1;
        storebit(t,i);
        judgesup(t,i);
    }
    while(re!=1)
    {   re=0;
        scanf(" %d,%dA%dB",&input,&a,&b);
        int bb=1000,i=0,times=4,aa=input;
       while(times>=1)
      {
          in[times]=aa/bb;
          aa=aa%bb;
          bb/=10;
          times--;
      }
       for(i=0;i<=9999;i++)
        {
            if(judgeAB(t,in,a,b,i)!=(10*a+b)) t[i][0]=0;
            re+=t[i][0];
        }
         printf("%d\n",re);
        if(re==1)
        {
            for(i=0;i<=9999;i++)
            {
                if(t[i][0]==1)
                    for(ii=4;ii>=1;ii--)
                {
                    printf("%d",t[i][ii]);
                }
            }
            return 0;
        }
    }
}
