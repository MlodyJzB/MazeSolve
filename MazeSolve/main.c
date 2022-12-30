#include <stdio.h>
#include <stdlib.h>
#include "../MazeSolve/MazeSolve.h"

#define N 2
#define M 2

int main()
{
	int** maze =(int**)malloc(N * sizeof *maze);
	for (int i = 0; i < N; i++)
	{
		maze[i] = (int*)malloc(M * sizeof *maze[i]);
	}

	maze[0][0] = 0;
	maze[0][1] = 1;
	maze[1][0] = 3;
	maze[1][1] = 0;

	int isSolved = solveMaze(maze, 0, 0, N, M);

	for (int i = 0; i < N; i++)
	{
		free(maze[i]);
	}
	free(maze);
}
