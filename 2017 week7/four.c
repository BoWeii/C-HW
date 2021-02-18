#include<stdio.h>
int main()
{   int a,b,c=1,d,e,s,f,k,yes=1,yes2=0; float z=0,fail=0;
    scanf("%d %d",&a,&b);
    k=a;f=b;

    for(k;k<=b;k++)
    {   int contrast=0;
           double total=0;
        while(k>=total)
        {
            total=pow(10,z);
            z+=1;

        }
            z-=2;
       // printf("%d\n",(int)z);
        z=(int) z;
        if(z==0)
        {
            fail=1;
        }
        else {
        contrast=(z+1)/2;
        //printf("%d\n",contrast);
        a=k;
        yes=1;
       for(contrast;contrast>=1;contrast-=1)
       {   //printf("      %d\n",contrast);

           e=(k/(pow(10,z)));
            d=((int)e)%10;
            s=a%10;
           // printf("%d %d\n",s,a);
           // printf("d=%d s=%d\n",d,s);
           if(d!=s) yes=0;

           a/=10;
           z-=1;
       }
       if(yes==1)
             {printf("%d ",k);
                yes2=1;
             }

         z=0;

      }}
      if(yes==0&&yes2==0||fail==1) printf("0");
return 0;
}
