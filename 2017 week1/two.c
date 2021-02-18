#include<stdio.h>
#include <math.h>
int main()
{
int a,b,c;
double chan,fu;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
chan=((-b)+sqrt(b*b-4*a*c))/(2*a) ;
fu=((-b)-sqrt(b*b-4*a*c))/(2*a) ;

printf("\n");

printf("%.1f\n",chan);
printf("%.1f",fu);


return 0;
}
