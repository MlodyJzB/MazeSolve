#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeSolve.h"
#include "../MazeSolve/MazeIO.h"

#define EMPTY ' '
#define WALL '*'
#define ROUTE '+'
#define PLAYER 'X'

#define TRUE 1
#define FALSE 0

int findRouteFromExit(struct Maze* mazeP, struct Point* exitPointP) {
	if (inBoundaries(exitPointP, mazeP->sizeP) == FALSE)
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

int inBoundaries(struct Point* pointP, struct Size* sizeP) {
	if ((pointP->x < 0) || (pointP->y < 0)) 
		return FALSE;
	if ((pointP->x >= sizeP->width) || (pointP->y >= sizeP->height)) 
		return FALSE;
	return TRUE;
}
