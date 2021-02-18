#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct  snake_s
{
	int x,y;
	struct  snake_s *next;
}snake_t;
int check(snake_t *head,int x,int y)
{
    int headx=head->x,heady=head->y;
    if(head->x==x&&head->y==y) return 1;
    if(head->x>9||head->y>9||head->x<0||head->y<0)
    {
       return -1;
    }
    while(head!=NULL){

     head=head->next; if(head==NULL) break;
     if(((head->x)==headx)&&((head->y)==heady)) return -1;

    }

    return 2;
}

snake_t *moving(int x,int y,char move[30],snake_t *head,snake_t *tail,int *getmove)
{
    int i=0,getcheck=0;
     snake_t *_head=head;
  //  printf("begin %d %d\n",head->x,head->y );
    while(move[i]!='\0')
    {
   //   printf("now move=%c\n",move[i]);//
      snake_t *temp=(snake_t *)malloc(sizeof(snake_t)),*temp2;
      if(move[i]=='u')
      {
        temp->x=head->x;temp->y=head->y-1;
        temp->next=head;

      }
      else if(move[i]=='d')
      {
      	temp->x=head->x;temp->y=head->y+1;
        temp->next=head;
      }
      else if(move[i]=='l')
      {
      	temp->x=head->x-1;temp->y=head->y;
       temp->next=head;
      }
      else if(move[i]=='r')
      {
      	temp->x=head->x+1;temp->y=head->y;
       temp->next=head;
      }
      head=temp;_head=temp;  i++;
       while(head->next!=NULL)
          {
          //    printf(" find tail head x=%d head y=%d\n",head->x,head->y);//
              temp2=head;
              head=head->next;
          }
      tail=temp2;   head=_head; //  printf("before tail=%d %d\n",tail->x,tail->y);//
     // getcheck=check(head,x,y);
      if(check(head,x,y)==-1) {*getmove=0;return head;}
      if(check(head,x,y)==2)
      {
         // printf("free tail\n");//
           free(tail->next);
           tail->next=NULL;
      }
      else if(check(head,x,y)==1)
      	{
      		*getmove=1;
      		return head;
         }
      }

     *getmove=2;
     return head;
}
void start(snake_t *head,snake_t *tail)
{
   int x=0,y=0,*getmove;
   char move[30];
   while(1)
   	{
   		scanf("%d %d %s",&x,&y,move);
        head=moving(x,y,move,head,tail,&getmove);
        if(getmove==2) printf("Fail\n");
        else if(getmove==1) printf("Success\n");
        else if(getmove==0) {printf("Game Over\n");break;}

    }
}

int main()
{
    snake_t *snake=(snake_t *)malloc(sizeof(snake_t)),*head=snake,*head2=snake,*temp2;
    int i=0;
    for(i=4;i>=0;i--)
    	{
           snake->x=i;snake->y=0;
         if(i>0)  snake->next=(snake_t *)malloc(sizeof(snake_t));
         if(i>0)  snake=snake->next;
         }
    snake->next=NULL;
    while(head!=NULL)
    {
       temp2=head;
       head=head->next;
    }
    start(head2,temp2);
}
