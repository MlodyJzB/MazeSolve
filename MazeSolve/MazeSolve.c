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

int findRouteFromExit(struct Maze* mazeP, struct Point* exitPointP) {
	if (inBoundaries(exitPointP, mazeP) == FALSE)
		return FALSE;

	int x = exitPointP->x;
	int y = exitPointP->y;
	if (mazeP->board[x][y] == PLAYER)
		return TRUE;
	if (mazeP->board[x][y] == WALL || mazeP->board[x][y] == ROUTE)
		return FALSE;

	mazeP->board[x][y] = ROUTE;
	struct Point nextPoint;

	initPoint(&nextPoint, x, y-1);
	if(findRouteFromExit(mazeP, &nextPoint))
		return TRUE;

	initPoint(&nextPoint, x, y+1);
	if (findRouteFromExit(mazeP, &nextPoint))
		return TRUE;

	initPoint(&nextPoint, x - 1, y);
	if (findRouteFromExit(mazeP, &nextPoint))
		return TRUE;

	initPoint(&nextPoint, x + 1, y);
	if (findRouteFromExit(mazeP, &nextPoint))
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
