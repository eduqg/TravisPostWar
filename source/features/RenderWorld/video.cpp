/*
 * Autor: Edson Alves
 * Data: 26/12/2012
 * e-mail: edsonalves@unb.br
 */
#include <iostream>
#include <cstdlib>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_thread.h>
#include "video.h"
#include <SDL/SDL_net.h>

using namespace std;

int red, green, blue ;

void init_sdl()
{

    int ar = SDL_Init(SDL_INIT_AUDIO);
    red = 255;
    green = blue = 0;
    if (ar != 0) {
        cerr << "Erro na inicialização do audio:" << SDL_GetError() << endl;
        exit(-1);
    }

    int rf = TTF_Init();

    if (rf != 0) {
		fprintf(stderr, "Erro na inicializacao da SDL_ttf: %s\n",
			    TTF_GetError());
			    exit(0);
    }

	int rc = SDL_Init(SDL_INIT_VIDEO);

	if (rc == -1) {
		cerr << "Erro na inicializacao da SDL: " << SDL_GetError() << endl;
		exit(-1);
	}

	SDLNet_Init();

	atexit(SDL_Quit);
}

void setup_window()
{
	const string appName = "Post War";
	const string resourcesDirectory = "source/features/RenderWorld/images/";

	string icon = "icon.bmp";
	string iconPath = resourcesDirectory + icon;

	SDL_WM_SetCaption(appName.c_str(), appName.c_str());
	SDL_WM_SetIcon(SDL_LoadBMP(iconPath.c_str()), NULL);

}

SDL_Surface * setup_video()
{
	SDL_Surface *screen = NULL;
	int width = 1208, height = 680, bitsPerPixel = 32;
	Uint32 videoOptions = SDL_HWSURFACE | SDL_DOUBLEBUF;

	screen = SDL_SetVideoMode(width, height, bitsPerPixel, videoOptions);

	if (!screen) {
		cerr << "Nao foi possivel inicializar o video com as configuracoes "
			 << "indicadas: " << SDL_GetError() << endl;
		exit(-2);
	}

	return screen;
}
