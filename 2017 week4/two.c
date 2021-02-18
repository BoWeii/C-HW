#include<stdio.h>
int main()
{
    int a,a1,b,b1,c,c1,d,d1,e1,e,f,f1;
    scanf("%d:%d",&a,&a1);
    scanf("%d:%d",&b,&b1);
    a=input(a,a1,b,b1);
    scanf("%d:%d",&c,&c1);
    scanf("%d:%d",&d,&d1);
    b=input(c,c1,d,d1);
    scanf("%d:%d",&e,&e1);
   scanf("%d:%d",&f,&f1);
    c=input(e,e1,f,f1) ;
    if(a==1) printf("error\n"); else printf("%d\n",a);
    if(b==1) printf("error\n"); else printf("%d\n",b);
    if(c==1) printf("error"); else printf("%d",c);
  return 0;
}

int input(int w,int x,int y,int z)
{    int t=(60*y+z)-(60*w+x);
      int m=0;
    if(w<24&&w>0&&x<60&&x>=0&&y<24&&y>0&&z<60&&z>=0)
    {
        if(t<120)
        {
            m=(t/30)*30;
            return m;
        }
        else if(t>=120&&t<240)
        {
            m=((t-120)/30+((t-120)%30!=0))*40+120;
            return m;
        }
        else if(t>=240)
        {
            m=((t-240)/30+((t-240)%30!=0))*60+280;
            return m;
        }
    }
    else return 1;
}
