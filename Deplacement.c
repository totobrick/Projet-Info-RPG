#include "Header.h"
#include <stdio.h>
/*
void displayTable(int table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}
*/


void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}


void move(int table[ROWS][COLS], int* posX, int* posY, int direction) {
    int deltaX = 0;
    int deltaY = 0;
    int verif = 0;
    int direction;
    
    // Determine le mouvement basé sur la direction
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
            printf("Direction Invalide!\n");
            return;
    }
    
    // calcule les nouvelle coordonné
    int newPosX = *posX + deltaX;
    int newPosY = *posY + deltaY;
    
    // check si les nouvelles coordonné sont bonnes
    if (newPosX >= 0 && newPosX < ROWS && newPosY >= 0 && newPosY < COLS) {
        // Move to the new cell
        *posX = newPosX;
        *posY = newPosY;
    } else {
        printf("Mouvement Invalide!\n");
    }
//}

//void playGame() 
    /*
    int posX = 0; // Initial X coordinate
    int posY = 0; // Initial Y coordinate
    */
    
    displayTable(table);
    
        do {
        printf("entrer un direction (2: Bas, 8: Haut, 4: Gauche, 6: Droite): ");
        verif = scanf("%d", &direction);
        vide_buffer();
    } while (direction != 2 && direction != 4 && direction != 6 && direction != 8 || verif != 1);
    
        // Move basé sur la direction choisi du joueur
        move(table, &posX, &posY, direction);
        //displayTable(table);
//}

