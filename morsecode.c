#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[])
{
 char *alphabet[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
     "...-",".--","-..-","-.--","--.."};
 char *number[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
 

 int i;
 char str[1000],str1[1000];
 gets(str); 
i=0;
  while(str[i]!='\0')
  {
 if(str[i]!=' '&&(!isdigit(str[i])))  
 {
     printf("%s ",alphabet[toupper(str[i])-65]);  
 } 
    if(str[i]==' ')
    {
     printf(" ");
    }
    if(isdigit(str[i])&&str[i]!=' ')
    {
      printf("%s ",number[str[i]-48]);    
    }

 
   i++;
  }
  printf("\n");
 
}



