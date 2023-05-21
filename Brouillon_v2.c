typedef struct{
    int type[4];
        /*
        type[0] = zombie        (1=oui 0=non)                           <- 1.Torche
        type[1] = troll         (1=oui 0=non)                           <- 2.Hache
        type[2] = harpy         (1=oui 0=non)                           <- 3.Arc
        type[3] = basilisk      (1=oui 0=non)       basilisk = basilic  <- 4.Bouclier
        */ 
} monster;

typedef struct{
    int type[4];
        /*
        type[0] = stick         (1=oui 0=non)       stick = baton
        type[1] = sword         (1=oui 0=non)       sword = epee
        type[2] = grimoire      (1=oui 0=non)
        type[3] = dagger        (1=oui 0=non)       dagger = dague
        */           
} relic;

typedef struct{
    int wall;       //1=oui 0=non
    int hidden;     //1=case visible  0=case cache
    int type[4];
        /*
        type[0] = treasure      (1=oui 0=non)
        type[1] = totem         (1=oui 0=non)
        type[2] = portal        (1=oui 0=non)       portal = portail
        type[3] = event         (1=oui 0=non)
        */
    monster m;
    relic r;
} card;

typedef struct{
    int neutral;    // 0=non et 1=oui 
    int malus;      // 0=non et 1=oui 
} event;


void board (card* tab, int size);
void init_wall (card* tab, int size);
void init_board (card* tab, int size);
void init_card(card* card1);

/*_________________________________________________________________________________________________*/

void board (card* tab, int size){
    init_wall(tab, size);
    init_board(tab, size);
    
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
    }
    //monster :
    for (int i=0 ; i<4 ; i++){
        (*card1).m.type[i] = 0;
    }
    //relic :
    for (int i=0 ; i<4 ; i++){
        (*card1).r.type[i] = 0;
    }
}
