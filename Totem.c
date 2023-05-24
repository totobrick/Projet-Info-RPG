#include "Header.h"
extern int Totem1;
extern int Totem2;

void teleport(Player P, card c) {

    // Vérification si le joueur est sur l'un des totems
    if (P.x==Totem1 && P.y==Totem1) {
        // Téléportation vers le deuxième totem
        P.X=Totem2
        P.y=Totem2
        printf("Le joueur a été téléporté vers le deuxième totem.\n");
    } else if (P.x==Totem2 && P.y==Totem2) {
        // Téléportation vers le premier totem
        P.X=Totem1
        P.y=Totem1
        printf("Le joueur a été téléporté vers le premier totem.\n");
    } else {
        printf("Le joueur n'est pas sur l'un des totems, aucune téléportation n'a eu lieu.\n");
    }
}
