#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

using namespace std;

SDL_Surface *botao_sair;
int saiu_creditos;

void RunImage(SDL_Surface *screen1, SDL_Surface *screen2, SDL_Surface *screen3)
{
	if (saiu_creditos == 0) {
		Vetor_mouse *vetor = new Vetor_mouse;
		for (int j = 680; j >= -680; j-=2) {
			vetor = get_Input();
			if (vetor->number == 39) {
				saiu_creditos = 1;
				break;
			}
			else if (compara_selecao(46, 77, vetor->x, 38, 76, vetor->y)) {
				saiu_creditos = 1;
				break;
			}

			BlitImage(screen1, screen3, 0, 0);
			BlitImage(screen1, screen2, 0, j);
			BlitImage(screen1, botao_sair, 46, 38);
			SDL_Flip(screen1);
			SDL_Delay(20);
		}
	}
	else {
		/* nothing to do */
	}
}



void creditos(SDL_Surface *screen)
{
	saiu_creditos = 0;
	string tela = "source/GameFeatures/Creditos/Images/fundo_creditos.png";
	SDL_Surface *telapreta = load_Image(tela, screen);
	string imagem_bryj = "source/GameFeatures/Creditos/Images/logo_postwar.png";
	SDL_Surface *bryj = load_Image(imagem_bryj, screen);
	string imagem_sdl = "source/GameFeatures/Creditos/Images/sdl_logo.png";
	SDL_Surface *sdl = load_Image(imagem_sdl, screen);
	string imagem_ubuntu = "source/GameFeatures/Creditos/Images/ubuntu_logo.png";
	SDL_Surface *ubuntu = load_Image(imagem_ubuntu, screen);
	string imagem_16 = "source/GameFeatures/Creditos/Images/nome_jogo.png";
	SDL_Surface *jogo_nome = load_Image(imagem_16, screen);
	string creditos_path = "source/GameFeatures/Creditos/Images/nome_creditos.png";
	SDL_Surface *creditos = load_Image(creditos_path, screen);
	string creditos_path1 = "source/GameFeatures/Creditos/Images/nome_creditos1.png";
	SDL_Surface *creditos1 = load_Image(creditos_path1, screen);
	string creditos_path2 = "source/GameFeatures/Creditos/Images/nome_creditos2.png";
	SDL_Surface *creditos2 = load_Image(creditos_path2, screen);
	string creditos_path3 = "source/GameFeatures/Creditos/Images/nome_creditos3.png";
	SDL_Surface *creditos3 = load_Image(creditos_path3, screen);
	string creditos_path4 = "source/GameFeatures/Creditos/Images/nome_creditos4.png";
	SDL_Surface *creditos4 = load_Image(creditos_path4, screen);
	string credito = "source/GameFeatures/Creditos/Images/botaoDeSair.png";
	botao_sair = load_Image(credito, screen);

	SDL_Flip(screen);

	play_music(musica_creditos);

	RunImage(screen, creditos, telapreta);
	RunImage(screen, creditos1, telapreta);
	RunImage(screen, creditos2, telapreta);
	RunImage(screen, creditos3, telapreta);
	RunImage(screen, creditos4, telapreta);
	RunImage(screen, bryj, telapreta);
	RunImage(screen, sdl, telapreta);
	RunImage(screen, ubuntu, telapreta);
	RunImage(screen, jogo_nome, telapreta);

	descarregar();
	Mix_HaltMusic();
	Mix_CloseAudio();
	load_menu(screen);
}
