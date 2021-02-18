#include<stdio.h>
int main()
{
    int ia,count=2,count2,re1,re2,re3,re4,d,c,z=0;   float fa,b,a;
    scanf("%d",&ia);
    if(ia>0)
    {
       for(count;count<ia/2;count++)
       {   fa=ia;
           a=(fa/count)-0.5;
           c=ia/count;
           b=(float)ia/(float)count;
           count2=count;
           if(a==c&&count!=2)//偶數
           {
               //printf("count=%d\n",count);
               re3=c-((count2-2)/2);
               re4=re3;
               for(re3;re3<=re4+(count)-2;re3++)
                {
                if(re3<0) break;
                if(re3!=0&&re3>0) printf("%d+",re3);
                 }
           if(re3>0) printf("%d\n",re3);
           }
       else if(b==c)//基數
        {
          // printf("b=%f c=%d",b,c);
           d=(int)b;
            if(d%2==1&&d!=1)
        {     //printf("count:%d\n",count);
            re1=count-(d/2);
            re2=re1;
            for(re1;re1<re2+d-1;re1++)
            {
                if(re1<0) break;
                if(re1!=0&&re1>0) printf("%d+",re1);
            }
           if(re1>0) printf("%d\n",re1);
        }

       }
       if(count==2&&a==c) z=c;
       }
      if(z!=0) printf("%d+%d \n",z,z+1); ////2­Ó
       printf("%d",ia); ////2­Ó
 }
     else printf("E");
return 0;
}
