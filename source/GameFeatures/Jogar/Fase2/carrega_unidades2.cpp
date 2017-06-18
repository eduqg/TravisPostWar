#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

/* loads france stage */
void carrega_franca(SDL_Surface *screen)
{
	string lado1("servidor");
	string color = "vermelho";

	for(int i = 0, j = 1;i < 6;i++,j += 30){
		string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
		SDL_Surface *soldado1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
		SDL_Surface *ataque_soldado = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
		SDL_Surface *down_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
		SDL_Surface *up_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral_vermelho.png";
		SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
		Unit *soldado = new Unit();

		string unidadea1 = "soldado";
		setar_soldado(soldado,
					  color,
					  unidadea1,
					  soldado1,
					  ataque_soldado,
					  down_attack,
					  up_attack,
					  soldado_lateral_a,
					  id);
		id++;
		blue_units.push_back(soldado);
		SDL_Rect dst;
		dst.x = hexagons[i*2][3]->x;
		dst.y = hexagons[i*2][3]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(blue_units[i]->name, &cutBox,  screen, &dst);
		hexagons[i*2][3]->unit = blue_units[i];
		hexagons[i*2][3]->contains_unit = 1;

		caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_vermelha.png";
		SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
		Unit *quartel_a = new Unit();
		string quarte = "quartel";
		setar_quartel(quartel_a,
					  color,
					  quarte,
					  quartel_azul_cabana,
					  quartel_azul_cabana,
					  quartel_azul_cabana,
					  id);
		id++;
		BlitImage(screen,
				  quartel_azul_cabana,
				  hexagons[6][1]->x,
				  hexagons[6][1]->y);
		hexagons[5][1]->unit = quartel_a;
		hexagons[5][1]->contains_unit = 1;
		hexagons[6][1]->unit = quartel_a;
		hexagons[6][1]->contains_unit = 1;
		hexagons[6][2]->contains_unit = 1;
		hexagons[6][2]->unit = quartel_a;
		hexagons[7][1]->contains_unit = 1;
		hexagons[7][1]->unit = quartel_a;
		hexagons[8][1]->contains_unit = 1;
		hexagons[8][1]->unit = quartel_a;
		hexagons[8][2]->contains_unit = 1;
		hexagons[8][2]->unit = quartel_a;
		hexagons[9][1]->contains_unit = 1;
		hexagons[9][1]->unit = quartel_a;
	}

	for (int i = 6, j = 1;i < 8;i++,j += 30) {
		string caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_vermelho.png";
		SDL_Surface *tanque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_vermelho.png";
		SDL_Surface *ataque_tanque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_ataqueParaBaixo(vermelho).png";
		SDL_Surface *down_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_ataqueParaCima(vermelho).png";
		SDL_Surface *up_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_lateral_vermelho.png";
		SDL_Surface *tanque_lateral= load_Image(caminho, screen);
		Unit *tanque1 = new Unit();

		string unidadea1 = "tanque";
		setar_tanque(tanque1,
					 color,
					 unidadea1,
					 tanque,
					 ataque_tanque,
					 down_attack,
					 up_attack,
					 tanque_lateral,
					 id);
		id++;
		blue_units.push_back(tanque1);
		SDL_Rect dst;
		dst.x = hexagons[i*2][3]->x;
		dst.y = hexagons[i*2][3]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(blue_units[i]->name, &cutBox,  screen, &dst);
		hexagons[i*2][3]->unit = blue_units[i];
		hexagons[i*2][3]->contains_unit = 1;
	}

	string caminho = "source/GameFeatures/Jogar/Fase2/images/metralhadora_vermelha_esquerda1.png";
	SDL_Surface *metralhadora1 = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase2/images/metralhadora_vermelha_ataque.png";
	SDL_Surface *metralhadora_ataque = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase2/images/barraLateral_vermelho.png";
	SDL_Surface *metralhadora_lateral = load_Image(caminho, screen);
	Unit *metralhadora = new Unit();
	string unidadea2 = "metralhadora";
	setar_metralhadora(metralhadora,
					   color,
					   unidadea2,
					   metralhadora1,
					   metralhadora_ataque,
					   metralhadora_lateral,
					   id);
	id++;
	blue_units.push_back(metralhadora);

	BlitImage(screen,
			  blue_units[8]->name,
			  hexagons[6][4]->x,
			  hexagons[6][4]->y);

	hexagons[6][4]->contains_unit=1;
	hexagons[6][4]->unit = metralhadora;
	hexagons[7][4]->contains_unit=1;
	hexagons[7][4]->unit = metralhadora;
	hexagons[8][4]->contains_unit=1;
	hexagons[8][4]->unit = metralhadora;



	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;
}

