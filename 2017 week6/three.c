#include<stdio.h>
#include<math.h>

void fuck(int a);

void JUDGE(int x,int y)
{
    int PowTimes=0;
    int tempt=x;
    for(x;x<=y;x*=tempt)
    {
        PowTimes=PowTimes+1;
    }
    int z=0;
    int q;
    int powsubtract;
    double powvalue;
    //printf("%d",PowTimes);
    for(z;z<=PowTimes;z++)
    {
        powsubtract=PowTimes-z;

        powvalue=pow(tempt,powsubtract);
        //printf("yee pow(%d, %d) = %f\n", tempt, powsubtract, powvalue);
        //printf("yee %d / %d = %d\n", y, powvalue, y/powvalue);
        q=y/powvalue;//q=商
        y=y%(int)powvalue;//y=餘式
        fuck(q);
       //檢測值 printf("%d %d %d\n",q,powvalue,fk);



    }
}
void fuck(int a)
{
    switch(a)
        {
        case 10:
        printf("A");
        break;
        case 11:
        printf("B");
        break;
        case 12:
        printf("C");
        break;
        case 13:
        printf("D");
        break;
        case 14:
        printf("E");
        break;
        case 15:
        printf("F");
        default :  printf("%d",a);
        break;
        }
}

int main()
{
    int a,b;
    scanf(" %d %d",&a,&b);
    if(a>16||a<2) printf("E");//E表示錯誤輸入
    else JUDGE(a,b);

    return 0;
}
