#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void coleta_ouro(Nation *pais, int valor_coleta_ouro){
    pais->gold_coins += valor_coleta_ouro;
}

void coleta_minerio(Nation *pais, int valor_coleta_minerio){
    pais->minerals += valor_coleta_minerio;
}

void coleta_comida(Nation *pais, int valor_coleta_comida){
    pais->food += valor_coleta_comida;
}
