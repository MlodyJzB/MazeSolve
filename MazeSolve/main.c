#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeSolve.h"
#include "../MazeSolve/MazeIO.h"

#define N 2
#define M 2

int main()
{
	int** board =(int**)malloc(N * sizeof * board);
	for (int i = 0; i < N; i++)
	{
		board[i] = (int*)malloc(M * sizeof * board[i]);
	}

	board[0][0] = 0;
	board[0][1] = 1;
	board[1][0] = 1;
	board[1][1] = 3;

	struct Point *startPointP = (struct Point*)malloc(sizeof (struct Point));
	initPoint(startPointP, 0, 0);

	struct Maze *mazeP = (struct Maze*)malloc(sizeof (struct Maze));
	mazeP->board = board;
	mazeP->startPointP = startPointP;
	mazeP->width = N;
	mazeP->height = M;

	int isSolved = solveMaze(mazeP, mazeP->startPointP);

	for (int i = 0; i < N; i++)
	{
		free(board[i]);
	}
	free(board);
	free(mazeP);
}
