  
 if (!has_colors()) {
        endwin();
        printf("Le terminal ne prend pas en charge les couleurs.\n");
        return 1;
    }

    // Initialisation des paires de couleurs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    // Affichage du texte en couleur
    attron(COLOR_PAIR(1));
    printw("HA\n");
    printw("ZO\n");
    printw("TR\n");
    printw("BA\n");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    printw("TO\n");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    printw("PO\n");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));
    printw("$$\n");
    attroff(COLOR_PAIR(4));

    attron(COLOR_PAIR(5));
    printw("VO\n");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(5));
    printw("RA\n");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(5));
    printw("MA\n");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(5));
    printw("CH\n");
    attroff(COLOR_PAIR(5));

    attron(COLOR_PAIR(6));
    printw("GR\n"); 
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(6));
    printw("EP\n");
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(6));
    printw("DA\n");
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(6));
    printw("BA\n");
    attroff(COLOR_PAIR(6));

    attron(COLOR_PAIR(7));
    printw("CARD\n");
    attroff(COLOR_PAIR(7));
