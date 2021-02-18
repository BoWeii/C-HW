#include<stdio.h>
int main()
{
    char ori[100]={'\0'};
    char pos[100]={'\0'};
    scanf("%s",ori);
    z(ori,pos);
    int i=0;
    for(i=0;pos[i]!='\0';i++)
    {
        printf("%c",pos[i]);
    }
}
int p(char a)
{
    int re;
    if(a=='^') re=3;
   else if(a=='*'||a=='/') re=2;
   else  if(a=='+'||a=='-') re=1;
   else re=0;
    return re;
}
int z(char *ori,char *pos)
{
    int i=0,ii=0,top=0;
    char stack[100]={'\0'};
    for(i=0;ori[i]!='\0';i++)
    {
        if(ori[i]=='(')
        {
            stack[++top]=ori[i];
        }
        else if(ori[i]=='+'||ori[i]=='-'||ori[i]=='*'||ori[i]=='/'||ori[i]=='^')
        {   while(p(stack[top])>p(ori[i]))
              {
                  pos[ii++]=stack[top--];
              }
            stack[++top]=ori[i];
        }
        else if(ori[i]==')')
        {
            while(stack[top]!='(')
            {
                pos[ii++]=stack[top--];
            }
            top--;
        }
        else
        {
            pos[ii++]=ori[i];
        }
    }

    while(top>0)
    {
        pos[ii++]=stack[top--];
        //printf("yee");
    }
}

