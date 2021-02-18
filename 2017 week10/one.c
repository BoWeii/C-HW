#include<stdio.h>
int main()
{  int x1,y1,x2,y2,per=0,area=0,error=0;
   int lastper=0,lastarea=0;
   int *per1=&per;int *area1=&area;
   scanf("%d",&x1);
  while(x1!=-1)
   {
       scanf("%d %d %d",&y1,&x2,&y2);
       compute(x1,y1,x2,y2,per1,area1);
    if(lastarea>area) area=lastarea;
    if(lastper>per) per=lastper;
lastper=per;lastarea=area;
if(x1==x2||y1==y2) error=1;
       scanf("%d",&x1);
   }
if(error==1) printf("Error");
    else printf("%d\n%d",area,per);
return 0;
}

void compute(int x1,int y1,int x2,int y2,int *per1,int *area1)
{
    *per1=2*(abs(y2-y1)+abs(x2-x1));
    *area1=(abs(y2-y1)*abs(x2-x1));
}


