// voir void event, portal et totem pour intercation_card
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> //pour la musique

#define SIZE 8 // tableau 6x6

typedef struct {
  int type[4];
  /*
  type[0] = shield       (1=oui 0=non)                           <- 1.basilisk
  type[1] =  torch       (1=oui 0=non)                           <- 2.zombie
  type[2] =   axe        (1=oui 0=non)                           <- 3.troll
  type[3] =   bow        (1=oui 0=non)                          <- 4.harpy
  */
} weapons;

typedef struct {
  int type[4];
  /*
  type[0] = basilisk     (1=oui 0=non)                          <- 1.Bouclier
  type[1] = zombie     (1=oui 0=non)                            <- 2.Torche
  type[2] = troll       (1=oui 0=non)                           <- 3.Hache
  type[3] = harpy    (1=oui 0=non)       basilisk = basilic     <- 4. Arc
  */
} monster;

typedef struct {
  int type[4];
  /*
  type[0] = stick         (1=oui 0=non)       stick = baton
  type[1] = sword         (1=oui 0=non)       sword = epee
  type[2] = grimoire      (1=oui 0=non)
  type[3] = dagger        (1=oui 0=non)       dagger = dague
  */
} relic;

typedef struct {
  int neutral; // 0=non et 1=oui
  int malus;   // 0=non et 1=oui
} event;

typedef struct {
  int num;       // de 1 à 4 => n° du joueur
  char nom[100]; // ATTENTION depasement tableau
  int class;     // Magicien, guerrier, ranger, voleur
  weapons w;     // 1=Bouclier, 1=Torche, 2=Hache, 3=Arc
  int relic;     // 0,1
  int treasure;  // 0=non, 1=oui
  int life;      // 0=mort 1=vivant
  int x;         // place x dans le tableau entre 1 et 6
  int y;         // place y dans le tableau entre 1 et 6
  int x_init;    // place initiale
  int y_init;    // place initiale
  int move;      // prend +1 à chaque fin de tour
  int chrono;    // temps de la partie pour ce joueur
  int slay;      // nombre de monstre tué
  int reversed;  // nombre case retourné
  int chest; // nombre de trésore trouvé.    Attention à pas confondre avec
             // "treasure"
  int Score_victory; // nombre de victoire accumulé
  int timer;         // timer du temps du joueur dans une partie
} Player;

typedef struct {
  int wall;   // 1=oui 0=non
  int hidden; // 1=case visible  0=case cache
  int type[4];
  /*
  type[0] = treasure      (1=oui 0=non)
  type[1] = totem         (1=oui 0=non)
  type[2] = portal        (1=oui 0=non)       portal = portail
  type[3] = event         (1=oui 0=non)
  */
  monster m;
  relic r;
} card;

// INITIALISATION DU JEU
void board(card *tab, int size);
void init_wall(card *tab, int size);
void init_board(card *tab, int size);
void init_card(card *card1);
void invert_card(card *card1, card *card2);
void generate_board(card *tab, int size);

void resetPlayerPosition(Player *p);

// AVANT DE JOUER
int nb_player(WINDOW *win);
void create_player(Player *p, WINDOW *win);

