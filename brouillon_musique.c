
//rick roll bis

#include <unistd.h>

int main() {
    const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";  // Lien vers la vidéo de Rick Astley

    const char* browser = "xdg-open";  // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux

    // Lancement du navigateur avec l'URL du Rick Roll
    execlp(browser, browser, rickRollURL, NULL);

    return 0;
}




