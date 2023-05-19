#include <stdio.h>

enum Weapons { TORCH = 1, SHIELD = 2, AXE = 3, BOW = 4 };            //ATTENTION aux =1,2,3,4, je pense qu'il n'est pas nécessaire
enum Enemies { BASILISK = 1, ZOMBIE = 2, TROLL = 3, HARPY = 4 };

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

void combat(int weapon, int enemy) {
    switch (enemy) {
        case BASILISK:
            if (weapon == SHIELD) {
                printf("Le Basilic est vaincu !\n");
            } else {
                printf("Game Over ! Le Basilic vous a tué.\n");
            }
            break;
        case ZOMBIE:
            if (weapon == TORCH) {
                printf("Le Zombie est vaincu !\n");
            } else {
                printf("Game Over ! Le Zombie vous a tué.\n");
            }
            break;
        case TROLL:
            if (weapon == AXE) {
                printf("Le Troll est vaincu !\n");
            } else {
                printf("Game Over ! Le Troll vous a tué.\n");
            }
            break;
        case HARPY:
            if (weapon == BOW) {
                printf("La Harpie est vaincue !\n");
            } else {
                printf("Game Over ! La Harpie vous a tué.\n");
            }
            break;
        default:
            printf("Ennemi non reconnu !\n");
            break;
    }
}

int main() {
    int weapon;
    int enemy; 
    int verif = 0;
  

    printf("Choisissez votre arme : \n");
    printf("1. Torche\n");
    printf("2. Bouclier\n");
    printf("3. Hache\n");
    printf("4. Arc\n");
    do {
        printf("Votre choix: ");
        verif = scanf("%d", &weapon);
        vide_buffer();
    } while (weapon != 1 && weapon != 2 && weapon != 3 && weapon != 4 || verif != 1);
verif=0;
    printf("Choisissez votre ennemi : \n");
    printf("1. Basilic\n");
    printf("2. Zombie\n");
    printf("3. Troll\n");
    printf("4. Harpie\n");
    do {
        printf("Votre choix:  ");
        verif = scanf("%d", &enemy);
        vide_buffer();
    } while (enemy != 1 && enemy != 2 && enemy != 3 && enemy != 4 || verif != 1);

    combat(weapon, enemy);

    return 0;
}

 
