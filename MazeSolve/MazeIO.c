#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeIO.h"

void initPoint(struct Point* pointP, int x, int y) {
	pointP->x = x;
	pointP->y = y;
}

struct Maze* readMaze(FILE* mazeTxtP) {
	int width, height;
	boardSizeFromFile(mazeTxtP, &width, &height);
	char** board = readBoard(mazeTxtP, width, height);

	struct Maze* mazeP = (struct Maze*)malloc(sizeof(struct Maze));
	return mazeP;
}

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, int width, int height) {
	mazeP->board = board;
	mazeP->exitPointP = exitPointP;
	mazeP->width = width;
	mazeP->height = height;
}

void boardSizeFromFile(FILE* mazeTxtP, int* widthDestP, int* heightDestP) {
	int firstLineLen = 0;
	char curC;
	do {
		curC = getc(mazeTxtP);
		firstLineLen++;
	} while (curC != '\n');
	firstLineLen--;

	int fileLength = fileLen(mazeTxtP);

	int rowsAmount = 0;
	do {
		rowsAmount++;
		if ((fseek(mazeTxtP, (long)firstLineLen, SEEK_CUR) != 0) || (ftell(mazeTxtP) > fileLength)) {
			printf("Error: Different size of lines in maze.txt file!");
			exit(1);
		}

		curC = getc(mazeTxtP);
		if ((curC != '\n') && (curC != EOF)) {
			printf("Error: Different size of lines in maze.txt file!");
			exit(1);
		}
	} while (curC != EOF);

	fseek(mazeTxtP, 0, SEEK_SET);
	*widthDestP = firstLineLen;
	*heightDestP = rowsAmount;
}

int fileLen(FILE* f) {
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);

	return len;
}

char** readBoard(FILE* mazeTxtP, int width, int height) {
	char** board = (char**)malloc(width * sizeof * board);
	for (int i = 0; i < width; i++)
	{
		board[i] = (char*)malloc(height * sizeof * board[i]);
	}
	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++) {
			board[x][y] = getc(mazeTxtP);
		}
		getc(mazeTxtP);
	}
	return board;
}
