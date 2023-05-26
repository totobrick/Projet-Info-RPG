#include "Header.h"


// Fonction pour vérifier si le joueur a obtenu le trésor et la relique 

int checkTreasure(Player* P) {
    int victory = 0;
    if (P.treasure == 1 && P.relic == 1) {
                victory = 1;

}
    else{
     victory = 0;   
    }

    return victory;
}

