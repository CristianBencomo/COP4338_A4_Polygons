# COP 4338_A4_Polygons      
Assignment 3          
Cristian Bencomo

## Description          
This program maintains a list of up to 1000 polygons, it stores their direction, number of vertices, and the location of each vertex.                 
These are the available commands: 
> add X0 Y0 X1 Y1 Xn Yn: creates a standard polygon with the defined vertices and locations                        
> summary: Displays the stored polygons and their values                
> turn k x: It will turn the polygon at index k to face the x direction (up,down,left,right, or any combination of those in any order, such as up-right or right-up)    
> shift k x: Shift polygon at index k by the specified x in each direction that it has saved            
> quit: quits and leaves the program            

All the previous functions work properly with no bugs found.

## Contents 
* Polygons.c file which contains all the source code
* PA1.pdf which contains the assignment instructions
* Makefile used to compile the program in Ubuntu
* polygons object ready to run (compiled in Ubuntu)
