#include <stdio.h>
#include <stdlib.h>
#include "../MazeSolve/MazeSolve.h"

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
	board[1][0] = 3;
	board[1][1] = 0;

	struct Maze *maze = (struct Maze*)malloc(sizeof (struct Maze));
	maze->board = board;
	maze->startN = 0;
	maze->startM = 0;
	maze->n = N;
	maze->m = M;

	int isSolved = solveMaze(maze, maze->startN, maze->startM);

	for (int i = 0; i < N; i++)
	{
		free(board[i]);
	}
	free(board);
	free(maze);
}
