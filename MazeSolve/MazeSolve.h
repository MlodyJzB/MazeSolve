#ifndef MAZESOLVE_H
#define MAZESOLVE_H

#include <stdio.h>
#include <stdlib.h>

#include "MazeIO.h"

int solveMaze(struct Maze* mazeP, struct Point* startPointP);
int inBoundaries(int startN, int startM, int n, int m);

#endif /* MazeSolve.h */
