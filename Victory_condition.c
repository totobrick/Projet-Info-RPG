#include "Header.h"


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
