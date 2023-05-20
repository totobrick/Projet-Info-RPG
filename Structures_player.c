#include<stdio.h>

typedef struct{
  char nom[100]; //ATTENTION depasement tableau
  int class; //Magicien, guerrier, ranger, voleur
  int weapon; //1,2,3,4
  int relic; //0,1
  int life; // 0=mort 1=vivant
  int x; // place x dans le tableau entre 0 et 7
  int y; // place y dans le tableau entre 0 et 7
}Joueur;


void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

int main() {  
    class = 0
    int verif = 0;
   

    do {
        printf("Quelle est votre classe ? ");
        verif = scanf("%d", &classe);
        vide_buffer();
    } while (classe != 1 && classe != 2 && classe != 3 && classe != 4 || verif != 1);
  
  
