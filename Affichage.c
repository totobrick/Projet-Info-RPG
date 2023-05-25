// VOIR LE CAS OU JOUR ENTOURE DE 4 MURS/CARTES RETOURNEES -> retour case départ et on retourne les cartes 
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define SIZE 8              //tableau 6x6


typedef struct{
    int type[4];
        /*
        type[0] = shield       (1=oui 0=non)                           <- 1.basilisk
        type[1] =  torch       (1=oui 0=non)                           <- 2.zombie
        type[2] =   axe        (1=oui 0=non)                           <- 3.troll
        type[3] =   bow        (1=oui 0=non)                          <- 4.harpy
        */ 
} weapons;

typedef struct{
    int type[4];
        /*
        type[0] = basilisk     (1=oui 0=non)                          <- 1.Bouclier
        type[1] = zombie     (1=oui 0=non)                            <- 2.Torche
        type[2] = troll       (1=oui 0=non)                           <- 3.Hache
        type[3] = harpy    (1=oui 0=non)       basilisk = basilic     <- 4. Arc
        */ 
} monster;

typedef struct{
    int type[4];
        /*
        type[0] = stick         (1=oui 0=non)       stick = baton
        type[1] = sword         (1=oui 0=non)       sword = epee
        type[2] = grimoire      (1=oui 0=non)
        type[3] = dagger        (1=oui 0=non)       dagger = dague
        */           
} relic;

typedef struct{
    int neutral;    // 0=non et 1=oui 
    int malus;      // 0=non et 1=oui 
} event;

typedef struct{
    char nom[100];            //ATTENTION depasement tableau
    int class;                //Magicien, guerrier, ranger, voleur
    weapons w;                //1=Bouclier, 1=Torche, 2=Hache, 3=Arc
    int relic;                //0,1
    int treasure;             //0=non, 1=oui
    int life;                 // 0=mort 1=vivant
    int x;                    // place x dans le tableau entre 1 et 6
    int y;                    // place y dans le tableau entre 1 et 6
    int x_init;                //place initiale
    int y_init;                //place initiale
    int move;                  //prend +1 à chaque fin de tour
    int chrono;                // temps de la partie pour ce joueur
    int slay;                  //nombre de monstre tué
    int reversed;              //nombre case retourné
    int chest;                 //nombre de trésore trouvé.    Attention à pas confondre avec "treasure"
    int Score_victory;         //nombre de victoire accumulé 
    int timer;                 //timer du temps du joueur dans une partie
}Player;


typedef struct{
    int wall;       //1=oui 0=non
    int hidden;     //1=case visible  0=case cache
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
void init_wall (card* tab, int size);
void init_board (card* tab, int size);
void init_card(card* card1);
void invert_card(card* card1, card* card2);
void generate_board (card* tab, int size);
void board (card* tab, int size);

// AVANT DE JOUER
int nb_player (WINDOW* win);
void create_player(Player* p);

// DURANT LE JEU
void choose_weapon(Player* p, WINDOW* win);
void return_card(Player* p, card* c)
void perso_move(Player* p, card* tab, int size);
void show_board (card* tab, int size);

void resetPlayerPosition(Player* p);
//void move(int table[ROWS][COLS], int* posX, int* posY, int direction);
//void event(card* c, Player* P);
int checkTreasure(Player player);
void Exchang_Totem (Player P, card c,card new_card,card tempo);
void Portal (Player* P, card* tab, int size);
void updateScore(FILE* fichier, Player P);

/*_________________________________________________________________________________________________*/
void board (card* tab, int size){
    init_wall(tab, size);
    init_board(tab, size);
    generate_board(tab, size);
    //show_board (tab, size);
}
/*_________________________________________________________________________________________________*/

				// INITIALISATION DU JEU

void init_wall (card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int j=0; j<size ; j++){
        (*(tab + 0*size + j)).wall=1;
    }
    for (int i=1 ; i<(size-1) ; i++){
        (*(tab + i*size + 0)).wall=1;
        for (int j=1 ; j<(size-1) ; j++){
            (*(tab + i*size + j)).wall=0;
        }
        (*(tab + i*size + 7)).wall=1;
    }
    for (int j=0; j<size ; j++){
        (*(tab + (size-1)*size + j)).wall=1;
    }
    printf("Initialisation des murs terminée.\n");
}

