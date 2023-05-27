#include "Header.h"


void board(card *tab, int size, WINDOW* win_game) {
    init_wall(tab, size);
    init_board(tab, size);
    generate_board(tab, size);
    wclear(win_game);
    show_board(tab, size, win_game);
    
}

void hide_board(card *tab, int size, WINDOW* win_game){
    for(int i=0; i<(size-1) ; i++){
        for(int j=0; j<(size-1) ; j++){
            (*(tab + i*size + j)).hidden = 0;        //on retourne toutes les cases du jeu
        }
    }
    show_board(tab, size, win_game);
}
/*_________________________________________________________________________________________________*/

// INITIALISATION DU JEU

void init_wall(card *tab, int size) {
  if (size <= 0) {
    exit(1);
  }
  for (int j = 0; j < size; j++) {
    (*(tab + 0 * size + j)).wall = 1;
  }
  for (int i = 1; i < (size - 1); i++) {
    (*(tab + i * size + 0)).wall = 1;
    for (int j = 1; j < (size - 1); j++) {
      (*(tab + i * size + j)).wall = 0;
    }
    (*(tab + i * size + 7)).wall = 1;
  }
  for (int j = 0; j < size; j++) {
    (*(tab + (size - 1) * size + j)).wall = 1;
  }
  printf("Initialisation des murs terminee.\n");
}

void init_board(card *tab, int size) {
  if (size <= 0) {
    exit(1);
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      init_card(tab + i * size + j);
    }
  }
  printf("Initialisation des cartes terminee.\n");
}

void init_card(card *card1) {
  (*card1).hidden = 0;
  for (int i = 0; i < 4; i++) {
    (*card1).type[i] = 0;
    (*card1).m.type[i] = 0; // monster
    (*card1).r.type[i] = 0; // relic
  }
}

void invert_card(card *card1, card *card2) {
  card *transit_card = malloc(sizeof(card));
  // transit_card = card1
  (*transit_card).hidden = (*card1).hidden;
  for (int i = 0; i < 4; i++) {
    (*transit_card).type[i] = (*card1).type[i];
    (*transit_card).m.type[i] = (*card1).m.type[i]; // monster
    (*transit_card).r.type[i] = (*card1).r.type[i]; // relic
  }

  // card1=card2
  (*card1).hidden = (*card2).hidden;
  for (int i = 0; i < 4; i++) {
    (*card1).type[i] = (*card2).type[i];
    (*card1).m.type[i] = (*card2).m.type[i]; // monster
    (*card1).r.type[i] = (*card2).r.type[i]; // relic
  }

  // card2=transit_card
  (*card2).hidden = (*transit_card).hidden;
  for (int i = 0; i < 4; i++) {
    (*card2).type[i] = (*transit_card).type[i];
    (*card2).m.type[i] = (*transit_card).m.type[i]; // monster
    (*card2).r.type[i] = (*transit_card).r.type[i]; // relic
  }
  free(transit_card);
}

