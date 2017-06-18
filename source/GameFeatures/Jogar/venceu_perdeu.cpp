#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <iostream>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void perdeu_jogo(SDL_Surface *screen){
    string imagem_perdeu = "source/GameFeatures/Jogar/images/tela_derrota.png";

    SDL_Surface *tela = load_Image(imagem_perdeu, screen);

    for(int i = 2; i <= 256;i++){
        SDL_SetAlpha(tela,SDL_RLEACCEL | SDL_SRCALPHA,(Uint8)i);
        BlitImage(screen, tela, 0, 0);
        SDL_Delay(20);
        SDL_Flip(screen);
    }
    load_menu(screen);
}

void venceu_jogo(SDL_Surface *screen){
    string imagem_venceu = "source/GameFeatures/Jogar/images/tela_vitoria.png";

    SDL_Surface *tela = load_Image(imagem_venceu, screen);

    for(int i = 2; i <= 256;i++){
        SDL_SetAlpha(tela,SDL_RLEACCEL | SDL_SRCALPHA,(Uint8)i);
        BlitImage(screen, tela, 0, 0);
        SDL_Delay(20);
        SDL_Flip(screen);
    }
    load_menu(screen);

}
