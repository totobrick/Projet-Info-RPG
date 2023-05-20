//A MODIFIER : mettre le portail, prendre en compte la place des joueurs (4 cases vides)
//      ->mettre ce qu'il y a sur cases J1, J2, J3, J4 sur les 4 dernières cases pour libérer la place aux 4 joueurs
//PB : le jeu n'est pas ALEATOIRE !

void generate_board (card* tab, int size);

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
                    (*(tab + i*size + j)).event = 1;
                }
                //Les 4 monstres
                else if(cards[alea] == 'b'){
                    (*(tab + i*size + j)).m.basilisk = 1;
                }
                else if(cards[alea] == 'z'){
                    (*(tab + i*size + j)).m.zombie = 1;
                }
                else if(cards[alea] == 't'){
                    (*(tab + i*size + j)).m.troll = 1;
                }
                else if(cards[alea] == 'h'){
                    (*(tab + i*size + j)).m.harpy = 1;
                }
                // coffre et totem
                else if(cards[alea] == 'C'){
                    (*(tab + i*size + j)).treasure = 1;
                }
                else if(cards[alea] == 'T'){
                    (*(tab + i*size + j)).totem = 1;
                }
                //Les 4 armes antiques
                else if(cards[alea] == 'E'){
                    (*(tab + i*size + j)).r.sword = 1;
                }
                else if(cards[alea] == 'B'){
                    (*(tab + i*size + j)).r.stick = 1;
                }
                else if(cards[alea] == 'G'){
                    (*(tab + i*size + j)).r.grimoire = 1;
                }
                else if(cards[alea] == 'D'){
                    (*(tab + i*size + j)).r.dagger = 1;
                }
                //portail
                else if(cards[alea] == 'P'){
                    (*(tab + i*size + j)).portal = 1;
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
