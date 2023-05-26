#include "Header.h"

int main(){
    srand(time(NULL));
    card* game = NULL; 
    game = malloc(SIZE*SIZE*sizeof(card));            //game est notre plateau de jeu (tableau)
    if (game == NULL){
        printf("Problème d'allocation de mémoire pour la création du tableau du jeu.\n");
        exit(10);
    }
    board(game, SIZE);
    for (int i=0 ; i<SIZE ; i++){
        printf("\n    Ligne n°%d\n",i);
        for (int j=0 ; j<SIZE ; j++){
            printf("[%d,%d,%d,%d,%d,%d,   %d,%d,%d,%d,   %d,%d,%d,%d]\n",(*(game + i*SIZE + j)).wall, (*(game + i*SIZE + j)).hidden, (*(game + i*SIZE + j)).type[0], (*(game + i*SIZE + j)).type[1], (*(game + i*SIZE + j)).type[2], (*(game + i*SIZE + j)).type[3], (*(game + i*SIZE + j)).m.type[0], (*(game + i*SIZE + j)).m.type[1], (*(game + i*SIZE + j)).m.type[2], (*(game + i*SIZE + j)).m.type[3], (*(game + i*SIZE + j)).r.type[0], (*(game + i*SIZE + j)).r.type[1], (*(game + i*SIZE + j)).r.type[2], (*(game + i*SIZE + j)).r.type[3]);
        }
    }
    free(game);//ATTENTION
  return 0;
}

/*
void show_board (card* tab, int size){
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

void hidden_box(card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int i=0 ; i<size ; i++){
        tab[i][0].hidden=0;
        for (int j=0 ; j<size ; j++){
            tab[i][j].hidden=0;
        }
    }*/