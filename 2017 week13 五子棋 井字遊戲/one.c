#include<stdio.h>
int main()
{
int a[10][10]={0},i=0,ii=0;
int b[10][10]={0},m=0;
for(i=0;i<=9;i++)
{
    for(ii=0;ii<=9;ii++)
    {
        scanf(" %d",&a[ii][i]);
        b[ii][i]=a[ii][i];
    }
}
printf("\n");
for(i=0;i<=9;i++)
{
    for(ii=0;ii<=9;ii++)

    {
        if(a[ii][i]==0)
        {   //printf("i=%d ii=%d\n",ii,i);
            m=judge(a,ii,i);
            if(m==1)  a[ii][i]=8;

        }

    }
}
/*for(i=0;i<=9;i++)
{
    for(ii=0;ii<=9;ii++)
    {
        if(a[ii][i]-b[ii][i]!=0) printf("%d %d\n",i,ii);
    }
}*/

/*for(i=0;i<=9;i++)
{
    for(ii=0;ii<=9;ii++)
    {
        printf("%d ",a[ii][i]);
    }
    printf("\n");
}*/



}
int judge(int *aa,int i,int ii)
{
    int (*a)[10]=aa,re=0;
    int ic=i,iic=ii;
    int manyleft=0,manyright=0;
    int manytop=0,manydown=0;
    int manyrt=0,manyld=0;
    int manyrd=0,manylt=0;
 ///////////橫///////////
 if(i!=9){while(a[ic+1][iic]==1)//->
 {
   //  printf("right %d---%d\n",ic+1,iic);
     ic++;
     manyright++;
     if(manyright==4) break;
 }}
 if(manyright>=4) re=1;
 ic=i;iic=ii;
 if(i!=0){while(a[ic-1][iic]==1)//<-
 { // printf("lefy %d---%d\n",ic-1,iic);
     ic--;
     manyleft++;
    if(manyleft==4) break;
 }}
 if(manyleft==4) re=1;
 if(manyleft+manyright==4&&manyleft+manyright<=5) re=1;
ic=i;iic=ii;
 ////////直///////////
 if(ii!=0){while(a[ic][iic-1]==1)//^
 { // printf("top %d---%d\n",ic,iic-1);
     iic--;
     manytop++;
   if(manytop==4) break;
 }}
 if(manytop==4) re=1;
 ic=i;iic=ii;
 if(ii!=9){while(a[ic][iic+1]==1)//v
 { // printf("down %d---%d\n",ic,iic+1);
     iic++;
     manydown++;
    if(manydown==4) break;
 }}
 if(manydown==4) re=1;
 if(manydown+manytop>=4&&manydown+manytop<=5) re=1;
  ic=i;iic=ii;
 //////////右上rt左下ld///////////
 if(ii!=0&&i!=9){while(a[ic+1][iic-1]==1)//  ^
 {  // printf("rt  %d---%d\n",ic+1,iic-1);                 // /
     ic++;
     iic--;
     manyrt++;
    if(manyrt==4) break;
 }}
 if(manyrt==4) re=1;
 ic=i;iic=ii;
 if(ii!=9&&i!=0){while(a[ic-1][iic+1]==1)//  /
 { //printf("ld  %d---%d\n",ic-1,iic+1);                      // v
    ic--;
    iic++;
     manyld++;
   if(manyld==4) break;
 }}
 if(manyld==4) re=1;
 if(manyld+manyrt>=4&&manyld+manyrt<=5) re=1;
  ic=i;iic=ii;
 /////////左上lt右下rd////////////
if(i!=0&&ii!=0){while(a[ic-1][iic-1]==1)//  ^
 {                       //
  //printf("lt %d---%d\n",ic-1,iic-1);
     ic--;
     iic--;
     manylt++;
   if(manylt==4) break;
 }}
 if(manylt==4) re=1;
 ic=i;iic=ii;
 if(i!=9&&ii!=9){while(a[ic+1][iic+1]==1)//  \
                        //   v
 { //printf("rd  %d---%d\n",ic+1,iic+1);
    ic++;
    iic++;
     manyrd++;
  if(manyrd==4) break;
 }}
 if(manyrd==4) re=1;
 if(manyrd+manylt>=4&&manyrd+manylt<=5) re=1;
  ic=i;iic=ii;
 ////////ok/////
 if(re==1) printf("%d %d\n",ii,i);
 return re;
}



