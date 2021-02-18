#include<stdio.h>
#include <graphics.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define  amount  100
typedef struct
{
   int x,y;
}location;
typedef struct
{
   char name[100];
   int dis;
}_weapon;
typedef struct
{
   int name;
   int hp;
   int atk;
   location l;

}_monster;
typedef struct
{
   int hp;
   int atk;
   location l;
   _weapon w;
   int (*kill) (_monster *);
}_soldier;

void sort(_monster monster[],int *index)
{
   int i=0,ii=0;
   _monster temp;
   for(i=0;i<(*index);i++)
   {
      for(ii=i+1;ii<(*index);ii++)
      {
         if(monster[i].name>monster[ii].name)
         {
            temp=monster[i];
            monster[i]=monster[ii];
            monster[ii]=temp;
         }
      }
   }
}
int checkposition(_soldier *soldier,_monster monster[],int *monsterIndex)
{
   int i=0;
   for(i=0;i<*monsterIndex;i++)
   {
      if((*soldier).hp>0)
      {
       if((*soldier).l.x==monster[i].l.x&&(*soldier).l.y==monster[i].l.y) return 1;
       }
   }
   for(i=0;i<*monsterIndex;i++)
   {
      if(monster[i].l.x==monster[*monsterIndex].l.x&&monster[i].l.y==monster[*monsterIndex].l.y) return 1;
   }
   return 0;
}
void creat(_soldier *soldier,_monster monster[],int *monsterIndex,_weapon weapon[],int *weaponIndex)
{
   char inpu[20]="fuck";
   int i=0,check_monster_name=0,check2=0,checkweapon=0,checkmonster=0;
   _soldier none_soldier;
   _weapon none_weapon;
   while(strcmp(inpu,"start")!=0)
   {
      checkweapon=0;check_monster_name=0;
      scanf(" %s",inpu);
    //  printf("inpu=%s 123\n",inpu);
    if(strcmp(inpu,"start")==0) //檢查start時有無key資料
      {
         if(!(*monsterIndex!=0&&check2==1))
         {
            printf("Error!\n");
            strcpy(inpu,"yee");
         }
      }
      else if(strcmp(inpu,"is")==0&&check2==1) printf("Error!\n"); //檢查重複key soldier
      else if(strcmp(inpu,"d")==0)
      {
        if(check2==1) printf("soldier hp:%d fp:%d weapon:%s location:%d,%d \n",(*soldier).hp,(*soldier).atk,(*soldier).w.name,(*soldier).l.x,(*soldier).l.y);
         for(i=0;i<*monsterIndex;i++) printf("monster id:%04d hp:%d fp:%d location:%d,%d\n",monster[i].name,monster[i].hp,monster[i].atk,monster[i].l.x,monster[i].l.y);
      }



      else if(strcmp(inpu,"is")==0)
      {
         scanf(" %d %d %d %d",&((*soldier).hp),&((*soldier).atk),&((*soldier).l.x),&((*soldier).l.y));
        // printf("soldier hp:%d fp:%d weapon:%s lacation:%d,%d \n",(*soldier).hp,(*soldier).atk,(*soldier).w.name,(*soldier).l.x,(*soldier).l.y);
         if(checkposition(soldier,monster,monsterIndex)==1) printf("Error!\n");
         else if(!((*soldier).hp>0&&(*soldier).atk>=0&&(*soldier).l.x>=0&&(*soldier).l.x<=99&&(*soldier).l.y>=0&&(*soldier).l.y<=99)) //檢查soldier的資料是否正確
         {
            printf("Error!\n");
         }
         else check2=1;
      }





      else if(strcmp(inpu,"iw")==0)
      {
         scanf("%s %d",weapon[*weaponIndex].name,&weapon[*weaponIndex].dis);
         for(i=0;i<*weaponIndex;i++) //確認武器有無重複或是攻擊距離錯誤
         {
            if(strcmp(weapon[i].name,weapon[*weaponIndex].name)==0 || weapon[*weaponIndex].dis<=0)
            {
               checkweapon=1;
               break;
            }
         }
          if(checkweapon==0&&weapon[*weaponIndex].dis>0) (*weaponIndex)++;
          else printf("Error!\n");
      }
      else if(strcmp(inpu,"im")==0)
      {

         scanf(" %d %d %d %d %d",&monster[*monsterIndex].name,&monster[*monsterIndex].hp,&monster[*monsterIndex].atk,&monster[*monsterIndex].l.x,&monster[*monsterIndex].l.y);
         if(monster[*monsterIndex].name<=0||monster[*monsterIndex].name>9999)  printf("Error!\n");
         else if((*soldier).l.x==monster[*monsterIndex].l.x&&(*soldier).l.y==monster[*monsterIndex].l.y) printf("Error!\n");
         else if(checkposition(soldier,monster,monsterIndex)==1) printf("Error!\n");
         else if(monster[*monsterIndex].hp<=0||monster[*monsterIndex].atk<0||monster[*monsterIndex].l.x<0||monster[*monsterIndex].l.x>=100||monster[*monsterIndex].l.y<0||monster[*monsterIndex].l.y>99)
          {
             printf("Error!\n");//檢查monster的屬性輸入有無問題
          }

         else
         {  for(i=0;i<(*monsterIndex);i++) //檢查monster的name有無重複
            {
               if(monster[*monsterIndex].name==monster[i].name){
                  check_monster_name=1;
                  break;
               }
            }
            if(check_monster_name==0)
            {
               (*monsterIndex)++;
               sort(monster,monsterIndex);
            }
            else printf("Error!\n");
         }
      }
   }
}
void start(_soldier *soldier,_monster monster[],const int monsterIndex,_weapon weapon[],int *weaponIndex)
{
   char inpu[20];
   int i=0,check=0,x=0,y=0,term=0,temp=0,a=0,error=0,checkmonster=0;
   while(1)
   {
      check=0;error=0;checkmonster=0;
      scanf(" %s",inpu);
     // printf("inpu=%s term=%d \n",inpu,term);

      if(1)
      {
         if(strcmp(inpu,"im")==0||strcmp(inpu,"is")==0||strcmp(inpu,"iw")==0) printf("Error!\n");
         else if(strcmp(inpu,"d")==0)
         {
            printf("soldier hp:%d fp:%d weapon:%s location:%d,%d \n",(*soldier).hp,(*soldier).atk,(*soldier).w.name,(*soldier).l.x,(*soldier).l.y);
            for(i=0;i<monsterIndex;i++)
            {
              if(monster[i].hp!=0) printf("monster id:%04d hp:%d fp:%d location:%d,%d\n",monster[i].name,monster[i].hp,monster[i].atk,monster[i].l.x,monster[i].l.y);
          //  for(i=0;i<*weaponIndex;i++) printf("weapon name: %s \n",weapon[i].name);
            }
         }
         else if(strcmp(inpu,"equip")==0)
         {
            scanf(" %s",inpu);
           for(i=0;i<(*weaponIndex);i++)
            {
              // printf("weapon:%s \n",weapon[i].name);
               if(strcmp(weapon[i].name,inpu)==0)
               {
                 // printf("weapon equiped :%s\n",weapon[i].name);
                  (*soldier).w=weapon[i];
                  check=1;
               }
            }
            if(check==0) printf("Error!\n");
         }
         else if(strcmp(inpu,"a")==0)
         {
            scanf(" %d",&a);
            for(i=0;i<monsterIndex;i++)
            {
               //printf("all monster=:%04d\n",monster[i].name);

               if(monster[i].name==a)
               {
                  //printf("find it\n");
                  if(monster[i].hp<=0)
                  {
                    // printf("Error monster is dead\n");
                     break;
                  }
                  else if(sqrt(pow((double)(monster[i].l.x-(*soldier).l.x),2.0)+pow((double)(monster[i].l.y-(*soldier).l.y),2.0))<=(double)(*soldier).w.dis)
                  {
                     //printf("dis enough\n");
                     if((*soldier).atk>=0&&(*soldier).atk<=10) monster[i].hp-=5;
                     else   if((*soldier).atk>10&&(*soldier).atk<=50) monster[i].hp-=10;
                     else  if((*soldier).atk>50) monster[i].hp-=20;
                     if(monster[i].hp<=0) (*soldier).atk+=5;
                     check=1;
                     break;
                  }
               }
            }
            if(check==0) printf("Error!\n");
         }
         else if(strcmp(inpu,"m")==0)
         {
            scanf(" %d %d",&x,&y);
            for(i=0;i<monsterIndex;i++)
            {
               if((x==monster[i].l.x&&y==monster[i].l.y&&monster[i].hp>0)||x<0||x>99||y<0||y>99)
               {
                  //printf("Error!\n");
                  error=1;
               }
            }

            if(abs(x-(*soldier).l.x)+abs(y-(*soldier).l.y)<=5&&error==0)
            {
               (*soldier).l.x=x;(*soldier).l.y=y;
               check=1;
            }
            else printf("Error!\n");
         }
      }
      if(check==1)//monster 攻擊
      {
         for(i=0;i<monsterIndex;i++)
            {
               if(sqrt(pow((double)(monster[i].l.x-(*soldier).l.x),2.0)+pow((double)(monster[i].l.y-(*soldier).l.y),2.0))<=2.0&&monster[i].hp>0)
               {
                  if(monster[i].atk>=0&&monster[i].atk<=10) (*soldier).hp-=5;
                  else if(monster[i].atk>10&&monster[i].atk<=50) (*soldier).hp-=10;
                  else if(monster[i].atk>50) (*soldier).hp-=20;
                 //  printf("monster:%d atk soldier -%d\n",monster[i].name,monster[i].atk);
               }
            }
       }
       for(i=0;i<monsterIndex;i++)
       {
          if(monster[i].hp<=0) checkmonster+=1;
       }
       if((*soldier).hp<=0)
       {
          printf("monster win!\n");
          for(i=0;i<monsterIndex;i++)
          {
             if(monster[i].hp>0) printf("monster id:%04d hp:%d fp:%d location:%d,%d\n",monster[i].name,monster[i].hp,monster[i].atk,monster[i].l.x,monster[i].l.y);
          }
          break;

       }
       if(checkmonster==monsterIndex)
       {
          printf("soldier win!\n");
          printf("soldier hp:%d fp:%d weapon:%s location:%d,%d \n",(*soldier).hp,(*soldier).atk,(*soldier).w.name,(*soldier).l.x,(*soldier).l.y);
          break;
       }
   }



}
int main()
{
    int monsterIndex=0,weaponIndex=0;
    _soldier soldier;
    strcpy(soldier.w.name,"none");
    soldier.w.dis=1;soldier.hp=0;
    _monster monster[amount];
    _weapon weapon[amount];
    initwindow(1000,1000,"yee");
    creat(&soldier,monster,&monsterIndex,weapon,&weaponIndex);
   // printf("monsterindex=%d \n",monsterIndex);
    start(&soldier,monster,monsterIndex,weapon,&weaponIndex);
}
