  
Couleur:
#include <ncurses.h>

int main() {
    // Initialisation de NCurses
    initscr();
    start_color();

    // Vérification de la prise en charge des couleurs
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
    init_pair(8, COLOR_BLACK, COLOR_RED);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_BLACK, COLOR_BLUE);
    init_pair(11, COLOR_BLACK, COLOR_YELLOW);
    init_pair(12, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(13, COLOR_BLACK, COLOR_CYAN);

    // Affichage du texte en couleur
    attron(COLOR_PAIR(1));
    printw("Texte en rouge\n");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    printw("Texte en vert\n");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    printw("Texte en bleu\n");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));
    printw("Texte en jaune\n");
    attroff(COLOR_PAIR(4));

    attron(COLOR_PAIR(5));
    printw("Texte en magenta\n");
    attroff(COLOR_PAIR(5));

    attron(COLOR_PAIR(6));
    printw("Texte en cyan\n");
    attroff(COLOR_PAIR(6));

    attron(COLOR_PAIR(7));
    printw("Texte en blanc\n");
    attroff(COLOR_PAIR(7));

    attron(COLOR_PAIR(8));
    printw("Texte noir sur fond rouge\n");
    attroff(COLOR_PAIR(8));

    attron(COLOR_PAIR(9));
    printw("Texte noir sur fond vert\n");
    attroff(COLOR_PAIR(9));

    attron(COLOR_PAIR(10));
    printw("Texte noir sur fond bleu\n");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(11));
    printw("Texte noir sur fond jaune\n");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(12));
    printw("Texte noir sur fond magenta\n");
    attroff(COLOR_PAIR(12));

    attron(COLOR_PAIR(13));
    printw("Texte noir sur fond cyan\n");
    attroff(COLOR_PAIR(13));

    // Rafraîchissement de l'écran
    refresh();

    // Attendre une touche pour quitter
    getch();

    // Restaurer les paramètres par défaut de NCurses et quitter
    endwin();

    return 0;
}


//Joueur
printf("\U0001F9D9");//Mage (la magie du plomb)emoticon
printf("\U0001F93A");//Chevalier (escrime) emoticon
printf("\U0000265E");//Chevalier (chess (Echec et mat)) emoticons
printf("\U0001F47A");//Voleur (mask de démon japonais (fait attention à la lune!)) emoticon
printf("\U0001F3C3");//Ranger (personne qui court (who are you running from?)) emoticon

//Monstre
printf("\U0001F9DF");//Zombie (OH MAN!)emoticon
printf("\U0001F40D");//Basilique (serpent (SNEK)) emoticon
printf("\U0001F426");//Harpie (oiseau (attention traveau pour cause d'un mur de glace)) emoticon
printf("\U0001F479");//Troll (démon japonais) emoticon

//Reliques
printf("\U0001F5E1");//Dague emoticon
printf("\U0001F4D6");//Livre (ouvert) emoticon
printf("\U00002694");//Epee (croisée (une ne suffisait pas ?)) emoticon
printf("\U0001F3D1");//Baton (cross de hockey) emoticon

//Maps
printf("\U0000274C");//Mur (croix rouge (ZEVENT?)) emoticon
printf("\U0001F540");//Spawn emoticon
printf("\U000026E9");//Portail (Torii (UWU)) emoticon
printf("\U0001F5FF");//Totem (GIGA Chad Totem) emoticon
printf("\U0001F4B0");//Trésor (sac d'argent (Dubai)) emoticon
printf("\U000025A0");//Case caché 


//Armes
printf("\U0001FA93");//Hache (pompier) emoticon
printf("\U0001F3F9");//Arc (flèche dans le genou) emoticon
printf("\U000026E8");//Bouclier (oui le monde est contre toi)emoticon
printf("\U0001F56F");//Torche (bougie) emoticon

//Statut
printf("\U0001F480");//Mort (game over) emoticon
printf("\U0001F3C6");//Trophée (victoire) emoticon


// site : https://unicode-explorer.com/emoji/