void init_board (card* tab, int size){
    if (size<=0){
        exit(1);
    }
    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<size ; j++){
            init_card(tab +  i*size + j);
        }
    }
    printf("Initialisation des cartes terminée.\n");
}

void init_card(card* card1){
    (*card1).hidden = 0;
    for (int i=0 ; i<4 ; i++){
        (*card1).type[i] = 0;
        (*card1).m.type[i] = 0;         //monster
        (*card1).r.type[i] = 0;         //relic
    }
}

void invert_card(card* card1, card* card2){
    card* transit_card = malloc(sizeof(card));
    //transit_card = card1
    (*transit_card).hidden = (*card1).hidden;
    for (int i=0 ; i<4 ; i++){
        (*transit_card).type[i] = (*card1).type[i];
        (*transit_card).m.type[i] = (*card1).m.type[i];     //monster
        (*transit_card).r.type[i] = (*card1).r.type[i];     //relic
    }

    //card1=card2
    (*card1).hidden = (*card2).hidden;
    for (int i=0 ; i<4 ; i++){
        (*card1).type[i] = (*card2).type[i];
        (*card1).m.type[i] = (*card2).m.type[i];            //monster
        (*card1).r.type[i] = (*card2).r.type[i];            //relic
    }

    //card2=transit_card
    (*card2).hidden = (*transit_card).hidden;
    for (int i=0 ; i<4 ; i++){
        (*card2).type[i] = (*transit_card).type[i];
        (*card2).m.type[i] = (*transit_card).m.type[i];     //monster
        (*card2).r.type[i] = (*transit_card).r.type[i];     //relic
    }
    free(transit_card);
}

