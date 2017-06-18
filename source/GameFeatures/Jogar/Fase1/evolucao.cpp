#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

SDL_Surface *screen;
SDL_Surface *nome1;

/* describes the soldier evolution */
void evolucao_soldado(Nation *pais)
{
	pais->gold_coins -= 30;
	if (pais->gold_coins < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->minerals -= 50;
	if (pais->minerals < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->food -= 20;
	if (pais->food <0) {
		return;
	}
	else {
		/* nothing to do */
	}
	for (unsigned int i=0;i<hexagons.size();i++) {
		for (unsigned int j=0;j<hexagons[i].size();j++) {
			if (hexagons[i][j]->contains_unit==1) {
				if (hexagons[i][j]->unit->color == pais->color) {
					if (hexagons[i][j]->unit->unit_type == "soldado") {
						hexagons[i][j]->unit->health_points = 250;
						hexagons[i][j]->unit->attack_points = 150;
						hexagons[i][j]->unit->deffense_points = 150;
					}
					else {
						/* nothing to do */
					}
				}
				else {
					/* nothing to do */
				}
			}
			else {
				/* nothing to do */
			}
		}
	}
}

/* describes the evolution of the quartel */
void evolucao_quartel(Nation *pais)
{
	pais->gold_coins -= 50;
	if (pais->gold_coins < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->minerals -= 50;
	if (pais->minerals < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->food -= 40;
	if (pais->food <0) {
		return;
	}
	else {
		/* nothing to do */
	}
	for (unsigned int i=0;i<hexagons.size();i++) {
		for (unsigned int j=0;j<hexagons[i].size();j++) {
			if (hexagons[i][j]->contains_unit==1) {
				if (hexagons[i][j]->unit->color == pais->color) {
					if (hexagons[i][j]->unit->unit_type == "quartel") {
						if (hexagons[i][j]->unit->color == "azul") {
							string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_quartel_azul.png";
							nome1 = load_Image(caminho, screen);
						}
						else {
							string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_quartel_vermelho.png";
							nome1 = load_Image(caminho, screen);
						}
						hexagons[i][j]->unit->health_points = 1250;
						hexagons[i][j]->unit->attack_points = 0;
						hexagons[i][j]->unit->deffense_points = 500;
						hexagons[i][j]->unit->name = nome1;
					}
					else {
					   /* nothing to do */
					}
				}
				else {
				   /* nothing to do */
				}
			}
			else {
			   /* nothing to do */
			}
		}
	}
}
