#include "Header.h"

void (Player P, card c){
 int new_direction;
  do{
  printf("Choisissez les coordonnés x, entre 1 et 6, vers lesquels vous voulez allez!");
  verif = scanf ("%d", &new_direction);
  vide_buffer();
  }while ( verif != 1 && new_direction<1 && new_direction>6);
  
  
}
