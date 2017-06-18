#include <iostream>

using namespace std;
int compara_selecao(int x_min, int x_max, int x, int y_min, int y_max, int y)
{
	if (x >= x_min && x <= x_max && y >= y_min && y<= y_max) {
		return 1;
	}
	else {
		return 0;
	}
}
