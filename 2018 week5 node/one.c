#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct data_s
{
   int num,top;
   struct data_s *next;
}data_t;

data_t *push(data_t *data,int num,int top)
{
   data_t *temp=(data_t *)malloc(sizeof(data_t)),*head;
   temp->num=num;temp->top=top;temp->next=NULL;
   if(data==NULL)
   {
      return temp;
   }
   else
   {
      head=data;
      while(data->next!=NULL)
      {
         data=data->next;
      }
      data->next=temp;
      return head;
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
    return result;
}
data_t *ex(data_t *data,int num,int top)
{
   data_t *head=data,*temp=(data_t *)malloc(sizeof(data_t)),*z;
   while(data!=NULL&&(data->top)>=top)
   {
     if((data->top)==top)
         {
            data->num+=num;
            return head;
         }
      z=data;
      data=data->next;
   }
   temp->top=top;
   temp->num=num;
   temp->next=data;
   z->next=temp;
   return head;
}
int main()
{
    char text[10000],*word[100];
    int i=0,len1=0,temp=0,many=0,top=0,left=0,big=0,check=0;
    data_t *one,*temp2=(data_t *)malloc(sizeof(data_t)),*head;
    one=NULL;
    gets(text);
    len1=split(word,text);
    for(i=0;i<=len1;i++)
    {
       temp=atoi(word[i]);
       one=push(one,temp,len1-i);
    }
    head=one;
    scanf("%d",&many);
    for(i=0;i<many;i++)
    {
        one=head;
        scanf("%d %d",&top,&left);
        if(top>(head->top))
         {
            temp2->top=top;
            temp2->num=left;
            temp2->next=head;
            head=temp2;
            continue;
         }

           head=ex(head,left,top) ;
   }
   one=head;
    while(one!=NULL)
    {
         if (one->num==0)
         {
          one=one->next;  continue;
         }
         if(one->num>0&&one!=head) printf("+");
         if(one->top==0) {printf("%d",one->num);check=1;}
         else  if(one->num==1)
         {
            if(one->top==1)  {printf("x");check=1;}
            else if(one->top!=1)  {printf("x^%d",one->top);check=1;}
         }
         else  if(one->num==-1)
         {
            if(one->top==1)  {printf("-x");check=1;}
            else if(one->top!=1)  {printf("-x^%d",one->top);check=1;}
         }
         else if(one->top==1)
         {
          printf("%dx",one->num );
          check=1;
         }
         else {printf("%dx^%d",one->num,one->top);check=1;}

       one=one->next;

    }
  if(check==0) printf("0");
  return 0;
}




