#include "Header.h"

void afficherTexteCentre(const char *texte, int largeur) {
    int longueur = strlen(texte);
    int espaces = (largeur - longueur) / 2;

    for (int i = 0; i < espaces; i++) {
        printf(" ");
    }

    printf("%s\n", texte);
}

int main() {
    char texte[] = "Bienvenue dans CY Memory RPG !";
    int largeur = 80;

    afficherTexteCentre(texte, largeur);

    return 0;
}
