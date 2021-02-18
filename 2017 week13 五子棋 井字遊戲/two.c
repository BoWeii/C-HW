#include<stdio.h>
int main()
{   int term=-1,i=0,ii=0,flag=0;
    int check[3][3]={0};
    char spe;
    scanf(" %d",&term);

   while(1)
   {  scanf(" %c",&spe);
      if((int)spe==119)  ///w
       {
           for(i=0;i<=2;i++)
            {
                 for(ii=0;ii<=2;ii++)
                {
                  if(check[i][ii]==0)
                  {
                    check[i][ii]=3;
                    if(judge(check)==3)
                        {
                            printf("Computer will win with (%d, %d)\n",i,ii);
                           flag=1;
                        }
                    check[i][ii]=0;
                  }
                }
            }
          if(flag==0) printf("no\n");
             flag=0;
       }

       else if((int)spe==100) ///d
       {
             for(i=0;i<=2;i++)
            {
                 for(ii=0;ii<=2;ii++)
                {
                  if(check[i][ii]==0)
                  {

                    check[i][ii]=10;
                    if(judge(check)==10)
                    {
                        printf("Player will win with (%d, %d)\n",i,ii);
                       flag=1;
                    }
                    check[i][ii]=0;
                  }
                }
            }
            for(i=0;i<=2;i++)
            {
                 for(ii=0;ii<=2;ii++)
                {
                  if(check[i][ii]==0)
                  {
                    check[i][ii]=3;
                    if(judge(check)==3)
                    {
                        printf("Computer will win with (%d, %d)\n",i,ii);
                         flag=1;
                    }

                    check[i][ii]=0;
                  }
                }
            }
             if(flag==0) printf("no\n");
             flag=0;
       }

       else
      {

          if(term==1)//computer  value=3
          {
              i=(int)spe-48;
              scanf(" %d",&ii);
              if(check[i][ii]!=0) printf("input error\n");
              else
                {
                    check[i][ii]=3;
                     term--;
                }
          }
          else if(term==0)//player  value=10
          {
              i=(int)spe-48;
              scanf(" %d",&ii);
             if(check[i][ii]!=0) printf("input error\n");
             else
                {
                    check[i][ii]=10;
                     term++;
                }
          }
      }
       if(judge(check)==3)
       {
           printf("Computer win");
           return 0;
       }
       else if(judge(check)==10)
       {
           printf("Player win");
           return 0;
       }
       else if(judge(check)==87)
       {
           printf("fair");
           return 0;
       }
   }

}
int judge(int *c)
{   int re=0;
    int (*check)[3]=c;
    int i=0,ii=0,t=0;
    for(i=0;i<=2;i++)
    {  t=0;
        for(ii=0;ii<=2;ii++)
        {
          t+=check[i][ii];
        }
     //   printf("- no.%d=%d\n",i,t);
        if(t==9)
       {
        re=3;
      //  printf(" 3 - der\n");
        return re;
       }
       else if(t==30)
       {
        re=10;
       //   printf(" 10 - der\n");
        return re;
       }
    }

     for(i=0;i<=2;i++)
    {   t=0;
        for(ii=0;ii<=2;ii++)
        {
          t+=check[ii][i];
        }
      //  printf("| no.%d=%d\n",i,t);
        if(t==9)
      {
        re=3;
       // printf(" 3 | der\n");
        return re;
       }
      else if(t==30)
      {
        re=10;
        // printf(" 10 | der\n");
        return re;
       }
    }
   // printf(" \ der %d\n",check[0][0]+check[1][1]+check[2][2]);
    if(check[0][0]+check[1][1]+check[2][2]==9) ///  "\"   //////
    {
         re=3;
         printf("3 \ der\n");
         return re;
    }
    else if(check[0][0]+check[1][1]+check[2][2]==30)
    {
        re=10;
       //   printf(" 10 \ der\n");
        return re;
    }
  //  printf(" / der %d\n",check[0][2]+check[1][1]+check[2][0]);
     if(check[0][2]+check[1][1]+check[2][0]==9) ///  "/"   //////
    {
         re=3;
        // printf("3 / der\n");
         return re;
    }
    else if(check[0][2]+check[1][1]+check[2][0]==30)
    {
        re=10;
       // printf("10 / der\n");
        return re;
    }
    t=0;
 for(i=0;i<=2;i++)
 {
     for(ii=0;ii<=2;ii++)
     {
        t+=check[i][ii];
     }
 }
 if(t==55||t==62)
 {
     re=87;
     return 87;
 }
 return re;

}







