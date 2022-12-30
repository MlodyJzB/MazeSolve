#ifndef MAZESOLVE_H
#define MAZESOLVE_H

#include <stdio.h>
#include <stdlib.h>

#include "MazeIO.h"

int findRouteFromExit(struct Maze* mazeP, struct Point* startPointP);
int inBoundaries(struct Point* pointP, struct Maze* mazeP);

#endif /* MazeSolve.h */