// DISTRIBUTION DES CARTES
void generate_board(card *tab, int size) {
  char cards[] = {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'b', 'b', 'b', 'b', 'z', 'z', 'z', 'z', 't', 't', 't', 't', 'h', 'h', 'h', 'h', 'C', 'C', 'T', 'T', 'E', 'B', 'G', 'D', 'P'};
  int remaining_card = 32; // remaining_card = cartes_restantes
  /*
  cards[] est le tableau de toutes nos 32 cartes à placer aléatoirement sur un
  plateau de 36. Voici le détail de ces cartes :
      -> Les 7 événements :
          'e' = événement (x7)
      -> Les 16 monstres :
          'b' = basilic   (x4)
          'z' = zombie    (x4)
          't' = troll     (x4)
          'h' = harpie    (x4)
      -> Les 2 coffres au trésor :
          'C' = coffre    (x2)
      -> Les 2 totems :
          'T' = totem     (x2)
      -> Les 4 armes antiques (reliques) :
          'E' = épée      (x1)
          'B' = bâton     (x1)
          'G' = grimoire  (x1)
          'D' = dague     (x1)
      -> 1 portail de téléportation :
          'P' = portail   (x1)
  */
  // le tableau tab est déjà initialisé dans une fonction précédente, pas besoin
  // de le faire ici
  for (int i = 1; i < (size - 1); i++) {   // Lignes tableau
    for (int j = 1; j < (size - 1); j++) { // Colonnes tableau
      if (remaining_card > 0) {
        int alea = rand() % remaining_card;
        // événement
        if (cards[alea] == 'e') {
          (*(tab + i * size + j)).type[3] = 1;
        }
        // Les 4 monstres
        else if (cards[alea] == 'b') {
          (*(tab + i * size + j)).m.type[0] = 1;
        } else if (cards[alea] == 'z') {
          (*(tab + i * size + j)).m.type[1] = 1;
        } else if (cards[alea] == 't') {
          (*(tab + i * size + j)).m.type[2] = 1;
        } else if (cards[alea] == 'h') {
          (*(tab + i * size + j)).m.type[3] = 1;
        }
        // coffre et totem
        else if (cards[alea] == 'C') {
          (*(tab + i * size + j)).type[0] = 1;
        } else if (cards[alea] == 'T') {
          (*(tab + i * size + j)).type[1] = 1;
        }
        // Les 4 armes antiques
        else if (cards[alea] == 'E') {
          (*(tab + i * size + j)).r.type[1] = 1;
        } else if (cards[alea] == 'B') {
          (*(tab + i * size + j)).r.type[0] = 1;
        } else if (cards[alea] == 'G') {
          (*(tab + i * size + j)).r.type[2] = 1;
        } else if (cards[alea] == 'D') {
          (*(tab + i * size + j)).r.type[3] = 1;
        }
        // portail
        else if (cards[alea] == 'P') {
          (*(tab + i * size + j)).type[2] = 1;
        }

        else {
          printf(" OUPS ! Le jeu n'a pas pu etre cree. La carte generee aleatoirement n'est pas dans le paquet.\n");
          exit(1);
        }
        cards[alea] = cards[remaining_card - 1];
        remaining_card = remaining_card - 1;
      }
      else {
        clear();
        printw("Toutes les cartes du jeu sont placees !\n"); // est affiché 4 fois
                                                          // car il y a 4 cases
                                                          // vides pour mettre
                                                          // les joueurs
        refresh();
      }
    }
  }
  invert_card(tab + 1 * size + 3, tab + 6 * size + 3);
  invert_card(tab + 3 * size + 6, tab + 6 * size + 5);
  invert_card(tab + 4 * size + 1, tab + 6 * size + 6);
}


void return_card(card* c){		//le joueur a déjà son arme !
        (*c).hidden = 1;
        refresh();
}

