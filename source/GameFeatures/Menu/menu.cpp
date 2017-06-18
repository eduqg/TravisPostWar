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

Mix_Music *musica_tela_de_abertura;
Mix_Music *musica_tela_de_opcoes;
Mix_Music *musica_creditos;
Mix_Chunk *efeito_click;
Mix_Chunk *efeito_selecao_cancelar;
int secreto = 0;
int start;
int FPS = 150;

void load_menu(SDL_Surface *screen)
{

	SDL_Surface *jogar_selecionado;
	SDL_Surface *creditos_selecionado;
	SDL_Surface *sair_selecionado;
	SDL_Surface *estatisticas_selecionado;
	SDL_Surface *opcoes_selecionado;

	/* carregando imagens */
	string path_jogo = "source/GameFeatures/Menu/Images/jogar_selecionado.png";
	jogar_selecionado = load_Image(path_jogo, screen);

	string path_estatisticas = "source/GameFeatures/Menu/Images/estatisticas_selecionado.png";
	estatisticas_selecionado = load_Image(path_estatisticas, screen);

	string path_creditos = "source/GameFeatures/Menu/Images/creditos_selecionado.png";
	creditos_selecionado = load_Image(path_creditos, screen);

	string path_sair = "source/GameFeatures/Menu/Images/sair_selecionado.png";
	sair_selecionado = load_Image(path_sair, screen);

	string path_opcoes = "source/GameFeatures/Menu/Images/opcoes_selecionado.png";
	opcoes_selecionado = load_Image(path_opcoes, screen);

	string path = "source/GameFeatures/Menu/Images/menu.png";
	SDL_Surface *menu = load_Image(path, screen);

	string path_easter = "source/GameFeatures/Menu/Images/easter.png";
	SDL_Surface *easter = load_Image(path_easter, screen);

	string breve = "source/GameFeatures/Menu/Images/embreve.png";
	SDL_Surface *embreve = load_Image(breve, screen);

	/* tocando a musica */
	init();
	carregar();
	play_music(musica_tela_de_abertura);

	BlitImage(screen, menu, 0, 0);
	SDL_Flip(screen);
	Vetor_mouse *vetor = new Vetor_mouse;
	start = 0;
	FPS = 150;
	while (1) {
		start = SDL_GetTicks();
		vetor = get_Input();

		/*
		 * cout << "Posicao do mouse ("
		 *      << vetor->x
		 *      << ","
		 *      << vetor->y
		 *      <<")"<<endl;
		 * cout << "Click: " << vetor->click << endl;
		 */

		if (compara_selecao(478.5, 731.5, vetor->x, 211, 275, vetor->y)) {
			BlitImage(screen, menu, 0, 0);
			BlitImage(screen, jogar_selecionado, 478.5, 211);
			SDL_Flip(screen);

			if (vetor->click == 1) {
				play_effect(efeito_click);
				inicio(screen);
			}
		}
		else if (compara_selecao(450,798,vetor->x,311,375,vetor->y)) {
			BlitImage(screen, menu, 0, 0);
			BlitImage(screen, opcoes_selecionado, 450.0, 311);
			frame_delay(start);
			SDL_Flip(screen);
			if (vetor->click == 1) {
				play_effect(efeito_click);
				opcoes(screen);
				BlitImage(screen, menu, 0, 0);
				SDL_Flip(screen);
			}
		}
		else if (compara_selecao(355, 798,vetor->x, 417, 475, vetor->y)) {
			BlitImage(screen, menu, 0, 0);
			BlitImage(screen, estatisticas_selecionado, 355.0, 411);
			frame_delay(start);
			SDL_Flip(screen);

			if (vetor->click == 1) {
				play_effect(efeito_click);
				secreto++;

				if (secreto == 1) {
					BlitImage(screen, embreve, 478, 211);
					SDL_Flip(screen);
					SDL_Delay(1000);
				}

				if (secreto == 10) {
					BlitImage(screen, easter, 478, 211);
					SDL_Flip(screen);
					SDL_Delay(2000);
					secreto = 0;
				}
			}
		}
		else if (compara_selecao(425, 798, vetor->x, 511, 575, vetor->y)) {
			BlitImage(screen, menu, 0, 0);
			BlitImage(screen, creditos_selecionado, 425.0, 511);
			frame_delay(start);
			SDL_Flip(screen);

			if (vetor->click == 1) {
				play_effect(efeito_click);
				Mix_HaltMusic();
				creditos(screen);
			}
		}
		else if (compara_selecao(350, 798, vetor->x, 611, 675, vetor->y)) {
			BlitImage(screen, menu, 0, 0);
			BlitImage(screen, sair_selecionado, 350.0, 611);
			frame_delay(start);
			SDL_Flip(screen);

			if (vetor->click == 1) {
				Mix_VolumeChunk(efeito_selecao_cancelar, 20);
				play_effect(efeito_selecao_cancelar);
				SDL_Delay(500);
				descarregar();
				Mix_CloseAudio();
				SDL_Quit();
				exit(0);
			}
		}
		/* SDL_Delay(10); */
		frame_delay(start);
	}
}

void clica_menu_menor(SDL_Surface *screen)
{
	BlitImage(screen, menu_menor, 488, 200);
	SDL_Flip(screen);
	int start = 0;
	Vetor_mouse *vetor = new Vetor_mouse();
	while (1) {
		vetor = get_Input();
		start = SDL_GetTicks();
		if (compara_selecao(500, 771, vetor->x, 225, 271, vetor->y)) {
			BlitImage(screen, menu_menor, 488, 200);
			BlitImage(screen, voltar_jogo_sel, 500, 225);
			SDL_Flip(screen);
			if (vetor->click == 1) {
				blit_tela(screen, 0);
				frame_delay(start);
				break;
			}
		}
		else if (compara_selecao(553, 642, vetor->x, 283, 310, vetor->y)) {
			BlitImage(screen, menu_menor, 488, 200);
			BlitImage(screen, opcoes_sel, 553, 280);
			SDL_Flip(screen);
			if (vetor->click == 1) {
				opcoes(screen);
			}
		}
		else if (compara_selecao(570, 646, vetor->x, 338, 373, vetor->y)) {
			BlitImage(screen, menu_menor, 488, 200);
			BlitImage(screen, sair_sel, 570, 338);
			SDL_Flip(screen);
			if (vetor->click == 1) {
				load_menu(screen);
				/* saiu_jogo=1; */
			}
		}
		frame_delay(start);
	}
	SDL_Flip(screen);
}

void frame_delay(int start)
{
	if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000 / FPS)) {
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - start));
	}
}
