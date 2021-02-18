#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
 FILE *input,*output;
 input=fopen("scores.txt","r");
 output=fopen("sortedscores.txt","w");
 char id[10][9],name[10][11],itmp[9],ntmp[11];
 int score[10],tmp=0,i,j,sum=0;
 float sd=0.0,av=0.0,st=0.0;
 for(i=0;i<10;i++)
 {
  fscanf(input,"%s %s %d",&id[i],&name[i],&score[i]);
  sum=sum+score[i];
 }
 for(i=8;i>0;i--)
 {
  for(j=0;j<=i;j++)
  {
   if(score[j]>score[j+1])
   {
    tmp=score[j];
    score[j]=score[j+1];
    score[j+1]=tmp;
    strcpy(itmp,id[j]);
    strcpy(id[j],id[j+1]);
    strcpy(id[j+1],itmp);
    strcpy(ntmp,name[j]);
    strcpy(name[j],name[j+1]);
    strcpy(name[j+1],ntmp);
   }
  }
 }
 printf("ID          NAME    Score\n");
 fprintf(output,"ID          NAME    Score\n");
 for(i=0;i<10;i++)
 {
  fprintf(output,"%s %9s  %d\n",id[i],name[i],score[i]);
 }
 printf("%s %9s %d\n",id[9],name[9],score[9]);
    printf("%s %9s %d\n",id[0],name[0],score[0]);
    av=sum/10.0;
    printf("Average : %f\n",av);
    for(i=0;i<10;i++)
    {
     st=st+score[i]*score[i]-2.0*score[i]*av+av*av;
 }
 sd=sqrt(st/10);
 printf("Standard Deviation : %f\n",sd);
 fclose(output);
 system("pause");
 return 0;
}
