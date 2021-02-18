#include<stdio.h>
int main ()
{
    int a,b,c,d,e,f;
 scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    int ba=b-a;
    int fe=f-e;
    int dc=d-c;
    int temp,da,yo;
     if(c<b&&a<d)
     {
         if(c<a)
         {
             temp=a;
             a=c;
             c=temp;
         }
         if(b>d)
         {
             temp=b;
             b=d;
             d=temp;
         }
         da=ba+dc-(b-c);
     }
     else {da=ba+dc;}

      if(e<d&&a<f)
     {
         if(e<a)
         {
             temp=a;
             a=e;
             e=temp;
         }
         if(f<d)
         {
             temp=f;
             f=d;
             d=temp;
         }
             yo=da+fe-(abs(d-e));
 }
 else {yo=da+fe;}

    //printf("%d %d %d %d\n",ba,dc,fe,da);
    printf("%d",yo);









}
