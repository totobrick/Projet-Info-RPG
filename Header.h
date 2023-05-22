#include <stdio.h>
#include <time.h>
#include <unistd.h>         //pour la musique
#include <stdlib.h>

#define SIZE 8              //tableau 6x6

typedef struct{
    char nom[100];            //ATTENTION depasement tableau
    int class;                //Magicien, guerrier, ranger, voleur
    weapons w;                //0=Torche, 1=Shield, 2=Axe, 3=bow
    int relic;                //0,1
    int treasure;             //0=non, 1=oui
    int life;                 // 0=mort 1=vivant
    int x;                    // place x dans le tableau entre 1 et 6
    int y;                    // place y dans le tableau entre 1 et 6
    int x_init;                //place initiale
    int y_init;                //place initiale
}Player;

typedef struct{
    int type[4];
        /*
        type[0] = torch        (1=oui 0=non)                           <- 1.zombie
        type[1] = axe         (1=oui 0=non)                           <- 2.troll
        type[2] = bow         (1=oui 0=non)                           <- 3.harpy
        type[3] = shield       (1=oui 0=non)                          <- 4.basilisk
        */ 
} weapons;

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

void init_wall (card* tab, int size);
void init_board (card* tab, int size);
void init_card(card* card1);
void invert_card(card* card1, card* card2);
void generate_board (card* tab, int size);
void board (card* tab, int size);
