#ifndef MAZEIO_H
#define MAZEIO_H

#include <stdio.h>
#include <stdlib.h>

struct Maze {
	int** board;
	struct Point* exitPointP;
	int width;
	int height;
};

struct Point {
	int x;
	int y;
};

void initPoint(struct Point* pointP, int x, int y);

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, int width, int height);

void boardSizeFromFile(FILE* mazeTxtP, int* widthDestP, int* heightDestP);

int fileLen(FILE* f);

char** readBoard(FILE* mazeTxtP, int width, int height);
#endif /* MazeIO.h */
