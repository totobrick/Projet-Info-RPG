#include "Header.h"

int main() {
    time_t startTime, endTime;
    int running = 0;
    int input;

    printf("Appuyez sur 1 pour démarrer le chronomètre ou 0 pour l'arrêter...\n");

    while (1) {
        scanf("%d", &input);

        if (input == 1) {
            if (running == 0) {
                running = 1;
                startTime = time(NULL);
                printf("Chronomètre démarré.\n");
            } else {
                printf("Le chronomètre est déjà en marche.\n");
            }
        } else if (input == 0) {
            if (running == 1) {
                running = 0;
                endTime = time(NULL);
                printf("Le chronomètre s'est arrêté.\n");
                break;
            } else {
                printf("Le chronomètre est déjà arrêté.\n");
            }
        } else {
            printf("Valeur invalide. Veuillez entrer 1 pour démarrer ou 0 pour arrêter le chronomètre.\n");
        }
    }

    if (running == 0) {
        double elapsedTime = difftime(endTime, startTime);
        printf("Temps écoulé : %.2f secondes\n", elapsedTime);
    }

    return 0;
}
