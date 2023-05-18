#include <stdio.h>

enum Armes { TORCHE = 1, BOUCLIER = 2, HACHE = 3, ARC = 4 };
enum Ennemis { BASILIC = 1, ZOMBIE = 2, TROLL = 3, HARPIE = 4 };

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

void combat(int arme, int ennemi) {
    switch (ennemi) {
        case BASILIC:
            if (arme == BOUCLIER) {
                printf("Le Basilic est vaincu !\n");
            } else {
                printf("Game Over ! Le Basilic vous a tué.\n");
            }
            break;
        case ZOMBIE:
            if (arme == TORCHE) {
                printf("Le Zombie est vaincu !\n");
            } else {
                printf("Game Over ! Le Zombie vous a tué.\n");
            }
            break;
        case TROLL:
            if (arme == HACHE) {
                printf("Le Troll est vaincu !\n");
            } else {
                printf("Game Over ! Le Troll vous a tué.\n");
            }
            break;
        case HARPIE:
            if (arme == ARC) {
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
    int arme;
    int ennemi; 
    int verif = 0;
  

    printf("Choisissez votre arme : \n");
    printf("1. Torche\n");
    printf("2. Bouclier\n");
    printf("3. Hache\n");
    printf("4. Arc\n");
      do {
        printf("Votre choix: ");
        verif = scanf("%d", &arme);
        vide_buffer();
    } while (arme != 1 && arme != 2 && arme != 3 && arme != 4 || arme != 1);
verif=0;
    printf("Choisissez votre ennemi : \n");
    printf("1. Basilic\n");
    printf("2. Zombie\n");
    printf("3. Troll\n");
    printf("4. Harpie\n");
       do {
        printf("Votre choix:  ");
        verif = scanf("%d", &ennemi);
        vide_buffer();
    } while (ennemi != 1 && ennemi != 2 && ennemi != 3 && ennemi != 4 || ennemi != 1);

    combat(arme, ennemi);

    return 0;
}

 
