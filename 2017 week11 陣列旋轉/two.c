#include<stdio.h>
int main()
{
    int a[20]={{NULL}};
    int b[20]={{NULL}};
    int n[20]={{NULL}};
    int u[20]={{NULL}};
    int times3=0,flag=0,error=-1,c=0,posbn=0,cmd=0,component=0,times=0,posa=0,posb=0,times2=0,thesamea=0,thesameb=0;
    scanf(" %d",&cmd);
    while(cmd!=0)
    {
       if(cmd<7&&cmd>2) scanf(" %d",&component);
       if(cmd==1)
        {
            for(times=0;times<20;times++)
            {
                a[times]=0;
            }
            printf("A:[");
            for(times=0;times<=posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<=posb;times++)
            {
               if(b[times]==0) continue;
                else printf("%d,",b[times]);
            }
            printf("]\n");
           // printf("%d",posb);
        }
        else if(cmd==2)
        {
            for(times=0;times<20;times++)
            {
                b[times]=0;
            }
             printf("A:[");
            for(times=0;times<posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<posb;times++)
            {
               if(b[times]==0) continue;
                else printf("%d,",b[times]);
            }
            printf("]\n");
        }
        else if(cmd==3)
        {
            for(times=0;times<=posa;times++)
            {
                if(a[times]==component)
                {
                    thesamea=1;
                  break;
                }

            }
            if(thesamea==0)
            {
                a[posa]=component;
               //  printf("posa=%d\posb=%d\n",posa,posb);
                posa++;
            }

              printf("A:[");
            for(times=0;times<=posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<=posb;times++)
            {
                if(b[times]==0) continue;
                else printf("%d,",b[times]);
            }
            printf("]\n");
            thesamea=0;
        }
         else if(cmd==4)/////////////////////////////////
        {
            for(times=0;times<=posb;times++)
            {
                if(b[times]==component)
                {
                    thesameb=1;
                  break;
                }

            }
            if(thesameb==0)
            {
                b[posb]=component;
               //  printf("posa=%d\posb=%d\n",posa,posb);
                posb++;
              //  printf("posb==%d\n",posb);
            }

              printf("A:[");
            for(times=0;times<=posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<=posb;times++)
            {
                if(b[times]==0) continue;
                else printf("%d,",b[times]);
            }
            printf("]\n");
            thesameb=0;

        }
        else if(cmd==5)
        {
            for(times=0;times<=posa;times++)
            {
                if(a[times]==component) a[times]=0;
            }
              printf("A:[");
            for(times=0;times<=posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<=posb;times++)
            {
                if(b[times]==0) continue;
                else printf("%d,",b[times]);;
            }
            printf("]\n");
        }
        else if(cmd==6)
        {
            for(times=0;times<=posb;times++)
            {
                if(b[times]==component) b[times]=0;
            }
              printf("A:[");
            for(times=0;times<=posa;times++)
            {
                if(a[times]==0) continue;
                else printf("%d,",a[times]);
            }
            printf("]");
            printf("B:[");
            for(times=0;times<posb;times++)
            {
                if(b[times]==0) continue;
                printf("%d,",b[times]);
            }
            printf("]\n");
        }
        else if(cmd==8)
        {  //printf("posa=%d\posb=%d\n",posa,posb);
           if(posa>=posb)
           {   printf("[");
               for(times=0;times<=posb;times++)
               {  //printf("times=%d\n",times);
                   if(b[times]!=0)
                  {

                   for(times2=0;times2<=posa;times2++)
                   {
                       if(b[times]==a[times2])
                      {
                         if(b[times]!=0&&a[times2]!=0)
                         {
                           printf("%d,",a[times2]);
                         }
                       if(b[times]==0) continue;
                      }
                    }
                  }
               }
               printf("]\n");
           }
           else if(posa<posb)
           {
              printf("[");
               for(times=0;times<=posa;times++)
               {  //printf("times=%d\n",times);
                   if(a[times]!=0)
                  {

                   for(times2=0;times2<=posb;times2++)
                   {
                       if(a[times]==b[times2])
                      {
                         if(b[times2]!=0&&a[times]!=0)
                         {
                           printf("%d,",b[times2]);
                         }
                       if(b[times2]==0) continue;
                      }
                    }
                  }
               }
               printf("]\n");
           }
           }


        else if(cmd==7)
        {   flag=0;
            posbn=posb;
            printf("[");
              for(times=0;times<=posa;times++)
              {
                  if(a[times]==0) continue;
                  else printf("%d,",a[times]);
              }
              //////////////////////////////////////
              for(times=0;times<=posb;times++)
              {
                  for(times2=0;times2<=posa;times2++)
                  {                    //5
                      if(a[times2]==b[times])
                      {flag=1;
                        break;
                      }

                   }
                   if(flag==0)
                      {
                          if(b[times]!=0) printf("%d,",b[times]);
                          else continue;
                      }

                   flag=0;
              }


              printf("]\n");
         }
         else if(cmd==9)////
         {  //printf("posb==%d\n",posb);

                 for(times=0;times<=posa;times++)
                 {
                     error=-1;
                     c=0;
                     times3=0;
                     if(a[times]!=0)
                     {  // printf("a[times]=%d\n",a[times]);
                         for(times2=0;times2<=posb;times2++)
                     {

                         if(b[times2]==0) continue;
                         else
                         {   times3++;
                              if(b[times2]==a[times])
                             {
                              //  printf("break a=%d\n",a[times]);
                               // printf("break b=%d\n",b[times2]);

                                continue;
                             }
                           c++;
                         //  printf("a=%d\n",a[times]);
                         //  printf("b=%d\n",b[times2]);
                         //  printf("c=%d  times3=%d\n",c,times3);

                         }
                     }
                      if(c==times3)
                            {  // printf("error=1\n");
                                error=1;
                            }
                            else
                            {  // printf("error=-1\n");
                                error=-1;
                            }
                    // printf("c=%d  times 3 =%d\n",c,times3);
                     c=0;
                     times3=0;
                     if(error==1)
                     {
                        // printf("a[times]=%d b[times2]=%d \n",a[times],b[times2]);
                         printf("0\n");
                         break;

                     }
                 }
                 }
                 if(error==-1) printf("1\n");

       }

       scanf("%d",&cmd);
    }
    return 0;
}
