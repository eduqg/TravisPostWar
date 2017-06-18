/*
 * Autor: Edson Alves
 * Data: 26/12/2012
 * e-mail: edsonalves@unb.br
 */
#include <iostream>
#include <SDL/SDL.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "draw.h"
#include "video.h"

using namespace std;

SDL_Surface *render_World()
{

	init_sdl();
	setup_window();
	SDL_Surface *screen = setup_video();

    string tela = "source/features/RenderWorld/images/tela_preta.png";
    SDL_Surface *preta = load_Image(tela, screen);

    string um = "source/features/RenderWorld/images/front_end1.png";
    SDL_Surface *end1 = load_Image(um, screen);
    BlitImage(screen, preta, 0, 0);
    BlitImage(screen, end1, 0, 0);
    SDL_Flip(screen);
    SDL_Delay(3000);

    string dois = "source/features/RenderWorld/images/front_end2.png";
    SDL_Surface *end2 = load_Image(dois, screen);
    BlitImage(screen, preta, 0, 0);
    BlitImage(screen, end2, 0, 0);
    SDL_Flip(screen);
    SDL_Delay(3000);

    string tres = "source/features/RenderWorld/images/front_end3.png";
    SDL_Surface *end3 = load_Image(tres, screen);
    BlitImage(screen, preta, 0, 0);
    BlitImage(screen, end3, 0, 0);
    SDL_Flip(screen);
    SDL_Delay(3000);

    string quatro = "source/features/RenderWorld/images/front_end4.png";
    SDL_Surface *end4 = load_Image(quatro, screen);
    BlitImage(screen, preta, 0, 0);
    BlitImage(screen, end4, 0, 0);
    SDL_Flip(screen);
    SDL_Delay(3000);

    string cinco = "source/features/RenderWorld/images/TelaJogo.png";
    SDL_Surface *end5 = load_Image(cinco, screen);
    BlitImage(screen, preta, 0, 0);
    BlitImage(screen, end5, 0, 0);
    SDL_Flip(screen);
    SDL_Delay(3000);

    return screen;
}
