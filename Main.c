int main() {
    FILE *fichier;
    char ligne[256];
    initscr();
    // raw();
    //noecho();

    start_color();            //active la couleur
    if (!has_colors()) {
        endwin();
        printf("Le terminal ne prend pas en charge les couleurs.\n");
    }
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
  starty_menu = 22;
  height_menu = 15;
  width_menu = 55;

  // MENU
  WINDOW *win_menu = newwin(height_menu, width_menu, starty_menu, startx_menu);
  int menu = 1; // menu=1 -> on est ds menu     menu=0 -> on n'est plus ds menu
                // (ds le jeu par ex)
  int menu_select = 1; // les menus à sélectionner vont de 1 à 4
  wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
  wprintw(win_menu, "Tableau des scores\n");
  wprintw(win_menu, "Sortir\n");
  refresh();
  wrefresh(win_menu);

  int EXIT = 0; // EXIT = 0 -> on reste dans le menu        EXIT = 1 -> on va
                // ailleurs que dans le menu
  int key_pressed = 0;
  do {
    key_pressed = getch();
    if (key_pressed == (int)'q' || key_pressed == (int)'Q') { // en entrant q : on sort du jeu
      endwin();
      return 0;
    }
    if (key_pressed == KEY_UP || key_pressed == '8') {
        menu_select--;
        //printw("Key_up appuye\n");
        refresh();
    }
    if (key_pressed == KEY_DOWN || key_pressed == '2') {
      menu_select++;
      //printw("Key_down appuye\n");
      refresh();
    }
    if (menu_select <= 0) {
      menu_select = 3;
    }
    if (menu_select > 3) {
      menu_select = 1;
    }
    wclear(win_menu);
    // Changement taille texte qd on est dessus
    switch (menu_select) {
        case 1:
          wprintw(win_menu, "-> NOUVELLE PARTIE <-\n");
          wprintw(win_menu, "Tableau des scores\n");
          wprintw(win_menu, "Sortir\n");
          break;
        case 2:
          wprintw(win_menu, "Nouvelle partie\n");
          wprintw(win_menu, "-> TABLEAU DES SCORES <-\n");
          wprintw(win_menu, "Sortir\n");
          break;
        case 3:
          wprintw(win_menu, "Nouvelle partie\n");
          wprintw(win_menu, "Tableau des scores\n");
          wprintw(win_menu, "-> SORTIR <-\n");
          break;
        default:
          printf("ERREUR d'affichage menu.");
          exit(103);
          break;
    }
    //refresh();
    wrefresh(win_menu);
    if (key_pressed == '\n') { // Le joueur a sélectionné un des 4 menus
      EXIT = 1;
    }
  } while (!EXIT);

  clear();

  int e1 = 1, e2 = 1, e3 = 1, e4 = 1, e5 = 1, e6 = 1, e7 = 1, e8 = 1, e9 = 1, e10 = 1, e11 = 1;
    
  if (menu_select == 1) {
    wmove(win_menu, 0, 0);
    int nmb_player = nb_player(win_menu);

    Player p1;
    Player p2;
    Player p3;
    Player p4;
    Player *pp1 = &p1;
    Player *pp2 = &p2;
    Player *pp3 = &p3;
    Player *pp4 = &p4;
    int c1=1, c2=1, c3=1, c4=1;

    // INITIALISATION DES 4 JOUEURS
    WINDOW* win_name = newwin(1, 120, 0, 0);    // fenêtre affichage nom joueur
    wclear(win_name);
    wprintw(win_name, "Joueur 1");
    wrefresh(win_name);
    move(1,0);
    create_player(pp1, win_menu, c1, c2, c3, c4); // Créée l'identité du joueur 1
    sleep(2);
    p1.num = 1;
    p1.life = 1;   // 0=mort 1=vivant
    p1.x = 3;      // place x dans le tableau entre 1 et 6
    p1.y = 1;      // place y dans le tableau entre 1 et 6
    p1.x_init = 3; // place initiale
    p1.y_init = 1; // place initiale
    clear();
    refresh();
    
    wclear(win_name);
    wprintw(win_name, "Joueur 2");
    wrefresh(win_name);
    move(1,0);
    create_player(pp2, win_menu, c1, c2, c3, c4); // Créée l'identité du joueur 2
    sleep(2);
    p2.num = 2;
    p2.life = 0;   // 0=mort 1=vivant
    p2.x = 1;      // place x dans le tableau entre 1 et 6
    p2.y = 4;      // place y dans le tableau entre 1 et 6
    p2.x_init = 1; // place initiale
    p2.y_init = 4; // place initiale
    clear();
    refresh();

    if (nmb_player >= 3) {
      wclear(win_name);
      wprintw(win_name, "Joueur 3");
      wrefresh(win_name);
      move(1,0);
      create_player(pp3, win_menu, c1, c2, c3, c4); // Créée l'identité du joueur 3
      sleep(2);
      p3.num = 3;
      p3.life = 0;   // 0=mort 1=vivant
      p3.x = 4;      // place x dans le tableau entre 1 et 6
      p3.y = 6;      // place y dans le tableau entre 1 et 6
      p3.x_init = 4; // place initiale
      p3.y_init = 6; // place initiale
      clear();
      refresh();
    }
    if (nmb_player == 4) {
      wclear(win_name);
      wprintw(win_name, "Joueur 4");
      wrefresh(win_name);
      move(1,0);
      create_player(pp4, win_menu, c1, c2, c3, c4); // Créée l'identité du joueur 4
      sleep(2);
      p4.num = 4;
      p4.life = 0;   // 0=mort 1=vivant
      p4.x = 6;      // place x dans le tableau entre 1 et 6
      p4.y = 3;      // place y dans le tableau entre 1 et 6
      p4.x_init = 6; // place initiale
      p4.y_init = 3; // place initiale
      clear();
      refresh();
    }

    srand(time(NULL));
    WINDOW *win_game = newwin(30, 100, 5, 10);    // fenêtre du plateau de jeu
    WINDOW *win_interface = newwin(20, 100, 30, 40);
    card *game;
    game = malloc(SIZE * SIZE *sizeof(card)); // game est notre plateau de jeu (tableau)
    if (game == NULL) {
        printf("Problème d'allocation de memoire pour la creation du tableau du jeu.\n");
        exit(10);
    }
    board(game, SIZE, win_game);
    
    Player* tab_player[] = {pp1, pp2, pp3, pp4};             //tableau où il y a les 4 joueurs
    int r=-1;
    do{
        hide_board(game, SIZE, win_game);
        r++;
        r = r%nmb_player;
        (*(tab_player[r])).life = 1;
        do{
            wclear(win_name);
            wprintw(win_name, "A vous de jouer %s.", (*(tab_player[r])).nom);
            wrefresh(win_name);
            play(tab_player[r], game, SIZE, win_interface, win_game, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);			// INTERACTION JOUEUR
            (*(tab_player[r])).move ++;
        } while( (*(tab_player[r])).life==1 && ((*(tab_player[r])).relic!=1 || (*(tab_player[r])).treasure!=1));
        e1=1, e2=1, e3=1, e4=1, e5=1, e6=1, e7=1, e8=1, e9=1, e10=1, e11=1;
        resetPlayerPosition(tab_player[r]);
    } while ( (*(tab_player[r])).relic!=1 || (*(tab_player[r])).treasure!=1 );        //condition de VICTOIRE

      show_board(game, SIZE, win_game);
      clear();
      move(0,0);
      printw("BRAVO !\n %s a brillamment gagne en %d tours.\n Dommage pour les autres !", (*(tab_player[r])).nom, (*(tab_player[r])).move);
      refresh();
      sleep(5);
      for(int i=0; i<nmb_player ; i++){
          Score_creator(tab_player[i]); 
      }

        
    // do{
    // choose_weapon(Player* p, WINDOW* win);
    // getch();
    //}while(p.life==1);				//tant que joueur en vie et n'a pas
    //gagné

    free(game);
  } else if (menu_select == 2) {
        // Ouvrir le fichier en mode lecture
        fichier = fopen("Score.txt", "r");
        if (fichier == NULL) {
            fprintf(stderr, "Impossible d'ouvrir le fichier\n");
            return 1;
        }
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            printw("%s", ligne);
        }
        getch();
        fclose(fichier);
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