// DISTRIBUTION DES CARTES
void generate_board (card* tab, int size){
    char cards[] = { 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'b' , 'b' , 'b' , 'b' , 'z' , 'z' , 'z' , 'z' , 't' , 't' , 't' , 't' , 'h' , 'h' , 'h' , 'h' , 'C' , 'C' , 'T' , 'T' , 'E' , 'B' , 'G' , 'D', 'P' };
    int remaining_card = 32;                               // remaining_card = cartes_restantes
    /*
    cards[] est le tableau de toutes nos 32 cartes à placer aléatoirement sur un plateau de 36.
    Voici le détail de ces cartes :
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
    //le tableau tab est déjà initialisé dans une fonction précédente, pas besoin de le faire ici
    for (int i=1 ; i<(size-1) ; i++){                   //Lignes tableau
        for (int j=1 ; j<(size-1) ; j++){               //Colonnes tableau
            if (remaining_card > 0){
                int alea= rand() % remaining_card;
                // événement
                if(cards[alea] == 'e'){
                    (*(tab + i*size + j)).type[3] = 1;
                }
                //Les 4 monstres
                else if(cards[alea] == 'b'){
                    (*(tab + i*size + j)).m.type[3] = 1;
                }
                else if(cards[alea] == 'z'){
                    (*(tab + i*size + j)).m.type[0] = 1;
                }
                else if(cards[alea] == 't'){
                    (*(tab + i*size + j)).m.type[1] = 1;
                }
                else if(cards[alea] == 'h'){
                    (*(tab + i*size + j)).m.type[2] = 1;
                }
                // coffre et totem
                else if(cards[alea] == 'C'){
                    (*(tab + i*size + j)).type[0] = 1;
                }
                else if(cards[alea] == 'T'){
                    (*(tab + i*size + j)).type[1] = 1;
                }
                //Les 4 armes antiques
                else if(cards[alea] == 'E'){
                    (*(tab + i*size + j)).r.type[1] = 1;
                }
                else if(cards[alea] == 'B'){
                    (*(tab + i*size + j)).r.type[0] = 1;
                }
                else if(cards[alea] == 'G'){
                    (*(tab + i*size + j)).r.type[2] = 1;
                }
                else if(cards[alea] == 'D'){
                    (*(tab + i*size + j)).r.type[3] = 1;
                }
                //portail
                else if(cards[alea] == 'P'){
                    (*(tab + i*size + j)).type[2] = 1;
                }
                
                else {
                    printf(" OUPS ! Le jeu n'a pas pu être créé. La carte générée aléatoirement n'est pas dans le paquet.\n");
                    exit(1);
                }
                cards[alea] = cards[remaining_card-1];
                remaining_card = remaining_card -1;
            }
            else{
                printf("Toutes les cartes du jeu sont placées !\n");                //est affiché 4 fois car il y a 4 cases vides pour mettre les joueurs
            }
        }
    }
    invert_card( tab + 1*size + 3 , tab + 6*size + 3);
    invert_card( tab + 3*size + 6 , tab + 6*size + 5);
    invert_card( tab + 4*size + 1 , tab + 6*size + 6);
}

/*_________________________________________________________________________________________________*/
				// AVANT DE JOUER
				
int nb_player (WINDOW* win){
	do{
		wprintw(win, "Combien de joueurs êtes-vous (entre 2 et 4) : ");
		wrefresh(win);
		int choice = getch();
	} while(choice=!2 && choice=!3 && choice=!4);
	return choice;
}

void create_player(Player* p){
	int height = 15;
	int width = 100;
	int start_y = 10;
	int start_x = 10;
	WINDOW* win = newwin(height, width, start_y, start_x);
	wprintw(win, "Entrez votre pseudo : ");
	wrefresh(win);
	wgetnstr(win, (*p).nom, 99)		//récupère au max 99 caractères -> pas de dépassement
	wclear(win);
	do {
            wprintw(win,"Choisissez votre Classe : \n");
            wprintw(win,"    1. Magicien\n");
            wprintw(win,"    2. Guerrier\n");
            wprintw(win,"    3. Ranger\n");
            wprintw(win,"    4. Voleur\n");
            wprintw(win,"Votre choix: ");
	    wrefresh(win);
            int c = getch();
    } while (c != '1' && c != '2' && c != '3' && c != '4');
    (*p).class = c;
    (*p).relic = 0;                //0,1
	(*p).treasure = 0;             //0=non, 1=oui
    (*p).move = 0;                  //prend +1 à chaque fin de tour
    (*p).chrono = 0;                // temps de la partie pour ce joueur
    (*p).slay = 0;                  //nombre de monstre tué
    (*p).reversed = 0;              //nombre case retourné
    (*p).chest = 0;                 //nombre de trésore trouvé.    Attention à pas confondre avec "treasure"
    (*p).Score_victory = 0;         //nombre de victoire accumulé
    (*p).timer = 0;                 //timer du temps du joueur dans une partie
	
    free(win);
}

/*_________________________________________________________________________________________________*/
				// DURANT LE JEU


void return_card(Player* p, card* c){		//le joueur a déjà son arme !
	(*c).hidden = 1;
	refresh();
	
	

}

void choose_weapon(Player* p, WINDOW* win){
        wprintw(win, "Choisissez votre arme : \n");
        wprintw(win, "    1. Bouclier\n");
        wprintw(win, "    2. Torche\n");
        wprintw(win, "    3. Hache\n");
        wprintw(win, "    4. Arc\n");
        wrefresh(win);
    
        do {
            wprintw(win, "Votre choix : ");
            wrefresh(win);
            int choice = getch();
        } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');

        if (choice == '1'){               //bouclier
            p.w.type[0] = 1;
            p.w.type[1] = 0;
            p.w.type[2] = 0;
            p.w.type[3] = 0;
        }
    
        else if (choice == '2'){          //Torche
            p.w.type[0] = 0;
            p.w.type[1] = 1;
            p.w.type[2] = 0;
            p.w.type[3] = 0;
        }
    
        else if (choice == '3'){          //hache
            p.w.type[0] = 0;
            p.w.type[1] = 0;
            p.w.type[2] = 1;
            p.w.type[3] = 0;
        }
    
    
        else{                           //arc
            p.w.type[0] = 0;
            p.w.type[1] = 0;
            p.w.type[2] = 0;
            p.w.type[3] = 1;   
        }
}


//void play();
//void perso_move(Player* p);

//Déplace joueur sur une case du tableau
void perso_move(Player* p, card* tab, int size){
    do{
        int forbidden=0;
        // indique si le joueur a le droit de se déplacer sur la case où il veut aller
        //    forbidden = 0       -> c'est ok
        //    forbidden = 1       -> c'est un mur ou une carte retournée
        
        int key = getch();
        if (key!=KEY_UP && key!=KEY_DOWN && key!=KEY_RIGHT && key!=KEY_LEFT){
            forbidden = 1;
        }
            switch (key){           //Vérifie que la saisie de déplacement est correcte (pas de char) et possible (pas vers un wall)
                case KEY_UP :
                    if ( (*(tab + (p.y+1)*size + p.x)).wall == 1 || (*(tab + (p.y+1)*size + p.x)).hidden == 1 ){        //interdiction de déplacement
                        forbidden = 1;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).y ++;
                    }
                    break;
                case KEY_DOWN :
                    if ( (*(tab + (p.y-1)*size + p.x)).wall == 1 || (*(tab + (p.y-1)*size + p.x)).hidden == 1 ){
                        forbidden = 1;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).y --;
                    }
                    break;
                case KEY_RIGHT :
                    if ( (*(tab + (p.y)*size + p.x+1)).wall == 1 || (*(tab + (p.y)*size + p.x+1)).hidden == 1 ){
                        forbidden = 1;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).x ++;
                    }
                    break;
                case KEY_LEFT :
                    if ( (*(tab + (p.y)*size + p.x-1)).wall == 1 || (*(tab + (p.y)*size + p.x-1)).hidden == 1 ){
                        forbidden = 1;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).x --;
                    }
                    break;
                default :
                    printw("ERREUR au moment de la saisie de déplacement du joueur. Veuillez réessayer avec les flèches haut, bas, droite ou gauche");
                    break;
            }
    } while(forbidden==1);           //tant qu'on ne rencontre pas un mur. ATTENTION au cas où le oueur est coincé entre 4 murs !!! -> le faire mourir.
    refresh();
}
/*
void play(){
    //number of players
    //enter identity
    //création tableau
    //choose arm
    perso_move(p);        //p est le player, on aura besoin de ses coordonnées et son arme

}
*/

