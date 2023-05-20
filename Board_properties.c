typedef struct{
    int zombie;     // 1, < Torche
    int troll;      // 2, < Hache
    int harpy;      // 3, < Arc
    int basilisk;   // 4, < Bouclier				basilisk = basilic 
} monster;

typedef struct{
    int stick;      	//1=oui 0=non               stick = baton
    int sword;      	//1=oui 0=non               sword = epee
    int grimoire;       //1=oui 0=non
    int dagger;			//1=oui 0=non               dagger = dague
} relic;

typedef struct{
    int wall;       //1=oui 0=non
    int hidden;     //1=case visible  0=case cache
    int treasure;   //1=oui 0=non
    int totem;      //1=oui 0=non
    int portal;     //1=oui 0=non			        portal = portail
    int event;     //1=oui 0=non 
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
    (*card1).treasure = 0;
    (*card1).totem = 0;
    (*card1).portal = 0;
    (*card1).event = 0;
    //monster :
    (*card1).m.zombie = 0;
    (*card1).m.troll = 0;
    (*card1).m.harpy = 0;
    (*card1).m.basilisk = 0;
    //relic :
    (*card1).r.stick = 0;
    (*card1).r.sword = 0;
    (*card1).r.grimoire = 0;
    (*card1).r.dagger = 0;
}
