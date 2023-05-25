#include "Header.h"
int main(){ //juste pour tester sur place mercredi ou vendrdi
  
FILE *fichier = fopen("Score.txt", "a"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier.\n");
    return 1; // Quitter le programme en cas d'erreur
} 

    fprintf(fichier, " /t  /t /n");  //il faut reflechir pour mettre le nom et rajouter une variable "coup" qui prend +1 à chaque fin de tour. de plus il faut mettre le temps de la partie je crois.
   fclose(fichier);
  
   FILE *fichier = fopen("Score.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int valeur1, valeur2;
    fscanf(fichier, "%d", &valeur1);
    fscanf(fichier, "%d", &valeur2);

    if (valeur1 > valeur2) {
        printf("La valeur 1 est supérieure à la valeur 2.\n");
    } else if (valeur1 < valeur2) {
        printf("La valeur 1 est inférieure à la valeur 2.\n");
    } else {
        printf("La valeur 1 est égale à la valeur 2.\n");
  
  fclose(fichier);
  return 0;
}
  
/*  
char ligne[100]; // Choisir une taille appropriée pour stocker une ligne du fichier
int numeroLigne = 3; // Exemple : numéro de la ligne à réécrire

// Parcourir le fichier jusqu'à la ligne souhaitée
int i = 1;
while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    if (i == numeroLigne) {
        // La ligne spécifique est trouvée, vous pouvez la réécrire
        fseek(fichier, -strlen(ligne), SEEK_CUR); // Positionne le curseur avant la ligne
        fprintf(fichier, "Nouvelle ligne à écrire\n"); // Écrit la nouvelle ligne
        break; // Sort de la boucle une fois la ligne réécrite
    }
    i++;
}

// Si la ligne spécifique n'est pas trouvée, vous pouvez afficher un message d'erreur
if (i > numeroLigne) {
    printf("La ligne spécifique n'a pas été trouvée.\n");
}

// Fermez le fichier une fois que vous avez terminé les opérations
fclose(fichier);
*/

  
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE* fichier = fopen("donnees.txt", "a+");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Exemple d'utilisation : ajout d'employés et mise à jour de salaire
    ajouterEmploye(fichier, 1, "John Doe", 5000.0);
    ajouterEmploye(fichier, 2, "Jane Smith", 6000.0);
    ajouterEmploye(fichier, 3, "Bob Johnson", 5500.0);

    mettreAJourSalaire(fichier, 2, 6500.0);
    mettreAJourSalaire(fichier, 4, 7000.0); // L'employé avec l'ID 4 n'existe pas, donc aucun changement

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
