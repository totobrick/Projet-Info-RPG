#include<stdio.h>

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

int main() {  
    class = 0
    int verif = 0;
   

    do {
        printf("Quelle est votre classe ? ");
        verif = scanf("%d", &classe);
        vide_buffer();
    } while (classe != 1 && classe != 2 && classe != 3 && classe != 4 || verif != 1);
  
  
