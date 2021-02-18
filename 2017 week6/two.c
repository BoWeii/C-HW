#include<stdio.h>
#include <ctype.h>
#include <string.h>

void jud(float i1,float i2,float i3,float i4)
{   float i5=0;
    if(i2-i1==i3-i2 && i3-i2==i4-i3 && i2-i1==i4-i3)
    {
        i5=i4+(i4-i3);
        printf("%.0f %.0f %.0f %.0f %.0f\n", i1, i2, i3, i4, i5);
    }
    else if(i2/i1==i3/i2 && i3/i2==i4/i3  && i2/i1==i4/i3)
    {
        i5=i4*(i4/i3);
        printf("%.0f %.0f %.0f %.0f %.0f\n", i1, i2, i3, i4, i5);
    }
    else
        printf("E");


}

int main()
{
    //float a,b,c,d;
    char strNum[4][256] = { 0 };
    int num[4] = { 0 };
    int t;float e;
    scanf("%d",&t);
    int i = 0;
    int j = 0;
   if(1<=t&&t<=20)
    {
        for(j; j < t; j++)
        {
            //scanf("%f %f %f %f",&a,&b,&c,&d);
            for(i = 0; i < 4; i++)
            {
                scanf(" %s", &strNum[i]);

                int k = 0;
                for(k; k < strlen(strNum[i]); k++)
                {
                    if(strNum[i][k]<'0' || strNum[i][k]>'9')
                    {
                        printf("E");
                        return 0;
                    }
                }



                /*
                if( 1 > num[i] || num[i] > 20)
                {
                    printf("E");
                    return 0;
                }
                */
            }
           // printf("%f\n", (float)num[0] / (float)num[1]);
           // jud((float)num[0],(float)num[1],(float)num[2],(float)num[3]);
        }
    }
    else printf("E");
    return 0;

}
