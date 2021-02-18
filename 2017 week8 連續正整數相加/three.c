#include<stdio.h>
int main()
{
    float  cost=0,own=0,alev=0,nev=0,sent=0; int error=0,a=1;
    scanf("%f %f %f",&cost,&own,&nev);
    if(cost<0&&cost>-100&&own>=0&&own<=30000&&nev>=0&&nev<=10000&&(int)nev==nev)
    {
        while(-cost<own)
        {
            if(nev>0)
            {own=own+cost;//進化
            own+=1.5;//進化德水
            nev--;alev++;own+=1.5;
            if((own+nev*1.5<-cost)&&own<-cost)
                break;//全部未進化傳送也不購
             else if(-cost>own)//可犧牲未進化
            {   //printf("in side");
                while((a*1.5+own<=-cost)&&a<nev)
                {
                    a++;
                }
                own=a*1.5+own;
                nev=nev-a;
            }
            }
        }
         printf("%d",(int)alev);
    }
    else printf("E");


}
