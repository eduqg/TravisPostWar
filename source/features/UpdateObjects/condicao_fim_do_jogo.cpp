#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

void verifica_derrota(SDL_Surface *screen)
{
	cout << "Entrei na condicao" << endl;
	Unit *temp;
	string unit_type = "quartel";
	for (unsigned int i = 0; i < hexagons.size(); i++) {
		cout << "andando i: " << i << endl;
		for (unsigned int j = 0; j < hexagons[i].size() ; j++) {
			cout << "andando j: " << j << endl;
			if (hexagons[i][j]->contains_unit == 1) {
				cout << "achei uma unit" << endl;
				temp = hexagons[i][j]->unit;
				cout << "temp unit_type:" << temp->unit_type << endl;
				if (temp->unit_type == unit_type && temp->health_points == 0) {
					string mensagem = "Você perdeu!LOSER!!";
					desenha_texto(mensagem, screen, 50, 50, 60);
				}
				else {
					break;
				}
			}
		}
	}
}