// DURANT LE JEU
void return_card(card* c);
void Portal (Player* p, card* tab, int size, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void Event(card *c, Player *p, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);

void perso_move(Player* p, card* tab, int size, int x_newcard, int y_newcard); // key = KEY_UP ou KEY_DOWN ou KEY_RIGHT ou KEY_LEFT
void play(Player *p, card *tab, int size, WINDOW *win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void choose_weapon(Player *p, WINDOW *win);
void interaction_card(Player *p, card* tab, int size, WINDOW *win, int x_newcard, int y_newcard, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void combat(Player *p, card *c);
void show_board(card *tab, int size);

// void move(int table[ROWS][COLS], int* posX, int* posY, int direction);
// void event(card* c, Player* P);
int checkTreasure(Player *p);
void Exchang_Totem(Player P, card c, card new_card, card tempo);
void updateScore(FILE *fichier, Player P);

/*_________________________________________________________________________________________________*/
void board(card *tab, int size) {
  init_wall(tab, size);
  init_board(tab, size);
  generate_board(tab, size);
  // show_board (tab, size);
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
  printf("Initialisation des murs terminée.\n");
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
  printf("Initialisation des cartes terminée.\n");
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
          printf(" OUPS ! Le jeu n'a pas pu être créé. La carte générée aléatoirement n'est pas dans le paquet.\n");
          exit(1);
        }
        cards[alea] = cards[remaining_card - 1];
        remaining_card = remaining_card - 1;
      }
      else {
        clear();
        printw("Toutes les cartes du jeu sont placées !\n"); // est affiché 4 fois
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

// RETOUR CASE DEPART
void resetPlayerPosition(Player *p) {
  (*p).x = (*p).x_init;
  (*p).y = (*p).y_init;
  printw("Position du joueur %s réinitialisé.\n", (*p).nom);
}

/*_________________________________________________________________________________________________*/
// AVANT DE JOUER

int nb_player(WINDOW *win) {
  int choice = 0;
  do {
    choice = 0;
    wclear(win);
    wmove(win, 0, 0);
    wprintw(win, "Combien de joueurs etes-vous (entre 2 et 4) : ");
    wrefresh(win);
    choice = getch();
  } while (choice != '2' && choice != '3' && choice != '4');
    sleep(1);
    if (choice=='2'){
        return 2;
    }
    else if (choice=='3'){
        return 3;
    }
    return 4;
}

void create_player(Player *p, WINDOW *win) {
  wprintw(win, "\nEntrez votre pseudo : ");
  wrefresh(win);
  wgetnstr(win, (*p).nom,98); // récupère au max 98 caractères -> pas de dépassement
  int c = 0;
  do {
    c = 0;
    wmove(win, 3, 0);
    wprintw(win, "\nChoisissez votre Classe : \n");
    wprintw(win, "    1. Magicien\n");
    wprintw(win, "    2. Guerrier\n");
    wprintw(win, "    3. Ranger\n");
    wprintw(win, "    4. Voleur\n");
    wprintw(win, "Votre choix: ");
    wrefresh(win);
    c = getch();
  } while (c != '1' && c != '2' && c != '3' && c != '4');
    (*p).class = c;
    (*p).w.type[0] = 0;
    (*p).w.type[1] = 0;
    (*p).w.type[2] = 0;
    (*p).w.type[3] = 0;
    (*p).relic = 0;    // 0,1
    (*p).treasure = 0; // 0=non, 1=oui
    (*p).move = 0;     // prend +1 à chaque fin de tour
    (*p).chrono = 0;   // temps de la partie pour ce joueur
    (*p).slay = 0;     // nombre de monstre tué
    (*p).reversed = 0; // nombre case retourné
    (*p).chest = 0; // nombre de trésor trouvé.    Attention à pas confondre avec
                  // "treasure"
    (*p).Score_victory = 0; // nombre de victoire accumulé
    (*p).timer = 0;         // timer du temps du joueur dans une partie
    
    wclear(win);
    wrefresh(win);
}

/*_________________________________________________________________________________________________*/
// DURANT LE JEU


void return_card(card* c){		//le joueur a déjà son arme !
        (*c).hidden = 1;
        refresh();
}

//REVOIR fonctionnement portal
void Portal (Player* p, card* tab, int size, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    int new_direction_x = 0;
    int new_direction_y = 0;
    card* new_card = NULL;
    int delta_ascii = '1' - 1;
    do{
        wclear(win);
        new_direction_x = 0;
        new_direction_y = 0;
        do{
            wprintw(win, "\nChoisissez les coordonnées x, entre 1 et 6, vers lesquels vous voulez allez!");
            wrefresh(win); new_direction_x = getch();
        }while (new_direction_x < '1' || new_direction_x > '6');
        new_direction_x = new_direction_x - delta_ascii ;
        
        do{
            wprintw(win,"\nChoisissez les coordonnées y, entre 1 et 6, vers lesquels vous voulez allez!");
            wrefresh(win); new_direction_y = getch();
        }while (new_direction_y < '1' || new_direction_y > '6');
        new_direction_y = new_direction_y - delta_ascii ;

        card* new_card = tab + new_direction_y*size + new_direction_x;

    } while ((*new_card).wall == 1 || (*new_card).hidden == 1 || (new_direction_y==1 && new_direction_x==3) || (new_direction_y==3 && new_direction_x==6) || (new_direction_y==4 && new_direction_x==1)  || (new_direction_y==6 && new_direction_x==4) );

    return_card(new_card);
    refresh();
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

void Event(card *c, Player *p, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    //if (event == 1){
    do{
        int randevent = rand() %11;
        if (randevent == 0 && e1==1){
            printw(" ... /n/n Sérieusement...?/n ");
            const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";        // Lien vers la vidéo de Rick Astley en 8 bit
            const char* browser = "xdg-open";                                // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux
            execlp(browser, browser, rickRollURL, NULL);                    // Lancement du navigateur avec l'URL du Rick Roll
            e1 = 0;
            return ;
        }
        
        if (randevent == 1 && e2==1){
            printw ("Une harpie sauvage apparaît! « It's over Anakin, I have the highground! », dit-elle.\n");
            (*c).type[3]=0;
            (*c).m.type[3]=1;
            //change la case en monstre harpy et lance le combat. la case devient définitivement une harpy.
            e2 = 0;
            return;
        }
        
        if (randevent == 2 && e3==1){
            printw ("Vous voyez au loin un homme qui ne bouge pas. Vous vous approchez en pensant qu'il pourrait avoir besoin d'aide. Tous à coup, vous le voyez courrir en hurlant: LEEROY JENKINS!!! À cause de cette action, vous vous retrouvez sous une marée draconique, et mourrez, malgré tout avec l'honneur d'un grand guerrier!\n");
            (*p).life = 0;
            printw("Game over!\n");
            resetPlayerPosition(p);
            e3 = 0;
            return;
        }
        if (randevent == 3 && e4==1){
            printw ("Vous croisez une espèce de grosse tortue avec plein de pics sur sa carapace, et qui crache du feu. Elle vous regarde, et vous demande si vous n'avez pas vu une princesse blonde en robe rose. Vous lui dites que non, et par colère, il vous vole 10 petites étoiles! (si vous possédiez votre relique, elle est retournée à son point d'emplacement)\n");
            if ((*p).relic == 1){
                (*p).relic = 0; 
            }
            e4 = 0;
            return;
        }
        if (randevent==4 && e5==1){
            printw ("Un spectacle d'horreur se déroule devant vous ! Un pauvre poisson-clown hors de l'eau semble pleurer tout en ne pouvant pas respirer.\n Il semble répéter sans cesse ces mêmes mots :\n   « Vous n'avez pas vu mon fils ?\n Vous n'avez pas vu mon fils ?\n Vous n'avez pas vu mon... » \nLe manque d'oxygen a eu raison de lui. Vous avez désormais un nouvel objectif : après être sorti victorieux de ce labyrinthe infernal, vous vous mettrez à la recherche de ce fameux « fils ».\n");
            e5 = 0;
            return;
        }
        if (randevent==5 && e6==1){
            printw ("Vous croisez un énorme tuyau fait de métal. Intrigué, vous vous approchez et entendez une étrange voix dans votre tête : Il faut suivre le conduit. Ne sachant ce qu'est ce fameux « conduit », vous continuez votre route.\n");
            e6 = 0;
            return;
        }
        
        if (randevent==6 && e7==1){
            printw ("Un homme au loin vous demande comment rejoindre le « Sunny ». Il a les cheveux verts, comme si de la mousse lui avait poussé sur la tête. Il porte trois sabres au niveau de la ceinture, il paraît vraiment louche. Vous lui montrez une direction aléatoire en espérant qu'il vous laisse enfin tranquille. Il part dans la direction inverse complète. Quelle étrange rencontre !\n");
            e7=0;
            return;
        }
             
        if (randevent==7 && e8==1){
            printw ("Vous voyez une sorte de scientifique au loin. En essayant de vous approcher, vous voyez une sorte d'écran apparaître avec marqué dessus : « Fun value invalid ». \nVoyant que vous ne pouvez pas continuer, vous décidez d'abandonner et de continuer votre périple.\n");
            e8=0;
            return;
        }
    
        if (randevent==8 && e9==1){
            printw ("En vous baladant, vous tombez sur une étrange famille de deux squelettes. L'un petit, portant des habits rouge et blanc. Son frère, plus petit, porte un sweet à capuche bleu et un pantalon noir. Pour éviter tout combat inutile, vous attendez un peu que le temps passe.\n");
            e9 = 0;
            return;
        }
    
        if (randevent==9 && e10==1){
            printw ("Vous trouvez un parchemin ancien ! Quel secret cache t-il ? \nVous l'ouvrez et le contemplez. Il est écrit : « Seul Link peut vaincre Ganon. ». Du fait que vous ne vous nommez ni Link, ni Ganon, vous jetez ce torchon inutile.\n");
            e10 = 0;
            return;
        }
            
        if (randevent==10 && e11==1){
            printw ("Vous rencontrez au détour de ce labyrinthe un vieil homme. Il prétend être le directeur d'un lycée spécialisé en magie très connu : le Lycée Magique George Pompidou. Il exprime même l'envie de vous faire entrer dans son lycée, dans la classe de « Nintendor ». Vous acceptez, et par conséquent, il se mit à hurler : « 100.000 points pour Nintendor! »\n.");
            e11 = 0;
            return;
        }
        //else{
        //    printw ("Continuez votre route brave combattant !\n");
        //    return ;
        //}
    } while(e1==1 || e2==1 || e3==1 || e4==1 || e5==1 || e6==1 || e7==1 || e8==1 || e9==1 || e10==1 || e11==1);          
}


void play(Player* p, card* tab, int size, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    
    wclear(win);
    wmove(win, 0, 0);
    choose_weapon(p, win);
    int key = 0;		            //récupèrera la touche appuyée
    int forbidden = 0;
    card newcard;
    card* pnewcard = & newcard;				// pnewcard : pointe vers la carte ou on veut aller
    int x_newcard = 0;
    int y_newcard = 0;

    //si le joueur est coincé entre 4 murs (ou cartes dévoilé) -> MORT
    if (  ( (*(tab + ((*p).y-1)*size + (*p).x)).wall == 1 || (*(tab + ((*p).y-1)*size + (*p).x)).hidden == 1 )  &&  ( (*(tab + ((*p).y+1)*size + (*p).x)).wall == 1 || (*(tab + ((*p).y+1)*size + (*p).x)).hidden == 1 )  &&  ( (*(tab + ((*p).y)*size + (*p).x-1)).wall == 1 || (*(tab + ((*p).y)*size + (*p).x-1)).hidden == 1 )  &&  ( (*(tab + ((*p).y)*size + (*p).x+1)).wall == 1 || (*(tab + ((*p).y)*size + (*p).x+1)).hidden == 1)  ){
        (*p).life = 0;
        wprintw(win, "Game Over ! %s est mort\n", (*p).nom);
        wrefresh(win);
    }

    else {
        do{
            forbidden = 0;
            // indique si le joueur a le droit de se déplacer sur la case où il veut aller
                    //    forbidden = 0       -> c'est ok
                    //    forbidden = 1       -> c'est un mur ou une carte retournée 
            do{
                wmove(win, 0, 0);
                wprintw(win, "Où voulez-vous vous déplacer (utilisez les flèches de votre clavier) : ");
                wrefresh(win);
                forbidden = 0;
                key = getch();
                if(key!=KEY_UP && key!=KEY_DOWN && key!=KEY_RIGHT && key!=KEY_LEFT){
                    forbidden = 1;
                    wprintw(win, "\nMouvement entré invalide, veuillez réessayer.");
                }
            } while(forbidden==1);           //tant qu'on ne rencontre pas un mur. ATTENTION au cas où le joueur est coincé entre 4 murs !!! -> le faire mourir.

            switch(key){
                case KEY_UP:
                    if ( (*(tab + ((*p).y-1)*size + (*p).x)).wall == 1 || (*(tab + ((*p).y-1)*size + (*p).x)).hidden == 1){ //on va vers mur ou carte révélée
                        forbidden = 1;
                    }
                    else{
                        pnewcard = (tab + ((*p).y-1)*size + (*p).x);
                        x_newcard = (*p).x;
                        y_newcard = ((*p).y-1);
                    }
                    break;

                case KEY_DOWN:
                    if ( (*(tab + ((*p).y+1)*size +(*p).x)).wall == 1 || (*(tab + ((*p).y+1)*size + (*p).x)).hidden == 1){    //on va vers mur ou carte révélée
                        forbidden = 1;
                    }
                    else{
                        pnewcard = (tab + ((*p).y+1)*size + (*p).x);
                        x_newcard = (*p).x;
                        y_newcard = ((*p).y+1);
                    }
                    break;

                case KEY_RIGHT:
                    if ( (*(tab + ((*p).y)*size +(*p).x+1)).wall == 1 || (*(tab + ((*p).y)*size + (*p).x+1)).hidden == 1){    //on va vers mur ou carte révélée
                        forbidden = 1;
                    }
                    else{
                        pnewcard = (tab + ((*p).y)*size + (*p).x+1);
                        x_newcard = (*p).x+1;
                        y_newcard = ((*p).y);
                    }
                    break;

                case KEY_LEFT:
                    if ( (*(tab + ((*p).y)*size + (*p).x-1)).wall == 1 || (*(tab + ((*p).y)*size + (*p).x-1)).hidden == 1){    //on va vers mur ou carte révélée
                        forbidden = 1;
                    }
                    else{
                        pnewcard = (tab + ((*p).y)*size + (*p).x-1);
                        x_newcard = (*p).x-1;
                        y_newcard = ((*p).y);
                    }
                    break;

                default:
                    break;
            }
        } while(forbidden == 1);
    }
    return_card(pnewcard);        //retourne la carte ou on va pdt 3s
    show_board(tab, size);
    refresh();
    sleep(3);
    interaction_card(p, tab, size, win, x_newcard, y_newcard, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    //bouger que si on gagne : void interaction_card(Player* p, card* c);
    if ((*p).life == 1){
        perso_move(p, tab, size, x_newcard, y_newcard);
    }
}




void choose_weapon(Player* p, WINDOW* win){
    wclear(win);
    wmove(win, 0, 0);
    wprintw(win, "Choisissez votre arme : \n");
    wprintw(win, "    1. Bouclier\n");
    wprintw(win, "    2. Torche\n");
    wprintw(win, "    3. Hache\n");
    wprintw(win, "    4. Arc\n");
    wrefresh(win);

    int choice = 0;
    do {
        choice = 0;
        wprintw(win, "Votre choix : ");
        wrefresh(win);
        choice = getch();
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');

    if (choice == '1'){               //bouclier
        (*p).w.type[0] = 1;
        (*p).w.type[1] = 0;
        (*p).w.type[2] = 0;
        (*p).w.type[3] = 0;
    }

    else if (choice == '2'){          //Torche
        (*p).w.type[0] = 0;
        (*p).w.type[1] = 1;
        (*p).w.type[2] = 0;
        (*p).w.type[3] = 0;
    }

    else if (choice == '3'){          //hache
        (*p).w.type[0] = 0;
        (*p).w.type[1] = 0;
        (*p).w.type[2] = 1;
        (*p).w.type[3] = 0;
    }

    else{                           //arc
        (*p).w.type[0] = 0;
        (*p).w.type[1] = 0;
        (*p).w.type[2] = 0;
        (*p).w.type[3] = 1;
    }
}

void interaction_card(Player *p, card* tab, int size, WINDOW *win, int x_newcard, int y_newcard, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    //COMBAT AVEC LE MONSTRE fait (si il y en a)
    card *c = tab + y_newcard*size + x_newcard;
    combat(p, c);

    if ((*c).type[0]==1){
        (*p).treasure = 1;
    }

    else if ((*c).r.type[0]==1){ //Vérifie si la classe Ranger est sur la bonne relique
        if ((*p).class==3){
            (*p).relic=1;
            printw ("Le joueur vient de trouver sa relique.\n");
        }
        else{
            printw ("Oups! Ceci n'est pas ta relique... \n");
        }
    }

    else if ((*c).r.type[1]==1){ //Vérifie si la classe Guerrier est sur la bonne relique
        if ((*p).class==2){
            (*p).relic=1;
            printw ("Le joueur vient de trouver sa relique.\n");
        }
        else{
            printw ("Oups! Ceci n'est pas ta relique... \n");
        }
    }

    else if ((*c).r.type[2]==1){ //Vérifie si la classe Magicien est sur la bonne relique
        if((*p).class==1){
            (*p).relic=1;
            printw ("Le joueur vient de trouver sa relique.");
        }
        else{
            printw ("Oups! Ceci n'est pas ta relique... \n");
        }
    }

    else if ((*c).r.type[3]==1){ //Vérifie si la classe Voleur est sur la bonne relique
        if((*p).class==4){
            (*p).relic=1;
            printw ("Le joueur vient de trouver sa relique.");
        }
        else{
            printw ("Oups! Ceci n'est pas ta relique... \n");
        }
    }

    else if ((*c).type[3]==1){
        Event(c, p, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    }
    else if ((*c).type[2]==1){
        Portal(p, c, size, win);
    }

    else if ((*c).type[1]==1){
        //Totem(p,c); -> Exchang_Totem (Player P, card c,card new_card,card tempo);
        (*p).life=0;
    }

    if (checkTreasure(p)==1){
        //break;
    }

}

void combat(Player* p, card* c) {
    if ((*c).m.type[0] == 1){
            if((*p).w.type[0] == 1){
                printw ("Le Basilic est vaincu !\n");
                (*p).slay++;				//nbre de monstres tués
            }
            else{
                printw ("Game Over ! Le Basilic vous a tué.\n");
                (*p).life = 0;
             resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[1] == 1){
            if((*p).w.type[1] == 1){
                printw ("Le Zombie est vaincu !\n");
                (*p).slay++;
            }
            else{
                printw ("Game Over ! Le Zombie vous a tué.\n");
                (*p).life = 0;
             resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[2] == 1){
            if((*p).w.type[2] == 1){
                printw ("Le Troll est vaincu !\n");
                (*p).slay++;
            }
            else{
                printw ("Game Over ! Le Troll vous a tué.\n");
                (*p).life = 0;
                resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[3] == 1){
            if((*p).w.type[3] == 1){
                printw ("La Harpie est vaincu !\n");
                (*p).slay++;
            }
            else{
                printw ("Game Over ! La Harpie vous a tué.\n");
                (*p).life = 0;
                resetPlayerPosition(p);
            }
    }
}

//Déplace joueur sur une case du tableau
void perso_move(Player* p, card* tab, int size, int x_newcard, int y_newcard){		//key = KEY_UP ou KEY_DOWN ou KEY_RIGHT ou KEY_LEFT
    (*p).x = x_newcard;
    (*p).y = y_newcard;
}


// AFFICHAGE du JEU
void show_board(card *tab, int size) {
  for (int i = 1; i < (size - 1); i++) { // on affiche cartes par cartes
    for (int j = 1; j < (size - 1); j++) {
      move(i * 4, j * 10);
      if ((*(tab + i * size + j)).hidden == 0) {
        // addch('\u25A0');					// Affiche le caractère du
        // carré plein
        printw("\u25A0");
      } else {
        if ((*(tab + i * size + j)).type[0] == 1) { // trésor
          // addstr("\u{1F4B0}");
          printw("$");
        } else if ((*(tab + i * size + j)).type[1] == 1) { // totem
          printw("\U0001F5FF");
        } else if ((*(tab + i * size + j)).type[2] == 1) { // portail
          printw("\U000026E9");
        } else if ((*(tab + i * size + j)).type[3] == 1) { //événement
          printw("E");
        }
        // Les 4 monstres
        else if ((*(tab + i * size + j)).m.type[0] == 1) { // basilique
          printw("\U0001F40D");
        } else if ((*(tab + i * size + j)).m.type[1] == 1) { // zombie
          printw("\U0001F9DF");
        } else if ((*(tab + i * size + j)).m.type[1] == 1) { // troll
          printw("\U0001F479");
        } else if ((*(tab + i * size + j)).m.type[1] == 1) { // harpie
          printw("\U0001F426");
        }
        // Les 4 reliques (armes antiques)
        else if ((*(tab + i * size + j)).r.type[0] == 1) { // baton
          printw("\U0001F3D1");
        } else if ((*(tab + i * size + j)).r.type[1] == 1) { //épée
          printw("\U00002694");
        } else if ((*(tab + i * size + j)).r.type[2] == 1) { // grimoire
          printw("\U0001F4D6");
        } else if ((*(tab + i * size + j)).r.type[3] == 1) { // dague
          printw("\U0001F5E1");
        } else {
          printw("ERREUR");
        }
      }
    }
    printw("\n");
  }
}

/*____________________________________________________________________________*/
// MAIN

int main() {
  initscr();
  // raw();
  //noecho();
  keypad(stdscr, TRUE); // active la prise en charge des touches spéciales
                        // (comme les flèches)

  // Mesure Dimensions fenêtre affichage
  int y_max, x_max; // y_max = nbre de lignes de la fenêtre     x_max = nbre de
                    // colonnes de la fenêtre
  getmaxyx(stdscr, y_max, x_max); // mesure le nbre de lignes (y_max) et de
                                  // colonnes (x_max) qui peuvent être affichés

  // move(5,0);
  // LOGO
  int height_logo, width_logo, starty_logo, startx_logo;
  startx_logo = x_max / 2 - 65;
  starty_logo = 5;
  height_logo = 11;
  width_logo = 129;
  WINDOW *win_logo = newwin(height_logo, width_logo, starty_logo,
                            startx_logo); // cadre du logo

  // 128 caractères sur la 1ere ligne et 11 lignes
  wprintw(win_logo,
          " .d8888b. Y88b   d88P      888b     d888                            "
          "                           8888888b.  8888888b.   .d8888b.  \n");
  wprintw(win_logo,
          "d88P  Y88b Y88b d88P       8888b   d8888                            "
          "                           888   Y88b 888   Y88b d88P  Y88b \n");
  wprintw(win_logo,
          "888    888  Y88o88P        88888b.d88888                            "
          "                           888    888 888    888 888    888 \n");
  wprintw(win_logo,
          "888          Y888P         888Y88888P888  .d88b.  88888b.d88b.   "
          ".d88b.  888d888 888  888      888   d88P 888   d88P 888        \n");
  wprintw(win_logo,
          "888           888          888 Y888P 888 d8P  Y8b 888 *888 *88b "
          "d88**88b 888P*   888  888      8888888P*  8888888P*  888  88888 \n");
  wprintw(win_logo,
          "888    888    888   888888 888  Y8P  888 88888888 888  888  888 888 "
          " 888 888     888  888      888 T88b   888        888    888 \n");
  wprintw(win_logo,
          "Y88b  d88P    888          888   *   888 Y8b.     888  888  888 "
          "Y88..88P 888     Y88b 888      888  T88b  888        Y88b  d88P \n");
  wprintw(win_logo,
          " *Y8888P*     888          888       888  *Y8888  888  888  888  "
          "*Y88P*  888      *Y88888      888   T88b 888         *Y8888P88 \n");
  wprintw(win_logo,
          "                                                                    "
          "                  888                                       \n");
  wprintw(win_logo,
          "                                                                    "
          "             Y8b d88P                                       \n");
  wprintw(win_logo, "                                                          "
                    "                        *Y88P*\n");
  refresh();
  wrefresh(win_logo);

  move(y_max - 1, 0);
  printw("Appuyer sur la touche q pour sortir du jeu.\n");
  refresh();
  move(16, 0); // on replace le curseur après le logo de jeu

  int height_menu, width_menu, starty_menu, startx_menu;
  startx_menu = x_max / 2 - 10;
  starty_menu = 16;
  height_menu = 15;
  width_menu = 50;

  // MENU
  WINDOW *win_menu = newwin(height_menu, width_menu, starty_menu, startx_menu);
  int menu = 1; // menu=1 -> on est ds menu     menu=0 -> on n'est plus ds menu
                // (ds le jeu par ex)
  int menu_select = 1; // les menus à sélectionner vont de 1 à 4
  wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
  wprintw(win_menu, "Tableau des scores\n");
  wprintw(win_menu, "Regles\n");
  wprintw(win_menu, "Sortir\n");
  // refresh();
  wrefresh(win_menu);

  int EXIT = 0; // EXIT = 0 -> on reste dans le menu        EXIT = 1 -> on va
                // ailleurs que dans le menu
  do {
    int key_pressed = getch();
    if (key_pressed == (int)'q' ||
        key_pressed == (int)'Q') { // en entrant q : on sort du jeu
      endwin();
      return 0;
    }
    if (key_pressed == KEY_UP ||
        key_pressed == '8') { // ATTENTION : int key_pressed ?????
      menu_select--;
      printw("Key_up appuyé\n");
      refresh();
    }
    if (key_pressed == KEY_DOWN || key_pressed == '2') {
      menu_select++;
      printw("Key_down appuyé\n");
      refresh();
    }
    if (menu_select <= 0) {
      menu_select = 4;
    }
    if (menu_select > 4) {
      menu_select = 1;
    }
    wclear(win_menu);
    // Changement taille texte qd on est dessus
    switch (menu_select) {
    case 1:
      wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
      wprintw(win_menu, "Tableau des scores\n");
      wprintw(win_menu, "Regles\n");
      wprintw(win_menu, "Sortir\n");
      break;
    case 2:
      wprintw(win_menu, "Nouvelle partie\n");
      wprintw(win_menu, "-> TABLEAU DES SCORES <-\n");
      wprintw(win_menu, "Regles\n");
      wprintw(win_menu, "Sortir\n");
      break;
    case 3:
      wprintw(win_menu, "Nouvelle partie\n");
      wprintw(win_menu, "Tableau des scores\n");
      wprintw(win_menu, "-> REGLES <-\n");
      wprintw(win_menu, "Sortir\n");
      break;
    case 4:
      wprintw(win_menu, "Nouvelle partie\n");
      wprintw(win_menu, "Tableau des scores\n");
      wprintw(win_menu, "Regles\n");
      wprintw(win_menu, "-> SORTIR <-\n");
      break;
    default:
      printf("ERREUR d'affichage menu.");
      exit(103);
      break;
    }
    refresh();
    wrefresh(win_menu);
    if (key_pressed == '\n') { // Le joueur a sélectionné un des 4 menus
      EXIT = 1;
    }
  } while (!EXIT);

  clear();

  int e1 = 1, e2 = 1, e3 = 1, e4 = 1, e5 = 1, e6 = 1, e7 = 1, e8 = 1, e9 = 1,
      e10 = 1, e11 = 1;
  if (menu_select == 1) {

    int nmb_player = nb_player(win_menu);

    Player p1;
    Player p2;
    Player p3;
    Player p4;
    Player *pp1 = &p1;
    Player *pp2 = &p2;
    Player *pp3 = &p3;
    Player *pp4 = &p4;

    // INITIALISATION DES 4 JOUEURS
    create_player(pp1, win_menu); // Créée l'identité du joueur 1
    sleep(2);
    p1.num = 1;
    p1.life = 1;   // 0=mort 1=vivant
    p1.x = 3;      // place x dans le tableau entre 1 et 6
    p1.y = 1;      // place y dans le tableau entre 1 et 6
    p1.x_init = 3; // place initiale
    p1.y_init = 1; // place initiale
    
      
    create_player(pp2, win_menu); // Créée l'identité du joueur 2
    sleep(2);
    p2.num = 2;
    p2.life = 0;   // 0=mort 1=vivant
    p2.x = 1;      // place x dans le tableau entre 1 et 6
    p2.y = 4;      // place y dans le tableau entre 1 et 6
    p2.x_init = 1; // place initiale
    p2.y_init = 4; // place initiale

    if (nmb_player >= 3) {
      create_player(pp3, win_menu); // Créée l'identité du joueur 3
      sleep(2);
      p3.num = 3;
      p3.life = 0;   // 0=mort 1=vivant
      p3.x = 4;      // place x dans le tableau entre 1 et 6
      p3.y = 6;      // place y dans le tableau entre 1 et 6
      p3.x_init = 4; // place initiale
      p3.y_init = 6; // place initiale
    }
    if (nmb_player == 4) {
      create_player(pp4, win_menu); // Créée l'identité du joueur 4
      sleep(2);
      p4.num = 4;
      p4.life = 0;   // 0=mort 1=vivant
      p4.x = 4;      // place x dans le tableau entre 1 et 6
      p4.y = 6;      // place y dans le tableau entre 1 et 6
      p4.x_init = 4; // place initiale
      p4.y_init = 6; // place initiale
    }

    WINDOW *win_game = newwin(20, 100, 5, 15); // fenêtre du plateau de jeu
    WINDOW *win_interface = newwin(20, 100, 5, 40);
    card *game;
    game = malloc(SIZE * SIZE *sizeof(card)); // game est notre plateau de jeu (tableau)
    if (game == NULL) {
      printf("Problème d'allocation de mémoire pour la création du tableau du jeu.\n");
      exit(10);
    }
    board(game, SIZE);
    
    Player* tab_player[] = {pp1, pp2, pp3, pp4};             //tableau où il y a les 4 joueurs
    int r=-1;
    do{
        r++;
        r = r%nmb_player;
        (*(tab_player[r])).life = 1;
        do{
            play(tab_player[r], game, SIZE, win_interface, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);			// INTERACTION JOUEUR
            (*(tab_player[r])).move ++;
        } while( (*(tab_player[r])).life==1 && ((*(tab_player[r])).relic!=1 || (*(tab_player[r])).treasure!=1));
        e1=1, e2=1, e3=1, e4=1, e5=1, e6=1, e7=1, e8=1, e9=1, e10=1, e11=1;
    } while ( (*(tab_player[r])).relic!=1 || (*(tab_player[r])).treasure!=1 );        //condition de VICTOIRE

      show_board(game, SIZE);
      clear();
      move(0,0);
      printw("BRAVO !\n %s a brillamment gagné en %d tours.\n Dommage pour les autres !", (*(tab_player[r])).nom, (*(tab_player[r])).move);
      
        
    // do{
    // choose_weapon(Player* p, WINDOW* win);
    // getch();
    //}while(p.life==1);				//tant que joueur en vie et n'a pas
    //gagné

    free(game);
  } else if (menu_select == 2) {

  }

  else if (menu_select == 3) {
    // affiche le readme
  }

  else { // SORTIR du jeu
    endwin();
    return 0;
  }

  endwin();
  return 0;
}



/*____________________________________________________________________________*/
    

    

    /*
    printw(" ____     __    __                                                               ____    ____    ____     \n");
    printw("/\  _`\  /\ \  /\ \        /'\_/`\                                              /\  _`\ /\  _`\ /\  _`\    \n");
    printw("\ \ \/\_\\ `\`\\/'/       /\      \     __    ___ ___     ___   _ __   __  __   \ \ \L\ \ \ \L\ \ \ \L\_\  \n");
    printw(" \ \ \/_/_`\ `\ /' _______\ \ \__\ \  /'__`\/' __` __`\  / __`\/\`'__\/\ \/\ \   \ \ ,  /\ \ ,__/\ \ \L_L  \n");
    printw("  \ \ \L\ \ `\ \ \/\______\\ \ \_/\ \/\  __//\ \/\ \/\ \/\ \L\ \ \ \/ \ \ \_\ \   \ \ \\ \\ \ \/  \ \ \/, \\n");
    printw("   \ \____/   \ \_\/______/ \ \_\\ \_\ \____\ \_\ \_\ \_\ \____/\ \_\  \/`____ \   \ \_\ \_\ \_\   \ \____/\n");
    printw("    \/___/     \/_/          \/_/ \/_/\/____/\/_/\/_/\/_/\/___/  \/_/   `/___/> \   \/_/\/ /\/_/    \/___/ \n");
    printw("                                                                           /\___/                          \n");
    printw("                                                                           \/__/\n");
    */
    
    /*
    printw(" $$$$$$\ $$\     $$\       $$\      $$\                                                             $$$$$$$\  $$$$$$$\   $$$$$$\  \n");
    printw("$$  __$$\\$$\   $$  |      $$$\    $$$ |                                                            $$  __$$\ $$  __$$\ $$  __$$\ \n");
    printw("$$ /  \__|\$$\ $$  /       $$$$\  $$$$ | $$$$$$\  $$$$$$\$$$$\   $$$$$$\   $$$$$$\  $$\   $$\       $$ |  $$ |$$ |  $$ |$$ /  \__|\n");
    printw("$$ |       \$$$$  /$$$$$$\ $$\$$\$$ $$ |$$  __$$\ $$  _$$  _$$\ $$  __$$\ $$  __$$\ $$ |  $$ |      $$$$$$$  |$$$$$$$  |$$ |$$$$\ \n");
    printw("$$ |        \$$  / \______|$$ \$$$  $$ |$$$$$$$$ |$$ / $$ / $$ |$$ /  $$ |$$ |  \__|$$ |  $$ |      $$  __$$< $$  ____/ $$ |\_$$ |\n");
    printw("$$ |  $$\    $$ |          $$ |\$  /$$ |$$   ____|$$ | $$ | $$ |$$ |  $$ |$$ |      $$ |  $$ |      $$ |  $$ |$$ |      $$ |  $$ |\n");
    printw("\$$$$$$  |   $$ |          $$ | \_/ $$ |\$$$$$$$\ $$ | $$ | $$ |\$$$$$$  |$$ |      \$$$$$$$ |      $$ |  $$ |$$ |      \$$$$$$  |\n");
    printw(" \______/    \__|          \__|     \__| \_______|\__| \__| \__| \______/ \__|       \____$$ |      \__|  \__|\__|       \______/ \n");
    printw("                                                                                    $$\   $$ |                                    \n");
    printw("                                                                                    \$$$$$$  |                                    \n");
    printw("                                                                                     \______/\n");
    */
    
    /*

    printw(" @@@@@@@  @@@ @@@             @@@@@@@@@@   @@@@@@@@  @@@@@@@@@@    @@@@@@   @@@@@@@   @@@ @@@     @@@@@@@   @@@@@@@    @@@@@@@@  \n");
    printw("@@@@@@@@  @@@ @@@             @@@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@ @@@     @@@@@@@@  @@@@@@@@  @@@@@@@@@  \n");
    printw("!@@       @@! !@@             @@! @@! @@!  @@!       @@! @@! @@!  @@!  @@@  @@!  @@@  @@! !@@     @@!  @@@  @@!  @@@  !@@        \n");
    printw("!@!       !@! @!!             !@! !@! !@!  !@!       !@! !@! !@!  !@!  @!@  !@!  @!@  !@! @!!     !@!  @!@  !@!  @!@  !@!        \n");
    printw("!@!        !@!@!   @!@!@!@!@  @!! !!@ @!@  @!!!:!    @!! !!@ @!@  @!@  !@!  @!@!!@!    !@!@!      @!@!!@!   @!@@!@!   !@! @!@!@  \n");
    printw("!!!         @!!!   !!!@!@!!!  !@!   ! !@!  !!!!!:    !@!   ! !@!  !@!  !!!  !!@!@!      @!!!      !!@!@!    !!@!!!    !!! !!@!!  \n");
    printw(":!!         !!:               !!:     !!:  !!:       !!:     !!:  !!:  !!!  !!: :!!     !!:       !!: :!!   !!:       :!!   !!:  \n");
    printw(":!:         :!:               :!:     :!:  :!:       :!:     :!:  :!:  !:!  :!:  !:!    :!:       :!:  !:!  :!:       :!:   !::  \n");
    printw(" ::: :::     ::               :::     ::    :: ::::  :::     ::   ::::: ::  ::   :::     ::       ::   :::   ::        ::: ::::  \n");
    printw(" :: :: :     :                 :      :    : :: ::    :      :     : :  :    :   : :     :         :   : :   :         :: :: :\n");
    */
