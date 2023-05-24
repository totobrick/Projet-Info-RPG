#include "Header.h"

void afficherMenu() {
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Jouer\n");
        printf("2. Afficher le scoreboard\n");
        printf("3. Sortir\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Lancement du jeu...\n");
                // Appeler la fonction pour jouer ici
                break;
            case 2:
                printf("Affichage du scoreboard...\n");
                // Appeler la fonction pour afficher le scoreboard ici
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 3);
}

int main() {
    afficherMenu();
    return 0;
}
