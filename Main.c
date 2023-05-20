//nombre joueur, 

int main(){
    card* board;                                //allocation espace mémoire
    board = malloc(sizeof(card)*8*8);           // board est l'adresse de la 1ere case du tableau
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
}
