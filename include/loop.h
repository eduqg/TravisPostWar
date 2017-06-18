#ifndef _LOOP_H
#define _LOOP_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_net.h>
#include <string>

typedef struct _vetormouse {
	int x;
	int y;
	int click;
	int number;
	char* letra;
} Vetor_mouse;

extern void desenha_texto(char *texto,
                          SDL_Surface *dst,
                          int x,
                          int y,
                          int size);
extern Vetor_mouse *get_Input();
extern int compara_selecao(int x_min,
                           int x_max,
                           int x,
                           int y_min,
                           int y_max,
                           int y);
extern void mover_soldado(SDL_Surface *screen, int i, int x, int y);
extern int criar_servidor();
extern void mover_soldado(SDL_Surface *screen,
                          int x,
                          int y,
                          int totalElapsedTime,
                          int delay,
                          int lastdt);
extern int testeaudio(void *);
extern int conectar(char *ip_text);
extern TCPsocket Sclient;
extern TCPsocket Cserver;

#endif
