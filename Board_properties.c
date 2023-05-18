#include <stdio.h>
#include <time.h>
#include <stlib.h>

void board (card tab, int size);
void init_wall (card tab, int size);
void hidden_box(card tab, int size);
void show_board (card tab, int size);

typedef struct{
    int zombie;  // 1, < Torche
    int troll;   // 2, < Hache
    int harpy;  // 3, < Arc
    int basilisk; // 4, < Bouclier				basilisk = basilic 
} monster;

typedef struct{
    int stick;      	//stick = baton
    int sword;      	//sword = epee
    int grimoire;
    int dagger;			//dagger = dague
} relic;

typedef struct{
    int wall;    //1=oui 0=non
    int hidden; //0=cache 1=case visible
    monster m;
    int treasure;
    int totem;
    relic r;
    int portal;			//portal = portail
    int event;
    //evenement????
} card;

void init_wall (card tab, int size){
	if (size<=0){
		exit(1);
	}
	for (int j=0; j<size ; j++){
		tab[0][j].wall=1;
	}
	for (int i=1 ; i<(size-1) ; i++){
		tab[i][0].wall=1;
		for (int j=1 ; j<(size-1) ; j++){
			tab[i][j].wall=0;
		}
		tab[i][7].wall=1;
	}
	for (int j=0; j<size ; j++){
		tab[size-1][j].wall=1;
	}
}

void board (card tab, int size){
	init_wall(tab, size);
}

void show_board (card tab, int size){
	if (size<=0){
		exit(1);
	}
	for (int i=0 ; i<size ; i++){
		for (int j=0 ; j<size ; j++){
			printf("	", tab[i][j]);		//A COMPLETER
		}
		printf("\n", tab[i][j]);			//A COMPLETER
	}
}

void hidden_box(card tab, int size){
	if (size<=0){
		exit(1);
	}
	for (int i=0 ; i<size ; i++){
		tab[i][0].hidden=0;
		for (int j=0 ; j<size ; j++){
			tab[i][j].hidden=0;
		}
}

