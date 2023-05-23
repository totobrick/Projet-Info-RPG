#include <stdio.h>
#include <ncurses.h>

#include "Header.h"

void play();
void move(Player* p);

void play(){
    //number of players
    //enter identity
    //choose arm
    move(p);        //p est le player, on aura besoin de ses coordonnées et son arme

}


int main(){
    initscr();
    //raw();
    noecho();
    keypad(stdscreen, TRUE);            // active la prise en charge des touches spéciales (comme les flèches)
    
    move(2,5);
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
    int height, width, start_y, start_x;
    start_x = x_max/2;
    start_y = 15;
    height = 5;
    width = 30;
    
    //MENU
    WINDOW* win = newwin (height, width, start_y, start_x);
    refresh();
    int menu = 1;                           //menu=1 -> on est dans le menu     menu=0 -> on n'est plus dans le menu (ds le jeu par ex)
    int menu_select = 1;                    //les menus à sélectionner vont de 1 à 4
    wprintw(win, "-> NOUVELLE PARTIE <-\n");
    wprintw(win,"Charger une partie\n");    //ATTENTION : ou afficher le scoreboard ????
    wprintw(win,"Règles\n");
    wprintw(win,"Sortir\n");
    //refresh();
    wrefresh(win);
    int EXIT = 0;                           // EXIT = false -> on reste dans le menu        EXIT = true -> on va ailleurs que dans le menu
    while(!EXIT){
        //getch();
        if (key_pressed == KEY_UP){         //ATTENTION : int key_pressed ?????
            menu_select --;
        }
        if (key_pressed == KEY_DOWN){
            menu_select ++;
        }
        if (menu_select <=0){
            menu_select = 4;
        }
        if (menu_select >=4){
            menu_select = 1;
        }
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
        //refresh();
        wrefresh(win);
        if (key_pressed == vk_enter){
            Exit = 1;
        }
    }
    
    
    
    

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
    }
    
    
    
        
    
    
    endwin();
    return 0;
}
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
