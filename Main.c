#include "Header.h"

//nombre joueur, 
void resetPlayerPosition(int* posX, int* posY) {
    *posX = 0;
    *posY = 0;
    printf("Player's position reset to (0, 0).\n");


int main(){
    card* board;                                //allocation espace mémoire
    board = malloc(sizeof(card)*SIZE*SIZE);           // board est l'adresse de la 1ere case du tableau
    if (board == NULL){
        printf("Echec de la création du plateau de jeu !\n");
        exit(1);
    }
    
    free(board);                                //restitution espace mémoire
    return 0;
    
    
    if (checkTreasure(player)) {
        printf("Félicitations! Le joueur a obtenu le trésor et la relique correspondant à sa classe.\n");
    } else {
        printf("Désolé, le joueur n'a pas obtenu le trésor et la relique correspondant à sa classe.\n");
    }
 // à ne surtout pas enlever et à lier dans le futur
}
