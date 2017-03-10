#include <stdio.h>
#include <gameOfLife.h>

extern int X_DIM;
extern int Y_DIM;
extern int makeDead[9];
extern int makeAlive[9];

int shouldBeAlive(int x, int y, point **t) {
	int n = countNeighbours(x,y,t);
	return makeAlive[n];
}

int shouldBeDead(int x, int y, point **t) {
	int n = countNeighbours(x,y,t);
	return makeDead[n];
}

int countNeighbours(int x, int y, point **t) {
	int n = 0, i, j;
	
	for (i = -1; i <= 1; i++) 
		for (j = -1; j <= 1; j++) {
			if ( x + i >= 0 && x + i < X_DIM && y + j >= 0 && y + j < Y_DIM )
				if(t[x + i][y + j].state == 1 && !(i == j && j == 0))
					n++;
		}
 	return n;
}
void moveToNextGeneration(point **t) {
	int x,y;

	for (x = 0; x < X_DIM; x++)
		for(y=0; y < Y_DIM; y++)
			t[x][y].state = t[x][y].newState;
}

