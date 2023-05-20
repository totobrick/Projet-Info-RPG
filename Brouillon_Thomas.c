int main(){
    card* game;
    game = malloc(SIZE*SIZE*sizeof(card));            //game est notre plateau de jeu (tableau)
    board(game, SIZE);
    for (int i=0 ; i<SIZE ; i++){
        printf("\n    Ligne n°%d\n",i);
        for (int j=0 ; j<SIZE ; j++){
            printf("[%d,%d,%d,%d,%d,%d,   %d,%d,%d,%d,   %d,%d,%d,%d]\n",(*(game + i*SIZE + j)).wall, (*(game + i*SIZE + j)).hidden, (*(game + i*SIZE + j)).treasure, (*(game + i*SIZE + j)).totem, (*(game + i*SIZE + j)).portal, (*(game + i*SIZE + j)).event, (*(game + i*SIZE + j)).m.zombie, (*(game + i*SIZE + j)).m.troll, (*(game + i*SIZE + j)).m.harpy, (*(game + i*SIZE + j)).m.basilisk, (*(game + i*SIZE + j)).r.stick, (*(game + i*SIZE + j)).r.sword, (*(game + i*SIZE + j)).r.grimoire, (*(game + i*SIZE + j)).r.dagger);
        }
    }
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
