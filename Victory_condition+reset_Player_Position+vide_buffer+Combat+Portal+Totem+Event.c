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
             }while(new_card.wall == 1 && new_card == [1] [3] && new_card == [1] [2] && new_card == [1] [4] && new_card == [2] [3] && new_card == [4] [1] && new_card == [4] [2] && new_card == [3] [1]&& new_card == [5] [1] && new_card == [3] [6] && new_card == [3] [5] && new_card == [2] [6] && new_card == [4] [6] && new_card == [6] [4] && new_card == [6] [3] && new_card == [6] [5] && new_card == [5] [4]);
    
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



int e1 = 1, e2 = 1, e3 = 1, e4 = 1, e5 = 1, e6 = 1, e7 = 1, e8 = 1, e9 = 1, e10 = 1, e11 = 1;
Player P;
card c;

void event(card* c, Player* P, int e1, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){

//if (event == 1){
    do{
   int randevent = rand() %11;
    
    if (randevent == 0 && e1==1){
    
    printw(" ... /n/n Sérieusement...?/n ");
       
        const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";  // Lien vers la vidéo de Rick Astley en 8 bit
    const char* browser = "xdg-open";  // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux
    execlp(browser, browser, rickRollURL, NULL); // Lancement du navigateur avec l'URL du Rick Roll
        
        e1 = 0;
        return;
    }
        if (randevent == 1 && e2==1){
            
    printw ("Une harpie sauvage apparaît! « It's over Anakin, I have the highground! », dit-elle.\n");
        c.type[3]=0;
        c.m.type[2]=1;
        //change la case en monstre harpy et lance le combat. la case devient définitivement une harpy.
        e2=0;
            return;
            }
        if (randevent == 2 && e3==1){
            
    printw ("Vous voyez au loin un homme qui ne bouge pas. Vous vous approchez en pensant qu'il pourrait avoir besoin d'aide. Tous à coup, vous le voyez courrir en hurlant: LEEROY JENKINS!!!. À cause de cette action, vous vous retrouvez sous une marée draconique, et mourrez, malgré tous avec l'honneur d'un grand guerrier!\n");
            P.life = 0;
            printw("Game over!\n");
            resetPlayerPosition(P);
            e3=0;
         return;
        }
        if (randevent == 3 && e4==1){
        
    printw ("Vous croisez une espèce de grosse tortue avec plein de pics sur sa carapace, et qui crache du feu. Elle vous regarde, et vous demande si vous n'avez pas vu une princesse blonde en robe rose. Vous lui dites que non, et par colère, il vous vole 10 petites étoiles! (si vous possédiez votre relique, elle est retournée à son point d'emplacement)\n");
           if (P.relic == 1){
            P.relic = 0; 
           }
            e4=0;
            return;
        }
    if (randevent==4 && e5==1){
        
    printw ("Un spectacle d'horreur se déroule devant vous ! Un pauvre poisson-clown hors de l'eau semble pleurer tout en ne pouvant pas respirer.\n Il semble répéter sans cesse ces mêmes mots :\n   « Vous n'avez pas vu mon fils ?/n Vous n'avez pas vu mon fils ?/n Vous n'avez pas vu mon... » \nLe manque d'oxygen a eu raison de lui. Vous avez désormais un nouvel objectif : après être sorti victorieux de ce labyrinthe infernal, vous vous mettrez à la recherche de ce fameux « fils ».\n");
        e5=0;
        return;
    }
         if (randevent==5 && e6==1){
             
    printw ("Vous croisez un énorme tuyau fait de métal. Intrigué, vous vous approchez et entendez une étrange voix dans votre tête : Il faut suivre le conduit. Ne sachant ce qu'est ce fameux « conduit », vous continuez votre route.\n");
            e6=0;
                return;
         }
    
        if (randevent==6 && e7==1){
            
    printw ("Un homme au loin vous demande comment rejoindre « Sunny ». Il a les cheveux verts, comme si de la mousse lui avait poussé sur la tête. Il porte trois sabres au niveau de la ceinture, il paraît vraiment louche. Vous lui montrez une direction aléatoire en espérant qu'il vous laisse enfin tranquille. Il part dans la direction inverse complète. Quelle étrange rencontre !\n");
           e7=0;
            return;
        }
         
        if (randevent==7 && e8==1){
            
    printw ("Vous voyez une sorte de scientifique au loin. En essayant de vous approcher, vous voyez une sorte d'écran apparaître avec marqué dessus : « Fun value invalid ». \nVoyant que vous ne pouvez bas continuer, vous décidez d'abandonner et de continuer votre périple.\n");
            e8=0;
                return;
        }
    
        if (randevent==8 && e9==1){
    
    printw ("En vous baladant, vous tombez sur une étrange famille de deux squelettes. L'un petit, portant des habits rouge et blanc. Son frère, plus petit, porte un sweet à capuche bleuet et un pantalon noir. Pour éviter tout combat inutile, vous attendez un peu que le temps passe.\n");
        e9=0;
            return;
        }
    
        if (randevent==9 && e10==1){
            
    printw ("Vous trouvez un parchemin ancien ! Quel secret cache t-il ? \nVous l'ouvrez et le contemplez. Il est écrit : « Seul Link peut vaincre Ganon. ». Du fait que vous ne vous nommez ni Link, ni Ganon, vous jetez ce torchon inutile.\n");
    e10=0;
       return;
        }
            
        if (randevent==10 && e11==1){
            
    printw ("Vous rencontrez au détour de ce labyrinthe un vieil homme. Il prétend être le directeur d'un lycée spécialisé en magie très connu : le Lycée Magique George Pompidou. Il exprime même l'envie de vous faire entrer dans son lycée, dans la classe de « Nintendor ». Vous acceptez, et par conséquent, il se mit à hurler : « 100.000 points pour Nintendor! »\n.");
            e11=0;
        return;
        }
        else{
                  printw ("Problème ! L'événement n'a pas pu être lancé !\n");
                  }
} while(e1==1 && e2==1 && e3==1 && e4==1 && e5==1 && e6==1 && e7==1 && e8==1 && e9==1 && e10==1 && e11==1);
                  
// }
}
