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
