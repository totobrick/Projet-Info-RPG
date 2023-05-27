//Déplace joueur sur une case du tableau
void perso_move(Player* p, card* tab, int size, int x_newcard, int y_newcard){		//key = KEY_UP ou KEY_DOWN ou KEY_RIGHT ou KEY_LEFT
    (*p).x = x_newcard;
    (*p).y = y_newcard;
}


// RETOUR CASE DEPART
void resetPlayerPosition(Player *p) {
  (*p).x = (*p).x_init;
  (*p).y = (*p).y_init;
  move(1,0);
  printw("Position du joueur %s reinitialisee.\n", (*p).nom);
}
void updateScore(FILE* fichier, Player* P, char job[]) {
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    char player_name[100];
    char player_class[10];
    strcpy(player_class, job);
    int player_move;
    int player_reversed;
    int player_slay;
    int player_chest;
    int player_score_victory;
    char ligne[100];
  
    rewind(fichier);
  
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, &player_move, &player_reversed, &player_slay, &player_chest, &player_score_victory);

        if (strcmp(player_name, (*P).nom) == 0) {
            player_move += (*P).move;
            player_reversed += (*P).reversed;
            player_slay += (*P).slay;
            player_chest += (*P).chest;
            player_score_victory += (*P).Score_victory;

            fprintf(fichierTemp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
        } else {
            // Mettre à jour les valeurs des variables dans la branche else
            player_move = player_move;
            player_reversed = player_reversed;
            player_slay = player_slay;
            player_chest = player_chest;
            player_score_victory = player_score_victory;
            
            fprintf(fichierTemp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", player_name, player_class, player_move, player_reversed, player_slay, player_chest, player_score_victory);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("Score.txt");
    rename("temp.txt", "Score.txt");
}

void Score_creator(Player* P) {
    FILE* fichier = fopen("Score.txt", "a+");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    char job[10];
    if ((*P).classe == 1) {
        strcpy(job, "Magicien");
    } else if ((*P).classe == 2) {
        strcpy(job, "Guerrier");
    } else if ((*P).classe == 3) {
        strcpy(job, "Ranger");
    } else {
        strcpy(job, "Voleur");
    }

    fseek(fichier, 0, SEEK_END);
    long file_weight = ftell(fichier);

    if (file_weight == 0) {
        fprintf(fichier, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", (*P).nom, job, (*P).move, (*P).reversed, (*P).slay,(*P).chest, (*P).Score_victory);
    } else {
        updateScore(fichier, P, job);
    }

    fclose(fichier);
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
    refresh();
  } while (choice != '2' && choice != '3' && choice != '4');
    wprintw(win, "%d", choice -'0');
    wrefresh(win);
    sleep(2);
    if (choice=='2'){
        return 2;
    }
    else if (choice=='3'){
        return 3;
    }
    return 4;
}


void create_player(Player *p, WINDOW *win, int c1, int c2, int c3, int c4) {
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
    wprintw(win, "Votre choix : ");
    wrefresh(win);
    c = getch();
  } while (c != '1' && c != '2' && c != '3' && c != '4');
    wprintw(win, "%d", c-'0');
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


void play(Player* p, card* tab, int size, WINDOW* win, WINDOW* win_game, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int e9, int e10, int e11){
    
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
                wclear(win);
                wmove(win, 0, 0);
                wprintw(win, "Ou voulez-vous vous deplacer (utilisez les fleches de votre clavier) : ");
                wrefresh(win);
                forbidden = 0;
                key = getch();
                if(key!=KEY_UP && key!=KEY_DOWN && key!=KEY_RIGHT && key!=KEY_LEFT){
                    forbidden = 1;
                    wprintw(win, "\nMouvement entre invalide, veuillez reessayer.");
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
    show_board(tab, size, win_game);
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
    wclear(win);
    wmove(win, 0, 0);
}

void combat(Player* p, card* c, WINDOW* win) {
    wclear(win);
    wmove(win,0,0);
    wrefresh(win);
    if ((*c).m.type[0] == 1){
            if((*p).w.type[0] == 1){
                wprintw (win, "Le Basilic est vaincu !\n");
                (*p).slay++;				//nbre de monstres tués
            }
            else{
                wprintw (win, "Game Over ! Le Basilic vous a tue.\n");
                (*p).life = 0;
             resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[1] == 1){
            if((*p).w.type[1] == 1){
                wprintw (win, "Le Zombie est vaincu !\n");
                (*p).slay++;
            }
            else{
                wprintw (win, "Game Over ! Le Zombie vous a tue.\n");
                (*p).life = 0;
             resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[2] == 1){
            if((*p).w.type[2] == 1){
                wprintw (win, "Le Troll est vaincu !\n");
                (*p).slay++;
            }
            else{
                wprintw (win, "Game Over ! Le Troll vous a tue.\n");
                (*p).life = 0;
                resetPlayerPosition(p);
            }
    }
    else if ((*c).m.type[3] == 1){
            if((*p).w.type[3] == 1){
                wprintw (win,"La Harpie est vaincu !\n");
                (*p).slay++;
            }
            else{
                wprintw (win, "Game Over ! La Harpie vous a tue.\n");
                (*p).life = 0;
                resetPlayerPosition(p);
            }
    }
    wrefresh(win);
    sleep(3);
    wclear(win);
    wmove(win,0,0);
}
