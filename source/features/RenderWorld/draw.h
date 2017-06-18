/*
 * Autor: Edson Alves
 * Data: 24/12/2012
 * e-mail: edsonalves@unb.br
 */
#ifndef DRAW_H
#define DRAW_H
#include <string>
#include <SDL/SDL.h>

using namespace std;

extern Uint32 getPixel(SDL_Surface *surface, int x, int y);
extern void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
extern void drawCircle(SDL_Surface *screen, int radius, int x, int y,
	SDL_Color color);
extern void drawLine(SDL_Surface *screen, int x0, int y0, int x1, int y1,
	SDL_Color color);

extern void load_Image(string path, SDL_Surface *screen);
extern void drawYouLose(SDL_Surface *screen);
extern void drawYouWin(SDL_Surface *screen);
extern void drawBackground(SDL_Surface *screen);
extern void drawBoard(SDL_Surface *screen);
extern void drawY(SDL_Surface *screen);
extern void drawO(SDL_Surface *screen);
extern void drawU(SDL_Surface *screen);
extern void drawL(SDL_Surface *screen);
extern void drawO2(SDL_Surface *screen);
extern void drawS(SDL_Surface *screen);
extern void drawE(SDL_Surface *screen);
extern void drawW(SDL_Surface *screen);
extern void drawI(SDL_Surface *screen);
extern void drawN(SDL_Surface *screen);

#endif
