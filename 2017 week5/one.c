#include<stdio.h>
float s(int x)
{
    float m;
    if(x<=120)
    {
        m=x*2.1;
    }
    if(x<=330&&x>=121)
    {
        m=x*3.02;
    }
    if(x<=500&&x>=331)
    {
        m=x*4.39;
    }
    if(x<=700&&x>=501)
    {
        m=x*4.97;
    }
    if(x>=701)
    {
        m=x*5.63;
    }
   return m;
}
////////////////////////////////
float ns(int x)
{    float m;
    if(x<=120)
    {
        m=x*2.1;
    }
    if(x<=330&&x>=121)
    {
        m=x*2.68;
    }
    if(x<=500&&x>=331)
    {
        m=x*3.61;
    }
    if(x<=700&&x>=501)
    {
        m=x*4.01;
    }
    if(x>=701)
    {
        m=x*4.50;
    }
  return m;
}
////////////////////////////
int main()
{
int a,b,c;
float m1;float m2;
scanf("%d %d %d",&a,&b,&c);
if(a>=7&&a<=9)
{
   m2= s(c);
   if(b>c)
   {
       m2=s(c)-(b-c)*0.6;
   }
}
else
{
   m2= ns(c);
   if(b>c)
   {
m2=ns(c)-(b-c)*0.6;   }
}

printf("%.2f",m2);
return 0;
}








