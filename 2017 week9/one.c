#include<stdio.h>
#include<math.h>
int judnegative(float x)
{     int nip=x;
    int times=0,result=0;
    double calc;
     while((int)x!=x)
     {
         x*=10;
         times++;
     }
     calc=(double)nip*pow(10,times);
     result=calc-x;
     return result;
      /*ex: x=-12.3456
      nip=-12
      -12.34567 to -1234567  should run 5 times so times=5
      calc=nip(-12)*10^5=-1200000
      result=-1200000-(-1234567)*/
}
int main()
{
   float x;
   int k=-1;
   scanf("%f",&x);
   if(x>1000) printf("Error!");
   else if(x>=2&&x<=1000) k=x;
   else if(x==0||x==1) k=1000;
   else if((int)x==x&&x<0) k=x*(-11);
   else if((int)x!=x&&x>0) k=(int)x;
    else if((int)x!=x&&x<0) k=judnegative(x);
    //printf("k=%d\n",k);
   for(k;k>=2;k--)
   {
       if(isPrime(k))
       {
           printf("%d",k);
           break;
 }
   }
}


int isPrime(int num)
{
    int i=2;  int a;
    for(i;i<num;i++)
    {
        if(num%i==0) return a=0;

    }
    return a=1;
}
