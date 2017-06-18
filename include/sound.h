#ifndef _SOUND_H
#define _SOUND_H

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

extern void criaMusicas();
extern void init();
extern void carregar();
extern Mix_Chunk *carregarSom(const char *name);
extern Mix_Music *carregarMus(const char *name);
extern void descarregar();
extern void play_music(struct _Mix_Music *nome_da_musica);
extern void play_effect(struct Mix_Chunk *nome_do_efeito);

extern Mix_Music *musica_tela_de_abertura;
extern Mix_Music *musica_tela_de_opcoes;
extern Mix_Music *musica_selecao_de_estagio;
extern Mix_Music *musica_fase_1;
extern Mix_Music *musica_fase_2;
extern Mix_Music *musica_fase_3;
extern Mix_Music *musica_fase_4;
extern Mix_Music *musica_fase_5;
extern Mix_Music *musica_creditos;
extern Mix_Chunk *efeito_morte;
extern Mix_Chunk *efeito_click;
extern Mix_Chunk *efeito_tiro_soldado;
extern Mix_Chunk *efeito_explosao;
extern Mix_Chunk *efeito_game_over;
extern Mix_Chunk *efeito_level_up;
extern Mix_Chunk *efeito_metralhadora;
extern Mix_Chunk *efeito_selecao_ok;
extern Mix_Chunk *efeito_selecao_cancelar;
extern Mix_Chunk *efeito_sirene;
extern Mix_Chunk *efeito_tanque_movendo;

#endif
