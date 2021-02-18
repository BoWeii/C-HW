#include<stdio.h>
typedef struct
{
    char str[8];
    int x;
    int y;

} point;

point pt(int x,int y,int z)
{
    point p={x,z,y};
    return p;
}
int main()
{
  point a = {"abcdefg", 8 ,7};
  printf("%d,%d,%s",a.x,a.y,a.str);
}
