#include "Header.h"

void updateScore(FILE* fichier, Player* P, char job[]) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    char player_name[100];
    char player_class[10];
    strcpy(player_class, job);
    int player_move;
    int player_reversed;
    int player_slay;
    int player_chest;
    int player_score_victory;
    char ligne[100];
  
    rewind(fichier);
  
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, &player_move, &player_reversed, &player_slay, &player_chest, &player_score_victory);

        if (strcmp(player_name, (*P).name) == 0) {
            player_move += (*P).move;
            player_reversed += (*P).reversed;
            player_slay += (*P).slay;
            player_chest += (*P).chest;
            player_score_victory += (*P).score_victory;

            fprintf(fichierTemp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
        } else {
            fprintf(fichierTemp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("Score.txt");
    rename("temp.txt", "Score.txt");
}

void Score_creator(Player* P) {
    FILE* fichier = fopen("Score.txt", "a+");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    char job[10];
    if ((*P).class == 1) {
        strcpy(job, "Magicien");
    } else if ((*P).class == 2) {
        strcpy(job, "Guerrier");
    } else if ((*P).class == 3) {
        strcpy(job, "Ranger");
    } else {
        strcpy(job, "Voleur");
    }

    fseek(fichier, 0, SEEK_END);
    long file_weight = ftell(fichier);

    if (file_weight == 0) {
        fprintf(fichier, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", (*P).name, job, (*P).move, (*P).reversed, (*P).slay, (*P).chest, (*P).score_victory);
    } else {
        updateScore(fichier, P, job);
    }

    fclose(fichier);
}
