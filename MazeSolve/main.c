#include <stdio.h>
#include <stdlib.h>
#include "../MazeSolve/MazeSolve.h"

#define N 6
#define M 6

int main()
{
	int maze[N][M] = {
		{1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 1},
		{1, 0, 1, 0, 0, 0}, 
		{1, 0, 1, 0, 1, 1},
		{1, 0, 1, 0, 1, 1},
		{3, 0, 1, 0, 0, 0},
	};

	int isSolved = solveMaze(maze, 0, 1, N, M);
}
