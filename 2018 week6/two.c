#include<stdio.h>
#include<stdlib.h>
typedef struct {
int id;//學號
int score;//分數
} student_t;

typedef struct node_s {
student_t man;
struct node_s *next;
} node_t;

void printList(node_t *data)
{
   int co=0;
   if(data==NULL) printf("null\n");
   else
   {
      while(data!=NULL)
     {
      if(co==0) {printf("%d,%d",data->man.id,data->man.score);co++;}
     else  printf(",%d,%d",data->man.id,data->man.score);
      data=data->next;
     }
     printf("\n");
   }
}
node_t *insert(node_t *data,student_t student )
{
   node_t *head=data,*temp=(node_t *)malloc(sizeof(node_t));
   temp->man=student;temp->next=NULL;
   if(data==NULL) {return temp;}
   else
   {
      if(((data->man.score)>temp->man.score)||((data->man.score==temp->man.score)&&(data->man.id)>temp->man.id))//分數比開頭低or分數跟開頭相同但學號低
      {
         temp->next=data;
         return temp;
      }

      else//分數等同於開頭或大於
      {
         while(data->next!=NULL)
         {
             if(data->man.score == temp->man.score&&temp->man.score == data->next->man.score&&data->man.id < temp->man.id&&data->next->man.id > temp->man.id)//分數相同但學號介在節點前後中間
            {
               temp->next=data->next;data->next=temp;
               return head;
            }
            else if(data->man.score!=temp->man.score&&data->next->man.score==temp->man.score&&data->next->man.id>temp->man.id)//介在分數不同之間
            {
               temp->next=data->next;data->next=temp;
               return head;
            }
           data=data->next;
         }
         data->next=temp;
         return head;
      }
   }

}
node_t* deletes(node_t *data,int id)
{
   node_t *temp=(node_t *)malloc(sizeof(node_t)),*head=data,*bye;
   while(data!=NULL)
     {

         if(head->man.id==id)
         {
            temp=head->next;
            free(head);
            return temp;
         }
         if(data->next!=NULL&&data->next->man.id==id)
         {
            temp=data->next;
            temp=temp->next;
            bye=data->next;
            data->next=temp;
            free(bye);
            return head;
         }
         data=data->next;
     }
     return head;
}
int main()
{
   node_t *data=(node_t *)malloc(sizeof(node_t)); data=NULL;
   char inpu;
   int id=0,score=0;
   student_t student;
   while(1)
   {
      scanf(" %c",&inpu);
      if(inpu=='i')
      {
         scanf("%d,%d",&student.id,&student.score);

         data=insert(data,student);
      }
      else if(inpu=='p') printList(data);
      else if(inpu=='d')
      {
         scanf("%d",&student.id);
         data=deletes(data,student.id);
      }
      else if(inpu=='e') break;

   }
}
