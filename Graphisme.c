//logo et couleur


Voleur
"T" (code ASCII 84) : Ce caractère peut représenter un voleur de manière stylisée, avec ses bras étendus pour symboliser la discrétion et la rapidité.

"%" (code ASCII 37) : Ce caractère peut représenter un voleur avec son masque ou son bandeau sur le visage, symbolisant l'anonymat et la clandestinité.

"$" (code ASCII 36) : Ce caractère peut être utilisé pour représenter un voleur en référence à l'argent, un élément souvent associé aux activités des voleurs.

"@" (code ASCII 64) : Ce caractère peut représenter un voleur dans une position furtive ou accroupie, prêt à agir rapidement.


  Le chevalier :

"Ø" (code ASCII 216) : Ce caractère ressemble à un bouclier, représentant la protection et la défense du chevalier.
  
Le mage :


"§" (code ASCII 167) : Ce caractère peut représenter un livre de sorts, symbolisant la connaissance et la maîtrise des incantations d'un mage.

  ranger

"®" (code ASCII 174) : Ce caractère peut représenter un ranger avec son emblème ou son insigne, symbolisant son statut et son affiliation.

"Ô" (code ASCII 212) : Ce caractère peut évoquer l'image d'un ranger portant une capuche ou un chapeau, symbole de sa connexion avec la nature.

  
Couleur:

#include <stdio.h>

int main() {
    // Séquence d'échappement ANSI pour définir la couleur du texte en rouge
    printf("\033[31mTexte en rouge\033[0m\n");

    // Séquence d'échappement ANSI pour définir la couleur du fond en bleu et la couleur du texte en blanc
    printf("\033[44;37mTexte sur fond bleu\033[0m\n");

    return 0;
}

/*Dans cet exemple, nous utilisons la séquence d'échappement \033[ pour indiquer le début d'une séquence d'échappement ANSI. Ensuite, nous utilisons des codes spécifiques pour définir les attributs de texte,
tels que la couleur du texte et du fond. Le code 31 indique la couleur rouge, le code 44 indique le fond bleu et le code 37 indique le texte blanc. La séquence d'échappement \033[0m est utilisée pour réinitialiser
les attributs de texte par défaut.*/



//Joueur
printf("\U0001F9D9"); //mage emoticon
printf("\U0001F93A");//chevalier (escrime) emoticon
//Monstre
printf("\U0001F9DF");//zombie emoticon
printf("\U0001F40D");//Basilique (serpent) emoticon
printf("\U0001F426");//harpie (oiseau) emoticon





