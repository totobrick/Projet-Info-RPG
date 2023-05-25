#include "Header.h"
int main(){ //juste pour tester sur place mercredi ou vendrdi
  
  void Score_creator(Player P){
FILE *fichier = fopen("Score.txt", "a+"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Erreur\n");
    return 1; // Quitter le programme en cas d'erreur
} 
     updateScore(fichier, Player P);
    
      fprintf(fichier, "%s /t %d /t %d /t %d /t %d /t %d /t %d /n",  P.nom, P.class, P.move, P.reversed, P.slay, P.chest, P.Score_victory);
    
    
  fclose(fichier);
 // return 0;
  }

void updateScore(FILE* fichier, Player P) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int idFichier;
        char nomFichier[50];
        float salaireFichier;
        sscanf(ligne, "%d %s %f", &idFichier, nomFichier, &salaireFichier);

        if (idFichier == id) {
            fprintf(fichierTemp, "%d %s %.2f\n", id, nomFichier, nouveauSalaire);
        } else {
            fprintf(fichierTemp, "%d %s %.2f\n", idFichier, nomFichier, salaireFichier);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("donnees.txt");
    rename("temp.txt", "donnees.txt");
}

int main() {

   
    

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

    fclose(fichier);

    return 0;
}
} //void
