#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeIO.h"

void initPoint(struct Point* pointP, int x, int y) {
	pointP->x = x;
	pointP->y = y;
}