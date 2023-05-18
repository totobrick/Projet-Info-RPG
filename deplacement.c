#include<stdio.h>

int deplacement_joueur = 0;
int deplacement_case = 0;

while (deplacement_joueur != deplacement_case){
     break
     printf("Maintenant choisissez une direction :",\n);
     printf(\t,\t,\t,"Haut");
     printf(\t,\t,\t,"[8]");
     printf(\t,"Gauche [4]",\t,"[6] Droite");
     printf(\t,\t,\t,"[2]");
     printf(\t,\t,\t,"Bas");
     scanf("%d",deplacement_joueur);
     if deplacement_joueur == 8; // déplacement vers le Haut
          // checker la case devant le joueur et verifier le type de case, si ennemie voir si game over ?, si mur recommence la boucle de déplacement, sinon avance
     if deplacement_joueur == 2; // déplacement vers le Bas
     if deplacement_joueur == 4; // déplacement vers la Gauche
     if deplacement_joueur == 6; // déplacement vers la Droite
  
}
