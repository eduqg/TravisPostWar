#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../include/draw.h"
#include "../../include/video.h"
#include "../../include/loop.h"
#include "../../include/gamefeatures.h"

using namespace std;

void blit_tela(SDL_Surface *screen, int tela)
{
	if (tela == 0) {
		BlitImage(screen, without_mesh, 0, 0);
	}
	else {
		BlitImage(screen, with_mesh, 0, 0);
	}
	BlitImage(screen, heads_up_display, 0, 0);
	BlitImage(screen, menu_meio, 568, 78);
	/*
	 * string bora;
	 * string bora1;
	 * for (int i = 0; i < hexagons.size(); i++) {
	 *		for (int j = 0; j < hexagons[i].size(); j++) {
	 *			int start4 = SDL_GetTicks();
	 *			bora[0] += i;
	 *			bora1[0] += j;
	 *			cout << "bora: " << bora1 << endl;
	 *			desenha_texto(bora,
	 *                        screen,
	 *                        hexagons[i][j]->x,
	 *                        hexagons[i][j]->y,
	 *                        20);
	 *			desenha_texto(bora1,
	 *                        screen,
	 *                        hexagons[i][j]->x + 10,
	 *                        hexagons[i][j]->y,
	 *                        20);
	 *			bora = "0";
	 *			bora1 = "0";
	 *			frame_delay(start4);
	 *		}
	 *  }
	 */

	/*
	 * int i_menor;
	 * int j_menor;
	 * Unit *unit;
	 * int aux=0;
	 */
	for (unsigned int i = 0; i < hexagons.size(); i++) {
		for (unsigned int j=0; j<hexagons[i].size(); j++) {
			if (hexagons[i][j]->contains_unit == 1) {
				if (hexagons[i][j]->unit->unit_type == "soldado" ||
				    hexagons[i][j]->unit->unit_type == "helicoptero" ||
				    hexagons[i][j]->unit->unit_type == "tanque")
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagons[i][j]->x;
					dst.y = hexagons[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					SDL_BlitSurface(hexagons[i][j]->unit->name,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagons[i][j]->unit->unit_type == "quartel" &&
				        hexagons[i][j]->unit->color == "vermelho")
				{
					BlitImage(screen,
					          hexagons[6][1]->unit->name,
					          hexagons[6][1]->x,
					          hexagons[6][1]->y);
				}
				else if (hexagons[i][j]->unit->unit_type == "quartel" &&
				         hexagons[i][j]->unit->color == "azul")
				{
					BlitImage(screen,
					          hexagons[7][13]->unit->name,
					          hexagons[7][13]->x,
					          hexagons[7][13]->y);
				}
				else {
					if (hexagons[6][4]->contains_unit) {
						BlitImage(screen,hexagons[6][4]->unit->name,
						          hexagons[6][4]->x,
						          hexagons[6][4]->y);
					}
					//BlitImage(screen,hexagons[14][12]->unit->name,hexagons[14][12]->x,hexagons[14][12]->y);
					if (hexagons[10][12]->contains_unit) {
						BlitImage(screen,hexagons[10][12]->unit->name,
						          hexagons[10][12]->x,
						          hexagons[10][12]->y);
					}
					if (hexagons[2][13]->contains_unit) {
						BlitImage(screen,hexagons[2][13]->unit->name,
						          hexagons[2][13]->x,
						          hexagons[2][13]->y);
					}
				}
			}
			//BlitImage(screen, hexagons[2][8]->building->name, hexagons[2][8]->x, hexagons[2][8]->y);
		}
	}
}

void blit_tela_ataque(SDL_Surface *screen, int tela, int id, int x, int y)
{
	/*
	 * cout << "ENTREI BLIT ATAQUE" << endl;
	 * cout << "FUNCAO BLITE ATAQUE:" << endl;
	 * cout << "x:" << x << endl;
	 * cout << "y:" << y << endl;
	 */
	if (tela == 0) {
		BlitImage(screen, without_mesh, 0, 0);
	}
	else {
		BlitImage(screen, with_mesh, 0, 0);
	}

	BlitImage(screen, heads_up_display, 0, 0);

	for (unsigned int i = 0; i < hexagons.size(); i++) {
		for (unsigned int j = 0; j < hexagons[i].size(); j++) {

			if (hexagons[i][j]->contains_unit == 1) {
				/*
				 * cout << "foi, i: " << i << "j: " << j << endl;
				 * cout << "cheguei aqui" << endl;
				 * cout << "unit ID:"
				 *		<<	hexagons[i][j]->unit->id
				 *		<<	endl;
				 * cout << "x e y aponta para:"
				 *      << hexagons[x][y]->unit
				 *      << endl;
				 * cout << "unit unit_type:"
				 *      << hexagons[hexagon_selected->i_before]
				 *      			[hexagon_selected->j_before]->unit->unit_type
				 *      << endl;
				 */
				if (hexagons[i][j]->unit->id == id) {
					/* cout << "entrei if" << endl; */
					int w = hexagons[hexagon_selected->i_before]
					                 [hexagon_selected->j_before]->unit->x;
					int s = hexagons[hexagon_selected->i_before]
					                 [hexagon_selected->j_before]->unit->y;
					Unit *temp;
					temp = hexagons[hexagon_selected->i_before]
					                [hexagon_selected->j_before]->unit;
					/* cout << "temp:" << temp->unit_type << endl; */
					SDL_Surface *temp_s;
					string color = "vermelho";
					string cor2 = "azul";
					string unit_type = "metralhadora";
					string tipo2 = "soldado";
					string tipo3 = "helicoptero";
					string tipo4 = "tanque";
					/* cout << "color da unit atual:" << temp->color << endl; */
					/* cout << "Tipo unit atual:" << temp->unit_type << endl; */

					SDL_Rect cutBox = {0, 0, 32, 32};
					/* acha tanque azul */
					if (temp->unit_type == tipo4 && temp->color == cor2) {
						if (s < y && w == x) {
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha tanque vermelho */
					if (temp->unit_type == tipo4 && temp->color == color) {
						if (s < y && w == x){
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha helicoptero vermelho */
					if (temp->unit_type == tipo3 && temp->color == color) {
					/* por enquanto nunca vai achar, hu3 */
					}
					/* acha helicoptero azul */
					if (temp->unit_type == tipo3 && temp->color == cor2) {
						if (s < y && w == x) {
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						SDL_Rect dst = {(Sint16)w, (Sint16)s, 0, 0};
						SDL_BlitSurface(temp_s, &cutBox,  screen, &dst);

					}

				}

				if ((hexagons[i][j]->unit->unit_type == "soldado" ||
				      hexagons[i][j]->unit->unit_type == "helicoptero" ||
				      hexagons[i][j]->unit->unit_type == "tanque") &&
				 	 (hexagons[i][j]->unit->id != id))
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagons[i][j]->x;
					dst.y = hexagons[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					/* cout << "fiz isso i " << i << endl; */

					SDL_BlitSurface(hexagons[i][j]->unit->name,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagons[i][j]->unit->unit_type == "quartel" &&
				         hexagons[i][j]->unit->color == "vermelho")
				{
					BlitImage(screen,
					          hexagons[6][1]->unit->name,
					          hexagons[6][1]->x,
					          hexagons[6][1]->y);
				}
				else if (hexagons[i][j]->unit->unit_type == "quartel" &&
				         hexagons[i][j]->unit->color == "azul")
				{
					if (hexagons[7][13]->contains_unit) {
						BlitImage(screen,
						          hexagons[7][13]->unit->name,
						          hexagons[7][13]->x,
						          hexagons[7][13]->y);
					}
				}
				else {
					if (hexagons[6][4]->contains_unit) {
						BlitImage(screen,
						          hexagons[6][4]->unit->name,
						          hexagons[6][4]->x,
						          hexagons[6][4]->y);
					}
					//BlitImage(screen,hexagons[14][12]->unit->name,hexagons[14][12]->x,hexagons[14][12]->y);
					if (hexagons[10][12]->contains_unit) {
						BlitImage(screen,
						          hexagons[10][12]->unit->name,
						          hexagons[10][12]->x,
						          hexagons[10][12]->y);
					}
				}



				/*
				 * else if (hexagons[i][j]->unit->unit_type == "quartel") {
				 *     BlitImage(screen,
				 *	             hexagons[6][1]->unit->name,
				 *	             hexagons[6][1]->x,
				 *	             hexagons[6][1]->y);
				 * }
				 *
				 * // Lógica mágica para dar blit na metralhadora
				 * else {
				 *	   if (aux == 0){
				 *	       aux = 1;
				 *		   unit = hexagons[i][j]->unit;
				 *		   i_menor = i;
				 *		   j_menor = j;
				 *		   BlitImage(screen,
				 *		             hexagons[i][j]->unit->name,
				 *		             hexagons[i][j]->x,
				 *		             hexagons[i][j]->y);
				 *	    }
				 * }
				 */
			}
		}
	}
}
