#include "Header.h"
  
  void Score_creator(Player P){
FILE *fichier = fopen("Score.txt", "a+"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Erreur\n");
    return 1; // Quitter le programme en cas d'erreur
} 
    
    if (P.class == 1){
     char job [10];
      
    }
     updateScore(fichier, Player P, );
    
      fprintf(fichier, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  P.nom, P.class, P.move, P.reversed, P.slay, P.chest, P.Score_victory);
    
    
  fclose(fichier);

void updateScore(FILE* fichier, Player P) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char player_name[100];
        char player_class[10];
        int player_move;
        int player_reversed;
        int player_slay;
        int player_chest;
        int player_score_victory;
        sscanf(ligne, ""%s /t %d /t %d /t %d /t %d /t %d /t %d /n", &idFichier, nomFichier, &salaireFichier);

        if (player_name == P.name) {
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
