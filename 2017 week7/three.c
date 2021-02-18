#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,b1,b2,b3,b4,A1,A2,A3,A4;
    scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
    A4=a4;A3=a3;A2=a2;A1=a1;
    while(1)
    {    int A=0,B=0;
           a1=A1;a2=A2;a3=A3;a4=A4;
           scanf("%d",&b1);
           if(b1==-1) return 0;
           scanf("%d %d %d",&b2,&b3,&b4);
           if(b1==a1)
            {b1=11;a1=11;A++;}
           if(b2==a2)
           {b2=12;a2=12;A++;}
           if(b3==a3)
           {b3=13;a3=13;A++;}
           if(b4==a4)
           {b4=14;a4=14;A++;}
           //printf("%d\n%d\n%d\n%d\n",a1,a2,a3,a4);
           //printf("%d\n%d\n%d\n%d\n",b1,b2,b3,b4);
           //printf("%d",A);
           //////////////
           if(a1==b2)
            {a1=11;b2=12;B++;}
           else if(a1==b3)
           {a1=11;b3=13;B++;}
           else if(a1==b4)
           {a1=11;b4=14;B++;}
           ///////////////
           if(a2==b1)
           {a2=12;b1=11;B++;}
           else if(a2==b3)
           {a2=12;b3=13;B++;}
           else if(a2==b4)
           {a2=12;b4=14;B++;}
           /////////////////
           if(a3==b1)
           {a3=13;b1=11;B++;}
           else if(a3==b2)
           {a3=13;b2=12;B++;}
           else if(a3==b4)
           {a3=13;b4=14;B++;}
           ///////////////////
           if(a4==b2)
           {a4=14;b2=12;B++;}
           else if(a4==b3)
           {a4=14;b3=13;B++;}
           else if(a4==b1)
           {a4=14;b1=11;B++;}
          printf("%dA%dB\n",A,B);

    }
    return 0;
}
