// VOIR LE CAS OU JOUR ENTOURE DE 4 MURS/CARTES RETOURNEES -> retour case départ et on retourne les cartes 
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


//#include "Header.h"

//void play();
//void perso_move(Player* p);
/*
//Déplace joueur sur une case du tableau
void perso_move(Player* p, card* tab, int size){
    do{
        int authorize=1;
        // indique si le joueur a le droit de se déplacer sur la case où il veut aller
        //    authorize = 0       -> c'est un mur ou une carte retournée
        //    authorize = 1       -> c'est ok
        
        int key = getch();
        if (key!=KEY_UP && key!=KEY_DOWN && key!=KEY_RIGHT && key!=KEY_LEFT){
            authorize = 0;
        }
            switch (key){           //Vérifie que la saisie de déplacement est correcte (pas de char) et possible (pas vers un wall)
                case KEY_UP :
                    if ( (*(tab + (p.y+1)*size + p.x)).wall == 1 || (*(tab + (p.y+1)*size + p.x)).hidden == 1 ){        //interdiction de déplacement
                        authorize = 0;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).y = (*p).y + 1;
                    }
                    break;
                case KEY_DOWN :
                    if ( (*(tab + (p.y-1)*size + p.x)).wall == 1 || (*(tab + (p.y-1)*size + p.x)).hidden == 1 ){
                        authorize = 0;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).y = (*p).y - 1;
                    }
                    break;
                case KEY_RIGHT :
                    if ( (*(tab + (p.y)*size + p.x+1)).wall == 1 || (*(tab + (p.y)*size + p.x+1)).hidden == 1 ){
                        authorize = 0;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).x = (*p).x + 1;
                    }
                    break;
                case KEY_LEFT :
                    if ( (*(tab + (p.y)*size + p.x-1)).wall == 1 || (*(tab + (p.y)*size + p.x-1)).hidden == 1 ){
                        authorize = 0;
                    }
                    else{                                                                                               //le joueur va sur la case
                        (*p).x = (*p).x - 1;
                    }
                    break;
                default :
                    printw("ERREUR au moment de la saisie de déplacement du joueur. Veuillez réessayer avec les flèches haut, bas, droite ou gauche");
                    break;
            }
    } while(authorize==0);           //tant qu'on ne rencontre pas un mur. ATTENTION au cas où le oueur est coincé entre 4 murs !!! -> le faire mourir.
    refresh();
}

void play(){
    //number of players
    //enter identity
    //création tableau
    //choose arm
    perso_move(p);        //p est le player, on aura besoin de ses coordonnées et son arme

}
*/

int main(){
    initscr();
    //raw();
    noecho();
    keypad(stdscr, TRUE);            // active la prise en charge des touches spéciales (comme les flèches)
    
    move(5,0);
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
    refresh();
    
    int y_max, x_max;                                       // y_max = nbre de lignes de la fenêtre     x_max = nbre de colonnes de la fenêtre
    getmaxyx(stdscr, y_max, x_max);                         // mesure le nbre de lignes (y_max) et de colonnes (x_max) qui peuvent être affichés
    move(y_max-1, 0);
    printw("Appuyer sur q (minuscule) pour sortir du jeu.\n");
    refresh();
    move(15,0);						//on replace le curseur après le logo de jeu
    
    int height, width, start_y, start_x;
    start_x = x_max/2 - 10;
    start_y = 25;
    height = 10;
    width = 30;
    
    //MENU
    WINDOW* win = newwin (height, width, start_y, start_x);
    int menu = 1;                           //menu=1 -> on est ds menu     menu=0 -> on n'est plus ds menu (ds le jeu par ex)
    int menu_select = 1;                    //les menus à sélectionner vont de 1 à 4
    wprintw(win, "-> NOUVELLE PARTIE <-\n");
    wprintw(win,"Charger une partie\n");    //ATTENTION : ou Afficher le scoreboard ????
    wprintw(win,"Règles\n");
    wprintw(win,"Sortir\n");
    //refresh();
    wrefresh(win);
    
    int EXIT = 0;                           // EXIT = false -> on reste dans le menu        EXIT = true -> on va ailleurs que dans le menu
    do{
        int key_pressed = getch();
        if (key_pressed == (int)'q'){	//en entrant q : on sort du jeu
        	endwin();
        	return 0;
        }
        if (key_pressed == KEY_UP){         //ATTENTION : int key_pressed ?????
            menu_select --;
            printw("Key_up appuyé\n");
            refresh();
        }
        if (key_pressed == KEY_DOWN){
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
        wclear(win);
        // Changement taille texte qd on est dessus
        switch(menu_select){
            case 1 :
                wprintw(win, "-> NOUVELLE PARTIE <-\n");
                wprintw(win,"Charger une partie\n");
                wprintw(win,"Règles\n");
                wprintw(win,"Sortir\n");
                break;
            case 2 :
                wprintw(win, "Nouvelle partie\n");
                wprintw(win,"-> CHARGER UNE PARTIE <-\n");
                wprintw(win,"Règles\n");
                wprintw(win,"Sortir\n");
                break;
            case 3 :
                wprintw(win, "Nouvelle partie\n");
                wprintw(win,"Charger une partie\n");
                wprintw(win,"-> REGLES <-\n");
                wprintw(win,"Sortir\n");
                break;
            case 4 :
                wprintw(win, "Nouvelle partie\n");
                wprintw(win,"Charger une partie\n");
                wprintw(win,"Règles\n");
                wprintw(win,"-> SORTIR <-\n");
                break;
            default :
                printf("ERREUR d'affichage menu.");
                exit(103);
                break;
        }
        refresh();
        wrefresh(win);
        if (key_pressed == '\n'){
            EXIT = 1;
        }
    }while(!EXIT);
    endwin();
    return 0;
}   
    
    
    
/*
switch(menu_select){
        case 1:
            //a faire
            break;
        case 2:
            //a faire
            break;
        case 3:
            //affiche le readme
            break;
        case 4:
            endwin();
            EXIT = true;
            break;
}*/
    
    
    
        
    
    

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
    printw(" 
 .d8888b. Y88b   d88P      888b     d888                                                       8888888b.  8888888b.   .d8888b.  
d88P  Y88b Y88b d88P       8888b   d8888                                                       888   Y88b 888   Y88b d88P  Y88b 
888    888  Y88o88P        88888b.d88888                                                       888    888 888    888 888    888 
888          Y888P         888Y88888P888  .d88b.  88888b.d88b.   .d88b.  888d888 888  888      888   d88P 888   d88P 888        
888           888          888 Y888P 888 d8P  Y8b 888 "888 "88b d88""88b 888P"   888  888      8888888P"  8888888P"  888  88888 
888    888    888   888888 888  Y8P  888 88888888 888  888  888 888  888 888     888  888      888 T88b   888        888    888 
Y88b  d88P    888          888   "   888 Y8b.     888  888  888 Y88..88P 888     Y88b 888      888  T88b  888        Y88b  d88P 
 "Y8888P"     888          888       888  "Y8888  888  888  888  "Y88P"  888      "Y88888      888   T88b 888         "Y8888P88 
                                                                                      888                                       
                                                                                 Y8b d88P                                       
                                                                                  "Y88P"");
    */
