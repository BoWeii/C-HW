#include<stdio.h>
#include<math.h>
int main()
{
 int a,b,c,d,e;
  float st,bian,ave;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  ave=(a+b+c+d+e)/5.0;
  bian=(pow(a-ave,2)+pow(b-ave,2)+pow(c-ave,2)+pow(d-ave,2)+pow(e-ave,2))/5.0;
  st=pow(bian,0.5);
  printf("%.2f\n%.2f\n%.2f\n",bian,st,ave);
return 0;
}
