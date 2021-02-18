
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void build();
typedef struct node_s{
	char data;
	struct node_s *left,*right,*up;
}node_t;
node_t* generate (){return ((node_t*)malloc(sizeof(node_t)));}
void print(char *z,int type){
	int i=0,ii=0,k=0;
	for(;strlen((z+i*10))!=0;i++){
		if(type==1) printf("%s",(z+i*10));
		else{
			for(;*(z+i*10+ii)!='\0';ii++) k++;
			for(;k>=0;k--) if(*(z+i*10+k)!='\0')printf("%c",*(z+i*10+k));
			ii=k=0;
		}
	}
}
void left(char **root,char *child,node_t *current,int i,int type,char z[][10]){
	if(child[0]!='\0'){   
		char *temp=&z[i][0];
		current->left=generate();
		(*root)+=type;
		current->left->data=**root;
		//printf("Lda-%c-lev%d\n",current->left->data,i);
		while(isalpha(*temp)) temp++;
		*temp=**root;
		*(temp+1)='\0';
		build(root,child,current->left,i+1,type,z);
	}
}
void right(char **root,char *child,node_t *current,int i,int type,char z[][10]){
	if(child[0]!='\0'){
		char *temp=&z[i][0];
		current->right=generate();
		(*root)+=type;
		current->right->data=*(*root);
		//printf("Rda-%c-lev%d\n",current->right->data,i);
		while(isalpha(*temp)) temp++;
		*temp=**root;
		*(temp+1)='\0';
		build(root,child,current->right,i+1,type,z);
	}
}
void build(char **root,char *child,node_t *current,int i,int type,char z[][10]){ //child中序，root前後序
	//printf("%c,%s,lev-%d\n",**root,child,i);
	char *temp=child,s[50]="\0",s1[50]="\0",*str=s,*str1=s1;
	for(;*temp!=**root && *temp!='\0';temp++);//找根
	//----複製左type=1,右type=-1------
	for(;*child!=*temp;child++)
		*(str++)=*child;
	*str='\0';
	//-----複製右type=1,左type=-1------
	for(child++; *child!='\0';child++)
		*(str1++)=*child;
	*str1='\0';
	if(type==1){
		left(root,s,current,i,type,z);
		right(root,s1,current,i,type,z);
	}
	else{
		right(root,s1,current,i,type,z);
		left(root,s,current,i,type,z);
	}
}
int main(){
	int i=0;
	char type,In[50],Post[50]="\0",Pre[50]="\0",*root,z[10][10]={'\0'};
	node_t *top=generate();
	for(i=0;i<2;i++){
		scanf("%c\n",&type);
		switch(type){
			case 'P':
				gets(Pre);
				root=&Pre[0];
				break;
			case 'I':
				gets(In);
				break;
			case 'O':
				gets(Post);
				root=&Post[strlen(Post)-1];
				break;
		}
	}
	if(Post[0]!='\0'){
		top->data=Post[strlen(Post)-1];
		z[0][0]=*root;z[0][1]='\0';
		build(&root,In,top,1,-1,z);
		print((char*)z,-1);
	}
	else{
		top->data=Pre[0];
		z[0][0]=*root;z[0][1]='\0';
		build(&root,In,top,1,1,z);
		print((char*)z,1);
	}
}
/*建構唯一二元樹 

給定(1)中序，(2) 前序或後序，產生唯一個Binary Tree，依序印出Tree的內容，印出順序，Tree元素由上而下，由左而右印出。 

假設一二元樹如下圖 
A 
B C 
D E F G 
(A為根節點，B為A之左子樹，C為A之右子樹) 

前序(Pre-order)： 
1.訪問根節點 
2.訪問左子樹 
3.訪問右子樹 
上圖的走訪順序為：ABDECFG 

中序(In-order)： 
1.訪問左子樹 
2.訪問根節點 
3.訪問右子樹 
上圖的走訪順序為：DBEAFCG 

後序(Post-order)： 
1.訪問左子樹 
2.訪問右子數 
3.訪問根節點 
上圖的走訪順序為：DEBFGCA 

前序代碼：P 

中序代碼：I 

後序代碼：O 


*每次輸入一定有一個是中序。(中序搭配前序，或是中序搭配後序，不會有前序搭配後序) 
-------------- 
輸入說明 

第一筆輸入前序、中序或後序代碼。 
第二筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。 
第三筆輸入前序、中序或後序代碼。 
第四筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。 

------------- 
輸出說明 

輸出唯一二元樹的內容，由上而下，由左而右。 


------------- 
Sample input 
 
P         
ABCDEFGHI  
I 
BCAEDGHFI 

O
CBEHGIFDA
I
BCAEDGHFI

-------------- 
Sample output 

ABDCEFGIH*/