/*SOURCES :
https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
https://www.sbarjatiya.com/notes_wiki/index.php/Using_ncurses_library_with_C
*/
#include <ncurses.h>
#include <stdio.h>

int main(void){
  initscreen();
  printw("Bonjour!");
  
}
