#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

using namespace std;

void opcoes(SDL_Surface *screen)
{

	string tela = "source/GameFeatures/Opcoes/Images/fundo_opcoesMenu.png";
	SDL_Surface *telafundo = load_Image(tela, screen);
	string barra_volume = "source/GameFeatures/Opcoes/Images/barra_arte.png";
	SDL_Surface *imagemBarra = load_Image(barra_volume, screen);


	BlitImage(screen, telafundo, 0, 0);
	Vetor_mouse *vetor = new Vetor_mouse;
	int Mix_Volume(int channel, int volume2);
	/* int Mix_VolumeMusic(int volume2); */
	start = 0;
	float volume_menos = 5;
	float volume_mais = 5;
	int volume = 0;
	int volume2 = 128;

	while (1) {

		start = SDL_GetTicks();
		vetor = get_Input();

		if (volume_mais) {
			BlitImage(screen, imagemBarra, 750- (volume * 10), 343);
		}
		else if (volume_menos) {
			BlitImage(screen, imagemBarra, 750+ (volume * 10), 343);
		}

		/* botao X da tela */
		if (compara_selecao(792, 822, vetor->x, 296, 324, vetor->y)) {
			if (vetor->click == 1) {
				Mix_VolumeChunk(efeito_selecao_cancelar, 20);
				play_effect(efeito_selecao_cancelar);
				SDL_Delay(250);
				break;
			}
		}
		//Botao - do volume
		else if (compara_selecao(486, 506, vetor->x, 356, 378, vetor->y)) {
			if (vetor->click == 1) {
				play_effect(efeito_click);
				/* set the music volume to 1/2 maximum, and then check it */
				/* printf("volume was : %d\n", Mix_VolumeMusic(128-volume_menos)); */
				/* printf("volume is now : %d\n", Mix_VolumeMusic(-1)); */
				volume2 = volume2 - 5;
				Mix_Volume(-1, volume2);
				Mix_VolumeMusic(volume2);
				/* printf("volume is now : %d\n", Mix_Volume(0, volume2)); */
				/* volume_menos = volume_menos + 5; */
				volume++;
				BlitImage(screen, telafundo, 0, 0);

			}
		}
		//Botao + do volume
		else if (compara_selecao(801, 821, vetor->x, 356, 378, vetor->y)) {
			if (vetor->click == 1) {
				play_effect(efeito_click);
				/* set the music volume to 1/2 maximum, and then check it */
				/* printf("volume was : %d\n", Mix_VolumeMusic(Mix_VolumeMusic(-1)+5)); */
				/* printf("volume is now : %d\n", Mix_VolumeMusic(-1)); */
				volume2 = volume2 + 5;
				Mix_Volume(-1, volume2);
				Mix_VolumeMusic(volume2);
				/* printf("volume is now : %d\n", Mix_Volume(0, volume2)); */
				/* volume_menos = volume_menos - 5; */
				volume--;
				BlitImage(screen, telafundo, 0, 0);
			}
		}

		frame_delay(start);
		SDL_Flip(screen);
	}
}
