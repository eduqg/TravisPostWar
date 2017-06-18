#ifndef _SOUND_H
#define _SOUND_H

#include <SDL/SDL.h>
#include <string>

typedef struct _Sound {
	int position;
	Uint8 *buffer;
	int size;
} Sound;

#endif
