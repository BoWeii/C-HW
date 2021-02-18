#include<stdio.h>
int main()
{
   char text[250],inpu[1000],temp;
   int i=0,index=0,ii;
   for(i=0;i<=strlen(text);i++) text[i]='\0';
   gets(text);
   gets(inpu);
  // printf("%d",strlen(text));
   for(i=0;i<=strlen(inpu);i++)
   {

      switch(inpu[i])
      {
         case '0':
            index=0;
            break;
         case '$':
            index=strlen(text);
            break;
         case 'x':
            if(index==strlen(text)) continue;
            for(ii=index;ii<strlen(text);ii++) {
               text[ii]=text[ii+1];
              // printf("%c %c %d\n",text[i],text[ii],ii);
            }
            break;
         case 's':
             if(text[index]!='\0'&&text[index+1]!='\0')
             {
                temp=text[index];
                text[index]=text[index+1];
                text[index+1]=temp;
             }
             break;
         case 'i':
            for(ii=strlen(text);ii!=index-1;ii--) text[ii+1]=text[ii];
            text[index++]=inpu[i+1];
            i++;
            break;
         case 'u':
            if ((int)(text[index])>=97 && (int)(text[index])<=122 || (int)(text[index])>=65 && (int)(text[index])<=90)
            {
              // printf("in u\n");
               if((int)(text[index])>=97 && (int)(text[index])<=122)
               {
                 temp=(int)text[index]-32;
                 text[index]=temp;
               }
            }
            index++;
            break;
         case '+':
             index++;
             break;
         case '-':
            index--;
            break;
         default : break;
      }
    //  printf("%s\n",text);
    //  printf("i=%d  inpu[i]=%c  text[index]=%c  \n\n\n",i,inpu[i],text[index]);

   }
    printf("%s",text);
}
