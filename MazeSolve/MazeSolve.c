#include <stdio.h>
#include <stdlib.h>
#include "../MazeSolve/MazeSolve.h"

#define EMPTY 0
#define WALL 1
#define ROUTE 2
#define PLAYER 3

#define TRUE 1
#define FALSE 0

int solveMaze(struct Maze* maze, int startN, int startM) {
	int** board = maze->board;
	int n = maze->n;
	int m = maze->m;

	if (inBoundaries(startN, startM, n, m) == FALSE)
		return FALSE;

	if (board[startN][startM] == PLAYER)
		return TRUE;
	if (board[startN][startM] == WALL || board[startN][startM] == ROUTE)
		return FALSE;

	board[startN][startM] = ROUTE;

	int up = solveMaze(maze, startN - 1, startM);
	if (up == TRUE)
		return TRUE;

	int down = solveMaze(maze, startN + 1, startM);
	if (down == TRUE)
		return TRUE;

	int left = solveMaze(maze, startN, startM - 1);
	if (left == TRUE)
		return TRUE;

	int right = solveMaze(maze, startN, startM + 1);
	if (right == TRUE)
		return TRUE;

	board[startN][startM] = EMPTY;
	return FALSE;
}

int inBoundaries(int startN, int startM, int n, int m) {
	if ((startN < 0) || (startM < 0)) return FALSE;
	if ((startN >= n) || (startM >= m)) return FALSE;
	return TRUE;
}
