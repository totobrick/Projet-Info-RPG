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
  int Wizard = 0;
  int Knight = 0;
  int Ranger = 0;
  int Rogue = 0;
  time_t startTime, endTime;
  int direction;
  int number_of_players_who_played=0;
  int number_of_players=0;
  Player P;
  card c;
  card tab;
  Portal p;
  P.timer=0  
      
      
    do {
            printf("Combien êtes vous à jouer ?\n");
            verif = scanf("%d", number_of_players );
            vide_buffer();
        } while (number_of_players>=2 && number_of_players<=4 || verif != 1);
        verif=0;
    
    for (int i = 0; number_of_players>i; i++){
        do {
            printf("comment vous appellez-vous?\n");
            verif = scanf("%d", P.nom );
            vide_buffer();
        } while ( || verif != 1);
        verif=0;
} //for 
    
for (int i = 0; number_of_players>i; i++){
        do {
            printf("Choisissez votre Classe : \n");
            printf("1. Magicien\n");
            printf("2. Guerrier\n");
            printf("3. Ranger\n");
            printf("4. Voleur\n");
            printf("Votre choix: ");
            verif = scanf("%d", P.class );
            
            if (Wizard == 1){
                P.class=-1;
                printf("La classe choisie est déjà prise, veuillez en choisir une autre");
                }
            else if (P.class == 1 && Wizard ==0){
                Wizard =1;
                }
            
            if (Knight == 1){
                P.class=-1;
                printf("La classe choisie est déjà prise, veuillez en choisir une autre");
                }
            else if (P.class == 2 && Knight ==0){
                Knight =1;
                }
            
            if (Ranger == 1){
                P.class=-1;
                printf("La classe choisie est déjà prise, veuillez en choisir une autre");
                }
            else if (P.class == 3 && Ranger ==0){
                Ranger =1;
                }
            
            if (Rogue == 1){
                P.class=-1;
                printf("La classe choisie est déjà prise, veuillez en choisir une autre");
                }
           
            else if (P.class == 4 && Rogue ==0){
                Rogue =1;
                }
            
            vide_buffer();
        } while (P.class != 1 && P.class != 2 && P.class != 3 && P.class != 4 || verif != 1);
        verif=0;
} //for 
      
    
 while(number_of_players<number_of_players_who_played || victory==1){
     startTime = time(NULL);
     while (P.life==1 && P.relic==0 || P.treasure==0){
        printw("%d",game,"\n");
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
        printf("%d",game,"\n");
       
 /*---------------------------------- ETAPE 3 --------------------------------------*/
        if (c.m==1){
            combat(P,c);
            P.slay++
        }
        
        if (c.p==1){
            Portal(P,c);
        }
         
        if (c.e==1){
            event(c, P);
        }
         
        if (c.t==1){
            Totem(P,c);
            P.life=0;
        }
         
        if (c.r==0 && P.class==3){ //Vérifie si la classe Ranger est sur la bonne relique
            P.relic=1;
            printf("Le joueur vient de trouver sa relique");
        }
         
        if (c.r==1 && P.class==2){ //Vérifie si la classe Guerrier est sur la bonne relique
            P.relic=1;
            printf("Le joueur vient de trouver sa relique");
        }
         
         if (c.r==2 && P.class==1){ //Vérifie si la classe Magicien est sur la bonne relique
            P.relic=1;
            printf("Le joueur vient de trouver sa relique");
        }
         
         if (c.r==3 && P.class==4){ //Vérifie si la classe Voleur est sur la bonne relique
            P.relic=1;
            printf("Le joueur vient de trouver sa relique");
        }
         
        P.life=1;
        P.move++
      } // while joueur
endTime = time(NULL);
double elapsedTime = difftime(endTime, startTime);
P.timer=P.timer + elapsedTime; 
if (checkTreasure(P)==1){
    return;
    }
else if (checkTreasure(P)==0 && number_of_players_who_played==number_of_players){
    number_of_players_who_played=0;
    }
    number_of_players_who_played++;
} //while manche
show_board (tab,int size);
printw("%d",game,"\n");
printf("Le joueur, %s, a gagné",P.nom);
P.Score_victory++

} // main
