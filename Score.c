#include "Header.h"
void updateScore(FILE* fichier, Player* P,char job []) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return 1;
    }
        char player_name[100];
        char player_class[10];
        player_class = job;
        int player_move;
        int player_reversed;
        int player_slay;
        int player_chest;
        int player_score_victory;
    char ligne[100];
  rewind(fichier);
 
  while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        
    sscanf(ligne, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
    
        if (player_name == (*P).name) {
         player_move += (*P).move;
          player_reversed += (*P).reversed;
          player_slay += (*P).slay;
          player_chest += (*P).chest;
          player_score_victory += (*P).score_victory;
           
            fprintf(fichierTemp,  "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
        }  
  }
  
   if(player_name != (*P).name){
            fprintf(fichier, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  (*P).nom, job, (*P).move, (*P).reversed, (*P).slay, (*P).chest, (*P).Score_victory);
    }
    fclose(fichier);
    fclose(fichierTemp);

    remove("Score.txt");
    rename("temp.txt", "Score.txt");
}


  void Score_creator(Player* P){
FILE *fichier = fopen("Score.txt", "a+"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Erreur\n");
    return 1; // Quitter le programme en cas d'erreur
} 
    if ((*P).class == 1){
     char job [10];
        strcpy(job, "Magicien");
    }
   else if ((*P).class == 2){
     char job [10];
        strcpy(job, "Guerrier");
    }
    else if ((*P).class == 3){
     char job [10];
        strcpy(job, "Ranger");
    }
    else{
     char job [10];
        strcpy(job, "Voleur");
    }
    
    // Détermination de la taille du fichier
    fseek(fichier, 0, SEEK_END);
    long file_weight = ftell(fichier);

    // Vérification si le fichier est vide
    if (file_weight == 0) {
       fprintf(fichier, "%s /t %s /t %d /t %d /t %d /t %d /t %d /n",  (*P).nom, job, (*P).move, (*P).reversed, (*P).slay, (*P).chest, (*P).Score_victory);
    } else {
        updateScore(fichier, P, job);
    }
  fclose(fichier);
  }

