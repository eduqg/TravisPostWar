#include <iostream>
#include <string>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

Mix_Chunk *efeito_explosao;
int lastdt = SDL_GetTicks();
int totalElapsedTime = 0;
int delay = 200;
string derrotado = "branca";

void dano_ataque(SDL_Surface *screen)
{
	string tipoquartel = "quartel";
	/* inicializa o random */
	srand (time(NULL));

	string cor1 = "azul";
	string cor2 = "vermelho";

	int rand_defensor = rand() % 50 + 30;
	int rand_atacante = rand() % 50 + 40;

	Unit *atacante = hexagons[hexagon_selected->i_before]
								 [hexagon_selected->j_before]->unit;
	Unit *defensor = hexagons[hexagon_selected->i]
								 [hexagon_selected->j]->unit;

	if (atacante->unit_type == tipoquartel) {
		cout << "Unit não pode atacar" << endl;
		return;
	}

	int dano_no_atacante = ((defensor->attack_points/atacante->deffense_points)+1) *
						   (rand_defensor/2);
	int dano_no_defensor = ((atacante->attack_points/ defensor->deffense_points)+1)*
						   (rand_atacante);
	cout << "dano no atacante:" << dano_no_atacante << endl;
	cout << "dano no defensor:" << dano_no_defensor << endl;
	atacante->health_points -= dano_no_atacante;
	if (atacante->health_points <= 0) {
		atacante->health_points  = 0;
	}
	defensor->health_points -= dano_no_defensor;
	if (defensor->health_points < 0) {
		defensor->health_points  = 0;
	}

	if (defensor->unit_type == tipoquartel && defensor->health_points == 0) {
		cout << "defensor:" << defensor->color << endl;
		derrotado = defensor->color;
		cout << "derrotado:" << derrotado << endl;
	}
	cout << "atacante health_points:" << atacante->health_points << endl;
	cout << "defensor health_points:" << defensor->health_points << endl;

	if (atacante->health_points <= 0) {
		explode_unidade(screen,
						hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->x,
						hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->y,
						totalElapsedTime, delay, lastdt);
		hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit = NULL;
		hexagons[hexagon_selected->i_before]
				 [hexagon_selected->j_before]->contains_unit = 0;
	}
	else {
		hexagons[hexagon_selected->i_before]
				 [hexagon_selected->j_before]->unit->health_points = atacante->health_points;
	}
	if (defensor->health_points <= 0) {
		if (defensor->unit_type.compare("quartel") != 0) {
			if (defensor->unit_type.compare("metralhadora") != 0) {
				play_effect(efeito_explosao);
				explode_unidade(screen,
								hexagons[hexagon_selected->i][hexagon_selected->j]->x,
								hexagons[hexagon_selected->i][hexagon_selected->j]->y,
								totalElapsedTime, delay, lastdt);
				hexagons[hexagon_selected->i][hexagon_selected->j]->unit = NULL;
				hexagons[hexagon_selected->i][hexagon_selected->j]->contains_unit = 0;
			}
			else if (defensor->color == "azul") {
				play_effect(efeito_explosao);
				hexagons[9][12]->unit = NULL;
				hexagons[9][12]->contains_unit = 0;
				hexagons[10][12]->unit = NULL;
				hexagons[10][12]->contains_unit = 0;
				hexagons[11][12]->unit = NULL;
				hexagons[11][12]->contains_unit = 0;
				hexagons[12][12]->unit = NULL;
				hexagons[12][12]->contains_unit = 0;
				hexagons[13][12]->unit = NULL;
				hexagons[13][12]->contains_unit = 0;
			}
			else {
				play_effect(efeito_explosao);
				hexagons[6][4]->unit = NULL;
				hexagons[6][4]->contains_unit = 0;
				hexagons[7][4]->unit = NULL;
				hexagons[7][4]->contains_unit = 0;
				hexagons[8][4]->unit = NULL;
				hexagons[8][4]->contains_unit = 0;
			}
		}
		else if (defensor->color == "azul") {
			play_effect(efeito_explosao);
			hexagons[7][13]->unit = NULL;
			hexagons[7][13]->contains_unit = 0;
			hexagons[7][14]->unit = NULL;
			hexagons[7][14]->contains_unit = 0;
			hexagons[8][14]->unit = NULL;
			hexagons[8][14]->contains_unit = 0;
			hexagons[9][13]->unit = NULL;
			hexagons[9][13]->contains_unit = 0;
			hexagons[9][14]->unit = NULL;
			hexagons[9][14]->contains_unit = 0;
			hexagons[10][14]->unit = NULL;
			hexagons[10][14]->contains_unit = 0;

		}
		else {
			play_effect(efeito_explosao);
			hexagons[5][1]->unit = NULL;
			hexagons[5][1]->contains_unit = 0;
			hexagons[6][1]->unit = NULL;
			hexagons[6][1]->contains_unit = 0;
			hexagons[6][2]->contains_unit = 0;
			hexagons[6][2]->unit = NULL;
			hexagons[7][1]->contains_unit = 0;
			hexagons[7][1]->unit = NULL;
			hexagons[8][1]->contains_unit = 0;
			hexagons[8][1]->unit = NULL;
			hexagons[8][2]->contains_unit = 0;
			hexagons[8][2]->unit = NULL;
			hexagons[9][1]->contains_unit = 0;
			hexagons[9][1]->unit = NULL;
		}
	}
	else {
		hexagons[hexagon_selected->i][hexagon_selected->j]->unit->health_points = defensor->health_points;
	}
}

void explode_unidade(SDL_Surface *screen,
                     int x,
                     int y,
                     int totalElapsedTime,
                     int delay,
                     int lastdt)
{
	string caminho =
	            "source/GameFeatures/Jogar/Fase1/images/explosao_unidades.png";
	SDL_Surface *explosao = load_Image(caminho, screen);
	int n_sprites = 8;
	int tamanho_sprites = 32;
	int tempo_delay = 50;
	for (int i = 0; i <= 3; i++) {
		SDL_Rect cutBox = {0, 0, 32, 32};

		while (cutBox.x < n_sprites*tamanho_sprites) {
			blit_tela(screen, 1);
			int dt = SDL_GetTicks() - lastdt;
			lastdt = SDL_GetTicks();

			totalElapsedTime += dt;

			if (totalElapsedTime >= delay) {
				totalElapsedTime -= delay;
				cutBox.x += tamanho_sprites;
			}

			SDL_Rect dest = {(Sint16)x, (Sint16)y, 0, 0};
			SDL_BlitSurface(explosao, &cutBox, screen, &dest);
			SDL_Delay(tempo_delay);
			SDL_Flip(screen);
		}
	}
}
