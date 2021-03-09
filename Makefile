CC = gcc
CFLAGS = -g -Wall -c
LFLAGS = -g -Wall 

polygons : Polygons.c
	$(CC) $(LFLAGS) Polygons.c -o polygons

clean :
	\rm polygons.zip Polygons

zip : 
	zip polygons.zip *