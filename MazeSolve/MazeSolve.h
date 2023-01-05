#ifndef MAZESOLVE_H
#define MAZESOLVE_H

#include <stdio.h>
#include <stdlib.h>

#include "MazeIO.h"

int findRouteFromExit(struct Maze* mazeP, struct Point* exitPointP);

int inBoundaries(struct Point* pointP, struct Size* sizeP);

#endif /* MazeSolve.h */
