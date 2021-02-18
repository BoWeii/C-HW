#include<stdio.h>
int main()
{
int x,y,times,i,ii,times2,rottatetimes=0,rottatetotal=0,test2=0,test,error=0;
scanf(" %d %d",&x,&y);
times=x;times2=y;
int input;
test=x*y;
char aray[x][y];
char aray2[x][y];
for(i=0;i<times;i++)
{
       scanf(" %s",&aray[i]);
    // printf("%s",aray[i]);
     //aray2[i][0]=aray[i];
}

for(i = 0; i < times; i++)
{
    if(aray[i][y-1]>'9'||aray[i][y-1]<'0')
    {
        printf("i=%d\n",i);
        printf("%ctest\n",aray[i][y]);
        error=1;
        break;
    }
}
char *arayy=aray,*arayy2=aray2;
for(i = 0; i < times; i++)
{
    for(ii = 0; ii < times2; ii++)
    {
        //printf("%c",aray[i][ii]);
        aray2[i][ii]=aray[i][ii];
        //printf("%c",aray2[i][ii]);
    }
    printf("\n");
}
if(error==1)
{
    printf("E");
    return 0;
}
else if(error==0)
{scanf("%d",&rottatetimes);
while(rottatetimes>0)
{
      if(rottatetimes%10==2)
      {
          rottatetotal=rottatetotal+3;
      }

      else if(rottatetimes%10==1)
      {
          rottatetotal=rottatetotal+1;
      }
      else if(rottatetimes%10==3)
      {
          rottatetotal=rottatetotal+2;
      }
      rottatetimes/=10;
}
rottatetotal=rottatetotal%4;
rottate(aray,aray2,times2,rottatetotal,x,y);
}
}

void rottate(char *arayy,char *arayy2, int size,int which,int x,int y)
{   int i=0,ii=0,xx=x,yy=y;
    char (*array)[size] = arayy;
    char (*array2)[size] = arayy2;
    //printf(" %c ", array[1][1]);
    if(which==0)
    {
       for(i = 0; i < xx; i++)
       {
          for(ii = 0; ii < yy; ii++)
         {
            printf("%c",array[i][ii]);
         }
            printf("\n");
        }
    }
    if(which==1)
    {  char newaray[y][x];

     for(i=0;i<xx;i++)
     {
         for(ii=0;ii<yy;ii++)
         {
             newaray[ii][x-1]=array2[i][ii];

         }
         x--;
     }
        for(i = 0; i < yy; i++)
       {
          for(ii = 0; ii < xx; ii++)
         {
            printf("%c",newaray[i][ii]);
         }
            printf("\n");
        }
    }

    else if(which==3)
    {   printf("which=%d\n",which);
        char newaray[y][x];

      for(i=0;i<xx;i++)
     {  y=yy-1;
         for(ii=0;ii<yy;ii++)
         {
             newaray[y][i]=array2[i][ii];
              y--;
         }
        ;
     }
        for(i = 0; i < yy; i++)
       {
          for(ii = 0; ii < xx; ii++)
         {
            printf("%c",newaray[i][ii]);
         }
            printf("\n");
        }

    }
    else if(which==2)
    {   x=xx-1;
         for(i=0;i<xx;i++)
     {  y=yy-1;

         for(ii=0;ii<yy;ii++)
         {
             array[x][y]=array2[i][ii];
              y--;

         }
        x--;
     }
        for(i = 0; i < xx; i++)
       {
          for(ii = 0; ii < yy; ii++)
         {
            printf("%c",array[i][ii]);
         }
            printf("\n");
        }

    }

}


