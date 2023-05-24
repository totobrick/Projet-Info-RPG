#include "Header.h"

// Structure pour représenter un joueur
typedef struct{
  char nom[100]; //ATTENTION depasement tableau
  int class; //Magicien, guerrier, ranger, voleur
  int weapon; //1,2,3,4
  int relic; //0,1
  int treasure; //trésore = case, donc pas sur de devoir le mettre en structure player
  int life; // 0=mort 1=vivant
  int x; // place x dans le tableau entre 0 et 7
  int y; // place y dans le tableau entre 0 et 7
}Player;

// Fonction pour vérifier si le joueur a obtenu le trésor et la relique correspondant à sa classe
int checkTreasure(Player player) {
    int victory = 0;

    switch (player.class) {
        case 1: // Guerrier
            if (player.treasure == 1 && player.relic == 1) {
                victory = 1;
            }
            break;
        case 2: // Ranger
            if (player.treasure == 1 && player.relic == 1) {
                victory = 1;
            }
            break;
        case 3: // Magicien
            if (player.treasure == 1 && player.relic == 1) {
                victory = 1;
            }
            break;
        case 4: // Voleur
            if (player.treasure == 1 && player.relic == 1) {
                victory = 1;
            }
            break;
    }

    return victory;
}
