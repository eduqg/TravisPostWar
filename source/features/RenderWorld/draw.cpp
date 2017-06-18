/*
 * Autor: Edson Alves
 * Data: 24/12/2012
 * e-mail: edsonalves@unb.br
 */
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include "draw.h"

using namespace std;

/* função retirada da implementação da SDL */
Uint32 getPixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp) {
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				return p[0] << 16 | p[1] << 8 | p[2];
			}
			else {
				return p[0] | p[1] << 8 | p[2] << 16;
			}

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;
	}
}

/* função retirada da implementação da SDL */
void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp) {
		case 1:
			*p = pixel;
			break;
		case 2:
			*(Uint16 *)p = pixel;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *)p = pixel;
			break;
	}
}

void drawYouLose(SDL_Surface *screen)
{
	drawBackground(screen);
	drawY(screen);
	drawO(screen);
	drawU(screen);
	drawL(screen);
	drawO2(screen);
	drawS(screen);
	drawE(screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}

void drawYouWin(SDL_Surface *screen)
{
	drawBackground(screen);
	drawY(screen);
	drawO(screen);
	drawU(screen);
	drawW(screen);
	drawI(screen);
	drawN(screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}

void drawBackground(SDL_Surface *screen)
{
	SDL_Color white;
	white.r = white.g = white.b = 255;

	Uint32 whitePixel = SDL_MapRGB(screen->format, white.r, white.g, white.b);

	SDL_FillRect(screen, NULL, whitePixel);
}

void drawBoard(SDL_Surface *screen)
{
	SDL_Color black;
	black.r = black.g = black.b = 0;

	SDL_PixelFormat *format = screen->format;
	Uint32 blackPixel = SDL_MapRGB(format, black.r, black.g, black.b);

	SDL_Rect verticalBar;
	verticalBar.x = 235;
	verticalBar.y = 15;
	verticalBar.w = 15;
	verticalBar.h = 690;

	SDL_FillRect(screen, &verticalBar, blackPixel);

	verticalBar.x += 235;
	SDL_FillRect(screen, &verticalBar, blackPixel);

	SDL_Rect horizontalBar;
	horizontalBar.x = 15;
	horizontalBar.y = 235;
	horizontalBar.w = 690;
	horizontalBar.h = 15;

	SDL_FillRect(screen, &horizontalBar, blackPixel);

	horizontalBar.y += 235;
	SDL_FillRect(screen, &horizontalBar, blackPixel);
}

void drawY(SDL_Surface *screen)
{
	SDL_Color blue;
	blue.b = blue.g = 0;
	blue.r = 255;

	for (int i = 0; i < 30; i++) {
		drawLine(screen, 50 + i, 40, 115 + i, 115, blue);
		drawLine(screen, 115 + i, 115, 180 + i, 40, blue);
		drawLine(screen, 115+i, 115, 115+i, 180, blue);
	}
}

void drawO(SDL_Surface *screen)
{
	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	drawCircle(screen, 70, 250, 110, blue);
	drawCircle(screen, 50, 250, 110, white);
}

void drawU(SDL_Surface *screen)
{
	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	for (int i = 0; i < 30; i++) {
		drawLine(screen, 330 + i, 40, 330 + i, 120, blue);
	}

	drawCircle(screen, 60, 390, 120, blue);
	drawCircle(screen, 30, 390, 120, white);

	for (int i = 0; i < 100; i++) {
		drawLine(screen, 360+ i,120, 360 + i, 40, white);
		drawLine(screen, 390+ i,120, 390 + i, 40, white);
	}

	for (int i = 0; i < 30; i++) {
		drawLine(screen, 421 + i, 120, 421 + i, 40, blue);
	}
}

void drawL(SDL_Surface *screen)
{

	SDL_Color blue;
	blue.b = blue.g = 0;
	blue.r = 255;

	for (int i = 0; i < 30; i++) {

		drawLine(screen, 510 + i, 40, 510 + i, 180, blue);
		drawLine(screen, 540, 150 + i, 610, 150 + i, blue);

	}
}

void drawO2(SDL_Surface *screen)
{

	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	drawCircle(screen, 70, 680, 110, blue);
	drawCircle(screen, 50, 680, 110, white);
}

void drawS(SDL_Surface *screen)
{

	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;

	for (int i = 0; i < 30; i++) {

		drawLine(screen,780, 40 + i, 900, 40 + i, blue);
		drawLine(screen,780 + i, 40, 780 + i, 100, blue);
		drawLine(screen,780, 100 + i, 900, 100 + i, blue);
		drawLine(screen,870 + i, 130, 870 + i, 180, blue);
		drawLine(screen,870 + i, 130, 870 + i, 180, blue);
		drawLine(screen,780, 150 + i, 900, 150 + i, blue);

	}
}

void drawE(SDL_Surface *screen)
{

	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;

	for (int i = 0; i < 30; i++) {
		drawLine(screen,930, 40 + i, 1050, 40 + i, blue);
		drawLine(screen,930 + i, 40, 930 + i, 180, blue);
		drawLine(screen,930, 100 + i, 1000, 100 + i, blue);
		drawLine(screen,930, 150 + i, 1050, 150 + i, blue);

	}

}

void drawW(SDL_Surface *screen)
{
	SDL_Color red;
	red.g = red.b = 0;
	red.r = 255;
	for (int i = 0; i < 35; i++) {
		drawLine(screen, 550 + i, 17, 550 + i, 197, red);
		drawLine(screen, 685 + i, 17, 685 + i, 197, red);
		drawLine(screen, 620 + i, 107, 675 + i, 197, red);
		drawLine(screen, 550 + i, 197, 620 + i, 107, red);

	}

}

void drawI(SDL_Surface *screen)
{
	SDL_Color red;
	red.b = red.g = 0;
	red.r = 255;
	for(int i = 0; i < 35; i++) {
		drawLine(screen, 725 + i, 17, 725 + i, 197, red);
	}
}

void drawN(SDL_Surface *screen)
{
	SDL_Color red;
	red.b = red.g = 0;
	red.r = 255;
	for(int i = 0; i < 35; i++){
		drawLine(screen, 765 + i, 17, 765 + i, 197, red);
		drawLine(screen, 855 + i, 17, 855 + i, 197, red);
		drawLine(screen, 765 + i, 17, 855 + i, 197, red);
	}
}

void fillPoints(SDL_Surface *screen, int cx, int cy, int x, int y, Uint32 color)
{
	for (int j = x; j <= y; j++) {
		putPixel(screen, cx + x, cy + j, color);
		putPixel(screen, cx + x, cy - j, color);
		putPixel(screen, cx - x, cy + j, color);
		putPixel(screen, cx - x, cy - j, color);
		putPixel(screen, cx + j, cy + x, color);
		putPixel(screen, cx + j, cy - x, color);
		putPixel(screen, cx - j, cy + x, color);
		putPixel(screen, cx - j, cy - x, color);
	}
}

void drawCircle(SDL_Surface *screen, int radius, int x, int y, SDL_Color color)
{
	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

	/* algoritmo de Bresenham para círculos */
	int error = 3 - (radius << 1);
	int i = 0, j = radius;

	do {
		fillPoints(screen, x, y, i, j, pixelColor);

		if (error < 0) {
			error += (i << 2) + 6;
		} else {
			error += ((i - j) << 2) + 10;
			j--;
		}

		i++;
	} while (i <= j);

}

void drawLine(SDL_Surface *screen,
			  int x1,
			  int y1,
			  int x2,
			  int y2,
			  SDL_Color color)
{
	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

	/* bresenham's line algorithm */
	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if (steep) {
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;

	const int maxX = (int)x2;

	for (int x = (int)x1; x<maxX; x++) {
		if (steep) {
			putPixel(screen, y, x, pixelColor);
		}
		else {
			putPixel(screen, x, y, pixelColor);
		}
		error -= dy;

		if (error < 0) {
			y += ystep;
			error += dx;
		}
	}
}
