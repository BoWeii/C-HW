#include<stdio.h>
#include<string.h>
typedef struct
{
   char name[100];
   char num[100];
   char sex[2];
}student;
int main()
{
   int many=0,i=0,checkf=0,checkm=0,ii=0,checksame=0,checkd=0,checki=0;
   char text[100],*word[100];
   scanf("%d",&many);
  // printf("many=%d\n",many);
   while(many<1||many>9)
   {
      printf("error\n");
      scanf("%d",&many);
   }
   student data[many];
   getchar();
   for(i=0;i<many;i++)
   {
      //scanf("");
      checksame=0;
     // getchar();
      gets(text);
      split(word,text);
      for(ii=0;ii<=i;ii++)
      {
         if(i==ii) continue;
         if(strcmp(word[1],data[ii].num)==0) checksame=1;
      }
      if(checksame==0)
        {
           strcpy(data[i].name,word[0]);
         strcpy(data[i].num,word[1]);
         strcpy(data[i].sex,word[2]);
        }
      else
         {
            printf("error\n");
            i--;
         }
   }
   while(1)
   {
      checkf=0;checkm=0,checkd=0,checki=0;
      gets(text);
      split(word,text);
     // sort(data,many);
      if(strcmp(word[0],"f")==0)
      {
         for(i=0;i<many;i++)
         {
            if(strcmp(word[1],data[i].num)==0&&strcmp("-1",data[i].num)!=0)
            {
               printf("%s %s %s\n",data[i].name,data[i].num,data[i].sex);
               checkf=1;
            }
         }
         if(checkf==0) printf("error\n");
      }
      else if(strcmp(word[0],"l")==0)
      {
         for(i=0;i<many;i++)
         {
            if (strcmp("-1",data[i].num)==0) continue;
            printf("%s %s %s\n",data[i].name,data[i].num,data[i].sex);
         }
      }
      else if(strcmp(word[0],"i")==0)
      {
              for(i=0;i<many;i++)
              {
                 if(strcmp(data[i].num,word[2])==0) checki=1;
              }

              if(checki==0)
               {  strcpy(data[many].name,word[1]);
                  strcpy(data[many].num,word[2]);
                  strcpy(data[many++].sex,word[3]);
               }
               else printf("error\n");
      }
      else if(strcmp(word[0],"d")==0)
      {
          for(i=0;i<many;i++)
         {
            if(strcmp(word[1],data[i].num)==0)
            {
               strcpy(data[i].num,"-1");
               checkd=1;
            }
         }
         if(checkd==0) printf("error\n");
      }
      else if(strcmp(word[0],"m")==0)
      {

          for(i=0;i<many;i++)
         {
            if(strcmp(word[1],data[i].num)==0&&strcmp("-1",data[i].num)!=0)
            {
               strcpy(data[i].name,word[2]);
               strcpy(data[i].num,word[3]);
               strcpy(data[i].sex,word[4]);
               checkm=1;
            }

         }
         if(checkm==0) printf("error\n");
          //         gets(text);
          //split(word,text);
      }
      else if(strcmp(word[0],"q")==0) break;
      else printf("error\n");

   }
}
int split(char *words[],char *text)
{   int num=0,i=0,result=0;
    words[num++]=text;
    for(i=1;text[i]!='\0';i++)
    {
        if (text[i]==' ')
        {   text[i]='\0';
            words[num++]=&(text[++i]);
            result++;
        }
    }
    return result+1;
}
/*void sort(student *data[],int many)
{
   student temp;
   int i=0,ii=0;
   for(i=0;i<many;i++)
   {
      for(ii=i;ii<many;ii++)
      {
         if(atoi(*data[i]->num)>atoi(*data[ii]->num))
         {
            temp=*data[i];
            *data[i]=*data[ii];
            *data[ii]=temp;
         }
      }
   }
}*/
