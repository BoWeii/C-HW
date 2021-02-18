#include<stdio.h>
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
      printf("%d %d\n", start.x, start.y);
      if(map[start.x][start.y]==0)
      {
          map[start.x][start.y]=2;
          if(start.x==end.x&&start.y==end.y)
          {
              return 3;
          }

          if(search(map,size,pt(start.x,start.y+1),end)==3
             )
            return 3;
          if(search(map,size,pt(start.x+1,start.y),end)==3)
            return 3;
           if(search(map,size,pt(start.x,start.y-1),end)==3)
            return 3;
        if(search(map,size,pt(start.x-1,start.y),end)==3)
            return 3;
        map[start.x][start.y]=0;
                 return -1;
  }
   return map[start.x][start.y];
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
printf("\n");
   for(i=0;i<n;i++)
        {
            for(ii=0;ii<m;ii++)
             {
               printf("%d ",map[i][ii]);
             }
             printf("\n");
        }

}
































