#ifndef HEADER_H
#define HEADER_H


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
  int classe;     // Magicien, guerrier, ranger, voleur
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


//FICHIER
void updateScore(FILE* fichier, Player* P,char job []);
void Score_creator(Player* P);

// INITIALISATION DU JEU
void board(card *tab, int size, WINDOW* win_game);
void hide_board(card *tab, int size, WINDOW* win_game);
void init_wall(card *tab, int size);
void init_board(card *tab, int size);
void init_card(card *card1);
void invert_card(card *card1, card *card2);
void generate_board(card *tab, int size);

void resetPlayerPosition(Player *p);

// AVANT DE JOUER
int nb_player(WINDOW *win);
void create_player(Player *p, WINDOW *win, int c1, int c2, int c3, int c4);

// DURANT LE JEU
void return_card(card* c);
void Portal (Player* p, card* tab, int size, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void Exchang_Totem (Player* p, card* c, card* tab,int size, WINDOW* win);
void Event(card *c, Player *p, WINDOW* win, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);

void perso_move(Player* p, card* tab, int size, int x_newcard, int y_newcard); // key = KEY_UP ou KEY_DOWN ou KEY_RIGHT ou KEY_LEFT
void play(Player* p, card* tab, int size, WINDOW* win, WINDOW* win_game, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void choose_weapon(Player *p, WINDOW *win, WINDOW* win_game);
void interaction_card(Player *p, card* tab, int size, WINDOW *win, int x_newcard, int y_newcard, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11);
void combat(Player *p, card *c, WINDOW* win);
void show_board(card *tab, int size, WINDOW* win_game);


#endif 
