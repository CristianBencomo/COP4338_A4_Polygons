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

    for(int i = 0; i < INPUT_LENGTH && (ch = getchar()) != '\n'; i++)
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
    currentPolygon->vertexList = malloc(1 * sizeof(Polygon));

    for(int i=0; str[i] != '\0' || str[i+1] != '\0'; i+=2) // Loops through every character in the string
    {
        
        printf("%d", i);
        currentPolygon->vertexList = realloc(currentPolygon->vertexList, (i+1) * sizeof(Polygon)); // Allocate memory for new vertex
        currentPolygon->vertexList[currentPolygon->numberOfVertices].x = str[i] - '0'; // X
        currentPolygon->vertexList[currentPolygon->numberOfVertices].y = str[i+1] - '0'; // Y
        currentPolygon->numberOfVertices++;
    }
    polygonCount++;
}

// prints the list of polygons and each of their number of vertices plus their centroid (avg of x and y)
void summary(int polygonCount)
{
    printf("\nSUMMARY OF POLYGONS:\n");
    for(int i = 0; i < polygonCount; i++) // For every polygon
    {
        Polygon currentPolygon = polyList[i];
        int numVertices = currentPolygon.numberOfVertices;
        int centroid_x = 0, centroid_y = 0; 
        for(int j = 0; j <numVertices; j++) // For each vertex
        {   
            centroid_x += currentPolygon.vertexList[j].x; // add current x
            centroid_y += currentPolygon.vertexList[j].y; // add current y
        }

        centroid_x /= numVertices; // divide for centroid final result
        centroid_y /= numVertices; // divide for centroid final result
        
        //Printing 
        printf("Polygon #%d:\n", i+1);
        printf("Number of vertices = %d\nCentroid: X=%d Y=%d\n\n", numVertices,centroid_x, centroid_y);
    }
}

void turn()
{

}

void shift()
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
            if(polygonCount >= 1000)
            {
                printf("1000 polygons have been saved, no more polygons can be added\nPlease use a different command\n");
                continue;
            }
            add(parameters);
            // Add printf?
        }

        else if(strcasecmp(command, "summary") == 0) //summary command
        {
            summary(polygonCount);
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





