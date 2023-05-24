#include "Header.h"
extern int Totem1;
extern int Totem2;

void teleport(Player P, card c) {

    // Vérification si le joueur est sur l'un des totems
    if (c.P) {
        // Téléportation vers le deuxième totem
        grid[totem1_x][totem1_y] = 0;
        grid[totem2_x][totem2_y] = 2;
        printf("Le joueur a été téléporté vers le deuxième totem.\n");
    } else if (player_x == totem2_x && player_y == totem2_y) {
        // Téléportation vers le premier totem
        grid[totem2_x][totem2_y] = 0;
        grid[totem1_x][totem1_y] = 2;
        printf("Le joueur a été téléporté vers le premier totem.\n");
    } else {
        printf("Le joueur n'est pas sur l'un des totems, aucune téléportation n'a eu lieu.\n");
    }
}



int main {




}
