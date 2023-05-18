//nombre joueur, 
#include <stdio.h>
#include <stlib.h>
#include <time.h>


#define SIZE 8		//tableau 6x6

int main(){
    card* board;                                //allocation espace mémoire
    board = malloc(sizeof(card)*8*8);           // board est l'adresse de la 1ere case du tableau
    if (board == NULL){
        printf("Echec de la création du plateau de jeu !\n");
        exit(1);
    }
    
    free(board);                                //restitution espace mémoire
    return 0;
}
