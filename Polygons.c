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
void splitstr(char *str, char *command)
{
    char *token = strtok(str, " \0"); 
    strcpy(command, token);
}

// adding a polygon to the list
void add(char *str)
{
    char *token = strtok(str, " \0");
    token = strtok(NULL, " \0"); //skipping first token which is the command

    Polygon *currentPolygon = &polyList[polygonCount];
    currentPolygon->numberOfVertices = 0;
    currentPolygon->shiftDirection = NONE;
    currentPolygon->vertexList = malloc(1 * sizeof(Polygon));

    int x, y, inputCounter = 0;
    printf("Before while loop\n");
    while(token != NULL)
    {
        printf("In While loop\n");
        if(inputCounter % 2 == 0)
        {
            x = atoi(token);
            printf("in if\n");
        }
        else
        {
            printf("in else\n");
            y = atoi(token);
            currentPolygon->vertexList = realloc(currentPolygon->vertexList, (inputCounter + 1) * sizeof(Polygon)); // Allocate memory for new vertex
            currentPolygon->vertexList[currentPolygon->numberOfVertices].x = x; // X
            currentPolygon->vertexList[currentPolygon->numberOfVertices].y = y; // Y
            currentPolygon->numberOfVertices++;
            printf("X=%d Y=%d\n",currentPolygon->vertexList[currentPolygon->numberOfVertices].x, currentPolygon->vertexList[currentPolygon->numberOfVertices].y );
        }
        inputCounter++;
    }

    // for(int i=0; str[i] != '\0' || str[i+1] != '\0'; i+=2) // Loops through every character in the string
    // {
    //     currentPolygon->vertexList = realloc(currentPolygon->vertexList, (i+1) * sizeof(Polygon)); // Allocate memory for new vertex
    //     currentPolygon->vertexList[currentPolygon->numberOfVertices].x = str[i] - '0'; // X
    //     currentPolygon->vertexList[currentPolygon->numberOfVertices].y = str[i+1] - '0'; // Y
    //     currentPolygon->numberOfVertices++;
    // }
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
        float centroid_x = 0, centroid_y = 0; 
        for(int j = 0; j <numVertices; j++) // For each vertex
        {   
            centroid_x += currentPolygon.vertexList[j].x; // add current x
            centroid_y += currentPolygon.vertexList[j].y; // add current y
        }

        printf("Centroids x= %d    y=%d\n", centroid_x, centroid_y);
        centroid_x /= numVertices; // divide for centroid final result
        centroid_y /= numVertices; // divide for centroid final result
        
        //Printing 
        printf("Polygon #%d:\n", i+1);
        printf("direction: %d\n", currentPolygon.shiftDirection);
        printf("Number of vertices = %d\nCentroid: X=%d Y=%d\n\n", numVertices,centroid_x, centroid_y);
        
    }
}

void turn(char *str)
{
    char *token = strtok(str, " \0\n");
    printf("token %s\n", token);
    char *polygon_idx = malloc(sizeof(token));
    strcpy(polygon_idx, token); //Saving polygon index parameter
    printf("polygon_idx = %s\n", polygon_idx);

    Polygon *currentPolygon = &polyList[atoi(polygon_idx)]; //creating a pointer to the 

    token = strtok(NULL, " ");
    printf("token = %s\n", token);
    int direction = atoi(token);

    // printf("direction_int: %d\n", direction);
    // currentPolygon->shiftDirection = direction;

    free(polygon_idx);
    // free(direction);

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
        str = realloc(str, strlen(sizeof(input)));
        strcpy(str,input);
        // free(str);

        // separating command and parameters
        char *command = malloc(COMMAND_LENGTH*sizeof(char));
        splitstr(input, command);
        
        if(strcasecmp(command, "add") == 0) // Add command
        {
            if(polygonCount >= 1000)
            {
                printf("1000 polygons have been saved, no more polygons can be added\nPlease use a different command\n");
                continue;
            }
            add(str);
            printf("Polygon added\n");
        }

        else if(strcasecmp(command, "summary") == 0) //summary command
        {
            summary(polygonCount);
        }

        else if(strcasecmp(command, "turn") == 0) // turn command
        {
            turn(input);
            printf("Polygon direction changed\n");
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
        free(input);
        
    } while (!wantToExit);    
    
}





