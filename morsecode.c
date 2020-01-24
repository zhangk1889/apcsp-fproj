#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *to_morse(char *);

int main(int argc, char **argv)
{
  if (argc <= 1)
  {
  printf ("You didn't enter anything! Please type something in before hitting go.\n");
  }
  else
{
    char *temp;
    for (int counter = 1; counter < argc; counter++)
    {
        temp = to_morse(argv[counter]);
        printf("%s", temp);
        free(temp);
    }
    argc = argc - 1;
    if (argc == 1)
    {
  printf ("\nYou've inputted %d word.\n", argc);
    }
    else
    {
      printf ("\nYou've inputted %d words.\n", argc);
    }
}
    return 0;
}

char *to_morse(char *str)
{
    char *morse[27] =  {".-","-...","-.-.","-..",
".","..-.","--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char *output=malloc((strlen(str)*5)+1);
    output[0] = '\0';
    char character;

    for (int counter = 0; str[counter] != '\0'; counter++)
    {
        if(isalpha(str[counter]))
        {
            character = toupper(str[counter]);
            strcat(output,morse[character-'A']);
            strcat(output," ");
        }
    }

    return output;

    }
