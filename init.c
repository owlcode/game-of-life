#include <init.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

extern int X_DIM;
extern int Y_DIM;
extern int makeDead[9];
extern int makeAlive[9];
extern point** t;
extern int IT;

void init(int argc, char *argv[]) {
	int i = 0;
	char *p;
	long conv;
	FILE *f;
	
	if(argc < 4) {
		printf("Podaj wymagane parametry\n");
		printf("./life X_DIMENSION Y_DIMENSION ITERATIONS [IN_FILE OUT_FILE]\n");
		printf("Podanie -1 powoduje uzycie domyslnej wartosci\n");
		printf("Domyslnie: ./life 50 50 1000 null null \n");
		exit(1);
	}

	conv = strtol(argv[1], &p, 10);
	
	if (*p != '\0' || conv > 300) {
		printf("Bledne parametry uruchomienia !");
		exit(1);
	} else {
		if (conv != -1)
			X_DIM = conv;
	}

	conv = strtol(argv[2], &p, 10);

	if (*p != '\0' || conv > 300) {
		printf("Bledne parametry uruchomienia !");
		exit(1);
	} else {
		if (conv != -1)
			Y_DIM = conv;
	}

	
	conv = strtol(argv[3], &p, 10);
	
	if (*p != '\0' || conv > 10000) {
		printf("Bledne parametry uruchomienia !");
		exit(1);
	} else {
		if (conv != -1)
			IT = conv;
	}

		
    	t = malloc(X_DIM*sizeof(point *));
    	for(i=0;i<X_DIM;i++) t[i] = (point *)malloc(Y_DIM*sizeof(point));		
	
	if(argc > 4) {	
		if(!strcmp(argv[4],"-1")) {
			generateRandom();
		} else {
			f = fopen(argv[4], "r");		
			generateFromFile(f);
		}
	} else {
		generateRandom();
	}	
}
void generateFromFile(FILE *f) {
	int znak,i=0,j=0;
	point p;
	znak = getc(f);

	if (i > X_DIM || j > Y_DIM ) {
		printf("Zle dane wejsciowe");
		exit(1);
	}

	while (znak != EOF) {
		if (znak == 35) {
			p.state = 1;
			t[i][j] = p;
			i++;
		} else if (znak == 32) {
			p.state = 0;
			t[i][j] = p;
  			i++;
		} else if (znak == 10) {
			i = 0;
			j++;
		}

		
		
		znak = getc(f);
	}
}
void generateRandom() {
	int i,j,r;
	point p;
	srand(time(NULL));

	for (i = 0; i < X_DIM; i++) {
		for (j = 0; j < Y_DIM; j++) {
			r = (int)floor(rand()%100);
			
			if(r%3 == 0) {
				p.state = 1;
				t[i][j] = p; 
			} else {
				p.state = 0;
				t[i][j] = p;
			}	
		}
	}
}
