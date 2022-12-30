#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeIO.h"

void initPoint(struct Point* pointP, int x, int y) {
	pointP->x = x;
	pointP->y = y;
}

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, int width, int height) {
	mazeP->board = board;
	mazeP->exitPointP = exitPointP;
	mazeP->width = width;
	mazeP->height = height;
}