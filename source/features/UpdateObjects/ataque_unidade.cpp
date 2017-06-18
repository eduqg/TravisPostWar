#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

using namespace std;
char efeito_ataque;
Mix_Chunk *efeito_tiro_tanque;
Mix_Chunk *efeito_tiro_helicoptero;

void ataque_unidade(SDL_Surface *screen,
                    int x,
                    int y,
                    int totalElapsedTime,
                    int delay,
                    int lastdt)
{

	for (int i = 0; i < 5; i++) {
		string tipoquartel = "quartel";
		Unit *temp;
		Unit *temp_defensor;
		SDL_Surface *temp_s;
		SDL_Surface *temp_s2;
		int n_sprites = 0;
		int tamanho_sprites = 0;
		int n_sprites2 = 0;
		int tamanho_sprites2 = 0;


		int w = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->x;
		int s = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->y;
		int w_def = hexagons[hexagon_selected->i][hexagon_selected->j]->x;
		int s_def = hexagons[hexagon_selected->i][hexagon_selected->j]->y;


		if (hexagons[hexagon_selected->i_before]
		    [hexagon_selected->j_before]->contains_unit == 0)
		{
			break;
		}

		temp = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit;
		temp_defensor = hexagons[hexagon_selected->i][hexagon_selected->j]->unit;
		if (temp->unit_type == tipoquartel) {
			cout << "Nao pode atacar" << endl;
			return;
		}
		string color = "vermelho";
		string cor2 = "azul";
		string unit_type = "metralhadora";
		string tipo2 = "soldado";
		string tipo3 = "helicoptero";
		string tipo4 = "tanque";

		SDL_Rect cutBox = {0,0,32,32};
		if (temp_defensor->unit_type == tipo4 && temp_defensor->color == cor2) {
			efeito_ataque = 't';
			n_sprites = 4;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;

				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;

				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		/* acha tanque vermelho */
		if (temp_defensor->unit_type == tipo4 && temp_defensor->color == color) {
			efeito_ataque = 't';
			n_sprites = 4;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		/* acha helicoptero vermelho */
		if (temp_defensor->unit_type == tipo3 && temp_defensor->color == color) {
			efeito_ataque = 'h';
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
				n_sprites = 7;
			}

		}
		/* acha helicoptero azul */
		if (temp_defensor->unit_type == tipo3 && temp_defensor->color == cor2) {
			efeito_ataque = 'h';
			cout << "Achei helicoptero azul" << endl;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
				n_sprites = 9;
			}

		}
		/* acha metralhadora azul */
		if (temp_defensor->unit_type == unit_type && temp_defensor->color == cor2) {
			efeito_ataque = 'm';
			temp_s2 = temp_defensor->attack;
			cout << "Achei metralhadora" << endl;;
				cutBox.x = 64;
				cutBox.y = 0;
				cutBox.w = 64;
				cutBox.h = 64;
			tamanho_sprites = 64;
			n_sprites = 5;
		}
		/* acha metralhadora vermelha */
		if (temp_defensor->unit_type == unit_type && temp_defensor->color == color) {
			cout << "Achei metralhadora" << endl;
			temp_s2 = temp_defensor->attack;
			cutBox.x = 0;
			cutBox.y = 0;
			cutBox.w = 64;
			cutBox.h = 64;
			tamanho_sprites = 64;
			n_sprites = 5;
		}
		/* acha soldado vermelho */
		if (temp_defensor->color == color && temp_defensor->unit_type == tipo2) {
			efeito_ataque = 's';
			cout << "Achei vermelho" << endl;
			n_sprites = 5;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}

		/* acha soldado azul */
		if (temp_defensor->color == cor2 && temp_defensor->unit_type == tipo2) {
			efeito_ataque = 's';
			cout << "Achei azul" << endl;
			n_sprites = 5;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->down_attack;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->up_attack;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->attack;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		SDL_Rect cutBox2 = {0, 0, 32, 32};

		/* acha tanque azul */
		if (temp->unit_type == tipo4 && temp->color == cor2) {
			efeito_ataque = 't';
			n_sprites2 = 4;
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;

				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;

				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}
		/* acha tanque vermelho */
		if (temp->unit_type == tipo4 && temp->color == color) {
			efeito_ataque = 't';
			n_sprites2 = 4;
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}
		/* acha helicoptero vermelho */
		if (temp->unit_type == tipo3 && temp->color == color) {
			efeito_ataque = 'h';
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
				n_sprites2 = 7;
			}
		}
		/* acha helicoptero azul */
		if (temp->unit_type == tipo3 && temp->color == cor2) {
			cout << "Achei helicoptero azul" << endl;
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
				n_sprites2 = 9;
			}

		}
		/* acha metralhadora azul */
		if (temp->unit_type == unit_type && temp->color == cor2) {
			efeito_ataque = 'm';
			temp_s = temp->attack;
			cutBox2.x = 64;
			cutBox2.y = 0;
			cutBox2.w = 64;
			cutBox2.h = 64;
			tamanho_sprites2 = 64;
			n_sprites2 = 5;
		}
		/* acha metralhadora vermelha */
		if (temp->unit_type == unit_type && temp->color == color) {
			efeito_ataque = 'm';
			cout << "Achei metralhadora" << endl;
			temp_s = temp->attack;
			cutBox2.x = 0;
			cutBox2.y = 0;
			cutBox2.w = 64;
			cutBox2.h = 64;
			tamanho_sprites2 = 64;
			n_sprites2 = 5;
		}
		/* acha soldado vermelho */
		if (temp->color == color && temp->unit_type == tipo2) {
			efeito_ataque = 's';
			cout << "Achei vermelho" << endl;
			n_sprites2 = 5;
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}

		/* acha soldado azul */
		if (temp->color == cor2 && temp->unit_type == tipo2) {
			efeito_ataque = 's';
			cout << "Achei azul" << endl;
			n_sprites2 = 5;
			if (s < y && w == x) {
				temp_s = temp->down_attack;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->up_attack;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->attack;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}


		int tempo_delay = 50;

		while((cutBox.x <n_sprites * tamanho_sprites) &&
		      (cutBox2.x <n_sprites2*tamanho_sprites2))
		{
			blit_tela_ataque(screen, 1, temp_defensor->id, w, s);
			blit_tela_ataque(screen, 1, temp->id, x, y);

			int dt = SDL_GetTicks() - lastdt;
			lastdt = SDL_GetTicks();

			totalElapsedTime += dt;

			if (totalElapsedTime >= delay) {
				totalElapsedTime -= delay;
				cutBox.x += tamanho_sprites;
				cutBox2.x += tamanho_sprites2;
			}

			switch(efeito_ataque) {
				case 's':
					play_effect(efeito_tiro_soldado);
					break;
				case 'm':
					play_effect(efeito_metralhadora);
					break;
				case 't':
					play_effect(efeito_tiro_tanque);
					break;
				case 'h':
					play_effect(efeito_tiro_helicoptero);
					break;
			}

			SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};
			SDL_Rect dest2 = {(Sint16)w_def, (Sint16)s_def, 0, 0};

			SDL_BlitSurface(temp_s, &cutBox2, screen, &dest);
			SDL_BlitSurface(temp_s2, &cutBox, screen, &dest2);

			SDL_Delay(tempo_delay);

			SDL_Flip(screen);
		}
	}
}
