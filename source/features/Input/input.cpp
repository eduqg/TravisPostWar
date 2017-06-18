#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include "../../../include/loop.h"
#include <string>

using namespace std;

Vetor_mouse *get_Input()
{
	SDL_Event event;
	Vetor_mouse *vetor_mouse = new Vetor_mouse();
	vetor_mouse->click = -1;
	vetor_mouse->number = -1;

	if (SDL_PollEvent(&event)) {
		vetor_mouse->number = -1;
		switch (event.type) {
			/* the next two event types deal with mouse activity. */
			case SDL_MOUSEMOTION:
				vetor_mouse->x = event.motion.x;
				vetor_mouse->y = event.motion.y;
				return vetor_mouse;

				/*
				 * printf("New position is (%i, %i). ",
				 *        event.motion.x, event.motion.y);
				 *
				 * We can also get relative motion:
				 * printf("That is a (%i, %i) change.\n",
				 *	      event.motion.xrel, event.motion.yrel);
				 */
				break;
			case SDL_MOUSEBUTTONDOWN:
				vetor_mouse->click = event.button.button;
				vetor_mouse->x = event.motion.x;
				vetor_mouse->y = event.motion.y;
				/* cout<<"X do mouse: "<<vetor_mouse->x<<endl; */
				/* cout<<"Y do mouse: "<<vetor_mouse->y<<endl; *q
				return vetor_mouse;

				/*
				 * printf("Mouse button pressed. ");
				 * printf("Button %i at (%i,%i)\n",
				 * event.button.button,
				 * event.button.x, event.button.y);
				 */
				break;
			/*
			 * The SDL_QUIT event indicates that
			 * the windows "Close" button has been
			 * pressed. We can ignore this if we
			 * need to, but that tends to make
			 * users rather impatient.
			 */
			case SDL_QUIT:
				printf("Adeus.\n");
				exit(0);
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_0) {
					vetor_mouse->number = 0;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_1) {
					vetor_mouse->number = 1;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_2) {
					vetor_mouse->number = 2;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_3) {
					vetor_mouse->number = 3;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_4) {
					vetor_mouse->number = 4;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_5) {
					vetor_mouse->number = 5;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_6) {
					vetor_mouse->number = 6;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_7) {
					vetor_mouse->number = 7;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_8) {
					vetor_mouse->number = 8;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_9) {
					vetor_mouse->number = 9;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_PERIOD) {
					vetor_mouse->number = 10;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_a) {
					vetor_mouse->number = 11;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_b) {
					vetor_mouse->number = 12;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_c) {
					vetor_mouse->number = 13;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_d) {
					vetor_mouse->number = 14;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_e) {
					vetor_mouse->number = 15;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_f) {
					vetor_mouse->number = 16;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_g) {
					vetor_mouse->number = 17;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_h) {
					vetor_mouse->number = 18;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_i) {
					vetor_mouse->number = 19;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_j) {
					vetor_mouse->number = 20;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_k) {
					vetor_mouse->number = 21;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_l) {
					vetor_mouse->number = 22;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_m) {
					vetor_mouse->number = 23;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_n) {
					vetor_mouse->number = 24;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_o) {
					vetor_mouse->number = 25;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_p) {
					vetor_mouse->number = 26;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_q) {
					vetor_mouse->number = 27;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_r) {
					vetor_mouse->number = 28;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_s) {
					vetor_mouse->number = 29;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_t) {
					vetor_mouse->number = 30;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_u) {
					vetor_mouse->number = 31;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_v) {
					vetor_mouse->number = 32;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_x) {
					vetor_mouse->number = 33;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_w) {
					vetor_mouse->number = 34;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_y) {
					vetor_mouse->number = 35;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_z) {
					vetor_mouse->number = 36;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					vetor_mouse->number = 37;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_BACKSPACE) {
					vetor_mouse->number = 38;
					return vetor_mouse;
				}
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					vetor_mouse->number = 39;
					return vetor_mouse;
				}
		}
	}
	return vetor_mouse;
}
