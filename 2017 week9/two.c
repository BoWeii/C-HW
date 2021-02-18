#include<stdio.h>
double f1(double a,double x)
{
    double T;
    T=sqrt((a-pow(x,2)));
    // 5 1 2  7printf("T1=%lf\n",T);
    return T;
}
double f2(double a,double x)
{
    double T;
    T=fabs((a*pow(x,3)+7*x)/sqrt(a+x));
    //printf("T2=%lf\n",T);
    return T;
}
double T1(double a,double n,double p,double q)
{    double fuck=0,back=f1(a,p),front=f1(a,q),T,h;
    h=(q-p)/(double)n;
    double tempback=p+h,tempfront=q-h;
    for(tempback;tempback<=tempfront;tempback+=h)
        {
            fuck=fuck+f1(a,tempback);
        }
    T = (h/2)*(back+front+ 2*fuck);
    return T;
}
double T2(double a,double n,double p,double q)
{  double fuck=0,back=f2(a,p),front=f2(a,q),T,h;
    h=(q-p)/(double)n;
    //printf("h=%lf\n",h);
    double tempback=p+h,tempfront=q-h;
    for(tempback;tempback<=tempfront;tempback+=h)
        {
            fuck=fuck+f2(a,tempback);
        }
    T = (h/2)*(back+front+ 2*fuck);
    return T;
}
int main()
{   double y=-1,q,p,err,times,n; double a,h,result,t1,t2,er;
   scanf("%lf",&y);
   while(y!=0)
   {   n=2;
       scanf("%lf %lf %lf %lf",&a,&p,&q,&err);
       if(y==1)
       {
          while(1)
           {   er=pow(10,(double)err);
               result=fabs(T1(a,n,p,q)*er-T1(a,n+1,p,q)*er);
               //printf("T=%lf\n",T2(a,n,p,q));
               if(result<1)
               {
                printf("%.5lf\n",T1(a,n,p,q));
                break;
               }
               n++;
            }
       }
          else if(y==2)
         {
           while(1)
              { er=pow(10,(double)err);
               result=fabs(T2(a,n,p,q)*er-T2(a,n+1,p,q)*er);
               //printf("result=%lf   ",result);
               //printf("T=%lf\n",T2(a,n,p,q));
               if(result<1)
                {
                printf("%.5lf\n",T2(a,n,p,q));
                break;
                 }
                 n++;
               }
            }
     scanf("%lf",&y);
   }
}


