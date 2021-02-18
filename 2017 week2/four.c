#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int main()
{
float a,b,c,t;
scanf("%f%f%f",&a,&b,&c);
t=(b*b-4.0*a*c) ;
if(t>=0) {
    float yo=sqrt(b*b-4.0*a*c) ;
    printf("%.1f\n",(-b+yo)/(2.0*a) );
     printf("%.1f",(-b-yo)/(2.0*a) );
          }
else
{
          float re=abs(t);
          float suck=(-b/(2.0*a));
          float  sys=sqrt(re)/(2.0*a);
          sys=abs(sys);
          if(suck==0) suck=abs(suck);
         printf("%.1f+%.1fi\n",suck,sys);
         printf("%.1f-%.1fi",suck,sys);
}
return 0;

}

