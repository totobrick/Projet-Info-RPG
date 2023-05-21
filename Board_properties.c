/*_________________________________________________________________________________________________*/

void board (card* tab, int size){
    init_wall(tab, size);
    init_board(tab, size);
    generate_board(tab, size);
    //show_board (tab, size);
}

/*_________________________________________________________________________________________________*/

void init_wall (card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int j=0; j<size ; j++){
        (*(tab + 0*size + j)).wall=1;
    }
    for (int i=1 ; i<(size-1) ; i++){
        (*(tab + i*size + 0)).wall=1;
        for (int j=1 ; j<(size-1) ; j++){
            (*(tab + i*size + j)).wall=0;
        }
        (*(tab + i*size + 7)).wall=1;
    }
    for (int j=0; j<size ; j++){
        (*(tab + (size-1)*size + j)).wall=1;
    }
    printf("Initialisation des murs terminée.\n");
}

void init_board (card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<size ; j++){
            init_card(tab +  i*size + j);
        }
    }
    printf("Initialisation des cartes terminée.\n");
}

void init_card(card* card1){
    (*card1).hidden = 0;
    for (int i=0 ; i<4 ; i++){
        (*card1).type[i] = 0;
        (*card1).m.type[i] = 0;         //monster
        (*card1).r.type[i] = 0;         //relic
    }
}
