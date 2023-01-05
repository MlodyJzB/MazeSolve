#ifndef MAZEIO_H
#define MAZEIO_H

#include <stdio.h>
#include <stdlib.h>

struct Maze {
	int** board;
	struct Point* exitP;
	struct Size* sizeP;
};

struct Point {
	int x;
	int y;
};

struct Size {
	int width;
	int height;
};

void initPoint(struct Point* pointP, int x, int y);

struct Maze* readMaze(FILE* mazeTxtP);

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, struct size* sizeP);

struct Size* boardSizeFromFile(FILE* mazeTxtP);

int fileLen(FILE* f);

char** readBoardAndExit(FILE* mazeTxtP, struct Size* sizeP, struct Point** exitPointDestPP);

int onBoarder(struct Point* pP, struct Size* sP);

#endif /* MazeIO.h */
