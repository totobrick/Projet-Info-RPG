
int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11 = 1;

if (event == 1){
    do{
   int randevent = rand() %11;
    
    if (randevent == 0 && e1==1){
    
    printf(" ... /n/n Sérieusement...?/n ");
           //essayer les code qui fonctione le mieux pour la musique
        e1 = 0;
        return;
    }
        if (randevent == 1 && e2==1){
            
    printf ("Une harpie sauvage apparaît! « It's over Anakin, I have the highground! », dit-elle.\n")
        //change la case en monstre harpy et lance le combat. la case devient définitivement une harpy.
        e2=0;
            return;
            }
        if (randevent == 2 && e3==1){
            
    printf ("Vous voyez au loin un homme qui ne bouge pas. Vous vous approchez en pensant qu'il pourrait avoir besoin d'aide. Tous à coup, vous le voyez courrir en hurlant: LEEROY JENKINS!!!. À cause de cette action, vous vous retrouvez sous une marée draconique, et mourrez, malgré tous avec l'honneur d'un grand guerrier!\n");
            life = 0;
            e3=0;
         return;
        }
        if (randevent == 3 && e4==1){
        
    printf ("Vous croisez une espèce de grosse tortue avec plein de pics sur sa carapace, et qui crache du feu. Elle vous regarde, et vous demande si vous n'avez pas vu une princesse blonde en robe rose. Vous lui dites que non, et par colère, il vous vole 10 petites étoiles! (si vous possédiez votre relique, elle est retournée à son point d'emplacement)\n");
           if (relic == 1){
            relic = 0; 
           }
            e4=0;
            return;
    
    if (randevent==4 && e5==1){
        
    printf ("Un spectacle d'horreur se déroule devant vous ! Un pauvre poisson-clown hors de l'eau semble pleurer tout en ne pouvant pas respirer.\n Il semble répéter sans cesse ces mêmes mots :\n   « Vous n'avez pas vu mon fils ?/n Vous n'avez pas vu mon fils ?/n Vous n'avez pas vu mon... » \nLe manque d'oxygen a eu raison de lui. Vous avez désormais un nouvel objectif : après être sorti victorieux de ce labyrinthe infernal, vous vous mettrez à la recherche de ce fameux « fils ».\n");
        e5=0;
        return;
    }
         if (randevent==5 && e6==1){
             
    printf ("Vous croisez un énorme tuyau fait de métal. Intrigué, vous vous approchez et entendez une étrange voix dans votre tête : Il faut suivre le conduit. Ne sachant ce qu'est ce fameux « conduit », vous continuez votre route.\n");
            e6=0;
                return;
         }
    
        if (randevent==6 && e7==1){
            
    printf ("Un homme au loin vous demande comment rejoindre « Sunny ». Il a les cheveux verts, comme si de la mousse lui avait poussé sur la tête. Il porte trois sabres au niveau de la ceinture, il paraît vraiment louche. Vous lui montrez une direction aléatoire en espérant qu'il vous laisse enfin tranquille. Il part dans la direction inverse complète. Quelle étrange rencontre !\n");
           e7=0;
            return;
        }
         
        if (randevent==7 && e8==1){
            
    printf("Vous voyez une sorte de scientifique au loin. En essayant de vous approcher, vous voyez une sorte d'écran apparaître avec marqué dessus : « Fun value invalid ». \nVoyant que vous ne pouvez bas continuer, vous décidez d'abandonner et de continuer votre périple.\n");
            e8=0;
                return;
        }
    
        if (randevent==8 && e9==1){
    
    printf("En vous baladant, vous tombez sur une étrange famille de deux squelettes. L'un petit, portant des habits rouge et blanc. Son frère, plus petit, porte un sweet à capuche bleuet et un pantalon noir. Pour éviter tout combat inutile, vous attendez un peu que le temps passe.");
        e9=0;
            return;
        }
    
        if (randevent==9 && e10==1){
            
    printf("Vous trouvez un parchemin ancien ! Quel secret cache t-il ? \nVous l'ouvrez et le contemplez. Il est écrit : « Seul Link peut vaincre Ganon. ». Du fait que vous ne vous nommez ni Link, ni Ganon, vous jetez ce torchon inutile.\n");
    e10=0;
       return;
        }
            
        if (randevent==10 && e11==1){
            
    printf("Vous rencontrez au détour de ce labyrinthe un vieil homme. Il prétend être le directeur d'un lycée spécialisé en magie très connu : le Lycée Magique George Pompidou. Il exprime même l'envie de vous faire entrer dans son lycée, dans la classe de « Nintendor ». Vous acceptez, et par conséquent, il se mit à hurler : « 100.000 points pour Nintendor! ».")
            e11=0
        return;
        }
} while(e1==1 && e2==1 && e3==1 && e4==1 && e5==1 && e6==1 && e7==1 && e8==1 && e9==1 && e10==1 && e11==1)
                  else(){
                  printf ("Problème ! L'évenement n'a pas pu être lancé !\n");
                  }
 }
