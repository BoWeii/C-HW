#include<stdio.h>
int main()
{    int a,b ,c;
    scanf("%d%d%d",&a,&b,&c);
    gettriangle(a,b,c);
return 0;
}
int gettriangle(int a,int b,int c)
{
if (a+b<=c || a+c<=b || b+c<=a || a==0 || b==0 ||c==0) printf("not triangle");
else{
    if(a==b&&b==c) printf("equilateral triangle");
    else if (a==b|| b==c||a==c) printf("isosceles triangle");
    else  printf("triangle");}
return 0;
}




