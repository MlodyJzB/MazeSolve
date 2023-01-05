#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeIO.h"

#define TRUE 1
#define FALSE 0

void initPoint(struct Point* pointP, int x, int y) {
	pointP->x = x;
	pointP->y = y;
}

struct Maze* readMaze(FILE* mazeTxtP) {
	struct Size* sizeP = boardSizeFromFile(mazeTxtP);

	struct Point* exitP = (struct Point*)malloc(sizeof(struct Point));
	char** board = readBoardAndExit(mazeTxtP, sizeP, &exitP);

	struct Maze* mazeP = (struct Maze*)malloc(sizeof(struct Maze));
	initMaze(mazeP, exitP, board, sizeP);
	return mazeP;
}

void initMaze(struct Maze* mazeP, struct Point* exitPointP, int** board, struct size* sizeP) {
	mazeP->board = board;
	mazeP->exitP = exitPointP;
	mazeP->sizeP = sizeP;
}

struct Size* boardSizeFromFile(FILE* mazeTxtP) {
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

	struct Size* sizeP = (struct Size*)malloc(sizeof(struct Size));
	sizeP->width = firstLineLen;
	sizeP->height = rowsAmount;
	return sizeP;
}

int fileLen(FILE* f) {
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);

	return len;
}

char** readBoardAndExit(FILE* mazeTxtP, struct Size* sizeP, struct Point** exitPointDestPP) {
	char** board = (char**)malloc(sizeP->width * sizeof * board);
	for (int i = 0; i < sizeP->width; i++)
	{
		board[i] = (char*)malloc(sizeP->height * sizeof * board[i]);
	}
	for (int y = 0; y < sizeP->height; y++){
		for (int x = 0; x < sizeP->width; x++) {
			board[x][y] = getc(mazeTxtP);

			struct Point* pP = (struct Point*)malloc(sizeof(struct Point));
			initPoint(pP, x, y);
			if (onBoarder(pP, sizeP) && board[x][y] == ' ')
				*exitPointDestPP = pP;
			else
				free(pP);
		}
		getc(mazeTxtP);
	}
	return board;
}

int onBoarder(struct Point* pP, struct Size* sP) {
	if (pP->x == 0 || pP->y == 0 || pP->x == (sP->width - 1) || pP->y == (sP->height - 1))
		return TRUE;
	return FALSE;
}
