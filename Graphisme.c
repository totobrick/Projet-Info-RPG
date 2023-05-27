/*#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main() {*/
    FILE *fichier;
    char ligne[256];
    
    // Ouvrir le fichier en mode lecture
    fichier = fopen("chemin/vers/le/fichier.txt", "r");
    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier\n");
        return 1;
    }
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printw("%s", ligne);
    }
    
 /*   // Initialiser ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);*/
    
    // Lire et afficher le contenu du fichier ligne par ligne

  /*  // Attendre une touche pour quitter
    getch();
    
    // Terminer ncurses
    endwin();
    
    // Fermer le fichier
    fclose(fichier);
    
    return 0;
}*/
