#include<stdio.h>

int main(){
char name[87];
int  num;
int  a,b,c;

scanf("%s",&name);
scanf("%d",&num);
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);

printf("\n");

printf("Name:%s\n",name);
printf("ID:%d\n",num);
printf("Average:%d\n",(a+b+c)/3 );
printf("Total:%d\n",a+b+c);
printf("\n");
return 0;
}
