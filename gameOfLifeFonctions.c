#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initWorld(int height, int larg){
	int** world = malloc(height * larg * sizeof(int*));
	for (int i = 0; i < height * larg; i++){
		world[i] = malloc(2 * sizeof(int));
		world[i][0] = rand() % 2;
		world[i][1] = 0;
	}
	return world;
}

void updateNbNeighbour(int** world, int larg, int height){
	/* pour la cellule e, schéma de ses voisins:
	a b c
	d e f
	g h i */
	int a, b, c, d, f, g, h, i;
	for (int PosJ = 0; PosJ < height; PosJ++){
		for (int PosI = 0; PosI < larg; PosI++){
			a = world[((PosJ - 1 + height) % height) * larg + (PosI + larg - 1) % larg][0];
			b = world[((PosJ - 1 + height) % height) * larg + PosI][0];
			c = world[((PosJ - 1 + height) % height) * larg + (PosI + 1 + larg) % larg][0];
			d = world[(PosI - 1 + larg) % larg + PosJ * larg][0];
			f = world[(PosI + 1 + larg) % larg + PosJ * larg][0];
			g = world[((PosJ + 1 + height) % height) * larg + (PosI + larg - 1) % larg][0];
			h = world[((PosJ + 1 + height) % height) * larg + PosI][0];
			i = world[((PosJ + 1 + height) % height) * larg + (PosI + 1 + larg) % larg][0];

			world[height * PosJ + PosI][1] = a + b + c + d + f + g + h + i;
		}
	}
}

void updateLife(int** world, int larg, int height){
	for (int j = 0; j < height; j++){
		for (int i = 0; i < larg; i++){
			if (world[j * height + i][1] == 3) world[j * height + i][0] = 1;
			if ((world[j * height + i][1] < 2) | (world[j * height + i][1] > 3)) world[j * height + i][0] = 0;
		}
	}
}

void iterate(int** world, int larg, int height){
	printf("appel de updateNbNeighbour\n");
	updateNbNeighbour(world, larg, height);
	updateLife(world, larg, height);
}

void printWorld(int** world, int larg, int height){
	system("clear");
	printf(" ");
	for (int i = 0; i < larg; i ++) printf("_");
	printf("\n");
	for (int PosJ = 0; PosJ < height; PosJ++){
		printf("|");
		for (int PosI = 0; PosI < larg; PosI++){
			if (world[PosJ * height + PosI][0] == 1) printf("■");
			else printf(" ");
		}
		printf("|\n");
	}
	printf(" ");
	for (int i = 0; i < larg; i ++) printf("_");
	printf("\n");
}

int main(){
	srand(time(NULL));
	printf("Quelle sera la largeur du monde ?\n");
	int larg;
	scanf("%d", &larg);

	printf("Quelle sera la hauteur du monde ?\n");
	int height;
	scanf("%d", &height);

	printf("Combien d'itérations voulez vous voir ?\n");
	int it;
	scanf("%d", &it);

	printf("C'est parti !!\n");
	system("sleep 4");

	int** world = initWorld(height, larg);

	for (int i = 0; i < it; i++){
		iterate(world, larg, height);
		printWorld(world, larg, height);
		printf("itération %d\n", i+1);
		system("sleep 1");
	}
	return 1;
}
