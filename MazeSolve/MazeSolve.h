#ifndef MAZESOLVE_H
#define MAZESOLVE_H

#include <stdio.h>
#include <stdlib.h>

struct Maze {
	int** board;
	int startN;
	int startM;
	int n;
	int m;
};

int solveMaze(struct Maze *maze, int startN, int startM);
int inBoundaries(int startN, int startM, int n, int m);

#endif /* MazeSolve.h */
