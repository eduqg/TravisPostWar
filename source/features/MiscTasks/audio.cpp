#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../../../include/sound.h"

Mix_Music *musica_selecao_de_estagio;
Mix_Music *musica_fase_1;
Mix_Music *musica_fase_2;
Mix_Music *musica_fase_3;
Mix_Music *musica_fase_4;
Mix_Music *musica_fase_5;
Mix_Chunk *efeito_morte;
Mix_Chunk *efeito_tiro_soldado;
Mix_Chunk *efeito_game_over;
Mix_Chunk *efeito_level_up;
Mix_Chunk *efeito_metralhadora;
Mix_Chunk *efeito_selecao_ok;
Mix_Chunk *efeito_sirene;
Mix_Chunk *efeito_tanque_movendo;

/* inicializa a SDL e SDL_Mix */
void init()
{
	Uint16 audio_format = AUDIO_S16SYS;

	/* initialize SDL_mixer */
	if (Mix_OpenAudio(22050, audio_format, 2, 4096) < 0) {
		printf("Mix_OpenAudio> %s\n", Mix_GetError());
		exit(1);
	}
	atexit(Mix_CloseAudio);
}

/* carrega todos os arquivos (musicas, sons...) */
void carregar()
{
	/* MÚSICAS */
	musica_tela_de_abertura = carregarMus(
	                            "sounds/sound_track/tela_de_abertura.ogg");
	musica_fase_1 = carregarMus("sounds/sound_track/fase_1.ogg");
	musica_creditos = carregarMus("sounds/sound_track/creditos.ogg");

	/*  EFEITOS SONOROS */
	efeito_click = carregarSom("sounds/sounds_effects/click.ogg");
	efeito_selecao_ok  = carregarSom("sounds/sounds_effects/selecao_ok.ogg");
	efeito_selecao_cancelar = carregarSom(
	                           "sounds/sounds_effects/selecao_cancelar.ogg");
	efeito_tiro_soldado = carregarSom("sounds/sounds_effects/tiro_soldado.ogg");
	efeito_metralhadora = carregarSom("sounds/sounds_effects/metralhadora.ogg");
	efeito_morte = carregarSom("sounds/sounds_effects/morte.ogg");
	efeito_explosao = carregarSom("sounds/sounds_effects/explosao.ogg");
}

/* carrega efeito sonoro */
Mix_Chunk *carregarSom(const char *name)
{

	Mix_Chunk *som = Mix_LoadWAV(name);
	if (!som) {
		printf("ERRO CARREGAR EFEITO SONORO> arquivo:'%s'\n", name);
	}
	return som;
}

/* carrega fundo musical */
Mix_Music *carregarMus(const char *name)
{

	Mix_Music *mus = Mix_LoadMUS(name);
	if (!mus) {
		printf("ERRO CARREGAR MUSICA> arquivo:'%s'\n", name);
	}
	return mus;
}

void descarregar()
{
	Mix_FreeMusic(musica_tela_de_abertura);
	Mix_FreeMusic(musica_fase_1);
	Mix_FreeMusic(musica_creditos);
	Mix_FreeChunk(efeito_click);
	Mix_FreeChunk(efeito_selecao_ok);
	Mix_FreeChunk(efeito_selecao_cancelar);
	Mix_FreeChunk(efeito_tiro_soldado);
	Mix_FreeChunk(efeito_metralhadora);
	Mix_FreeChunk(efeito_morte);
	Mix_FreeChunk(efeito_explosao);
}

/* play/pause fundo musical */
void play_music(struct _Mix_Music *nome_da_musica)
{
	if (Mix_PlayMusic(nome_da_musica, -1) == -1) { /* play música */
		printf("ERRO TOCAR MUSICA> Mix_PlayMusic\n");
	}
}

/* - toca um efeito sonoro */
void play_effect(struct Mix_Chunk *nome_do_efeito)
{
	if (Mix_PlayChannel(-1, nome_do_efeito, 0) == -1) {
		printf("ERRO TOCAR EFEITO SONORO> Efeito\n");
	}
}
