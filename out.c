#include <out.h>
#include <stdio.h>


extern int X_DIM;
extern int Y_DIM;
extern int makeDead[9];
extern int makeAlive[9];
extern point** t;
extern int IT;

void printActualState() {
	int i,j;
	for (i = 0; i < Y_DIM; i++) { 
		for (j = 0; j < X_DIM; j++)
			if(t[j][i].state == 1)
				printf("#");
			else
				printf(" ");

		printf("\n");
	}
}
void saveToFile(FILE *file) {
	int i,j;
	
	for (i = 0; i < Y_DIM; i++) { 
		for (j = 0; j < X_DIM; j++)
			if(t[j][i].state == 1)
				fprintf(file, "#");
			else
				fprintf(file, " ");
		fprintf(file, "\n");
	}
}

