#include<stdio.h>

typedef struct{
    int zombie;
    int troll;
    int harpie;
    int basilic;
} monstre;

typedef struct{
    int baton;
    int epee;
    int grimoire;
    int dague;    
} relique;

typedef struct{
    int cache;
    monstre m;
    int tresor;
    int totem;
    relique r;
    int portail;
    int mur;
    int event;
    //evenement????
} Case;