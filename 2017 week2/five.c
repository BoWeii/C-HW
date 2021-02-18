#include<stdio.h>
int main()
{
  int wi,wo,ho,it,ot;
  float ts,tm,tl;
  float re,be;
  scanf("%d%d%d%d%d",&wi,&wo,&ho,&it,&ot);
  ts=wi*0.08+wo*0.139+ho*0.135+it*1.128+ot*1.483;
  tm=wi*0.07+wo*0.13+ho*0.121+it*1.128+ot*1.483;
  tl=wi*0.06+wo*0.108+ho*0.101+it*1.128+ot*1.483;
  if(ts<183) ts=183;
  if(tm<383  ) tm=383;
  if(tl<983) tl=983;
  if(tm>ts&&tl>ts) re=ts;
  else if(tl>tm&&ts>tm) re=tm;
  else if(ts>tl&&tm>tl) re=tl;
if(re<383) be=183;
if(re>=383&&re<983) be=383;23
if(re>=983) be=983;
  printf("%.0f\n%.0f",re,be);





return 0;
}
