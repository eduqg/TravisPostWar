#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <string>

void callback(void *userdata, Uint8 *audio, int length)
{
	memset(audio, 0, length);

	Sound *sound = (Sound *) userdata;

	if (sound->position == -1 || sound->position >= sound->size) {
		return;
	}

	int nextSamplesLength;

	if (sound->position + length > sound->size) {
		nextSamplesLength =  sound->size - sound->position;
	}
	else {
		nextSamplesLength = length;
	}

	SDL_MixAudio(audio,
	             sound->buffer + sound->position,
	             nextSamplesLength,
	             SDL_MIX_MAXVOLUME / 2);

	sound->position += nextSamplesLength;
}
