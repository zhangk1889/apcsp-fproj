#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *to_morse(char *);

int main(int argc, char **argv)
{
    char *temp;
    for (int counter = 1; counter < argc; counter++)
    {
        temp = to_morse(argv[counter]);
        printf("%s", temp);
        free(temp);
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
