 #include Header.h


                void resetPlayerPosition(Player* p) {
    (*p).x = (*p).x_init;
    (*p).y = (*p).y_init;
    printw ("Position du joueur %s réinitialisé.\n",(*p).nom);
}

       void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

                              void combat(Player P, card c) {
    if (c.m.type[0] == 1){
    
    if(P.w.type[0] == 1){
     printw ("Le Basilic est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Basilic vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[1] == 1){
    if(P.w.type[1] == 1){
     printw ("Le Zombie est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Zombie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[2] == 1){
    if(P.w.type[2] == 1){
     printw ("Le Troll est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Troll vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else{
    if(P.w.type[3] == 1){
     printw ("La Harpie est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! La Harpie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    }



// Fonction pour vérifier si le joueur a obtenu le trésor et la relique 

                                    int checkTreasure(Player* P) {
    int victory = 0;
    if (P.treasure == 1 && P.relic == 1) {
                victory = 1;

}
    else{
     victory = 0;   
    }

    return victory;
}



                                 void Exchang_Totem (Player P, card c,card new_card,card tempo) {
    
        do{
  int new_direction_x = 0;
  int new_direction_y = 0;
  do{
  printf("Choisissez les coordonnés x, entre 1 et 6, vers laquel le totem va être échanger");
  verif = scanf ("%d", &new_direction_x);
  vide_buffer();
  }while ( verif != 1 && new_direction_x<1 && new_direction_x>6);
 verif=0; 
 
 do{
  printf("Choisissez les coordonnés y, entre 1 et 6, vers laquel le totem va être échanger");
  verif = scanf ("%d", &new_direction_y);
  vide_buffer();
  }while ( verif != 1 && new_direction_y<1 && new_direction_y>6);
 verif=0
    
card new_card = tab [new_direction_x] [new_direction_y];
             }while(new_card.wall == 1 && new_card == [1] [3] && new_card == [4] [1] && new_card == [3] [6] && new_card == [6] [4]);
    
    card tempo = card new_card;
    card new_card = card c;
    card c = card tempo;
}


                             void Portal (Player* P, card* tab, int size){

     do{

        int new_direction_x = 0;
        int new_direction_y = 0;
        do{
            printf("Choisissez les coordonnés x, entre 1 et 6, vers lesquels vous voulez allez!");
            verif = scanf ("%d", &new_direction_x);
            vide_buffer();
        }while ( verif != 1 || new_direction_x<1 || new_direction_x>6);
        verif=0; 

        do{
            printf("Choisissez les coordonnés y, entre 1 et 6, vers lesquels vous voulez allez!");
            verif = scanf ("%d", &new_direction_y);
            vide_buffer();
        }while ( verif != 1 || new_direction_y<1 || new_direction_y>6);
        verif=0

        card* new_card = tab + new_direction_y*size + new_direction_x;

    }while ((*new_card).wall == 1 || (*new_card).hidden == 1 || (new_direction_y==1 && new_direction_x==3) || (new_direction_y==3 && new_direction_x==6) || (new_direction_y==4 && new_direction_x==1)  || (new_direction_y==6 && new_direction_x==4) );
    P.x = new_direction_x;
    P.y = new_direction_y;

}
