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
	int** board = mazeP->board;
	int x = startPointP -> x;
	int y = startPointP -> y;

	if (inBoundaries(x, y, mazeP->width, mazeP->height) == FALSE)
		return FALSE;

	if (board[x][y] == PLAYER)
		return TRUE;
	if (board[x][y] == WALL || board[x][y] == ROUTE)
		return FALSE;

	board[x][y] = ROUTE;
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

	board[x][y] = EMPTY;
	return FALSE;
}

int inBoundaries(int x, int y, int width, int height) {
	if ((x < 0) || (y < 0)) return FALSE;
	if ((x >= width) || (y >= height)) return FALSE;
	return TRUE;
}
