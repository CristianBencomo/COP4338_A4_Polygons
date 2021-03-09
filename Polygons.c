#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Keyword definition
#define TRUE 1
#define FALSE 0
#define INPUT_LENGTH 100
#define COMMAND_LENGTH 10
#define POLYGON_LIST_LENGTH 1000

//Type definitions
typedef enum  // Direction
{
    NONE = 0,
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8
} Direction;

typedef struct // Vertex 
{
    int x, y;
} Vertex;

typedef struct 
{
    int numberOfVertices;
    Direction shiftDirection;
    Vertex *vertexList;
}Polygon;

// Global variables
Polygon polyList[POLYGON_LIST_LENGTH]; // list of polygons
int polygonCount; // number of polygons

// Function that scans input dynamically to a pointer
char *dynamicScan(char *str)
{
    int ch; //character
    str = malloc(sizeof(char)); //allocate str

    for(int i = 0; i <INPUT_LENGTH && (ch = getchar()) != '\n'; i++)
    {
        str = realloc(str, (i+2)*sizeof(char)); //reallocate as characters are taken in
        str[i] = (char) ch;
        str[i+1] = '\0';
    }

    return str; //return final string
}

// Function that splits input into words
void splitstr(char *str, char *command, char *parameters)
{
    char *token = strtok(str, " \0"); 
    strcpy(command, token);
    token = strtok(NULL, " \0");


    if(token != NULL)
    {
        strcpy(parameters, token);
    }
}

// adding a polygon to the list
void add(char *str)
{
    polyList[polygonCount].numberOfVertices = 0;
    Polygon *currentPolygon = &polyList[polygonCount];
    currentPolygon->shiftDirection = NONE;

    for(int i=0; str[i] != '\0' || str[i+1] != '\0'; i+=2)
    {
        currentPolygon->vertexList[currentPolygon->numberOfVertices].x = str[i];
    //     currentPolygon->vertexList[currentPolygon->numberOfVertices].y = str[i+1];
    //     currentPolygon->numberOfVertices++;
    }
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
    int wantToExit = FALSE; //exit flag
    polygonCount = 0; // initialize count
    
    do
    {
        // ask the user for a command and handle input
        printf("Please enter a command...\n");
        char * input;
        char *str;
        input = dynamicScan(str);

        // separating command and parameters
        char *command = malloc(COMMAND_LENGTH*sizeof(char));
        char *parameters = malloc((INPUT_LENGTH - COMMAND_LENGTH) *sizeof(char));
        splitstr(input, command, parameters);
        free(input); // free memory from input
        
        if(strcasecmp(command, "add") == 0) // Add command
        {
            add(parameters);
        }

        else if(strcasecmp(command, "summary") == 0) //summary command
        {

        }

        else if(strcasecmp(command, "turn") == 0) // turn command
        {

        }

        else if(strcasecmp(command, "shift") == 0) // shift command
        {

        }

        else if(strcasecmp(command, "quit") == 0) // quit command
        {
            printf("Leaving program...\n");
            wantToExit = TRUE; // change exit flag
        }

        else
        {
            printf("Incorrect command, please enter a valid command\n");
        }

        // free allocated space
        free(command);
        free(parameters);

    } while (!wantToExit);    
    
}





