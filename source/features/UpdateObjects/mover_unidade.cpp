#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

void mover_soldado(SDL_Surface *screen,
				   int x,
				   int y,
				   int totalElapsedTime,
				   int delay,
				   int lastdt)
{

	string tipo1 = "quartel";
	string tipo2 = "metralhadora";
	Unit *temp;

	temp = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit;

	if (temp->unit_type == tipo1 || temp->unit_type == tipo2) {
		cout << "Nao pode mover" << endl;
		return;
	}

	hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit = NULL;
	hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->contains_unit = 0;

	SDL_Rect cutBox = {32,0,32,32};

	int tempo_delay;

	if (temp->unit_type=="helicoptero") {
		tempo_delay = 10;
	}
	else {
		tempo_delay = 50;
	}

	int w = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->x;
	int s = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->y;

	while (w != x || y != s) {
		blit_tela(screen,1);
		int dt = SDL_GetTicks() - lastdt;
		lastdt = SDL_GetTicks();

		if (w == x && s > y) {
			if (abs(y - s) == 1) {
				s = s - 1;
			}
			s = s - 2;
		}

		else if (w < x) {
			if(abs(w - x) == 1) {
				w = w + 1;
			}
			w = w + 2;
		}

		else if (w > x) {
			if(abs(w -y) == 1) {
				w = w -1;
			}
			w = w - 2;
		}

		if (s>y) {
			if (abs(y -s) == 1) {
				s = s - 1;
			}
			s = s - 2;
		}
		else if (s < y) {
			if(abs(y - s) == 1) {
				s = s + 1;
			}
			s = s + 2;
		}
		totalElapsedTime += dt;
		if (totalElapsedTime >= delay) {
			totalElapsedTime -= delay;
			if (cutBox.x == 0) {
				cutBox.x = 32;
			}
			else {
				cutBox.x -= 32;
			}
		}

		SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};
		if (hexagons[hexagon_selected->i_before]
		    [hexagon_selected->j_before]->contains_unit)
		{
			cout<<"WOLOLOLO"<<endl;
		}
		SDL_BlitSurface(temp->name, &cutBox, screen, &dest);
		SDL_Delay(tempo_delay);
		SDL_Flip(screen);
	}
	hexagons[hexagon_selected->i][hexagon_selected->j]->unit = temp;
	hexagons[hexagon_selected->i][hexagon_selected->j]->contains_unit = 1;
}
