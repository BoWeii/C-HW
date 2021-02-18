#include<stdio.h>
void one(char a[],char b[])
{ // printf("in one mode\n");
     char add[61],sub[61],c=0,zero=0;
     int many1=0,many2=0,times=0,many11,many22;
        while(1)
        {
          if(a[many1]==0) break;
          many1++;
        }
        while(1)
        {
          if(b[many2]==0) break;
          many2++;
        }
        many1--;many2--;
        many22=many2;many11=many1;
       if(many11>many22)
        {
            for(many22;many22>=0;many22--,many11--)
         {
             if((b[many22]-48+a[many11]-48)<10&&(b[many22]-48+a[many11]-48)>=0)
                {
                    add[zero]=b[many22]+a[many11]-48+c;
                    c=0;
                    if(add[zero]>=58)
                    {
                        add[zero]-=10;
                        c=1;
                    }
                  //  printf("<=10 %c\n",add[zero]);
                }
             else if((b[many22]-48+a[many11]-48)>=10)
                {
                add[zero]=b[many22]+a[many11]-48-10+c;
                 c=1;
               // printf(">10 %c\n",add[zero]);
                   }
                   zero++;
            }
            many22=many2;
            if(c==1)
            {
                a[many1-many2-1]+=1;
            }
            for(zero=0;zero<many1-many2;zero++)
            {
             printf("%c",a[zero]);
            }
            for(many22;many22>=0;many22--)
            {
               printf("%c",add[many22]);
            }
            printf("\n");
        }
}
void two(char a[],char b[])
{
   // printf("in two mode\n");
    char add[61],sub[61],B=0,zero=0;
     int many1=0,many2=0,times=0,many11,many22;
        while(1)
        {
          if(a[many1]==0) break;
          many1++;
        }
        while(1)
        {
          if(b[many2]==0) break;
          many2++;
        }
        many1--;many2--;
        many22=many2;many11=many1;
        for(many22;many22>=0;many22--,many11--)
         {
             if((a[many11]-b[many22]-B)<10&&(a[many11]-b[many22]-B)>=0)
                  {
                    add[zero]=48+a[many11]-b[many22]-B;
                    B=0;
                  //  printf("<=10 %c\n",add[zero]);
                  }
             else if(((a[many11]-48)-(b[many22]-48)-B)<0)
                  {
                add[zero]=58+a[many11]-b[many22]-B;
                 B=1;
              //  printf(">10 %c\n",add[zero]);
                   }
                   zero++;
        }

            if(B==1)
            {  // printf("b==0,many22=%d\n",many22);
                a[many1-many2-1]-=1;
            }
            many22=many2;
            for(zero=0;zero<many1-many2;zero++)
            {
             printf("%c",a[zero]);
            }
            for(many22;many22>=0;many22--)
            {
               printf("%c",add[many22]);
            }
            printf("\n");
        }
int main()
{
     char a[61],b[61],add[61],sub[61],c=0,sixone=61,zero=0;
     char aa[61],bb[61];
     int many1=0,many2=0,times=0,many11,many22;
        scanf(" %s",&a);
        scanf(" %s",&b);
        while(1)
        {
          if(a[many1]==0) break;
          many1++;
        }
        while(1)
        {
          if(b[many2]==0) break;
          many2++;
        }
        for(zero=0;zero<=many1;zero++)
        {
            aa[zero]=a[zero];
        }
        for(zero=0;zero<=many2;zero++)
        {
            bb[zero]=b[zero];
        }
        many1--;many2--;
        many11=many1;many22=many2;
         if(many1>many2) one(a,b);
         else one(b,a);

         if(many1>many2) two(aa,bb);
         else two(bb,aa);
}

