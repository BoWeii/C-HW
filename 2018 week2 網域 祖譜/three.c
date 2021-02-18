#include<stdio.h>
typedef struct
{
   int a,b,c;
}yee;
int main()
{
   char a;
   int many=0,i=0,total[many],index=0,to=0;
   yee re;
   scanf("%d",&many);
   for(i=0;i<many;i++)
   {
      getchar();
      a=getchar();

      if(a=='T')
      {
         scanf("%d %d %d",&re.a,&re.b,&re.c);
         total[index++]=re.a+re.b+re.c;
      }
      else if(a=='S')
      {
         scanf("%d",&re.a);
         total[index++]=4*re.a;
      }
      else if(a=='R')
      {
         scanf("%d %d",&re.a,&re.b);
         total[index++]=2*(re.a+re.b);
      }
      else if(a=='C')
      {
         scanf("%d",&re.a);
         total[index++]=8*re.a;
      }

   }
   for(i=0;i<many;i++)
   {
      to+=total[i];
      printf("%d \n",total[i]);
   }
   printf("%d ",to);
}
