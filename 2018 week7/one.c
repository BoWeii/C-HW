#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct dnode_s { 
char name[10]; 
int old; 
int year; 
int month; 
int day; 
struct dnode_s* front; 
struct dnode_s* next; 
} dnode_t; 
void split(char *text,char *word[]){
    int i=0,num=0,check=0;
    for(i=0;text[i]!='\0';i++)
    {
        if(text[i]=='"'&&check%2==0) {check++;word[num++]=(&text[i])+1;continue;}
        if(text[i]=='"'&&check%2==1) { check++; word[num++]=&text[i+2];text[i++]='\0';continue;}
        if(text[i]==' '&&check%2==1) continue;
        if(text[i]==' '&&text[i+1]!='"') {text[i]='\0';word[num++]=&text[++i];}

    }

}
void add(char name[100],int old,int year,int month,int day,dnode_t **root,dnode_t **tail)
{
    dnode_t *temp=(dnode_t *)malloc(sizeof(dnode_t)),*temp2;
    strcpy(temp->name,name);temp->old=old;temp->year=year;temp->month=month;temp->day=day;temp->front=NULL;temp->next=NULL;
    if((*root)==NULL)
    {
    	(*root)=temp;(*tail)=temp; 
    }
    else 
    {
  		temp2=*tail;
  		temp->next=NULL;
 		temp->front=temp2;
  		temp2->next=temp;
  		*tail=temp;
    }
}
void insert(char name[100],int old,int year,int month,int day,dnode_t **root,dnode_t **tail,char des[100])
{
  //  printf("root=%s  tail=%s\n",(*root)->name,(*tail)->name );
	int check=0,one=0;
     dnode_t *temp=(dnode_t *)malloc(sizeof(dnode_t)),*temp2,*temp3=*root;
    strcpy(temp->name,name);temp->old=old;temp->year=year;temp->month=month;temp->day=day;temp->front=NULL;temp->next=NULL;
     if(*root==NULL) {(*root)=temp; (*tail)=temp; one=1;}
     else {while(temp3!=NULL)
     {
     	temp2=temp3;
     	temp3=temp3->next;
 	 	if(strcmp(temp2->name,des)==0&&temp3==NULL)
 	 	{
 	 		temp2->next=temp;
 	 		temp->front=temp2;
 	 		*tail=temp;check=1;
 	 		break;
 	 	}
     	else if(strcmp(temp2->name,des)==0)
     	{ // printf("insert success\n");
     		temp3->front=temp;
     		temp->next=temp3;
     		temp2->next=temp;
     		temp->front=temp2;check=1;
     		//*tail=temp;
     		break;
     	}
     }}
     if(check==0&&one==0) printf("name not found\n");

}
void delete(char name[100],dnode_t **root,dnode_t **tail)
{
    // printf("root=%s  tail=%s\n",(*root)->name,(*tail)->name );
     int check=0;
     dnode_t *temp,*temp3=*root,*temp2;
     if(*root==NULL) { }
     else 
     	{
     	while(temp3!=(NULL))
     {
     	//printf("every time=%s\n",temp3->name );
     	
     	if(strcmp(temp3->name,name)==0&&temp3->next==NULL&&temp3->front==NULL)
     	{
     		check=1;*root=NULL;*tail=NULL; break;
     	}
     	if(strcmp(temp3->name,name)==0)
     	{
     		if(temp3->next==NULL)
     		{
     			temp2=temp3->front;
     			temp2->next=NULL;
     			*tail=temp2;
     			free(temp3);
     			check=1;
     			break;
     		}
     		else if(temp3->front==NULL)
     		{
     			temp2=temp3->next;
     			temp2->front=NULL;
     			*root=temp2;
     			free(temp3);
     			check=1;
     			break;
     		}
     		else{
     		temp=temp3->front;
     		temp2=temp3->next;
     		temp->next=temp2;
     		temp2->front=temp;
     		free(temp3);
     		check=1;
     		break;}
     	}
     	temp3=temp3->next;

     }
 		}
     if(check==0) printf("name not found\n");

}
void pop(dnode_t **root,dnode_t **tail,int ins)
{
	if(*root==NULL) printf("The Stack is empty\n" );
	else
	{
	   	dnode_t *temp=*tail;
	   if(ins==1) printf("%s\n",temp->name );
	   else if(ins==2) printf("%d\n", temp->old);
	   else if(ins==3) printf("%d_%d_%d\n", temp->year,temp->month,temp->day);
	   if(temp->front!=NULL)*tail=(temp)->front;
	   else {*tail=NULL;*root=NULL;}
       free(temp);
	}
}
void dequeue(dnode_t **root,dnode_t **tail,int ins)
{
	if(*root==NULL) printf("The Queue is empty\n" );
	else
	{
	   	dnode_t *temp=*root;
	   if(ins==1) printf("%s\n",temp->name );
	   else if(ins==2) printf("%d\n", temp->old);
	   else if(ins==3) printf("%d_%d_%d\n", temp->year,temp->month,temp->day);
	  if(temp->next!=NULL) *root=(temp)->next;
      else {*root=NULL;*tail=NULL;} 
       free(temp);
	}
}
 void printflist(dnode_t **root,dnode_t **tail)
 {
 	
 //	printf("%s %s\n",(*root)->name,(*tail)->name );
 	
 	dnode_t *head=*root;
 	if(head==NULL) {printf("The List is empty \n"); }
    else 
    {
    	printf("list name output: \n");
 	while(head!=NULL)
 		{
 			printf("%s\n",head->name );
 			head=head->next;
 			//if(head==(*tail)) break;
 		}
    }
 }
int main()
{
	int mode=0,ins=0,old=0,year=0,month=0,day=0,ins2=0;
	dnode_t *root,*tail,*data=(dnode_t *)malloc(sizeof(dnode_t));
	 data->next=NULL;data->front=NULL; root=NULL;tail=NULL;
	char text[100],*word[100];

		scanf("%d",&mode);
   	   if(mode==1||mode==2)
    	{
          
          while(1)
          {
              scanf("%d",&ins);
              if(ins==1)
              {
              	 scanf(" ");
         		gets(text);
         		split(text,word);
              	old=atoi(word[1]);year=atoi(word[2]);month=atoi(word[3]);day=atoi(word[4]);
              	add(word[0],old,year,month,day,&root,&tail);
              	
              }
             else if(ins==2)
              {
              	scanf("%d",&ins2);
                 if(mode==1) pop(&root,&tail,ins2);
                 else if(mode==2) dequeue(&root,&tail,ins2);
              }
              else if(ins==3) break;

          }


   	 	}
   	  
   	  else if(mode==3)
    	{
          
          while(1)
          {
          	scanf("%d",&ins);
          	if(ins==1)
              {
              	 scanf(" ");
         		gets(text);
         		split(text,word);
              	old=atoi(word[1]);year=atoi(word[2]);month=atoi(word[3]);day=atoi(word[4]);
              	insert(word[0],old,year,month,day,&root,&tail,word[5]);
              	
              }
             else if(ins==2)
              {
              	scanf("%d",&ins2);
              	scanf(" ");
              	gets(text);
              	split(text,word);
              	delete(word[0],&root,&tail);
                
              }
              else if(ins==3) printflist(&root,&tail);
              else break;

          }


   	 	}	

}
