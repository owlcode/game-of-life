#include <stdlib.h>
#include <time.h>
#include <pointStruct.h>
#include <stdio.h>

int X_DIM = 50;
int Y_DIM = 50;
/**
* Rules of making alive.
**/
int makeAlive[9] = {0,0,0,1,0,0,0,0,0};
int makeDead[9] = {1,1,0,0,1,1,1,1,1};
int IT = 1000;
point** t;

int main(int argc, char *argv[]) {  
	int i,j,k;
	FILE *f;

   	init(argc, argv);	
	
	for (i = 0; i < IT; i++) {
		puts("\033[H\033[J");
		printActualState(t);	

		for ( j = 0; j < X_DIM; j++ ) {
			for ( k = 0; k < Y_DIM; k++ ) { 
				if (t[j][k].state == 1) {
					t[j][k].newState = !shouldBeDead(j,k, t);
				} else if (t[j][k].state == 0) {
					t[j][k].newState = shouldBeAlive(j,k, t);
				}
			}
	 	}		

		moveToNextGeneration(t);
		usleep(200*1000);    
	}

	puts("\033[H\033[J");
	printActualState(t);

	if(argc > 5) {
		f = fopen(argv[5], "w");
		saveToFile(f);
	}
	
	for(i=0;i<X_DIM;i++) free(t[i]);
	free(t);

	return 0;
}
