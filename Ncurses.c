/*SOURCES :
https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
https://www.sbarjatiya.com/notes_wiki/index.php/Using_ncurses_library_with_C
POUR COMPILER :		gcc -o exe_ncurses Nucurses.c -lncurses
	-> l'extension -lncurses à la fin est essentielle
*/
#include <ncurses.h>

int main(){
	initscr();			//initscr() : configure la mémoire et efface l'écran
	int x=10, y=10;
	move(y , x);		//déplace le curseur au point de coordonnées (x,y).	x = nbre colonnes	y = nbre lignes
						//Si on ne l'affiche pas, le curseur est au point de coordonnées (0,0) cad en haut à droite
	
	printw("Bonjour!\n");	//printw("") : affiche un string(const char *) dans une fenêtre
	clear();				//efface l'écran
	int c = getch();		//getch() : pour l'entrée de l'utilisateur, renvoie la valeur int de cette clé
	
	move(0,0);
	printw("%d", c);	//affiche le code ASCII du caractère entré
	refresh();			//rafraîchit l'écran pour correspondre à ce qui est en mémoire
	
	getch();
	
	
	endwin();
	return 0;
}
