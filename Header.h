#include <stdio.h>
#include <time.h>
#include <unistd.h>         //?
#include <stdlib.h>
#include <string.h>         //?
#include <stdbool.h>        //?

#define SIZE 8              //tableau 6x6

//Création tableau (Thomas)
void invert_card(card* card1, card* card2);
void generate_board (card* tab, int size);
