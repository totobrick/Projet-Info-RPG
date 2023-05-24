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
//}

//void playGame() 
    /*
    int posX = 0; // Initial X coordinate
    int posY = 0; // Initial Y coordinate
    */
    
    displayTable(table);
    
    int direction;
        printf("Enter a direction (2: Down, 8: Up, 4: Left, 6: Right): ");
        scanf("%d", &direction);
        
        // Move based on the direction entered by the user
        move(table, &posX, &posY, direction);
        //displayTable(table);
//}

