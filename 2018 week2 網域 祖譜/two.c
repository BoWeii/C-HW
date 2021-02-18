#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
   int data[4];
   char name[100];
   int error;
   int group;
}yee;
void printcorrect(int index,char *result)
{
  char (*re)[100]=result;
  int i=0;
  printf("machines ");
  for(i=0;i<index;i++)
  {
     printf("%s",re[i]);
     if(i==index-1) break;
     if(i+2<index) printf(", ");
     else  printf(" and ");

  }
  printf(" are on the same local network.\n");
}
int main()
{
   char temp[100],result[100][100];
   yee data[100];
   int datalen=0,i=0,ii=0,index=0,search=0, many[100],manyindex=0,member=0,check=0;
   while(1)
   {
      scanf("%d.%d.%d.%d,%s",&data[datalen].data[0],&data[datalen].data[1],&data[datalen].data[2],&data[datalen].data[3],&data[datalen].name);
      if(strncmp(data[datalen].name,"none",4)==0) break;
      if(data[datalen].data[0]>255||data[datalen].data[1]>255||data[datalen].data[2]>255||data[datalen].data[3]>>255) data[datalen].error=1;
      else data[datalen].error=0;
      datalen++;
   }
   for(i=0;i<=datalen;i++) data[i].group=-1;
   for(i=0;i<=datalen;i++)
   {
      strcpy(result[index++],data[i].name);
      for(ii=i+1;ii<=datalen;ii++)
      {
         if(data[i].group==-1&&data[i].error==0&&data[i].data[0]==data[ii].data[0]&&data[i].data[1]==data[ii].data[1]&&data[i].error==0)
         {
            check=1;
            strcpy(result[index++],data[ii].name);
            data[ii].group=i;
         }
      }
     if(check==1) printcorrect(index,result);
      index=0;check=0;
   }
   for(i=0;i<=datalen;i++)
   {
      if(data[i].error==1) printf("machine %s is error ip\n",data[i].name);
   }
  // for(i=0;i<=datalen;i++) printf("%d %d %d %d %d %s\n",i,data[i].data[0],data[i].data[1],data[i].data[2],data[i].data[3],data[i].name);
}

