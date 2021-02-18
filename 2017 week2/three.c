#include<stdio.h>
int main()
{
int a,b,c,t;
float ap,bp,cp;

scanf("%d%d%d",&a,&b,&c);
if(a<=10) ap=a*380;
else if(a>=11 && a<=20) ap=a*(380*0.9);
else if(a>=21 && a<=30) ap=a*(380*0.85);
else if(a>=31) ap=a*380*0.8;

if(b<=10) bp=b*1200;
else if(b>=11 && b<=20) bp=b*(1200*0.95);
else if(b>=21 && b<=30) bp=b*(1200*0.85);
else if(b>=31) bp=b*(1200*0.8);

if(c<=10) cp=c*180;
else if(c>=11 && c<=20) cp=c*(180*0.85);
else if(c>=21 && c<=30) cp=c*(180*0.8);
else if(c>=31) cp=c*(180*0.7);

t=ap+bp+cp;
printf("%d",t);
return 0;
}
