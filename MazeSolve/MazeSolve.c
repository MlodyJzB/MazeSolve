#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeSolve.h"
#include "../MazeSolve/MazeIO.h"

#define EMPTY 0
#define WALL 1
#define ROUTE 2
#define PLAYER 3

#define TRUE 1
#define FALSE 0

int solveMaze(struct Maze* mazeP, struct Point* startPointP) {
	if (inBoundaries(startPointP, mazeP) == FALSE)
		return FALSE;

	int x = startPointP->x;
	int y = startPointP->y;
	if (mazeP->board[x][y] == PLAYER)
		return TRUE;
	if (mazeP->board[x][y] == WALL || mazeP->board[x][y] == ROUTE)
		return FALSE;

	mazeP->board[x][y] = ROUTE;
	struct Point nextPoint;

	initPoint(&nextPoint, x, y-1);
	int up = solveMaze(mazeP, &nextPoint);
	if (up == TRUE)
		return TRUE;

	initPoint(&nextPoint, x, y+1);
	int down = solveMaze(mazeP, &nextPoint);
	if (down == TRUE)
		return TRUE;

	initPoint(&nextPoint, x - 1, y);
	int left = solveMaze(mazeP, &nextPoint);
	if (left == TRUE)
		return TRUE;

	initPoint(&nextPoint, x + 1, y);
	int right = solveMaze(mazeP, &nextPoint);
	if (right == TRUE)
		return TRUE;

	mazeP->board[x][y] = EMPTY;
	return FALSE;
}

int inBoundaries(struct Point* pointP, struct Maze* mazeP) {
	if ((pointP->x < 0) || (pointP->y < 0)) 
		return FALSE;
	if ((pointP->x >= mazeP->width) || (pointP->y >= mazeP->height)) 
		return FALSE;
	return TRUE;
}
