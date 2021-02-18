  #include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stack_s
{
   char name[100];
   int old;
   int year;
   int month;
   int day;
   struct stack_s *next;
}stack_t ;

stack_t *push(stack_t *data,char name[90],int old,int year,int month,int day)
{
   stack_t *head=data;
   stack_t *temp=(stack_t *)malloc(sizeof(stack_t));
   strcpy(temp->name,name);temp->old=old;temp->year=year;temp->month=month;temp->day=day;temp->next=NULL;
   if(data==NULL) return temp;
   else
   {
      while(data->next!=NULL) data=data->next;
   }
   data->next=temp;

   return head;
}
stack_t *pop(stack_t *data,int mode)
{
   stack_t *bye;
   if(data==NULL) printf("The Stack is empty\n");

   else {
      if(mode==1) printf("%s\n",data->name);
      else if(mode==2) printf("%d\n",data->old);
      else if(mode==3) printf("%d_%d_%d\n",data->year,data->month,data->day);
      bye=data;
      data=(data->next);
      free(bye);
       }
       return data;
}
int main()
{
   int z=0,mode=0,old=0,year=0,month=0,day=0; char text[100],*word[100],*name[90],space[10];
   stack_t *data=(stack_t *)malloc(sizeof(stack_t));
   data=NULL;
   while(1)
   {
      scanf("%d",&z);
      if(z==1)
      {
         scanf(" ");
         gets(text);
         split(word,text);
         old=atoi(word[1]);year=atoi(word[2]);month=atoi(word[3]);day=atoi(word[4]);
         data=push(data,word[0],old,year,month,day);
      }
      else if(z==3) break;
      else if(z==2)
      {
         scanf("%d",&mode);
       data=pop(data,mode);
      }
   }
}
int split(char *words[],char *text)
{   int num=0,i=0,result=0,check=0;
    words[num++]=(&text[0])+1;
    for(i=2;text[i]!='\0';i++)
    {

        if(text[i]=='"')
        {
           text[i]='\0';
           words[num++]=&(text[i+2]);
           i++;
           check++;
           continue;

        }
        if(text[i]==' '&&check<1) continue;

        if (text[i]==' ')
        {   text[i]='\0';
            words[num++]=&(text[++i]);
            result++;
        }
    }
    return result+1;
}
