#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(){
	initscr();
	
	keypad(stdscr, TRUE);
	
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
    
    		 //128 caractèrp1, p2, p3, p4es sur la 1ere ligne et 11 lignes
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
    
    int EXIT = 0;                           // EXIT = 0 -> on reste dans le menu        EXIT = 1 -> on va ailleurs que dans le menu
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
	
	endwin();
	return 0;
}
