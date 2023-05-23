/*SOURCES :
https://www.youtube.com/watch?v=lV-OPQhPvSM
https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas 
https://www.sbarjatiya.com/notes_wiki/index.php/Using_ncurses_library_with_C

POUR COMPILER :		gcc -o exe_ncurses Nucurses.c -lncurses
	-> l'extension -lncurses à la fin est essentielle
Pour compiler TOUS les fichiers du dossier :
	-> gcc -o *.c (pas top mais ca marche)
*/
#include <ncurses.h>

int main(){
	initscr();		//initscr() : configure la mémoire et efface l'écran
	
	raw();
	noecho();
		/* cbreak() : pas imp, caractères entrés par utilisateur sont direct utilisables par le prgrm (sans attendre nouvelle ligne de code)
		   raw() : caractères directs utilisables par prgrm, Ctrl+C ne sort pas du programme
		   noecho() : caractères saisis ne sont pas affichés à l'écran
		   
		*/
	
	
	int x=5, y=2;
	move(y , x);		//déplace le curseur au point de coordonnées (x,y).	x = nbre colonnes	y = nbre lignes
				//Si on ne l'affiche pas, le curseur est au point de coordonnées (0,0) cad en haut à droite
	
	printw("Bonjour!\n");	//printw("") : affiche un string(const char *) dans une fenêtre
	getch();
	clear();		//efface l'écran
	
	move(0,0);
	int c = getch();	//getch() : attend l'entrée de l'utilisateur, renvoie la valeur int de cette clé
	printw("%d", c);	//affiche le code ASCII du caractère entré
		//OU  mvprintw(0,0,"%d", c)
	refresh();		//rafraîchit l'écran pour correspondre à ce qui est en mémoire -> si on met pas, risque de pas afficher
	getch();
	clear();
	
	int height = 15;
	int width = 100;
	int start_y = 10;
	int start_x = 10;
	WINDOW * win = newwin(height, width, start_y, start_x);
	box(win,0,0);		//box(win, int , int ) : met une bordure basique autour de la fenêtre
	mvwprintw(win, 1, 1, "Le texte est dans le cadre");
		/* wprintw(win, "") :		met le texte en haut à gauche dans le cadre mais remplace la bordure (écrit sur bordure)
		   mvwprint(win, y, x, "") :	met le texte aux coordonnées (x,y) dans le cadre
		*/
	refresh();
	wrefresh(win);		//rafraichit le cadre en paramètre, se met tjs en plus de refresh()
	getch();
	
	
	endwin();
	return 0;
}
