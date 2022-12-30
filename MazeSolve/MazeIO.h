#ifndef MAZEIO_H
#define MAZEIO_H

#include <stdio.h>
#include <stdlib.h>

struct Maze {
	int** board;
	struct Point* startPointP;
	int width;
	int height;
};

struct Point {
	int x;
	int y;
};

void initPoint(struct Point* pointP, int x, int y);

#endif /* MazeIO.h */
