#include "Header.h"



void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }


int main {
  
  int e1 = 1, e2 = 1, e3 = 1, e4 = 1, e5 = 1, e6 = 1, e7 = 1, e8 = 1, e9 = 1, e10 = 1, e11 = 1;
  int verif = 0;
  int weapon=0;
  int enemy=0;
  time_t startTime, endTime;
  int direction;
  int number_of_players_who_played=0;
  int number_of_players=0;
  Player P;
  card c;
  Portal p;
  
  P.timer=0  
    
 while(number_of_players<number_of_players_who_played){
     startTime = time(NULL);
     while (P.life==1 && P.relic==0 || P.treasure==0){
  
/*---------------------------------- ETAPE 1 --------------------------------------*/
                   
        printf("Choisissez votre arme : \n");
        printf("1. Bouclier\n");
        printf("2. Torche\n");
        printf("3. Hache\n");
        printf("4. Arc\n");
    
    
        do {
            printf("Votre choix: ");
            verif = scanf("%d", &weapon);
            vide_buffer();
        } while (weapon != 1 && weapon != 2 && weapon != 3 && weapon != 4 || verif != 1);
        verif=0;


        if (weapon == 1){               //bouclier
            P.w.type[0] = 1;
            P.w.type[1] = 0;
            P.w.type[2] = 0;
            P.w.type[3] = 0;
        }
    
    
        else if (weapon == 2){          //Torche
            P.w.type[0] = 0;
            P.w.type[1] = 1;
            P.w.type[2] = 0;
            P.w.type[3] = 0;
        }
    
    
        else if (weapon == 3){          //hache
            P.w.type[0] = 0;
            P.w.type[1] = 0;
            P.w.type[2] = 1;
            P.w.type[3] = 0;
        }
    
    
        else{                           //arc
            P.w.type[0] = 0;
            P.w.type[1] = 0;
            P.w.type[2] = 0;
            P.w.type[3] = 1;   
        }
    
/*---------------------------------- ETAPE 2 --------------------------------------*/
        printf("Enter a direction (2: Down, 8: Up, 4: Left, 6: Right): ");
        scanf("%d", &direction);
        move(table, &posX, &posY, direction);
       
 /*---------------------------------- ETAPE 3 --------------------------------------*/
        if (c.m==1){
            combat(P,c)
        }
        
        if (c.p==1){
            Portal(P,c)
        }
         
        if (c.t==1){
            Totem(P,c)
        }
         
        P.move++
      } // while joueur
endTime = time(NULL);
double elapsedTime = difftime(endTime, startTime);
P.timer=P.timer + elapsedTime;
P.move=0;    
number_of_players_who_played++
} //while manche


} // main
