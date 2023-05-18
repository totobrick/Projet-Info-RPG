void generate_board (card* tab, int size){       // il y a 36-4=32 cartes à coder, 4 seront vierges (pour les perso)
    /*Pour générer la 1ere carte :
        de 0 à 15 on aura un monstre
            -> 0 à 3 : Basilic
            -> 4 à 7 : Zombie
            -> 8 à 11 : Troll
            -> 12 à 15 : Harpie
    
    
    
    */
    int basilisk = 4, zombie = 4, troll = 4, harpy = 4;     //les 16 monstres
    int sword = 1, stick = 1, grimoire = 1, dagger = 1;     //les 4 armes antiques
    int treasure = 2;                                       //les 2 trésors
    int totem = 2;                                          //les 2 totems
    int event = 8;
    int nbre_card = basilisk + zombie + troll + harpy + sword + stick + grimoire + dagger + treasure + totem + event ;
    int alea = rand() % nbre_card;

}
