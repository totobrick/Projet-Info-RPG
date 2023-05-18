#include<stdio.h>

typedef struct{
    int zombie;  // 1, < Torche
    int troll;   // 2, < Hache
    int harpie;  // 3, < Arc
    int basilic; // 4, < Bouclier
} monstre;

typedef struct{
    int baton;      
    int epee;      
    int grimoire;
    int dague;    
} relique;

typedef struct{
    int cache; //0=cache 1= case visible
    monstre m;
    int tresor;
    int totem;
    relique r;
    int portail;
    int mur;
    int event;
    //evenement????
} Case;