//AFFICHAGE du JEU
void show_board(card* tab, int size){
	for (int i=1 ; i<(size-1) ; i++){						//on affiche cartes par cartes
		for (int j=1 ; j<(size-1) ; j++){
			move(i*4, j*10);
			if((*(tab + i*size + j)).hidden == 0){
				addch('\u25A0');					// Affiche le caractère du carré plein
			}
			else{
				if((*(tab + i*size + j)).type[0] == 1){			//trésor
				    addstr("\u{1F4B0}");
				}
				else if((*(tab + i*size + j)).type[1] == 1){		//totem
				    printw("\U0001F5FF");
				}
				else if((*(tab + i*size + j)).type[2] == 1){		//portail
				    printw("\U000026E9");
				}
				else if((*(tab + i*size + j)).type[3] == 1){		//événement
				    printw("E");
				}
				//Les 4 monstres
				else if((*(tab + i*size + j)).m.type[0] == 1){		//basilique
				    printw("\U0001F40D");
				}
				else if((*(tab + i*size + j)).m.type[1] == 1){		//zombie
				    printw("\U0001F9DF");
				}
				else if((*(tab + i*size + j)).m.type[1] == 1){		//troll
				    printw("\U0001F479");
				}
				else if((*(tab + i*size + j)).m.type[1] == 1){		//harpie
				    printw("\U0001F426");
				}
				//Les 4 reliques (armes antiques)
				else if((*(tab + i*size + j)).r.type[0] == 1){		//baton
				    printw("\U0001F3D1");
				}
				else if((*(tab + i*size + j)).r.type[1] == 1){		//épée
				    printw("\U00002694");
				}
				else if((*(tab + i*size + j)).r.type[2] == 1){		//grimoire
				    printw("\U0001F4D6");
				}
				else if((*(tab + i*size + j)).r.type[3] == 1){		//dague
				    printw("\U0001F5E1");
				}
				else{
				    printw("ERREUR");
				}
			}
			
		}
		printw("\n");
	}
	

}

/*____________________________________________________________________________*/
// MAIN

