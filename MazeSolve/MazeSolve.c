#include <stdio.h>
#include <stdlib.h>
#include "../MazeSolve/MazeSolve.h"

#define EMPTY 0
#define WALL 1
#define ROUTE 2
#define PLAYER 3

#define TRUE 1
#define FALSE 0

int solveMaze(int **maze, int startN, int startM, int n, int m) {
	if ((startN < 0) || (startM < 0)) return FALSE;
	if ((startN >= n) || (startM >= m)) return FALSE;

	if (maze[startN][startM] == PLAYER) {
		return TRUE;
	}
	if (maze[startN][startM] == WALL || maze[startN][startM] == ROUTE) {
		return FALSE;
	}

	maze[startN][startM] = ROUTE;
	int up = solveMaze(maze, startN - 1, startM, n, m);
	if (up == TRUE) {
		return TRUE;
	}
	int down = solveMaze(maze, startN + 1, startM, n, m);
	if (down == TRUE) {
		return TRUE;
	}
	int left = solveMaze(maze, startN, startM - 1, n, m);
	if (left == TRUE) {
		return TRUE;
	}
	int right = solveMaze(maze, startN, startM + 1, n, m);
	if (right == TRUE) {
		return TRUE;
	}

	maze[startN][startM] = EMPTY;
	return FALSE;
}
