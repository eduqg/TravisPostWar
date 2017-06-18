#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

/* load the level 2 sprites */
void fase2(SDL_Surface *screen,string qual_maquina)
{
	FPS = 150;
	Nation *franca = new Nation();
	string name = "França";
	string color = "vermelho";
	setar_pais(franca, 50, 50, 100, name, color);
	Nation *uk = new Nation();
	name = "UK";
	color = "azul";
	setar_pais(uk, 100, 40, 50, name, color);

	char pais_serv[100] = "franca";
	char pais_client[100] = "uk";

	carregar_fase2(screen);
	int lastdt = SDL_GetTicks();
	int totalElapsedTime = 0;
	int delay = 200;

	int minha_vez;

	Vetor_mouse *vetor = new Vetor_mouse();
	blit_tela(screen,0);
	SDL_Flip(screen);

	int start1 =0;
	if (qual_maquina.compare("cliente")) {
		minha_vez=1;
		while (1) {
			start = SDL_GetTicks();
			if (minha_vez) {
				blit_cima(franca,screen); //verifica_hexagono.cpp
				desenha_pontos(pontos_jogador1, screen); //fase1.cpp
				vetor = get_Input();
				string palavra = "Sua vez.";
				red = 255;
				green = 0;
				blue = 0;
				desenha_texto(palavra,screen,850, 38, 35);
				if (vetor->click == 1) {
					if (compara_selecao(568,647,vetor->x,78,111,vetor->y)) {
						clica_menu_menor(screen);
					}
					else {
						/* nothing to do */
					}
					if (verifica_hexagono(vetor->x,vetor->y)) {
						hexagon_selected->i_before = hexagon_selected->i;
						hexagon_selected->j_before = hexagon_selected->j;
						if (possui_unidade("vermelho")) {
							blit_tela(screen,1);
							blit_selecao(screen);
							blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
							blit_cima(franca,screen);
							while (1) {
								start1 = SDL_GetTicks();
								vetor = get_Input();
								if (vetor->click == 1) {
									verifica_hexagono(vetor->x,vetor->y);
									if (possui_unidade("vermelho")
										|| (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier
										&& hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type
										!= "helicoptero")) {
										break;
									}
									else {
										/* nothing to do */
									}
									if (alcance_ataque_soldado()) {
										codifica_ataque(code_s);
										enviar_msg(Sclient,code_s);
										ataque_unidade(screen,
													   hexagons[hexagon_selected->i][hexagon_selected->j]->x,
													   hexagons[hexagon_selected->i][hexagon_selected->j]->y,
													   totalElapsedTime,
													   delay,
													   lastdt);
										dano_ataque(screen);
										if (derrotado.compare(cor1) == 0) {
											vermelhoperde = 1;
											vermelhoganha = 0;
											azulganha = 1;
											azulperde = 0;
										}
										else {
											/* nothing to do */
										}
										if (derrotado.compare(cor2) == 0) {
											azulperde = 1;
											azulganha = 0;
											vermelhoganha = 1;
											vermelhoperde = 0;
										}
										else {
											/* nothing to do */
										}
										pontos_jogador1 -= 6;
										if (pontos_jogador1 < 3) {
											minha_vez = 0;
											pontos_jogador1 = 20;
										}
										else {
											/* nothing to do */
										}
										if (vermelhoperde == 1 && azulganha == 1) {
											perdeu_jogo(screen);
										}
										else {
											/* nothing to do */
										}
										if (azulganha == 1 && vermelhoganha == 1) {
											venceu_jogo(screen);
										}
										else {
											/* nothing to do */
										}
										break;
									}
									else {
										/* nothing to do */
									}
									if (alcance_movimento_soldado()) {
										strcpy (code_s,"00");
										code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
										code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
										code_s[4] = (char)(((int)'0')+hexagon_selected->i);
										code_s[5] = (char)(((int)'0')+hexagon_selected->j);
										enviar_msg(Sclient,code_s);
										mover_soldado(screen,
													  hexagons[hexagon_selected->i][hexagon_selected->j]->x,
													  hexagons[hexagon_selected->i][hexagon_selected->j]->y,
													  totalElapsedTime,
													  delay,
													  lastdt);
										pontos_jogador1 -= 3;
										if (pontos_jogador1 < 3) {
											minha_vez = 0;
											pontos_jogador1 = 20;
											coleta_minerio(franca, minerio_vermelho);
											coleta_ouro(franca, ouro_vermelho);
											coleta_comida(franca, comida_vermelha);
										}
										else {
											/* nothing to do */
										}
										break;
									}
									else {
										blit_tela(screen,0);
										blit_cima(franca,screen);
										break;
									}
								}
								else {
									/* nothing to do */
								}
								if ((unsigned)(SDL_GetTicks() - start1) < (unsigned)(1000/FPS)) {
									SDL_Delay((1000/FPS) - (SDL_GetTicks() - start1));
								}
								else {
									/* nothing to do */
								}
							}
						}
						else {
							/* nothing to do */
						}
						blit_tela(screen,0);
						blit_cima(franca,screen);
					}
					else {
						/* nothing to do */
					}
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor1) == 0) {
					vermelhoperde = 1;
					vermelhoganha = 0;
					azulganha = 1;
					azulperde = 0;
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor2) == 0) {
					azulperde = 1;
					azulganha = 0;
					vermelhoganha = 1;
					vermelhoperde = 0;
				}
				else {
					/* nothing to do */
				}
				if (azulganha == 1 && vermelhoperde == 1) {
					perdeu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if (vermelhoganha == 1 && azulperde == 1) {
					venceu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)) {
					SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
				}
				else {
					/* nothing to do */
				}
				frame_delay(start);
				SDL_Flip(screen);
			}
			else {
				blit_cima(franca,screen);
				string palavra = "Vez do outro jogador.";
				blit_tela(screen,0);
				desenha_texto(palavra,screen,845, 38, 25);
				if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)) {
					SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
				}
				else {
					/* nothing to do */
				}
				SDL_Flip(screen);
				char code_recv[100];
				receber_msg(Sclient,code_recv);
				amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
				if (code_recv[0] == '0' && code_recv[1] == '0') {
					pontos_jogador2 -=3;
				}
				else {
					/* nothing to do */
				}
				if (code_recv[0] == '0' && code_recv[1] == '1') {
					pontos_jogador2 -=6;
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor1) == 0) {
					vermelhoperde = 1;
					vermelhoganha = 0;
					azulganha = 1;
					azulperde = 0;
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor2) == 0) {
					azulperde = 1;
					azulganha = 0;
					vermelhoganha = 1;
					vermelhoperde = 0;
				}
				else {
					/* nothing to do */
				}
				if (pontos_jogador2 < 3) {
					minha_vez = 1;
					pontos_jogador2 = 20;
				}
				else {
					/* nothing to do */
				}
				if (vermelhoperde == 1 && azulganha == 1) {
					perdeu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if (azulganha == 1 && vermelhoperde == 1) {
					venceu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
			}
		}
	}
	else {
		blit_cima(uk,screen);
		minha_vez = 0;
		red = 0;
		green = 200;
		blue = 200;
		while (1) {
			start1 = SDL_GetTicks();
			if (minha_vez == 0) {
				blit_cima(uk,screen);
				string palavra = "Vez do outro jogador.";
				blit_tela(screen,0);
				desenha_texto(palavra,screen,845, 38, 25);
				if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)) {
						SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
				}
				else {
					/* nothing to do */
				}
				SDL_Flip(screen);
				vetor = get_Input();
				char code_recv[100];
				receber_msg(Cserver,code_recv);
				amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
				if (code_recv[0] == '0' && code_recv[1] == '0') {
						pontos_jogador1 -=3;
				}
				else {
					/* nothing to do */
				}
				if (code_recv[0] == '0' && code_recv[1] == '1') {
					pontos_jogador1 -=6;
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor1) == 0) {
					vermelhoperde = 1;
					vermelhoganha = 0;
					azulganha = 1;
					azulperde = 0;
				}
				else {
					/* nothing to do */
				}
				if (derrotado.compare(cor2) == 0) {
					vermelhoganha = 1;
					vermelhoperde = 0;
					azulperde = 1;
					azulganha = 0;
				}
				else {
					/* nothing to do */
				}
				if (pontos_jogador1 < 3) {
					minha_vez = 1;
					pontos_jogador1 = 20;
				}
				else {
					/* nothing to do */
				}
				if (azulperde == 1 && vermelhoganha == 1) {
					perdeu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if (vermelhoperde == 1 && azulganha == 1) {
					venceu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
			}
			else {
				blit_cima(uk,screen);
				desenha_pontos(pontos_jogador2, screen);
				vetor = get_Input();
				string palavra = "Sua vez.";
				desenha_texto(palavra,screen,845, 38, 25);
				if (vetor->click == 1) {
					if(compara_selecao(568,647,vetor->x,78,111,vetor->y)){
						clica_menu_menor(screen);
					}
					else {
						/* nothing to do */
					}
					if (verifica_hexagono(vetor->x,vetor->y)) {
						hexagon_selected->i_before = hexagon_selected->i;
						hexagon_selected->j_before = hexagon_selected->j;
						if (possui_unidade("azul")) {
							blit_cima(uk,screen);
							blit_tela(screen,1);
							blit_selecao(screen);
							blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
							while(1) {
								start1 = SDL_GetTicks();
								blit_cima(uk,screen);
								vetor = get_Input();
								if (vetor->click == 1) {
									verifica_hexagono(vetor->x,vetor->y);
									if (possui_unidade("azul")
										|| (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier
										&& hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type
										!= "helicoptero")) {
										break;
									}
									else {
										/* nothing to do */
									}
									if (alcance_ataque_soldado()) {
										codifica_ataque(code_s);
										enviar_msg(Cserver,code_s);
										ataque_unidade(screen,
													   hexagons[hexagon_selected->i][hexagon_selected->j]->x,
													   hexagons[hexagon_selected->i][hexagon_selected->j]->y,
													   totalElapsedTime,
													   delay,
													   lastdt);
										dano_ataque(screen);
										if (derrotado.compare(cor1) == 0) {
											vermelhoperde = 1;
											vermelhoganha = 0;
											azulganha = 1;
											azulperde = 0;
										}
										else {
											/* nothing to do */
										}
										if (derrotado.compare(cor2) == 0) {
											vermelhoganha = 1;
											vermelhoperde = 0;
											azulperde = 1;
											azulganha = 0;
										}
										else {
											/* nothing to do */
										}
										pontos_jogador2 -= 6;
										if (pontos_jogador2 < 3) {
											minha_vez = 0;
											pontos_jogador2 = 20;
										}
										else {
											/* nothing to do */
										}
										break;
									}
									else {
										/* nothing to do */
									}
									if (alcance_movimento_soldado()) {
										strcpy (code_s,"00");
										code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
										code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
										code_s[4] = (char)(((int)'0')+hexagon_selected->i);
										code_s[5] = (char)(((int)'0')+hexagon_selected->j);
										enviar_msg(Cserver,code_s);

										mover_soldado(screen,
													  hexagons[hexagon_selected->i][hexagon_selected->j]->x,
													  hexagons[hexagon_selected->i][hexagon_selected->j]->y,
													  totalElapsedTime,
													  delay,
													  lastdt);
										pontos_jogador2 -= 3;
										if (pontos_jogador2 < 3) {
											minha_vez = 0;
											pontos_jogador2 = 20;
											coleta_minerio(uk, minerio_azul);
											coleta_ouro(uk, ouro_azul);
											coleta_comida(uk, comida_azul);
										}
										else {
											/* nothing to do */
										}
										if ((azulganha == 1) && (vermelhoperde == 1)) {
											venceu_jogo(screen);
										}
										else {
											/* nothing to do */
										}
										if ((vermelhoperde == 1) && (azulganha == 1)) {
											perdeu_jogo(screen);
										}
										else {
											/* nothing to do */
										}
										break;
									}
									else {
										blit_tela(screen,0);
										blit_cima(uk,screen);
										break;
									}
								}
								else {
									/* nothing to do */
								}
								if((unsigned)(SDL_GetTicks() - start1) < (unsigned)(1000/FPS)){
									SDL_Delay((1000/FPS) - (SDL_GetTicks() - start1));
								}
								else {
									/* nothing to do */
								}
							}
						}
						else {
							/* nothing to do */
						}
						blit_tela(screen,0);
						blit_cima(uk,screen);
					}
					else {
						/* nothing to do */
					}
				}
				else {
					/* nothing to do */
				}
				if ((azulganha == 1) && (vermelhoperde == 1)) {
					venceu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if ((vermelhoperde == 1) && (azulganha == 1)) {
					perdeu_jogo(screen);
				}
				else {
					/* nothing to do */
				}
				if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)) {
						SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
				}
				SDL_Flip(screen);
			}
		}
	}
}
