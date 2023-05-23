#include "Header.h"

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


void invert_card(card* card1, card* card2){
    card* transit_card = malloc(sizeof(card));
    //transit_card = card1
    (*transit_card).hidden = (*card1).hidden;
    for (int i=0 ; i<4 ; i++){
        (*transit_card).type[i] = (*card1).type[i];
        (*transit_card).m.type[i] = (*card1).m.type[i];     //monster
        (*transit_card).r.type[i] = (*card1).r.type[i];     //relic
    }

    //card1=card2
    (*card1).hidden = (*card2).hidden;
    for (int i=0 ; i<4 ; i++){
        (*card1).type[i] = (*card2).type[i];
        (*card1).m.type[i] = (*card2).m.type[i];            //monster
        (*card1).r.type[i] = (*card2).r.type[i];            //relic
    }

    //card2=transit_card
    (*card2).hidden = (*transit_card).hidden;
    for (int i=0 ; i<4 ; i++){
        (*card2).type[i] = (*transit_card).type[i];
        (*card2).m.type[i] = (*transit_card).m.type[i];     //monster
        (*card2).r.type[i] = (*transit_card).r.type[i];     //relic
    }
    free(transit_card);
}

void generate_board (card* tab, int size){
    char cards[] = { 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'b' , 'b' , 'b' , 'b' , 'z' , 'z' , 'z' , 'z' , 't' , 't' , 't' , 't' , 'h' , 'h' , 'h' , 'h' , 'C' , 'C' , 'T' , 'T' , 'E' , 'B' , 'G' , 'D', 'P' };
    int remaining_card = 32;                               // remaining_card = cartes_restantes
    /*
    cards[] est le tableau de toutes nos 32 cartes à placer aléatoirement sur un plateau de 36.
    Voici le détail de ces cartes :
        -> Les 7 événements :
            'e' = événement (x7)
        -> Les 16 monstres :
            'b' = basilic   (x4)
            'z' = zombie    (x4)
            't' = troll     (x4)
            'h' = harpie    (x4)
        -> Les 2 coffres au trésor :
            'C' = coffre    (x2)
        -> Les 2 totems :
            'T' = totem     (x2)
        -> Les 4 armes antiques (reliques) :
            'E' = épée      (x1)
            'B' = bâton     (x1)
            'G' = grimoire  (x1)
            'D' = dague     (x1)
        -> 1 portail de téléportation :
            'P' = portail   (x1)
    */
    //le tableau tab est déjà initialisé dans une fonction précédente, pas besoin de le faire ici
    for (int i=1 ; i<(size-1) ; i++){
        for (int j=1 ; j<(size-1) ; j++){
            if (remaining_card > 0){
                int alea= rand() % remaining_card;
                // événement
                if(cards[alea] == 'e'){
                    (*(tab + i*size + j)).type[3] = 1;
                }
                //Les 4 monstres
                else if(cards[alea] == 'b'){
                    (*(tab + i*size + j)).m.type[3] = 1;
                }
                else if(cards[alea] == 'z'){
                    (*(tab + i*size + j)).m.type[0] = 1;
                }
                else if(cards[alea] == 't'){
                    (*(tab + i*size + j)).m.type[1] = 1;
                }
                else if(cards[alea] == 'h'){
                    (*(tab + i*size + j)).m.type[2] = 1;
                }
                // coffre et totem
                else if(cards[alea] == 'C'){
                    (*(tab + i*size + j)).type[0] = 1;
                }
                else if(cards[alea] == 'T'){
                    (*(tab + i*size + j)).type[1] = 1;
                }
                //Les 4 armes antiques
                else if(cards[alea] == 'E'){
                    (*(tab + i*size + j)).r.type[1] = 1;
                }
                else if(cards[alea] == 'B'){
                    (*(tab + i*size + j)).r.type[0] = 1;
                }
                else if(cards[alea] == 'G'){
                    (*(tab + i*size + j)).r.type[2] = 1;
                }
                else if(cards[alea] == 'D'){
                    (*(tab + i*size + j)).r.type[3] = 1;
                }
                //portail
                else if(cards[alea] == 'P'){
                    (*(tab + i*size + j)).type[2] = 1;
                }
                
                else {
                    printf(" OUPS ! Le jeu n'a pas pu être créé. La carte générée aléatoirement n'est pas dans le paquet.\n");
                    exit(1);
                }
                cards[alea] = cards[remaining_card-1];
                remaining_card = remaining_card -1;
            }
            else{
                printf("Toutes les cartes du jeu sont placées !\n");                //est affiché 4 fois car il y a 4 cases vides pour mettre les joueurs
            }
        }
    }
    invert_card( tab + 1*size + 3 , tab + 6*size + 3);
    invert_card( tab + 3*size + 6 , tab + 6*size + 5);
    invert_card( tab + 4*size + 1 , tab + 6*size + 6);
}