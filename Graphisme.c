  
Couleur:

#include "Header.h"

int main() {
    // Séquence d'échappement ANSI pour définir la couleur du texte en rouge
    printf("\033[31mTexte en rouge\033[0m\n");

    // Séquence d'échappement ANSI pour définir la couleur du fond en bleu et la couleur du texte en blanc
    printf("\033[44;37mTexte sur fond bleu\033[0m\n");

    return 0;
}

/*Dans cet exemple, nous utilisons la séquence d'échappement \033[ pour indiquer le début d'une séquence d'échappement ANSI. Ensuite, nous utilisons des codes spécifiques pour définir les attributs de texte,
tels que la couleur du texte et du fond. Le code 31 indique la couleur rouge, le code 44 indique le fond bleu et le code 37 indique le texte blanc. La séquence d'échappement \033[0m est utilisée pour réinitialiser
les attributs de texte par défaut.*/



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



#include <ncurses.h>
#include <wchar.h>

int main() {
    initscr();      // Initialise la bibliothèque ncurses
    cbreak();       // Désactive la mise en mémoire tampon de ligne
    noecho();       // Désactive l'affichage automatique des caractères saisis
    curs_set(0);    // Masque le curseur

    wchar_t emoji = L'\U0001F9D9';   // Code Unicode de l'emoji

    addwch(emoji);  // Affiche l'emoji en utilisant addwch()

    refresh();      // Rafraîchit l'écran
    getch();        // Attend une saisie de l'utilisateur
    endwin();       // Ferme la fenêtre ncurses et restaure le terminal

    return 0;
}
