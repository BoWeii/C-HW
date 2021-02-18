#include<stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
} point;

point pt(int x,int y)
{
    point p={x,y};
    return p;
}

int search(int *mmap,int size,point start,point end)
{
      int (*map)[size]=mmap;
      if(map[start.x][start.y]==0)
      {
          map[start.x][start.y1]=2;
          if(!map[end.x][end.y] &&
            !(search(map,size,pt(start.x, start.y + 1), end) ||
              search(map,size,pt(start.x + 1, start.y), end) ||
              search(map,size, pt(start.x, start.y - 1), end) ||
              search(map,size, pt(start.x - 1, start.y), end))) {
                 map[start.x][start.y] = 0;
         }
    }
   return map[end.x][end.y];
}
int main()
{
    int n,m;
    scanf(" %d %d",&n,&m);
    int map[n][m];
    int i=0,ii=0;
    for(i=0;i<n;i++)
        {
            for(ii=0;ii<m;ii++)
             {
               scanf("%d",&map[i][ii]);
             }
        }
        search(map,m,pt(0,1),pt(n-2,m-1));
//printf("\n");
    i=0;ii=1;
    if(map[i][ii]==2)
     {  while(!((ii==m-1)&&(i==n-2)))
     {
        // printf("%d %d\n", i, ii);
        if(map[i-1][ii]==2)
        {   map[i][ii]=3;
            i--;printf("u");
        }
         else if(map[i][ii+1]==2)
        {   map[i][ii]=3;
            ii++;printf("r");
        }
        else if(map[i+1][ii]==2)
        {   map[i][ii]=3;
            i++;printf("d");
        }
         else if(map[i][ii-1]==2)
        {   map[i][ii]=3;
            ii--;printf("l");
        }
    }
   return 0;
   }


}






























