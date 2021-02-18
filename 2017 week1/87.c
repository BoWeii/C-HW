#include<stdio.h>

int main(){

char man;
char ar;
char ex;

while(1)
{
    printf("boy?( y/n)");
man=getche();
printf("\n");
if(man=='y')
{
    printf("§L§Ð?(y/n)");
    ar=getche();
    printf("\n");
    if(ar=='y')
        printf("yes \n");
    else
        printf("no \n");
}
else printf("girl two years ex? (y/n)");
ex=getche();
printf("\n");
if(ex=='y')
    printf("y\n");
else printf("no\n");
}

}
