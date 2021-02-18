#include<stdio.h>
int spaceless(int x)
{   int a;
       a=x;
       for(a;a>=1;a--)
       {
           printf(".");
       }
}
int spacemore(int x)
{   int a;
       a=1;
       for(a;a<=x;a++)
       {
           printf(".");
       }

}
int num1(int x)
{   int a=1;
    for(a;a<=x;a++)
    {
        printf("%d",a);
    }
}
int num2(int x)
{   int a=x-1;
    for(a;a>=1;a--)
    {
        printf("%d",a);
    }
}
int num3(int x)
{
    for(x;x>=1;x-=2)
    {
        printf("%d",x);
    }
}
int num4(int x)
{    int a=3;
    for(a;a<=x;a+=2)
    {
        printf("%d",a);
    }
}
int main()
{    int a=0;int b=0 ;
    scanf("%d",&a);

  while(a!=-1)
  {  int b ;
     int up,j,down;int c=1; int spe=0;
   scanf("%d",&b);
  if(a==1)
  {
      if(b>=1&&b<=18)
        {
          up=(b-1)/2;
          spe=up;
          for(c;c<=up;c++)
          {
              spaceless(spe);
              spe--;
              num1(c);num2(c);
              printf("\n");
          }
          down=b-up;
          spe=0;
          for(down;down>=1;down--)
          {
              spacemore(spe);
              spe+=1;
              num1(down);num2(down);
              printf("\n");
          }
         }
        else
        {printf("E");
           printf("\n"); }
  }
///////////////////////////////////////////////////////////////////////////////////
    else if(a==2)
    {
        if(b>=1&&b<=5)
        {
            for(b;b>=1;b--)
            {
                j=2*b-1;
                spacemore(spe);
                spe++;
                num3(j),num4(j);
                printf("\n");
            }
        }
        else
        {printf("E");
        printf("\n");
        }
    }
    else if(a==-1) return 0;
     else
    {printf("E");
     printf("\n");
    }
  printf("\n");
  scanf("%d",&a);
  }
return 0;
}
