#include<stdio.h>
void num(char a)
{
    printf("%c",a);
    int stateout=1,state;
    char c=0;
    int b=0;
    while(b!=32)
    {
        scanf("%c",&c);
        b=c;
        if(b!=32) printf("%c",b);
        if(b==32) break;
       if(b<48||b>57) stateout=0;
}
    if(stateout==1) printf(" - Number\n");
    else if(stateout==0) printf(" - Invalid\n");
}
void ide(char a)
{    printf("%c",a);
    int stateout=3,state=-1;
   char c=0;
   int b=0;
    while(b!=32)
    {
        scanf("%c",&c);
        b=c;
         if(b==32) break;
        if(b!=32)printf("%c",b);
        if(!((b>=48&&b<=57)||(b==95)||(b>=65&&b<=90)||(b>=97&&b<=122)||b==32)) state=0;
        if(state==0) stateout=0;
    }
     if(stateout==3) printf(" - Identifier\n");
    else if(stateout==0) printf(" - Invalid\n");
}
void val(char a)
{   printf("%c",a);
    int stateout=0;
    char b=0;
        while(b!=32)
        {
            scanf("%c",&b);
           if(b!=32) printf("%c",b);
           if(b==32) break;
        }
        printf(" - Invalid\n");
}
int main()
{    char a;
     int in;
    while(1)
    {
        scanf("%c",&a);
        in=a;
        if(in==46) return 0;
       else if(!((in>=48&&in<=57)||(in>=65&&in<=90)||(in>=97&&in<=122)||in==32)) val(in); //非法
       else if(in>=48&&in<=57) num(in);  //數字
       else if((in>=65&&in<=90)||(in>=97&&in<=122)) ide(in);  //英文_
     }
    return 0;
}




