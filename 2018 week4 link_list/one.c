#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct data_s
{
   int num;
   struct data_s *next;
}data_t;

data_t *push(data_t *data,int num)
{
   data_t *head=data;
   data_t *tail=(data_t *)malloc(sizeof(data_t));
   tail->next=NULL;
   while(data->next!=NULL) data=data->next;

      data->num=num;
      data->next=tail;

   return head;
}
int main()
{
    char text[100],*word[100];
    int result[100];
    int i=0,len1=0,len2=0,temp=0,ii=0,temp1=0,temp2=0;
    for(i=0;i<100;i++) result[i]=0;
    data_t *one=(data_t *)malloc(sizeof(data_t));//one=NULL;
    data_t *two=(data_t *)malloc(sizeof(data_t));//two=NULL;
    data_t *head2=two;
    data_t *head1=one;
    one->next=NULL;two->next=NULL;
     //one=NULL;two=NULL;
    gets(text);
    len1=split(word,text);
    for(i=0;i<len1;i++)
    {
       temp=atoi(word[i]);
       one=push(one,temp);
    }
    //////////////////////////////////
    gets(text);
    len2=split(word,text);

      while(one->next!=NULL)
   {
    printf("one %d\n",one->num);
      one=one->next;
   }
   one=head1;
   for(i=0;i<len2;i++)
    {
       temp=atoi(word[i]);
       two=push(two,temp);
    }
    /*   while(two->next!=NULL)
   {
      printf("two %d\n",two->num);
      two=two->next;
   }
   two=head2;*/
   len1--;len2--;
 //  printf("len1=%d len2=%d\n",len1,len2);
    for(i=len1;i>=0;i--)
    {

       two=head2;
       for(ii=len2;ii>=0;ii--)
       {
          //  printf("i=%d ii=%d\n",i,ii);
          result[i+ii]+=two->num*one->num;
      //    printf("two = %d\n",two->num);
          two=two->next;
       }
    //   printf("one = %d \n",one->num);
       one=one->next;
    }
    for(i=len1+len2;i>=0;i--)
    {
       printf("%d ",result[i]);
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

