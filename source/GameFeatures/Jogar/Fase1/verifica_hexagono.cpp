#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"
#include <math.h>

using namespace std;

/* verifies the hexagon models */
int verifica_hexagono(int x, int y)
{
	float vx, vy;
	float re=0;
	float x_f = (float) x;
	float y_f = (float) y;

	for (unsigned int i=0;i<hexagons.size();i++) {
		for (unsigned int j=0;j<hexagons[i].size();j++) {
			vx = abs(x_f - hexagons[i][j]->center_in_x);
			vy = abs(y_f - hexagons[i][j]->center_in_y);
			re = (vx*vx)+(vy*vy);
			re = sqrt(re);
			if (re <= 20) {
				hexagon_selected->i = i;
				hexagon_selected->j = j;
				return 1;
			}
			else {
				/* nothing to do */
			}
		}
	}
return 0;
}

/* verifies if theres a unit */
int possui_unidade(string color)
{
	if (hexagons[hexagon_selected->i][hexagon_selected->j]->contains_unit) {
		if (!hexagons[hexagon_selected->i][hexagon_selected->j]->unit->color.compare(color)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

/* verifies the range of moving of a soldier */
int alcance_movimento_soldado()
{
	if ((abs(hexagon_selected->j_before - hexagon_selected->j) <= 1)
		 &&(abs(hexagon_selected->i_before - hexagon_selected -> i)  >0)
		 &&(abs(hexagon_selected->i_before - hexagon_selected->i) < 3)) {
		if ((abs(hexagon_selected->i_before - hexagon_selected->i) == 2)
			 &&(abs(hexagon_selected->j_before - hexagon_selected->j) == 1 )) {
			return 0;
		}
		else {
			/* nothing to do */
		}
		if (hexagons[hexagon_selected->i][hexagon_selected->j]->contains_unit) {
			return 0;
		}
		else {
			/* nothing to do */
		}
		return 1;
	}
	else {
		return 0;
	}


}

/* verifies the range of the soldier's atack */
int alcance_ataque_soldado()
{
	if ((abs(hexagon_selected->j_before - hexagon_selected->j) <= 1)
		 &&(abs(hexagon_selected->i_before - hexagon_selected->i) > 0)
		 &&(abs(hexagon_selected->i_before - hexagon_selected->i) < 3)) {
		if ((abs(hexagon_selected->i_before - hexagon_selected->i) == 2)
			 &&(abs(hexagon_selected->j_before - hexagon_selected->j) == 1 )) {
			return 0;
		}
		else {
			/* nothing to do */
		}

		if (hexagons[hexagon_selected->i][hexagon_selected->j]->contains_unit) {
			Unit *temp1 = hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit;
			Unit *temp2 = hexagons[hexagon_selected->i][hexagon_selected->j]->unit;
			if (temp2->color != temp1->color) {
				return 1;
			}
			else {
				/* nothing to do */
			}
		}
		else {
			/* nothing to do */
		}

		return 0;
	}
	else {
		return 0;
	}

}
