#include<stdio.h>
int yee(int x,int y)
{    int re;
     re=y-x;
     return re;
}
int main()
{ int times,x,y;
  int a=1; int b;int c=1;int total=0; int superimpose; int x1=-1;int y1=-1;
  scanf("%d",&times);
  if(times>0)
  {for(a;a<=times;a++)
  {
      scanf("%d",&b);
      if(b>=5000||b<=0)
      {printf("E\n");
      return 0;
      }
      else{
      for(c;c<=b;c++)
      {

          int superimpose=0;
          int dis=0;
          scanf(" %d %d",&x,&y);
          if(x>6000||y>6000||x<0||y<0)
          {printf("E\n");
            return 0;
          }
          else if(x>y)
          {printf("E\n");
            return 0;
          }
          else{
          dis=yee(x,y);
          if(y1>x&&y>y1) superimpose=x-y1; //-----
                                          //   ------
          else if(x<y1&&y<=y1) dis=0;  //------------
                                     //    ---
          total=total+dis+superimpose;
          x1=x; y1=y;
            }
      }
      c=1;
      printf("%d\n",total);
      total=0;
      x1=-1;y1=-1;
      }
  }
  }
  else printf("E\n");
  return 0;
}
