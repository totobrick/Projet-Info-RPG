#include <stdio.h>

#define ROWS 5
#define COLS 5

void afficherTableau(int tableau[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
}

void deplacer(int tableau[ROWS][COLS], int* posX, int* posY, int direction) {
    int deltaX = 0;
    int deltaY = 0;
    
    // Déterminer le déplacement en fonction de la direction
    switch (direction) {
        case 2: // Bas
            deltaX = 1;
            break;
        case 8: // Haut
            deltaX = -1;
            break;
        case 4: // Gauche
            deltaY = -1;
            break;
        case 6: // Droite
            deltaY = 1;
            break;
        default:
            printf("Direction invalide !\n");
            return;
    }
    
    // Calculer les nouvelles coordonnées
    int newPosX = *posX + deltaX;
    int newPosY = *posY + deltaY;
    
    // Vérifier si les nouvelles coordonnées sont valides
    if (newPosX >= 0 && newPosX < ROWS && newPosY >= 0 && newPosY < COLS) {
        // Déplacer vers la nouvelle case
        *posX = newPosX;
        *posY = newPosY;
    } else {
        printf("Déplacement impossible !\n");
    }
}

int main() {
    int tableau[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int posX = 0; // Coordonnée X initiale
    int posY = 0; // Coordonnée Y initiale
    
    afficherTableau(tableau);
    
    int direction;
    while (1) {
        printf("Entrez une direction (2: Bas, 8: Haut, 4: Gauche, 6: Droite) : ");
        scanf("%d", &direction);
        
        // Déplacer en fonction de la direction entrée par l'utilisateur
        deplacer(tableau, &posX, &posY, direction);
        afficherTableau(tableau);
    }
    
    return 0;
}
