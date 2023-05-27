# Projet-Informatique: CY-Memo-RPG


## Description brève

Notre projet est un Memory, dans lequel vous incarnez un des quatre personnages disponibles, à la recherche d'une relique mythique, et d'un ancien trésor caché. Lors de votre recherche, vous devrez combattre de nombreux monstres et serez confrontés à de nombreux dangers! 
Dans ce jeu, vous pourrez vous déplacez, de bas en haut, et de gauche à droite, mais attention! Vous devrez vous souvenir des cases vu par vous et le autres joueurs, car elles deviendront invisibles à chaque fois que l'un d'entre vous perd et retourne à son point de départ!


## Compilation et execution

Grace au makefile, rien de plus simple! Il vous suffit d'ouvrir votre terminal:

![alt texte](https://azurplus.fr/wp-content/uploads/1612494018_Comment-commencer-a-utiliser-le-terminal-Linux.png)

1. Accédez au répertoire contenant le Makefile:

![alt texte](https://www.jetestelinux.com/wp-content/uploads/2016/03/rmdir.png)

2. Et de simplement écrire "make" à l'intérieur du terminal, le fichier Makefile se chargera de tous, à votre place!

![alt texte](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRxGQjtvwVysznhXwRDiexpv8UCTxYQL1rrfA&usqp=CAU)

3. Enfin, pour executer, il vous suffira d'écrire "./exec_TPA", et le programme se lancera!


## Structre de projet

Notre projet utilise la bibliothèque "ncurses", qui permet d'avoir un affichage graphique bien plus propre et bien plus agréable.

![alt texte](https://upload.wikimedia.org/wikipedia/commons/thumb/2/27/Linux-menuconfig.png/220px-Linux-menuconfig.png)

En plus de cette bibliothèque, notre programme est composé de plusieurs fichier fonctionnant tous ensemble, mais ne vous en faite pas, comme dis précédement, le Makefile s'occupe de toute la partie compilation!

![alt texte](https://user.oc-static.com/upload/2019/07/03/15621610186591_ls%20-la.PNG)


## Exemple

```
void perso_move(Player* p, card* tab, int size, int x_newcard, int y_newcard){        //key = KEY_UP ou KEY_DOWN ou KEY_RIGHT ou KEY_LEFT
    (p).x = x_newcard;
    (p).y = y_newcard;
}
```

Comme on pourrait s'y attendre, cette fonction est la fonction qui nous permet de pouvoir nous déplacer. c'est grâçe à elle que votre personnage a la possibilité de ce déplacer dans le labyrinthe!


## Documentation

Afin que vous compreniez mieux comment fonctionne la bibliothèque ncurses, voici un lien vous enmenant vers un site vous expliquant comment cette bibliothèque fonctionne et comment l'obtenir et l'utiliser si besoin :

[texte](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)


## Contributions tiers et License

Comme marqué précédement dans la rubrique Documentation, nous avons utilisé la bibliothèque ncurses, alors voici le lien vers le site officiel :

[texte](https://invisible-island.net/ncurses/)


## Auteurs et remerciments

Nous avons donc été trois à travailler sur ce projet:
- Thomas RYKACZEWSKI
- Pierre GUESDON
- Alexis BERTRAND

Nous tenions tous de même à remercier notre professeur d'informatique, ANSERMIN Eva, qui a su nous aider et répondre dès que nous avions une question.


## Statut du projet

Notre équipe part du principe qu'un projet n'est jamais complètement fini, en effet, nous pensons qu'on peut toujours tout améliorer. Malgré tout, nous pensons tous aujourd'hui qu'il est préférable pour nous d'avancer et de partir sur un autre projet, qui pourrait nous permettre d'avance encore plus de le monde de la programmation.


![alt texte](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSipKWizbCNxkO2fYXV8z6HpnDWoDvnmnsWdw&usqp=CAU)