/* loads united kingdom stage */
void carrega_uk(SDL_Surface *screen)
{
	string lado2("cliente");
	string cor2 = "azul";

	for (int i = 0;i < 6;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
		SDL_Surface *soldado1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque.png";
		SDL_Surface *soldado_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_baixo.png";
		SDL_Surface *soldado_ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_cima.png";
		SDL_Surface *soldado_ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral.png";
		SDL_Surface *soldado_lateral_v = load_Image(caminho, screen);
		Unit *soldado = new Unit();
		string unit = "soldado";
		setar_soldado(soldado,
					  cor2,
					  unit,
					  soldado1,
					  soldado_ataque,
					  soldado_ataque_baixo,
					  soldado_ataque_cima,
					  soldado_lateral_v,
					  id);
		id++;
		red_units.push_back(soldado);

		SDL_Rect dst;
		dst.x = hexagons[i*2][12]->x;
		dst.y = hexagons[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(red_units[i]->name, &cutBox,  screen, &dst);
		hexagons[i*2][12]->unit = red_units[i];
		hexagons[i*2][12]->contains_unit = 1;
		red_units[0]->x = hexagons[i*2][12]->x;
		red_units[0]->y = hexagons[i*2][12]->y;

	}

	for (int i = 6;i < 8;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_movimentacao_esqueda.png";
		SDL_Surface *helicoptero1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul.png";
		SDL_Surface *helicoptero_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_baixo.png";
		SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_cima.png";
		SDL_Surface *helicoptero_ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_barraLateral.png";
		SDL_Surface *helicoptero_lateral = load_Image(caminho, screen);
		Unit *helicoptero = new Unit();
		string unidade1 = "helicoptero";
		setar_helicoptero(helicoptero,
						  cor2,
						  unidade1,
						  helicoptero1,
						  helicoptero_ataque,
						  helicoptero_ataque_baixo,
						  helicoptero_ataque_cima,
						  helicoptero_lateral,
						  id);
		id++;
		red_units.push_back(helicoptero);

		SDL_Rect dst;
		dst.x = hexagons[i*2][12]->x;
		dst.y = hexagons[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(red_units[i]->name, &cutBox,  screen, &dst);
		hexagons[i*2][12]->unit = red_units[i];
		hexagons[i*2][12]->contains_unit = 1;
		red_units[0]->x = hexagons[i*2][12]->x;
		red_units[0]->y = hexagons[i*2][12]->y;
	}


	for (int i = 8;i < 9;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_esquerda1.png";
		SDL_Surface *tanque1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque.png";
		SDL_Surface *tanque_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_baixo.png";
		SDL_Surface *tanque_ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_cima.png";
		SDL_Surface *tanque_ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_lateral_a.png";
		SDL_Surface *tanque_lateral = load_Image(caminho, screen);
		Unit *tanque = new Unit();
		string unidade3 = "tanque";
		setar_tanque(tanque,
					 cor2,
					 unidade3,
					 tanque1,
					 tanque_ataque,
					 tanque_ataque_baixo,
					 tanque_ataque_cima,
					 tanque_lateral,
					 id);
		id++;
		red_units.push_back(tanque);
		SDL_Rect dst;
		dst.x = hexagons[i*2][12]->x;
		dst.y = hexagons[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(red_units[i]->name, &cutBox,  screen, &dst);
		hexagons[i*2][12]->unit = red_units[i];
		hexagons[i*2][12]->contains_unit = 1;
		red_units[0]->x = hexagons[i*2][12]->x;
		red_units[0]->y = hexagons[i*2][12]->y;
	}


	/* loads blue quarter's sprites */
	string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
	SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
	Unit *quartel_a = new Unit();
	string quarte = "quartel";
	setar_quartel(quartel_a,
				  cor2,
				  quarte,
				  quartel_azul_cabana,
				  quartel_azul_cabana,
				  quartel_azul_cabana,
				  id);
	id++;
	BlitImage(screen,
			  quartel_azul_cabana,
			  hexagons[7][13]->x,hexagons[7][13]->y);
	hexagons[7][13]->unit = quartel_a;
	hexagons[7][13]->contains_unit= 1;
	hexagons[7][14]->unit = quartel_a;
	hexagons[7][14]->contains_unit= 1;
	hexagons[8][14]->unit = quartel_a;
	hexagons[8][14]->contains_unit= 1;
	hexagons[9][13]->unit = quartel_a;
	hexagons[9][13]->contains_unit= 1;
	hexagons[9][14]->unit = quartel_a;
	hexagons[9][14]->contains_unit= 1;
	hexagons[10][14]->unit = quartel_a;
	hexagons[10][14]->contains_unit= 1;
	red_units.push_back(quartel_a);
}








