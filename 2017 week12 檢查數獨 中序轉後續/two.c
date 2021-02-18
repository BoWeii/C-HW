#include<stdio.h>
int eror(char *a,int two2,int two,int base)
{   char (*n)[9]=a;
int total=0,re=0;
int twoo2=two;
       for(two;two>=base;two--)
        { //printf("hi\n");
           for(two2=twoo2;two2>=base;two2--)
            {
               total+=(n[two][two2]-48);
            }
        }
        if(total!=45) re=-1;
            return re;
}
int main()
{   int i,ii,error=0,check=0,two3=2,two4=2,total=0,fuck=0;
    int two=two3,two2=two3,a=0,base;
    char n[9][9];
    for(i=0;i<=8;i++)
    {
        for(ii=0;ii<=8;ii++)
        {
            scanf(" %c",&n[i][ii]);
        }
    }
    /////check L /////0
    for(i=0;i<=8;i++)
    {
        for(ii=0;ii<=8;ii++)//橫
        {
            for(check=ii-1;check>=0;check--)
            {
                if(n[i][ii]==n[i][check])
                {error=1;}
            }
        }
        for(ii=0;ii<=8;ii++)//直
        {
            for(check=ii-1;check>=0;check--)
            {
                if(n[ii][i]==n[check][i])
                    {error=1;}
            }
        }
    }
    if(error==1)
    {
        printf("No");
        return 0;
    }
    ////check 3*3
    for(two3=2;two3<=8;two3+=3)
    {

      for(two4=2,base=0;two4<=8;two4+=3)
      {
        if(eror(n,two3,two4,base)==-1)
        {
           // printf("two3=%d two4=%d\n",two3,two4);
            printf("No"); return 0;
        }
        base+=3;
      }

    }
     printf("Yes");

}


