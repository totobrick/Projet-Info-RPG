#include "Header.h"

#define ROWS 6
#define COLS 6

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




// ----------------------------------------------------------------------------


// game_functions.c

#include <stdio.h>

#define ROWS 6
#define COLS 6

void displayTable(int table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void move(int table[ROWS][COLS], int* posX, int* posY, int direction) {
    int deltaX = 0;
    int deltaY = 0;
    
    // Determine the movement based on the direction
    switch (direction) {
        case 2: // Down
            deltaX = 1;
            break;
        case 8: // Up
            deltaX = -1;
            break;
        case 4: // Left
            deltaY = -1;
            break;
        case 6: // Right
            deltaY = 1;
            break;
        default:
            printf("Invalid direction!\n");
            return;
    }
    
    // Calculate the new coordinates
    int newPosX = *posX + deltaX;
    int newPosY = *posY + deltaY;
    
    // Check if the new coordinates are valid
    if (newPosX >= 0 && newPosX < ROWS && newPosY >= 0 && newPosY < COLS) {
        // Move to the new cell
        *posX = newPosX;
        *posY = newPosY;
    } else {
        printf("Invalid move!\n");
    }
}

void playGame() {
    int table[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int posX = 0; // Initial X coordinate
    int posY = 0; // Initial Y coordinate
    
    displayTable(table);
    
    int direction;
    while (1) {
        printf("Enter a direction (2: Down, 8: Up, 4: Left, 6: Right): ");
        scanf("%d", &direction);
        
        // Move based on the direction entered by the user
        move(table, &posX, &posY, direction);
        displayTable(table);
    }
}

int main() {
    playGame();
    
    return 0;
}
