#include <stdio.h>
int main(){ //juste pour tester sur place mercredi ou vendrdi
  
FILE *fichier = fopen("Score.txt", "a"); //le mode 'a' ajoute du texte à la fin du fichier

  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier.\n");
    return 1; // Quitter le programme en cas d'erreur
}le mode 

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
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *fichier = fopen("nom_du_fichier.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int *valeurs = NULL;
    int taille_tableau = 0;
    int capacite_tableau = 10;
    int i;

    while (!feof(fichier)) {
        int valeur;
        fscanf(fichier, "%d", &valeur);

        if (taille_tableau >= capacite_tableau) {
            capacite_tableau *= 2;
            valeurs = realloc(valeurs, capacite_tableau * sizeof(int));
        }

        valeurs[taille_tableau] = valeur;
        taille_tableau++;
    }

    qsort(valeurs, taille_tableau, sizeof(int), compare);

    for (i = 0; i < 10 && i < taille_tableau; i++) {
        printf("%d\n", valeurs[i]);
    }

    free(valeurs);
    fclose(fichier);
    return 0;
}
*/
