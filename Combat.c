void resetPlayerPosition(Player* p) {
    (*p).x = (*p).x_init;
    (*p).y = (*p).y_init;
    printw ("Position du joueur %s réinitialisé.\n",(*p).nom);
}

void vide_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
    }
}

void combat(Player P, card c) {
    if (c.m.type[0] == 1){
    
    if(P.w.type[0] == 1){
     printw ("Le Basilic est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Basilic vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[1] == 1){
    if(P.w.type[1] == 1){
     printw ("Le Zombie est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Zombie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else if (c.m.type[2] == 1){
    if(P.w.type[2] == 1){
     printw ("Le Troll est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! Le Troll vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    else{
    if(P.w.type[3] == 1){
     printw ("La Harpie est vaincu !\n");
        P.slay++;
    }
    else{
     printw ("Game Over ! La Harpie vous a tué.\n");
     resetPlayerPosition( &P);
    }
    }
    }
  
    
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

