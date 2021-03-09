#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Keyword definition
#define TRUE 1
#define FALSE 0
#define INPUT_LENGTH 100


// Function that scans input dynamically to a pointer
char *dynamicScan(char *str)
{
    int ch; //character
    str = malloc(sizeof(char));

    for(int i = 0; i <INPUT_LENGTH && (ch = getchar()) != '\n'; i++)
    {
        str = realloc(str, (i+2)*sizeof(char));
        str[i] = (char) ch;
        str[i+1] = '\0';
    }

    return str;
}

// Function that splits input into words
void splitstr(char *str, char **result_str)
{
    char delim[] = {' ', '\0';
    char *token = strtok(str, delim);
    
    // int word = 0;
    // int ch_num = 0;

    
    // for(int i = 0; i < strlen(str); i++)
    // {
    //     if(str[i] == ' ' || str[i] == '\0' || str[i] == '\n')
    //     {

    //     }
    //     else
    //     {

    //     }
    // }
}

void adding()
{

}

void summary()
{

}

void turn()
{

}

void shift()
{

}

void quit()
{

}

int main(int argc, char const *argv[])
{
    int wantToExit = FALSE;
    
    
    do
    {
        // ask the user for a command and handle input
        printf("Please enter a command...\n");
        char * input; // = malloc(INPUT_LENGTH);
        char *str;
        input = dynamicScan(input);
        free(str); // free memory of temp var str

        char **commandByParts;

        
        printf("%s", input);





        
        
        if(strcasecmp(argv[0], "add") == 0)
        {

        }

        else if(strcasecmp(argv[0], "summary") == 0)
        {

        }

        else if(strcasecmp(argv[0], "turn") == 0)
        {

        }

        if(strcasecmp(argv[0], "shift") == 0)
        {

        }

        if(strcasecmp(argv[0], "quit") == 0)
        {
            printf("Leaving program...\n");
            wantToExit = TRUE;
        }

        else
        {
            printf("Incorrect command, please enter a valid command\n");
        }

        // free used memory
        free(input);

    } while (!wantToExit);    
}





