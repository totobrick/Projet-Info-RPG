/*SOURCES :
https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
https://www.sbarjatiya.com/notes_wiki/index.php/Using_ncurses_library_with_C
*/
#include <ncurses.h>

int main(){
  initscr();
  printw("Bonjour!");
  refresh();
  getch();
  endwin();
  
  return 0;
}
