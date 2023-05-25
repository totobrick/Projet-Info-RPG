#include "Header.h"
int main(){ //juste pour tester sur place mercredi ou vendrdi
  void Score_creator(Player P){
FILE *fichier = fopen("Score.txt", "a+"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Erreur\n");
    return 1; // Quitter le programme en cas d'erreur
} 

    fprintf(fichier, "%s /t %d /t %d /t %d /t %d /t %d",  P.nom, P.slay, P.chest, P.reversed, P.Score_victory, P.move); 
    
  fclose(fichier);
  return 0;
}
  
typedef struct {
    int id;
    char nom[50];
    float salaire;
} Employe;

void ajouterEmploye(FILE* fichier, int id, const char* nom, float salaire) {
    fprintf(fichier, "%d %s %.2f\n", id, nom, salaire);
}

void mettreAJourSalaire(FILE* fichier, int id, float nouveauSalaire) {
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

    // Exemple d'utilisation : ajout d'employés et mise à jour de salaire
    addPlayer(fichier, 1, "John Doe", 5000.0);
    addPlayer(fichier, 2, "Jane Smith", 6000.0);
    addPlayer(fichier, 3, "Bob Johnson", 5500.0);

    miseAjour(fichier, 2, 6500.0);
    miseAjour(fichier, 4, 7000.0); // L'employé avec l'ID 4 n'existe pas, donc aucun changement

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
