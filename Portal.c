#include "Header.h"

void Portal (Player* P, card* tab, int size){

     do{

        int new_direction_x = 0;
        int new_direction_y = 0;
        do{
            printf("Choisissez les coordonnés x, entre 1 et 6, vers lesquels vous voulez allez!");
            verif = scanf ("%d", &new_direction_x);
            vide_buffer();
        }while ( verif != 1 && new_direction_x<1 && new_direction_x>6);
        verif=0; 

        do{
            printf("Choisissez les coordonnés y, entre 1 et 6, vers lesquels vous voulez allez!");
            verif = scanf ("%d", &new_direction_y);
            vide_buffer();
        }while ( verif != 1 && new_direction_y<1 && new_direction_y>6);
        verif=0

        card* new_card = tab + new_direction_y*size + new_direction_x;

    }while ((*new_card).wall == 1 || (*new_card).hidden == 1 || (new_direction_y==1 && new_direction_x==3) || (new_direction_y==3 && new_direction_x==6) || (new_direction_y==4 && new_direction_x==1)  || (new_direction_y==6 && new_direction_x==4) );
    P.x = new_direction_x;
    P.y = new_direction_y;

}
