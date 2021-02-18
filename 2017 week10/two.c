#include<stdio.h>
void add(int n1,int d1,int n2,int d2,int *numerator,int *deniminator,int *real)
{   int yee=0;
     int mother=d1*d2,son=n1*d2+n2*d1;
   // printf("mo=%d\n",mother);
   //  printf("son=%d\n",son);
   if(son>0)
   {
   while(son/mother>=1)
   {
         son-=mother;
         (*real)++;
   }
        int sontemp=son;
   for(sontemp;sontemp>1;sontemp--)
     {
         if(mother%sontemp==0&&son%sontemp==0)
         {
             *numerator=son/sontemp;
             *deniminator=mother/sontemp;
             yee=1;
             break;
         }
     }
       if(yee!=1)
         {
               *numerator=son;
             *deniminator=mother;
         }
         //printf("real=%d nume=%d denimi=%d\n",*real,*numerator,*deniminator);
     }
     else if(son<0)
     {
         while(son/mother<=-1)
   {
         son+=mother;
         (*real)--;
   }
        int sontemp=son;
   for(sontemp;sontemp<-1;sontemp++)
     {
         if(mother%sontemp==0&&son%sontemp==0)
         {
             *numerator=-abs(son/sontemp);
             *deniminator=abs(mother/sontemp);
             yee=1;
             break;
         }
     }
       if(yee!=1)
         {
               *numerator=son;
             *deniminator=abs(mother);
         }
     }
     else
     {
         *real=-87;
     }
  //printf("real=%d\n",*real);
}
void multiply(int n1, int d1, int n2, int d2, int *numerator, int *deniminator,int *real)
{
   int yee=0;
     int mother=d1*d2,son=n1*n2;
     //printf("mo=%d\n",mother);
   //  printf("son=%d\n",son);
   if(son>0)
   {
   while(son/mother>=1)
   {
         son-=mother;
         (*real)++;
   }
        int sontemp=son;
   for(sontemp;sontemp>1;sontemp--)
     {
         if(mother%sontemp==0&&son%sontemp==0)
         {
             *numerator=son/sontemp;
             *deniminator=mother/sontemp;
             yee=1;
             break;
         }
     }
       if(yee!=1)
         {
               *numerator=son;
             *deniminator=mother;
         }
         //printf("real=%d nume=%d denimi=%d\n",*real,*numerator,*deniminator);
     }
     else if(son<0)
     {
         while(son/mother<=-1)
   {
         son+=mother;
         (*real)--;
   }
        int sontemp=son;
   for(sontemp;sontemp<-1;sontemp++)
     {
         if(mother%sontemp==0&&son%sontemp==0)
         {
             *numerator=-abs(son/sontemp);
             *deniminator=abs(mother/sontemp);
             yee=1;
             break;
         }
     }
       if(yee!=1)
         {
               *numerator=-abs(son);
             *deniminator=abs(mother);
         }
     }

}
    int main()
{
    int n1,n2,d1,d2,numerator1=-87,deniminator1=-1;
    int real1=0,error=0;
    int *numerator=&numerator1,*deniminator=&deniminator1,*real=&real1;
    scanf("%d/%d",&n1,&d1);
    scanf("%d/%d",&n2,&d2);
    if(n1==0||n2==0||d1==0||d2==0)
    {
        printf("ERROR\nERROR");
        return 0;
    }
    add(n1,d1,n2,d2,numerator,deniminator,real);
         if(real1==-87) printf("0\n");
        else if(real1!=0&&numerator1!=0)  printf("%d(%d/%d)\n",real1,numerator1,deniminator1);
        else if(real1!=0&&numerator1==0) printf("%d\n",real1);
        else  printf("%d/%d\n",numerator1,deniminator1);
        real1=0;
    multiply(n1,d1,n2,d2,numerator,deniminator,real);
   if(real1==-87) printf("0");
        else if(real1!=0&&numerator1!=0)  printf("%d(%d/%d)\n",real1,abs(numerator1),deniminator1);
        else if(real1!=0&&numerator1==0) printf("%d\n",real1);
        else  printf("%d/%d\n",numerator1,deniminator1);

}



