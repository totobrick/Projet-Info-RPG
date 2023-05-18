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
    int event;          //evenement????
    monster m;
    relic r;
} card;

void board (card tab, int size);
void init_wall (card tab, int size);
void init_card (card tab, int size);
void hidden_box(card tab, int size);
void show_board (card tab, int size);

/*_________________________________________________________________________________________________*/

void board (card* tab, int size){
    init_wall(tab, size);
    init_card(tab, size);
    
    show_board (tab, size);
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
}
/*
void init_card (card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<size ; j++){
            tab[i][j].hidden = 0;
            tab[i][j].treasure = 0;
            tab[i][j].totem = 0;
            tab[i][j].portal = 0;
            tab[i][j].event = 0;
            //monster :
            tab[i][j].m.zombie = 0;
            tab[i][j].m.troll = 0;
            tab[i][j].m.harpy = 0;
            tab[i][j].m.basilisk = 0;
            //relic :
            tab[i][j].r.stick = 0;
            tab[i][j].r.sword = 0;
            tab[i][j].r.grimoire = 0;
            tab[i][j].r.dagger = 0;
        }
    }
    
}

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

