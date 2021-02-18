#include<stdio.h>
typedef struct
{   int child;
    int parent;
} yee;
int main()
{
   yee data[100];
   int many=0,i=0,a=0,b=0,ii=0,check=0,longg=0,big=0,x=0,xx=0;
   for(i=0;i<=99;i++) data[i].child=87;
   scanf("%d",&many);
   for(i=0;i<many-1;i++)
   {
       scanf("%d %d",&a,&b);
       if(a>big) big=a;if(b>big) big=b;
       data[i].child=b;data[i].parent=a;

   }
//   for(i=0;data[i].child!=87;i++) printf("child=%d parent=%d\n",data[i].child,data[i].parent);
   for(i=0;i<=big;i++)
   {
       for(ii=i+1;ii<=big;ii++)
       {
           printf("%d-%d-%d \n",i,ii,ex(i,ii,data,many-1));
       }
   }
}
int ex(int apa,int bpa,yee *data,int many)
{
   int counta=0,countb=0,i=0,ii=0,a[100], b[100],oria=apa,orib=bpa,iii=0;
   for(i=0;i<=99;i++)
   {
       a[i]=87;b[i]=87;
   }
   a[counta]=apa;b[countb]=bpa;
   while(1)
   {
       for(i=0;i<=many;i++)
       {
           if (data[i].child==apa)
           {
              // printf("apa=%d\n",apa);
               apa=data[i].parent;
               a[++counta]=apa;
               if(apa==orib) return counta;
           }
           if (data[i].child==bpa)
           {
              // printf("bpa=%d\n",bpa);
               bpa=data[i].parent;
               b[++countb]=bpa;
               if(bpa==oria) return countb;
            }
         }
        for(ii=0;ii<=countb;ii++)
               {
                  for(iii=0;iii<=counta;iii++)
                  {
                     if(a[iii]==b[ii]) return iii+ii;
                  }
               }
   }
}
