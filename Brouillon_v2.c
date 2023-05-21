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
