#include <stdio.h>
#include<math.h>
#define max 10
typedef struct
{
    char number[9];
    char name[10];
    int score;
} all;
int main()
{
 FILE *fin, *fout;
 int n,i=0,ii=0;
 float ave=0,std=0;
 fin=fopen("in1.txt","rt");//  int1=profile name,chage this if your profile name not equal int1
 if(fin==NULL)
    {
   printf("Fail To Open File in1.txt!!\nI don't have girlfriend QQ");
   return 0;
    }
 fout=fopen("out1.txt","w+t");// as the same state from fin
  if(fout==NULL)
    {
   printf("Fail To Open File out1.txt!!\nI don't have girlfriend QQ");
   fclose(fin);
   return 0;
    }
  all data[max],temp;
   for(i=0;i<10;i++)
   {
       fscanf(fin,"%s",&data[i].number);
       fscanf(fin,"%s",&data[i].name);
       fscanf(fin,"%d",&data[i].score);
   }
   for(i=0;i<10;i++)
   {
       for(ii=i+1;ii<10;ii++)
       {

           if(data[i].score<data[ii].score)
           {
                  temp=data[i];
                  data[i]=data[ii];
                  data[ii]=temp;
           }
       }
   }
   for(i=0;i<10;i++)
   {
       fprintf(fout,"%-10s",data[i].number);
       fprintf(fout," %-10s",data[i].name);
       fprintf(fout," %3d\n",data[i].score);
       ave+=data[i].score;
   }
   ave/=10;
    fprintf(fout,"Average:%3.2f\n",ave);
     for(i=0;i<10;i++)
   {
     std+=pow(data[i].score-ave,2);
   }
   std/=10;
   std=pow(std,0.5);
   fprintf(fout,"Standard deviation:%3.2f\n",std);
 fclose(fin);
 fclose(fout);
}




