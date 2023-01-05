#include <stdio.h>
#include <stdlib.h>

#include "../MazeSolve/MazeSolve.h"
#include "../MazeSolve/MazeIO.h"

#define W 2
#define H 2

int main()
{
	FILE* mazeTxtP;
	if (fopen_s(&mazeTxtP, "maze.txt", "r") != 0) {
		printf("Missing maze.txt");
		exit(1);
	}
	struct Maze* mazeP = readMaze(mazeTxtP);
	fclose(mazeTxtP);

	printf("Initial maze:\n\n");
	printMazeBoard(mazeP);
	printf("\n");

	if (findRouteFromExit(mazeP, mazeP->exitP)) {
		printf("Solved maze:\n\n");
		printMazeBoard(mazeP);
	}
	else {
		printf("It is impossible to solve the given maze!");
	}

	freeMaze(mazeP);
}
