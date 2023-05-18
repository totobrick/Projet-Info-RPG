//code pour lancé une musique

 #include <SDL2/SDL.h>

int main() {
    // Initialisation de la bibliothèque SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Chargement du fichier audio
    SDL_AudioSpec audioSpec;
    Uint32 audioLength;
    Uint8* audioBuffer;
    if (SDL_LoadWAV("chemin/vers/votre/musique.wav", &audioSpec, &audioBuffer, &audioLength) == NULL) {
        printf("Erreur lors du chargement du fichier audio : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Ouverture du périphérique audio
    if (SDL_OpenAudio(&audioSpec, NULL) < 0) {
        printf("Erreur lors de l'ouverture du périphérique audio : %s\n", SDL_GetError());
        SDL_FreeWAV(audioBuffer);
        SDL_Quit();
        return 1;
    }

    // Lecture de la musique
    SDL_PauseAudio(0);

    // Attente de la fin de la musique
    SDL_Delay(audioSpec.samples * audioLength / audioSpec.freq);

    // Fermeture du périphérique audio
    SDL_CloseAudio();

    // Libération du buffer audio
    SDL_FreeWAV(audioBuffer);

    // Fermeture de la bibliothèque SDL
    SDL_Quit();

    return 0;
}


//code pour lancé un rick roll

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void openURL(const char* url) {
    char command[256];
    snprintf(command, sizeof(command), "xdg-open %s", url);  // Remplacez "xdg-open" par la commande appropriée pour votre système d'exploitation (par ex. "start" sur Windows)
    system(command);
}

int main() {
    const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";  // Lien vers la vidéo de Rick Astley

    printf("Cliquez pour voir quelque chose d'incroyable !\n");

    // Attend que l'utilisateur appuie sur une touche
    getchar();

    // Ouvre le lien du Rick Roll dans le navigateur par défaut
    openURL(rickRollURL);

    return 0;
}


//rick roll bis

#include <unistd.h>

int main() {
    const char* rickRollURL = "https://youtu.be/xLGktQmtR5A";  // Lien vers la vidéo de Rick Astley

    const char* browser = "xdg-open";  // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux

    // Lancement du navigateur avec l'URL du Rick Roll
    execlp(browser, browser, rickRollURL, NULL);

    return 0;
}




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
