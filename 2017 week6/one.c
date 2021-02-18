#include<stdio.h>
int isPrime(int num)
{
    int i=2;  int a;
    for(i;i<num;i++)
    {
        if(num%i==0) return a=0;

    }
    return a=1;
}
int isFactor(int x,int y)
{
    int a;
    if(x%y==0) return a=1;
    else return a=0;

}
int compute(int num)
{   int yee=1;
    int i=2;
    for(i;i<=num;i++)
    {
        yee=yee*i;
    }
    return yee;
}
int main()
{
float b; int i=2; int total=0;
scanf("%f",&b);
if(b<0) printf("E");
else if(b==(int)b)
    {   int a=b;
        for(i;i<a;i++)
 {
     if(isFactor(a,i)&&isPrime(i))
     {printf("%d ",compute(i));
    total=total+compute(i);
     }

 }  printf("\n%d",total);
 }
else printf("E");
}







