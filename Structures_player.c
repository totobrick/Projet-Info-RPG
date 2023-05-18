#include<stdio.h>

typedef struct{
  char nom[100]; //ATTENTION depasement tableau
  int class; //Magicien, guerrier, ranger, voleur
  int weapon; //1,2,3,4
  int relic; //0,1
}Joueur;


void vide_buffer(){
  while (getchar()!='/n'){
  }
}
int main() {
  int class;
  int verif;
  do{
    printf("Quelle est votre classe?");
    verif=scanf("%d",&class);
    vide_buffer();
  }while(class !=1 || class !=2 || class !=3 || class !=4 || verif !=1);

