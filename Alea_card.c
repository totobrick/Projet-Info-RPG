void generate_board (card tab[][], int size);

void generate_board (card tab[][], int size){       //ATTENTION METTRE EN POINTEUR
    char cards[] = { 'b' , 'b' , 'b' , 'b' , 'z' , 'z' , 'z' , 'z' , 't' , 't' , 't' , 't' , 'h' , 'h' , 'h' , 'h' , 'E' , 'B' , 'G' , 'D' , 'C' , 'C' , 'T' , 'T' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' };
    int remaining_card = 32;                               // remaining_card = cartes_restantes
    /*
    cards[] est le tableau de toutes nos cartes à placer aléatoirement.
    Voici le détail de ces cartes :
        -> Les 16 monstres :
            'b' = basilic   (x4)
            'z' = zombie    (x4)
            't' = troll     (x4)
            'h' = harpie    (x4)
        -> Les 4 armes antiques (reliques) :
            'E' = épée      (x1)
            'B' = bâton     (x1)
            'G' = grimoire  (x1)
            'D' = dague     (x1)
        -> Les 2 coffres au trésor :
            'C' = coffre    (x2)
        -> Les 2 totems :
            'T' = totem     (x2)
        -> Les 8 événements :
            'e' = événement (x8)
    */
    
    //le tableau tab est déjà initialisé dans une fonction précédente, pas besoin de le faire ici
    for (int i=1 ; i<(size-1) ; i++){
        for (int j=1 ; j<(size-1) ; j++){
            if (remaining_card > 0){
                int alea= rand() % remaining_card;
                //Les 4 monstres
                if(cards[alea] == 'b'){
                    tab[i][j].m.basilisk = 1;
                }
                else if(cards[alea] == 'z'){
                    tab[i][j].m.zombie = 1;
                }
                else if(cards[alea] == 't'){
                    tab[i][j].m.troll = 1;
                }
                else if(cards[alea] == 'h'){
                    tab[i][j].m.harpy = 1;
                }
                //Les 4 armes antiques
                else if(cards[alea] == 'E'){
                    tab[i][j].r.sword = 1;
                }
                else if(cards[alea] == 'B'){
                    tab[i][j].r.stick = 1;
                }
                else if(cards[alea] == 'G'){
                    tab[i][j].r.grimoire = 1;
                }
                else if(cards[alea] == 'D'){
                    tab[i][j].r.dagger = 1;
                }
                // coffre et totem
                else if(cards[alea] == 'C'){
                    tab[i][j].treasure = 1;
                }
                else if(cards[alea] == 'T'){
                    tab[i][j].totem = 1;
                }
                // événement
                else if(cards[alea] == 'e'){
                    tab[i][j].event = 1;
                }
                else {
                    printf(" OUPS ! Le jeu n'a pas pu être créé. La carte générée aléatoirement n'est pas dans le paquet.\n");
                    exit(1);
                }
                cards[alea] = cards[remaining_card-1];
                remaining_card = remaining_card -1;
            }
            else{
                printf("Toutes les cartes du jeu sont placées !\n");
            }
        }
    } 
}
    
    
    
    
    
    
    
    
    
    
    
    
    
/*Pour générer la 1ere carte :
        de 1 à 16 on aura un monstre
            -> 1 à 4 : Basilic
            -> 5 à 8 : Zombie
            -> 9 à 12 : Troll
            -> 13 à 16 : Harpie
   
    */
 /*
    int basilisk = 4, zombie = 4, troll = 4, harpy = 4;     //les 16 monstres
    int sword = 1, stick = 1, grimoire = 1, dagger = 1;     //les 4 armes antiques
    int treasure = 2;                                       //les 2 trésors
    int totem = 2;                                          //les 2 totems
    int event = 8;
    
    int all_cards[12]= {basilisk, zombie, troll, harpy, sword, stick, grimoire, dagger, treasure, totem, event};
    int coeff[12];
    coeff[0] = basilisk
    for (int i=1 ; i<strlen(all_cards) ; i++){
        coeff[i] = coeff[i-1] + all_cards[i];
    }
    int nbr_card = 0;
    for (int i=0; i<strlen(all_cards) ; i++){
        nbr_card += all_cards[i];                          // nbre_cartes = 36-4 = 32 (4 seront vierges pour les perso)
    }
    
    int alea= 0 ;
    for (int i=1 ; i<(size-1) ; i++){
        for (int j=1 ; j<(size-1) ; j++){
            alea = (rand()%nbr_card) + 1;                   //varie de 1 à 32 (tour 1)
            (*(tab + i*size + j))
        }
    }
*/
    
    
/*
    int basilisk = 4, zombie = 4, troll = 4, harpy = 4;     //les 16 monstres
    int sword = 1, stick = 1, grimoire = 1, dagger = 1;     //les 4 armes antiques
    int treasure = 2;                                       //les 2 trésors
    int totem = 2;                                          //les 2 totems
    int event = 8;
    int nbre_card = basilisk + zombie + troll + harpy + sword + stick + grimoire + dagger + treasure + totem + event ;  // il y a 36-4=32 cartes à coder, 4 seront vierges (pour les perso)
    int alea;
    
    while (nbre_card>0){
        alea = (rand() % nbre_card) +1;
        whi
    }

}
*/
