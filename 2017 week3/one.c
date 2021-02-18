#include<stdio.h>
#include<stddef.h>
int main()
{   int hour3,day31;
   int day32=NULL;
   int a,b,c;
   int error=0;
   int hour2,day21;
   int day22=NULL;
    int day12=NULL;
   int hour1,day11;

   scanf("%d",&a);
   scanf("%d",&hour1);
       if(hour1==1)
       {    scanf("%d",&day11);
           if(day11==10||day11==20||day11==30||day11==40||day11==50) error=1;
           if(day11>59||day11<11) error=1;
       }
       else if(hour1==2)
        {    scanf("%d %d",&day11,&day12);
         if(day12==10||day12==20||day12==30||day12==40||day12==50) error=1;
       if(day12>59||day12<11) error=1;

       }
        else  {
            scanf("%d",&day11);
            error=1;
        }
//////////////////////////////////////////////



      scanf("%d",&b);
      scanf("%d",&hour2);
       if(hour2==1)
        {
        scanf("%d",&day21);
       if(day21==10||day21==20||day21==30||day21==40||day21==50) error=1;
       if(day21>59||day21<11) error=1;
       }
      else if(hour2==2)
        {
        scanf("%d %d",&day21,&day22);
            if(day21==10||day21==20||day21==30||day21==40||day21==50) error=1;
       if(day21>59||day21<11) error=1;
           if(day21==10||day21==20||day21==30||day21==40||day21==50) error=1;
       if(day21>59||day21<11) error=1;
           if(day22==10||day22==20||day22==30||day22==40||day22==50) error=1;
       if(day22>59||day22<11) error=1;
       }
        else  {
            scanf("%d",&day11);
            error=1;
        }

///////////////////////////////////////////////////
     scanf("%d",&c);
     scanf("%d",&hour3);
       if(hour3==1){
       scanf("%d",&day31);
        if(day31==10||day31==20||day31==30||day31==40||day31==50) error=1;//¨¾¤î¿é¤JÂ§«ô1~Â§«ô5«D1~9¸`
       if(day31>59||day31<11) error=1;//¨¾¤î¿é¤J«DÂ§«ô1~5
       }
       else if(hour3==2) {
        scanf("%d %d",&day31,&day32);
          if(day31==10||day31==20||day31==30||day31==40||day31==50) error=1;//¨¾¤î¿é¤JÂ§«ô1~Â§«ô5«D1~9¸`
       if(day31>59||day31<11) error=1;//¨¾¤î¿é¤J«DÂ§«ô1~5
         if(day32==10||day32==20||day32==30||day32==40||day32==50) error=1;
       if(day32>59||day32<11) error=1;
      }
        else  {
            scanf("%d",&day11);
            error=1;
        }
///////////////////////////////////////////////////////

    if (error!=1)
    {
    if(day11==day21 )  {printf("%d,%d,%d\n",a,b,day11); error=2;}
    if(day11==day22 )  {printf("%d,%d,%d\n",a,b,day11); error=2;}
    if(day12==day21 )  {printf("%d,%d,%d\n",a,b,day12); error=2;}
    if(day12==day22 )  {printf("%d,%d,%d\n",a,b,day12);error=2;}//
      if(day11==day31 )  {printf("%d,%d,%d\n",a,c,day11);error=2;}
    if(day11==day32 )  {printf("%d,%d,%d\n",a,c,day11);error=2;}
    if(day12==day31 )  {printf("%d,%d,%d\n",a,c,day12);error=2;}
    if(day12==day32 )  {printf("%d,%d,%d\n",a,c,day12);error=2;}

    if(day21==day31 )  {printf("%d,%d,%d\n",b,c,day21);error=2;}
    if(day21==day32 )  {printf("%d,%d,%d\n",b,c,day21);error=2;}
    if(day22==day31 )  {printf("%d,%d,%d\n",b,c,day22);error=2;}
    if(day22==day32 )  {printf("%d,%d,%d\n",b,c,day22);error=2;}//


    }
    if (error==2) printf("");
    else if (error==1) printf("-1");
    else  printf("correct");

}
