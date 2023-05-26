#include "Header.h"
  
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichier;

    // Ouverture du fichier en mode lecture
    fichier = fopen("donnees.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Détermination de la taille du fichier
    fseek(fichier, 0, SEEK_END);
    long taille_fichier = ftell(fichier);

    // Vérification si le fichier est vide
    if (taille_fichier == 0) {
        printf("Le fichier est vide.\n");
    } else {
        printf("Le fichier n'est pas vide.\n");
    }

    // Fermeture du fichier
    fclose(fichier);



  void Score_creator(Player P){
FILE *fichier = fopen("Score.txt", "a+"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Erreur\n");
    return 1; // Quitter le programme en cas d'erreur
} 
    
    if (P.class == 1){
     char job [10];
        strcpy(job, "Magicien");
    }
   else if (P.class == 2){
     char job [10];
        strcpy(job, "Guerrier");
    }
    else if (P.class == 3){
     char job [10];
        strcpy(job, "Ranger");
    }
    else{
     char job [10];
        strcpy(job, "Voleur");
    }
    
    
     updateScore(fichier, Player P, job);
    
      fprintf(fichier, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  P.nom, job, P.move, P.reversed, P.slay, P.chest, P.Score_victory);
    
  fclose(fichier);

void updateScore(FILE* fichier, Player P,job ) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }
        char player_name[100];

        char player_class[10];

        int player_move;

        int player_reversed;

        int player_slay;

        int player_chest;

        int player_score_victory;
    char ligne[100];
  rewind(fichier);
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        
    sscanf(ligne, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
    
        if (player_name == P.name) {
         player_move += P.move;
          player_slay += P.slay;
          player_chest += P.
           
            fprintf(fichierTemp, "%d %s %.2f\n", id, nomFichier, nouveauSalaire);
        } else {
            fprintf(fichierTemp, "%d %s %.2f\n", idFichier, nomFichier, salaireFichier);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("Score.txt");
    rename("temp.txt", "Score.txt");
}

    // Lecture du fichier pour afficher les employés et leurs salaires mis à jour
    rewind(fichier); // Rembobiner le fichier au début
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int id;
        char nom[50];
        float salaire;
        sscanf(ligne, "%d %s %f", &id, nom, &salaire);
        printf("ID : %d, Nom : %s, Salaire : %.2f\n", id, nom, salaire);
    }
    return 0;
}
} //void