int main(){
    initscr();
    //raw();
    noecho();
    keypad(stdscr, TRUE);            // active la prise en charge des touches spéciales (comme les flèches)
    
    //Mesure Dimensions fenêtre affichage
    int y_max, x_max;                                       // y_max = nbre de lignes de la fenêtre     x_max = nbre de colonnes de la fenêtre
    getmaxyx(stdscr, y_max, x_max);                         // mesure le nbre de lignes (y_max) et de colonnes (x_max) qui peuvent être affichés
    
    //move(5,0);
    //LOGO
    int height_logo, width_logo, starty_logo, startx_logo;
    startx_logo = x_max/2 - 65;
    starty_logo = 5;
    height_logo = 11;
    width_logo = 129;
    WINDOW* win_logo = newwin(height_logo, width_logo, starty_logo, startx_logo);	//cadre du logo
    
    		 //128 caractères sur la 1ere ligne et 11 lignes
    wprintw(win_logo," .d8888b. Y88b   d88P      888b     d888                                                       8888888b.  8888888b.   .d8888b.  \n");
    wprintw(win_logo,"d88P  Y88b Y88b d88P       8888b   d8888                                                       888   Y88b 888   Y88b d88P  Y88b \n");
    wprintw(win_logo,"888    888  Y88o88P        88888b.d88888                                                       888    888 888    888 888    888 \n");
    wprintw(win_logo,"888          Y888P         888Y88888P888  .d88b.  88888b.d88b.   .d88b.  888d888 888  888      888   d88P 888   d88P 888        \n");
    wprintw(win_logo,"888           888          888 Y888P 888 d8P  Y8b 888 *888 *88b d88**88b 888P*   888  888      8888888P*  8888888P*  888  88888 \n");
    wprintw(win_logo,"888    888    888   888888 888  Y8P  888 88888888 888  888  888 888  888 888     888  888      888 T88b   888        888    888 \n");
    wprintw(win_logo,"Y88b  d88P    888          888   *   888 Y8b.     888  888  888 Y88..88P 888     Y88b 888      888  T88b  888        Y88b  d88P \n");
    wprintw(win_logo," *Y8888P*     888          888       888  *Y8888  888  888  888  *Y88P*  888      *Y88888      888   T88b 888         *Y8888P88 \n");
    wprintw(win_logo,"                                                                                      888                                       \n");
    wprintw(win_logo,"                                                                                 Y8b d88P                                       \n");
    wprintw(win_logo,"                                                                                  *Y88P*\n");
    refresh();
    wrefresh(win_logo);
    
    
    move(y_max-1, 0);
    printw("Appuyer sur la touche q pour sortir du jeu.\n");
    refresh();
    move(16,0);						//on replace le curseur après le logo de jeu
    
    int height_menu, width_menu, starty_menu, startx_menu;
    startx_menu = x_max/2 - 10;
    starty_menu = 25;
    height_menu = 10;
    width_menu = 30;
    
    //MENU
    WINDOW* win_menu = newwin (height_menu, width_menu, starty_menu, startx_menu);
    int menu = 1;                           //menu=1 -> on est ds menu     menu=0 -> on n'est plus ds menu (ds le jeu par ex)
    int menu_select = 1;                    //les menus à sélectionner vont de 1 à 4
    wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
    wprintw(win_menu,"Tableau des scores\n");
    wprintw(win_menu,"Règles\n");
    wprintw(win_menu,"Sortir\n");
    //refresh();
    wrefresh(win_menu);
    
    int EXIT = 0;                           // EXIT = false -> on reste dans le menu        EXIT = true -> on va ailleurs que dans le menu
    do{
        int key_pressed = getch();
        if (key_pressed == (int)'q' || key_pressed == (int)'Q'){	//en entrant q : on sort du jeu
        	endwin();
        	return 0;
        }
        if (key_pressed == KEY_UP || key_pressed == '8'){         //ATTENTION : int key_pressed ?????
            menu_select --;
            printw("Key_up appuyé\n");
            refresh();
        }
        if (key_pressed == KEY_DOWN || key_pressed == '2'){
            menu_select ++;
            printw("Key_down appuyé\n");
            refresh();
        }
        if (menu_select <=0){
            menu_select = 4;
        }
        if (menu_select >4){
            menu_select = 1;
        }
        wclear(win_menu);
        // Changement taille texte qd on est dessus
        switch(menu_select){
            case 1 :
                wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
                wprintw(win_menu,"Tableau des scores\n");
                wprintw(win_menu,"Règles\n");
                wprintw(win_menu,"Sortir\n");
                break;
            case 2 :
                wprintw(win_menu, "Nouvelle partie\n");
                wprintw(win_menu,"-> TABLEAU DES SCORES <-\n");
                wprintw(win_menu,"Règles\n");
                wprintw(win_menu,"Sortir\n");
                break;
            case 3 :
                wprintw(win_menu, "Nouvelle partie\n");
                wprintw(win_menu,"Tableau des scores\n");
                wprintw(win_menu,"-> REGLES <-\n");
                wprintw(win_menu,"Sortir\n");
                break;
            case 4 :
                wprintw(win_menu, "Nouvelle partie\n");
                wprintw(win_menu,"Tableau des scores\n");
                wprintw(win_menu,"Règles\n");
                wprintw(win_menu,"-> SORTIR <-\n");
                break;
            default :
                printf("ERREUR d'affichage menu.");
                exit(103);
                break;
        }
        refresh();
        wrefresh(win_menu);
        if (key_pressed == '\n'){			//Le joueur a sélectionné un des 4 menus
            EXIT = 1;
        }
    }while(!EXIT);
    
    clear();
    
    if(menu_select==1){
		
	    int nmb_player = nb_player(win2);
		Player* p1, p2, p3, p4;
	    	
	    	//INITIALISATION DES 4 JOUEURS
		create__player (p1);				//Crée l'identité d'1 joueur
		(*p1).life = 1;                 // 0=mort 1=vivant
		(*p1).x = 3;                    // place x dans le tableau entre 1 et 6
		(*p1).y = 1;                    // place y dans le tableau entre 1 et 6
		(*p1).x_init = 3;                //place initiale
		(*p1).y_init = 1;                //place initiale
	    	
	    	create__player (p2);				//Crée l'identité d'1 joueur
		(*p2).life = 0;                 // 0=mort 1=vivant
		(*p2).x = 1;                    // place x dans le tableau entre 1 et 6
		(*p2).y = 4;                    // place y dans le tableau entre 1 et 6
		(*p2).x_init = 1;                //place initiale
		(*p2).y_init = 4;                //place initiale
		
		if (nmb_player >= 3){
			create__player (p3);				//Crée l'identité d'1 joueur
			(*p3).life = 0;                 // 0=mort 1=vivant
			(*p3).x = 4;                    // place x dans le tableau entre 1 et 6
			(*p3).y = 6;                    // place y dans le tableau entre 1 et 6
			(*p3).x_init = 4;                //place initiale
			(*p3).y_init = 6;                //place initiale
		}
		if (nmb_player == 4){
			create__player (p4);				//Crée l'identité d'1 joueur
			(*p4).life = 0;                 // 0=mort 1=vivant
			(*p4).x = 4;                    // place x dans le tableau entre 1 et 6
			(*p4).y = 6;                    // place y dans le tableau entre 1 et 6
			(*p4).x_init = 4;                //place initiale
			(*p4).y_init = 6;                //place initiale
		}
	    	
		for (int i=0 ; i<nmb_player ; i++){
			
		}
        card* game;
        WINDOW* win2 = newwin(10,100, 20,0);
        
        game = malloc(SIZE*SIZE*sizeof(card));            //game est notre plateau de jeu (tableau)
	if (game == NULL){
		printf("Problème d'allocation de mémoire pour la création du tableau du jeu.\n");
		exit(10);
	}
	do{
            
        } while
	    
	board(game, SIZE);
	show_board(game, SIZE);
	do{
		choose_weapon(Player* p, WINDOW* win);
		getch();
	}while(p.life==1);				//tant que joueur en vie et n'a pas gagné
            
    else if (menu_select==2){

    	}
            
        else if (menu_select==3){
		//affiche le readme
    	}
            
        else{						//SORTIR du jeu
            endwin();
            return 0;
	}
    
    free(game);
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
