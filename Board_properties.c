#include <stdio.h>
#define SIZE 8		//tableau 6x6

typedef struct{
	int mur;	//1=oui 0=non
} space;		//space = 1 case du jeu

void board (space tab, int size){
	for (int i=1 ; i<(size-1) ; i++){
		for (int j=0 ; j<size ; j++){
			tab[i][j]
		}
	}
}

void show_board (space tab, int size){
	for (int i=0 ; i<size ; i++){
		for (int j=0 ; j<size ; j++){
			printf("	", tab[i][j]);		//A COMPLETER
		}
		printf("\n", tab[i][j]);			//A COMPLETER
	}
}
