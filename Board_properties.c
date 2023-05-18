#include <stdio.h>
#define SIZE 8		//tableau 6x6

#include<stdio.h>

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
	int mur;	//1=oui 0=non
	int hidden;	//0=cache 1= case visible
    monster m;
    int treasure;
    int totem;
    relic r;
    int portal;			//portal = portail
    int event;
    //evenement????
} space;


void board (space tab, int size){
	for (int j=0; j<size ; j++){
		tab[0][j].mur=1;
	}
	for (int i=1 ; i<(size-1) ; i++){
		tab[i][0].mur=1;
		for (int j=1 ; j<(size-1) ; j++){
			tab[i][j].mur=0;
		}
		tab[i][7].mur=1;
	}
	for (int j=0; j<size ; j++){
		tab[size-1][j].mur=1;
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

void return_box(space tab, int size){
	for (int i=0 ; i<size ; i++){
		tab[i][0].hidden=0;
		for (int j=0 ; j<size ; j++){
			tab[i][j].hidden=0;
		}
}
