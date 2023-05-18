#include <string.h>

void generate_board (card* tab, int size){
    /*Pour générer la 1ere carte :
        de 1 à 16 on aura un monstre
            -> 1 à 4 : Basilic
            -> 5 à 8 : Zombie
            -> 9 à 12 : Troll
            -> 13 à 16 : Harpie
    
    
    
    */
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
