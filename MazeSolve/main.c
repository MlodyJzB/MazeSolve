#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeSolve.h"
#include "../MazeSolve/MazeIO.h"

#define W 2
#define H 2

int main()
{
	int** board =(int**)malloc(W * sizeof * board);
	for (int i = 0; i < N; i++)
	{
		board[i] = (int*)malloc(H * sizeof * board[i]);
	}

	board[0][0] = 0;
	board[0][1] = 1;
	board[1][0] = 1;
	board[1][1] = 3;

	struct Point *exitPointP = (struct Point*)malloc(sizeof (struct Point));
	initPoint(exitPointP, 0, 0);

	struct Maze *mazeP = (struct Maze*)malloc(sizeof (struct Maze));
	initMaze(mazeP, exitPointP, board, W, H);

	int isSolved = findRouteFromExit(mazeP, mazeP->exitPointP);

	for (int i = 0; i < N; i++)
	{
		free(board[i]);
	}
	free(board);
	free(mazeP);
}
