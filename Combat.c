void resetPlayerPosition(Player* p) {
    (*p).x = (*p).x_init;
    (*p).y = (*p).y_init;
    printf("Position du joueur %s réinitialisé.\n",(*p).nom);
}

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

void combat(Player P, card c) {
    if (c.m.type[0] == 1){
    
    if(P.w.type[0] == 1){
     printf("Le Basilic est vaincu !\n");
        P.slay++;
    }
    else{
     printf("Game Over ! Le Basilic vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[1] == 1){
    if(P.w.type[1] == 1){
     printf("Le Zombie est vaincu !\n");
        P.slay++;
    }
    else{
     printf("Game Over ! Le Zombie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[2] == 1){
    if(P.w.type[2] == 1){
     printf("Le Troll est vaincu !\n");
        P.slay++;
    }
    else{
     printf("Game Over ! Le Troll vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else{
    if(P.w.type[3] == 1){
     printf("La Harpie est vaincu !\n");
        P.slay++;
    }
    else{
     printf("Game Over ! La Harpie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    }

int main() {
    card c;
    Player P;
    int verif = 0;
  int weapon=0;
  int enemy=0;

    printf("Choisissez votre arme : \n");
    printf("1. Bouclier\n");
    printf("2. Torche\n");
    printf("3. Hache\n");
    printf("4. Arc\n");
    do {
        printf("Votre choix: ");
        verif = scanf("%d", &weapon);
        vide_buffer();
    } while (weapon != 1 && weapon != 2 && weapon != 3 && weapon != 4 || verif != 1);
verif=0;
    if (weapon == 1){       //bouclier
        P.w.type[0] = 1;
        P.w.type[1] = 0;
        P.w.type[2] = 0;
        P.w.type[3] = 0;
    }
    else if (weapon == 2){          //Torche
        P.w.type[0] = 0;
        P.w.type[1] = 1;
        P.w.type[2] = 0;
        P.w.type[3] = 0;
    }
    else if (weapon == 3){          //hache
        P.w.type[0] = 0;
        P.w.type[1] = 0;
        P.w.type[2] = 1;
        P.w.type[3] = 0;
    }
    else{                             //arc
        P.w.type[0] = 0;
        P.w.type[1] = 0;
        P.w.type[2] = 0;
        P.w.type[3] = 1;   
    }
    
   
    printf("Choisissez votre ennemi : \n");
    printf("1. Basilic\n");
    printf("2. Zombie\n");
    printf("3. Troll\n");
    printf("4. Harpie\n");
    do {
        printf("Votre choix:  ");
        verif = scanf("%d", &enemy);
        vide_buffer();
    } while (enemy != 1 && enemy != 2 && enemy != 3 && enemy != 4 || verif != 1);
    
        if (enemy == 1){
        c.m.type[0] = 1;
        c.m.type[1] = 0;
        c.m.type[2] = 0;
        c.m.type[3] = 0;
    }
    else if (enemy == 2){
        c.m.type[0] = 0;
        c.m.type[1] = 1;
        c.m.type[2] = 0;
        c.m.type[3] = 0;
    }
    else if (enemy == 3){
        c.m.type[0] = 0;
        c.m.type[1] = 0;
        c.m.type[2] = 1;
        c.m.type[3] = 0;
    }
    else{
        c.m.type[0] = 0;
        c.m.type[1] = 0;
        c.m.type[2] = 0;
        c.m.type[3] = 1;   
    }
   
    combat(P,c);

    return 0;
}
