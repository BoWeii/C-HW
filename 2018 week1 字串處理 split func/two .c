#include<stdio.h>
int main()
{
   int lenone=0,lentwo=0,result=0,which=0,i=0;
   char textone[1000],texttwo[1000],*one[1000],*two[1000];
   gets(textone);
   gets(texttwo);
   lenone=split(one,textone);
   lentwo=split(two,texttwo);
   //printf("%d %d\n",lenone,lentwo);
   result=check(one,two,lenone,lentwo,&which);
  // printf("\nresult=%d",result);
   for(i=0;i<result;i++) printf("%s ",one[which+i]);
   printf("\n%d/%d",(int)result/reduction(lenone,result),(int)lenone/reduction(lenone,result));
}

int split(char *words[],char *text)
{   int num=0,i=0,result=0;
    words[num++]=text;
    for(i=1;text[i]!='\0';i++)
    {
        if (!(text[i]>='a'&&text[i]<='z'||text[i]>='0'&&text[i]<='9'||text[i]>='A'&&text[i]<='Z'))
        {
            if((text[i-1]>='a'&&text[i-1]<='z'||text[i-1]>='0'&&text[i-1]<='9'||text[i-1]>='A'&&text[i-1]<='Z')) text[i]='\0';
            if((text[i+1]>='a'&&text[i+1]<='z'||text[i+1]>='0'&&text[i+1]<='9'||text[i+1]>='A'&&text[i+1]<='Z'))
            {
               words[num++]=&(text[++i]);
                result++;
            }
        }
    }
    return result+1;
}
int check(char *one[],char *two[],int lenone,int lentwo,int *which)
{
   int i=0,ii=0,x=0,times=0,temp=0;
   for(i=0;i<lenone;i++)
   { // printf("\ni=%d  ",i);
      for(ii=0;ii<lentwo;ii++)
      { // printf("ii=%d one=%s  two=%s \n",ii,one[i],two[ii]);
         if(!strcmp(one[i],two[ii]))
         {  x=0;
            temp=0;
            while(one[x+i]!=NULL && two[x+ii]!=NULL)
            {
             //  printf("---------in while------------ \n one=%s two=%s times=%d\n",one[i+x],two[ii+x],temp);
               if(strcmp(one[x+i],two[x+ii])==0) {temp++; x++;}
               else break;
            }
        //   printf("times=%d temp=%d\n",times,temp);
           if(temp>times)
             {
              times=temp;
              *which=i;
             }
         }
      }
   }
   return times;
}
int reduction(int max,int word_1_amount){
    if(max%word_1_amount==0)
        return word_1_amount;
    else
        return reduction(word_1_amount,max%word_1_amount);
}














