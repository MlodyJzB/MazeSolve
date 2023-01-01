#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeIO.h"

void initPoint(struct Point* pointP, int x, int y) {
	pointP->x = x;
	pointP->y = y;
}

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, int width, int height) {
	mazeP->board = board;
	mazeP->exitPointP = exitPointP;
	mazeP->width = width;
	mazeP->height = height;
}

void mazeCheckAndSizeFromFile(FILE* mazeTxtP, int* widthDestP, int* heightDestP) {
	int firstLineLen = 0;
	char curC;
	do {
		curC = getc(mazeTxtP);
		firstLineLen++;
	} while (curC != '\n');
	firstLineLen--;

	int fileLength = fileLen(mazeTxtP);

	int rowsAmount = 1;
	do {
		rowsAmount++;
		if ((fseek(mazeTxtP, (long)firstLineLen, SEEK_CUR) != 0)||(ftell(mazeTxtP)>fileLength)) {
			printf("Error: Different size of lines in maze.txt file!");
			exit(1);
		}

		curC = getc(mazeTxtP);
		if ((curC != '\n') && (curC != EOF)) {
			printf("Error: Different size of lines in maze.txt file!");
			exit(1);
		}
	} while (curC != EOF);

	fseek(mazeTxtP, (long)firstLineLen, SEEK_SET);
	*widthDestP = firstLineLen;
	*heightDestP = rowsAmount;
}

int fileLen(FILE* f) {
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);

	return len;
}