//REVOIR fonctionnement portal
void Portal (Player* p, card* tab, int size, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    int new_direction_x = 0;
    int new_direction_y = 0;
    card new_card;
    card* pnew_card = &new_card;
    do{
        wclear(win);
        new_direction_x = 0;
        new_direction_y = 0;
        do{
            wmove(win, 0, 0);
            wprintw(win, "\nChoisissez les coordonnees x, entre 1 et 6, vers lesquels vous voulez allez!");
            wrefresh(win); new_direction_x = getch();
        }while (new_direction_x!='1' && new_direction_x!='2' && new_direction_x!='3' && new_direction_x!='4' && new_direction_x!='5' && new_direction_x!='6');
        new_direction_x = new_direction_x - '0' ;
        
        do{
            wmove(win, 2, 0);
            wprintw(win,"\nChoisissez les coordonnees y, entre 1 et 6, vers lesquels vous voulez allez!");
            wrefresh(win); new_direction_y = getch();
        }while (new_direction_y!='1' && new_direction_y!='2' && new_direction_y!='3' && new_direction_y!='4' && new_direction_y!='5' && new_direction_y!='6');
        new_direction_y = new_direction_y - '0' ;

        pnew_card = tab + new_direction_y*size + new_direction_x;

    } while (new_card.wall == 1 || new_card.hidden == 1 || (new_direction_y==1 && new_direction_x==3) || (new_direction_y==3 && new_direction_x==6) || (new_direction_y==4 && new_direction_x==1)  || (new_direction_y==6 && new_direction_x==4) );

    return_card(pnew_card);
    show_board(tab, size, win);
    refresh();
    wmove(win,0, 0);
    wclear(win);
    wrefresh(win);
    sleep(3);
    
    interaction_card(p, tab, size, win, new_direction_x, new_direction_y, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    refresh();
    sleep(3);
    //interaction_card(p, newcard, key, win);
    //bouger que si on gagne : void interaction_card(Player* p, card* c);

    (*p).x = new_direction_x;
    (*p).y = new_direction_y;
    refresh();
}


 void Exchang_Totem (Player* p, card* c, card* tab,int size, WINDOW* win) {
    wclear(win);
    wrefresh(win);
    wmove(win, 0, 0);
    card* new_card;
    int new_direction_x = 0;
    int new_direction_y = 0;
    do{
        new_direction_x = 0;
        new_direction_y = 0;
        do{
            wclear(win);
            wrefresh(win);
            wmove(win, 0, 0);
            wprintw(win, "Choisissez la coordonnee x, entre 1 et 6, vers laquelle le totem va etre echange :");
            wrefresh(win);
            new_direction_x = getch();
        } while (new_direction_x!='1' && new_direction_x!='2' && new_direction_x!='3' && new_direction_x!='4' && new_direction_x!='5' && new_direction_x!='6');
        new_direction_x = new_direction_x - '0';
        
        do{
            wclear(win);
            wrefresh(win);
            wmove(win, 0, 0);
            wprintw(win, "\nChoisissez la coordonnee y, entre 1 et 6, vers laquelle le totem va etre echangee :");
            wrefresh(win);
            new_direction_y = getch();
        } while (new_direction_y!='1' && new_direction_y!='2' && new_direction_y!='3' && new_direction_y!='4' && new_direction_y!='5' && new_direction_y!='6');
        new_direction_y = new_direction_y - '0';
        
        new_card = tab + new_direction_y*size + new_direction_x;
    } while ((*new_card).wall == 1 || (*new_card).hidden == 1 || (new_direction_y==1 && new_direction_x==3) || (new_direction_y==1 && new_direction_x==2) || (new_direction_y==1 && new_direction_x==4) || (new_direction_y==2 && new_direction_x==3) || (new_direction_y==4 && new_direction_x==1) || (new_direction_y==3 && new_direction_x==1) || (new_direction_y==4 && new_direction_x==2) || (new_direction_y==5 && new_direction_x==1) || (new_direction_y==6 && new_direction_x==4) || (new_direction_y==6 && new_direction_x==3) || (new_direction_y==6 && new_direction_x==5) || (new_direction_y==5 && new_direction_x==4) || (new_direction_y==3 && new_direction_x==6) || (new_direction_y==3 && new_direction_x==5) || (new_direction_y==2 && new_direction_x==6) || (new_direction_y==4 && new_direction_x==6));
     //on ne peut pas choisir : murs, cases départs des joueurs, les cases qui touchent les cases de départ des joueurs
     invert_card(c, new_card);
     wclear(win);
     wrefresh(win);
     wmove(win, 0, 0);
}


void Event(card *c, Player *p, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    wclear(win);
    wmove(win, 0, 0);
    int randevent = 0;
    do{
        randevent = rand() %11;
        if (randevent == 0 && e1==1){
            wprintw(win," ... /n/n Serieusement...?/n ");
            const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";        // Lien vers la vidéo de Rick Astley en 8 bit
            const char* browser = "xdg-open";                                // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux
            execlp(browser, browser, rickRollURL, NULL);                    // Lancement du navigateur avec l'URL du Rick Roll
            e1 = 0;
            wrefresh(win);
            sleep(10);
            return ;
        }
        
        if (randevent == 1 && e2==1){
            wprintw (win,"Une harpie sauvage apparait! « It's over Anakin, I have the highground! », dit-elle.\n");
            (*c).type[3]=0;
            (*c).m.type[3]=1;
            //change la case en monstre harpy et lance le combat. la case devient définitivement une harpy.
            e2 = 0;
            wrefresh(win);
            sleep(7);
            return;
        }
        
        if (randevent == 2 && e3==1){
            wprintw (win, "Vous voyez au loin un homme qui ne bouge pas. Vous vous approchez en pensant qu'il pourrait avoir besoin d'aide. Tout a coup, vous le voyez courir en hurlant: LEEROY JENKINS!!! A cause de cette action, vous vous retrouvez sous une maree draconique, et mourrez, malgre tout avec l'honneur d'un grand guerrier!\n");
            (*p).life = 0;
            printw("Game over!\n");
            resetPlayerPosition(p);
            e3 = 0;
            wrefresh(win);
            sleep(25);
            return;
        }
        if (randevent == 3 && e4==1){
            wprintw (win,"Vous croisez une espece de grosse tortue avec plein de pics sur sa carapace, et qui crache du feu. Elle vous regarde, et vous demande si vous n'avez pas vu une princesse blonde en robe rose. Vous lui dites que non, et par colere, il vous vole 10 petites etoiles! (si vous possediez votre relique, elle est retournee à son point d'emplacement)\n");
            if ((*p).relic == 1){
                (*p).relic = 0; 
            }
            e4 = 0;
            wrefresh(win);
            sleep(20);
            return;
        }
        if (randevent==4 && e5==1){
            wprintw (win,"Un spectacle d'horreur se deroule devant vous ! Un pauvre poisson-clown hors de l'eau semble pleurer tout en ne pouvant pas respirer.\n Il semble repeter sans cesse ces memes mots :\n   « Vous n'avez pas vu mon fils ?\n Vous n'avez pas vu mon fils ?\n Vous n'avez pas vu mon... » \nLe manque d'oxygen a eu raison de lui. Vous avez desormais un nouvel objectif : apres etre sorti victorieux de ce labyrinthe infernal, vous vous mettrez a la recherche de ce fameux « fils ».\n");
            e5 = 0;
            wrefresh(win);
            sleep(23);
            return;
        }
        if (randevent==5 && e6==1){
            wprintw (win, "Vous croisez un enorme tuyau fait de metal. Intrigue, vous vous approchez et entendez une etrange voix dans votre tete : Il faut suivre le conduit. Ne sachant ce qu'est ce fameux « conduit », vous continuez votre route.\n");
            e6 = 0;
            wrefresh(win);
            sleep(17);
            return;
        }
        
        if (randevent==6 && e7==1){
            wprintw (win, "Un homme au loin vous demande comment rejoindre le « Sunny ». Il a les cheveux verts, comme si de la mousse lui avait pousse sur la tete. Il porte trois sabres au niveau de la ceinture, il paraît vraiment louche. Vous lui montrez une direction aleatoire en esperant qu'il vous laisse enfin tranquille. Il part dans la direction inverse complète. Quelle etrange rencontre !\n");
            e7 = 0;
            wrefresh(win);
            sleep(22);
            return;
        }
             
        if (randevent==7 && e8==1){
            wprintw (win, "Vous voyez une sorte de scientifique au loin. En essayant de vous approcher, vous voyez une sorte d'ecran apparaitre avec marque dessus : « Fun value invalid ». \nVoyant que vous ne pouvez pas continuer, vous decidez d'abandonner et de continuer votre periple.\n");
            e8 = 0;
            wrefresh(win);
            sleep(13);
            return;
        }
    
        if (randevent==8 && e9==1){
            wprintw (win, "En vous baladant, vous tombez sur une etrange famille de deux squelettes. L'un petit, portant des habits rouge et blanc. Son frere, plus petit, porte un sweet à capuche bleu et un pantalon noir. Pour eviter tout combat inutile, vous attendez un peu que le temps passe.\n");
            e9 = 0;
            wrefresh(win);
            sleep(13);
            return;
        }
    
        if (randevent==9 && e10==1){
            wprintw (win,"Vous trouvez un parchemin ancien ! Quel secret cache t-il ? \nVous l'ouvrez et le contemplez. Il est ecrit : « Seul Link peut vaincre Ganon. ». Du fait que vous ne vous nommez ni Link, ni Ganon, vous jetez ce torchon inutile.\n");
            e10 = 0;
            wrefresh(win);
            sleep(12);
            return;
        }
            
        if (randevent==10 && e11==1){
            wprintw (win, "Vous rencontrez au detour de ce labyrinthe un vieil homme. Il pretend etre le directeur d'un lycee specialise en magie tres connu : le Lycee Magique George Pompidou. Il exprime même l'envie de vous faire entrer dans son lycee, dans la classe de « Nintendor ». Vous acceptez, et par consequent, il se mit a hurler : « 100.000 points pour Nintendor! »\n.");
            e11 = 0;
            wrefresh(win);
            sleep(17);
            return;
        }
        //else{
        //    printw ("Continuez votre route brave combattant !\n");
        //    return ;
        //}
    } while(e1==1 || e2==1 || e3==1 || e4==1 || e5==1 || e6==1 || e7==1 || e8==1 || e9==1 || e10==1 || e11==1);          
}

void interaction_card(Player *p, card* tab, int size, WINDOW *win, int x_newcard, int y_newcard, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    //COMBAT AVEC LE MONSTRE fait (si il y en a)

    wclear(win);
    wmove(win, 0, 0);
    wrefresh(win);
    card *c = tab + y_newcard*size + x_newcard;
    combat(p, c, win);

    if ((*c).type[0]==1){
        (*p).treasure = 1;
        wprintw(win, "Vous avez trouve un coffre au tresor. Bravo !\n");
        wrefresh(win);
        sleep(5);
        wclear(win);
        wmove(win, 0, 0);
        wrefresh(win);
    }

    else if ((*c).r.type[0]==1){ //Vérifie si la classe Ranger est sur la bonne relique
        if ((*p).classe==3){
            (*p).relic=1;
            wprintw (win, "Le joueur vient de trouver sa relique.\n");
        }
        else{
            wprintw (win, "Oups! Ceci n'est pas ta relique... \n");
        }
        wrefresh(win);
        sleep(5);
        wclear(win);
        wmove(win, 0, 0);
        wrefresh(win);
    }

    else if ((*c).r.type[1]==1){ //Vérifie si la classe Guerrier est sur la bonne relique
        if ((*p).classe==2){
            (*p).relic=1;
            wprintw (win, "Le joueur vient de trouver sa relique.\n");
        }
        else{
            wprintw (win, "Oups! Ceci n'est pas ta relique... \n");
        }
        wrefresh(win);
        sleep(5);
        wclear(win);
        wmove(win, 0, 0);
        wrefresh(win);
    }

    else if ((*c).r.type[2]==1){ //Vérifie si la classe Magicien est sur la bonne relique
        if((*p).classe==1){
            (*p).relic=1;
            wprintw (win, "Le joueur vient de trouver sa relique.");
        }
        else{
            wprintw (win, "Oups! Ceci n'est pas ta relique... \n");
        }
        wrefresh(win);
        sleep(5);
        wclear(win);
        wmove(win, 0, 0);
        wrefresh(win);
    }

    else if ((*c).r.type[3]==1){ //Vérifie si la classe Voleur est sur la bonne relique
        if((*p).classe==4){
            (*p).relic=1;
            wprintw (win, "Le joueur vient de trouver sa relique.");
        }
        else{
            wprintw (win, "Oups! Ceci n'est pas ta relique... \n");
        }
        wrefresh(win);
        sleep(5);
        wclear(win);
        wmove(win, 0, 0);
        wrefresh(win);
    }

    else if ((*c).type[3]==1){
        Event(c, p, win, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    }
    else if ((*c).type[2]==1){
        Portal (p, tab, size, win, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    }

    else if ((*c).type[1]==1){
        Exchang_Totem (p, c, tab, size, win);
        (*p).life=0;
    }
    wrefresh(win);
}

void show_board(card *tab, int size, WINDOW* win_game) {
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    wclear(win_game);
    
      for (int i = 1; i < (size - 1); i++) {        // on affiche cartes par cartes
        for (int j = 1; j < (size - 1); j++) {
          wmove(win_game, i * 4, j * 10);
          if ((*(tab + i * size + j)).hidden == 0) {
                wattron(win_game, COLOR_PAIR(7));
                wprintw(win_game, "CARD");                //carte face cachée
                wattroff(win_game, COLOR_PAIR(7));
          }
          else {
            if ((*(tab + i * size + j)).type[0] == 1) { // trésor
                wattron(win_game, COLOR_PAIR(4));
                wprintw(win_game, "$$");
                wattroff(win_game, COLOR_PAIR(4));
            }
            else if ((*(tab + i * size + j)).type[1] == 1) { // totem
                wattron(win_game, COLOR_PAIR(2));
                wprintw(win_game, "TO");
                wattroff(win_game, COLOR_PAIR(2));
            }
            else if ((*(tab + i * size + j)).type[2] == 1) { // portail
                wattron(win_game, COLOR_PAIR(3));
                wprintw(win_game, "PO");
                wattroff(win_game, COLOR_PAIR(3));
            }
            else if ((*(tab + i * size + j)).type[3] == 1) { //événement
                wattron(win_game, COLOR_PAIR(2));
                wprintw(win_game, "EV");
                wattroff(win_game, COLOR_PAIR(2));
            }
            // Les 4 monstres
            else if ((*(tab + i * size + j)).m.type[0] == 1) { // basilique
                wattron(win_game, COLOR_PAIR(1));
                wprintw(win_game, "BA");
                wattroff(win_game, COLOR_PAIR(1));
            }
            else if ((*(tab + i * size + j)).m.type[1] == 1) { // zombie
                wattron(win_game, COLOR_PAIR(1));
                wprintw(win_game, "ZO");
                wattroff(win_game, COLOR_PAIR(1));
            }
            else if ((*(tab + i * size + j)).m.type[2] == 1) { // troll
                wattron(win_game, COLOR_PAIR(1));
                wprintw(win_game, "TR");
                wattroff(win_game, COLOR_PAIR(1));
            }
            else if ((*(tab + i * size + j)).m.type[3] == 1) { // harpie
                wattron(win_game, COLOR_PAIR(1));
                wprintw(win_game, "HA");
                wattroff(win_game, COLOR_PAIR(1));
            }
            // Les 4 reliques (armes antiques)
            else if ((*(tab + i * size + j)).r.type[0] == 1) { // baton
                wattron(win_game, COLOR_PAIR(6));
                wprintw(win_game, "BA");
                wattroff(win_game, COLOR_PAIR(6));
            }
            else if ((*(tab + i * size + j)).r.type[1] == 1) { //épée
                wattron(win_game, COLOR_PAIR(6));
                wprintw(win_game, "EP");
                wattroff(win_game, COLOR_PAIR(6));
            }
            else if ((*(tab + i * size + j)).r.type[2] == 1) { // grimoire
                wattron(win_game, COLOR_PAIR(6));
                wprintw(win_game, "GR");
                wattroff(win_game, COLOR_PAIR(6));
            }
            else if ((*(tab + i * size + j)).r.type[3] == 1) { // dague
                wattron(win_game, COLOR_PAIR(6));
                wprintw(win_game, "DA");
                wattroff(win_game, COLOR_PAIR(6));
            }
            else {
                wattron(win_game, COLOR_PAIR(7));
                wprintw(win_game, "ERREUR");
                wattroff(win_game, COLOR_PAIR(7));
            }
          }
        }
        printw("\n");
      }
    wrefresh(win_game);
}

