#include <stdio.h>

enum Weapons { TORCH = 0, SHIELD = 1, AXE = 2, BOW = 3 };            //ATTENTION aux =1,2,3,4, je pense qu'il n'est pas nécessaire (non necessaire pour les ennemies, mais pour les armes si car cela facilite le programme) 
enum Enemies { BASILISK = 0, ZOMBIE = 1, TROLL = 2, HARPY = 3 };

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

void combat(int weapon-1, int enemy-1) {
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

