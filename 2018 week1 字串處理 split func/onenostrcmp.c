#include<stdio.h>
typedef struct
{
    char *n;
    int t;
} all;
int main()
{   int len=0,i=0,relen, count[100],ii=0;
    char text[1000],*words[1000],*countWords[100],P[100],Q[100];
    gets(text);
    len=split(words,text);
    scanf("%s",P);
    scanf("%s",Q);
    for(i=0;i<=98;i++)
    {
       countWords[i]='\0';
      count[i]=0;

    }
    for(i=0;i<len;i++) {
      if(!fuck(words[i],P))
      {
         printf("%s ",Q);
          continue;
      }
      printf("%s ",words[i]);
   }
   printf("\n");
    for(i=0;i<len;i++) {
      if(!fuck(words[i],P)) printf("%s ",Q);
      printf("%s ",words[i]);

    }
    printf("\n");
    for(i=0;i<len;i++) {
      if(!fuck(words[i],P)) continue;
      printf("%s ",words[i]);

    }
    printf("\n");
    relen=fix(words,countWords,len,count);

   all result[relen+2];
     for(i=0;i<relen;i++)
     {
        result[i].n=countWords[i];
        result[i].t=count[i];
     }

     for(i=0;i<relen;i++)
     {
        for(ii=0;ii<i;ii++)
        {
           if(result[ii].t<result[i].t)
           {
              result[relen]=result[ii];
              result[ii]=result[i];
              result[i]=result[relen];

           }
        }
     }
     result[relen].t=0;
     for(i=0;result[i].t!=0;i++)
     {
        for(ii=0;ii<i;ii++)
        {
           if(result[i].t==result[ii].t )
           {
              if(fuck(result[i].n,result[ii].n)==-1)
              {
                 result[relen+1]=result[i];
                 result[i]=result[ii];
                 result[ii]=result[relen+1];
              }
           }
        }
     }
    for(i=0;i<relen;i++)
    {
       printf("%s ",result[i].n);
       printf("%d\n",result[i].t);

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
int fix(char *words[],char *countWords[],int len,int *count)
{   int i=0,ii=0,x=0,check=0,index=1;
    countWords[0]=words[0];
    for(i=0;i<len;i++){
     if(!isin(words[i],countWords,len,count))
     {
        count[index]++;
        countWords[index++]=(words[i]);

     }
    }
    return index;
}
int isin(char *words,char *countwords[],int size,int count[])
{  int i=0;
   for(i=0;i<=size;i++)
   {
      if(countwords[i]!='\0')
      {
         if(fuck(words,countwords[i])==0)
         {
            count[i]++;
            return 1;
         }
      }
      else return 0;
   }
}

int fuck(char *a,char *b)
{
   int i=0;
   while(1)
   {
     if((int)a[i]<(int)b[i]) return -1;
     if((int)a[i]>(int)b[i]) return 1;
     if (strlen(a)==strlen(b) && (strlen(a)-1)==i) return 0 ;
     i++;
       }
}
