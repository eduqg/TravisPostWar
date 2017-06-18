#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

/* allow the soldiers to be moved */
void mover_soldado(SDL_Surface *screen, int i, int x, int y)
{
	int posi = red_units[i]->x;
	for (int j = posi;j<x;j++) {
		SDL_Rect pos = {j, y};
		red_units[i]->x = j;
		red_units[i]->y = y;
		SDL_BlitSurface(red_units[i]->name, NULL, screen, &pos);
		SDL_Flip(screen);
	}
}
