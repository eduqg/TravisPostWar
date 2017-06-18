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

/* load level 1 */
void fase1(SDL_Surface *screen,
		   string qual_maquina,
		   Nation *pais_serv,
		   Nation *pais_client)
{
	FPS = 150;
	int lastdt = SDL_GetTicks();
	int totalElapsedTime = 0;
	int delay = 200;
	int minha_vez;
	Vetor_mouse *vetor = new Vetor_mouse;
	blit_tela(screen,0);
	SDL_Flip(screen);
	int start1 =0;
	if (qual_maquina.compare("cliente")) {
		minha_vez=1;
		while(1) {
			start = SDL_GetTicks();
			if (minha_vez) {
				blit_cima(pais_serv,screen); //verifica_hexagono.cpp
				desenha_pontos(pontos_jogador1, screen); //fase1.cpp
				vetor = get_Input();
				string palavra = "Sua vez.";
				red = 255;
				green = 255;
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
						if (possui_unidade("vermelho") ) {
							blit_tela(screen,1);
							blit_selecao(screen);
							blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
							blit_cima(pais_serv,screen);
							while(1) {
								start1 = SDL_GetTicks();
								vetor = get_Input();
								if (vetor->click == 1) {
									verifica_hexagono(vetor->x,vetor->y);
									if (possui_unidade("vermelho") || (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier && hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type != "helicoptero")) {
										break;
									}
									else {
										/* nothing to do */
									}
									if (alcance_ataque_soldado()) {
										codifica_ataque(code_s);
										//cout << "passei codifica" << endl;
										enviar_msg(Sclient,code_s);
										ataque_unidade(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
										dano_ataque(screen);
										//cout << "enviei" << endl;
										//cout << "animei attack" << endl;
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
											cout << "Entrei aqui 1" << endl;
											azulperde = 1;
											azulganha = 0;
											vermelhoganha = 1;
											vermelhoperde = 0;
										}
										else {
										/* nothing to do */
										}
										pontos_jogador1 -= 6;
										if (pontos_jogador1<3) {
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
										/*nothing to do */
									}
									if (alcance_movimento_soldado()) {
										if (hexagons[hexagon_selected->i][hexagon_selected->j]->mine == 1) {
											if (hexagons[2][8]->building->conquered == 1) {
												break;
											}
											else {
												/* nothing to do */
											}
											minerio_vermelho += 20;
											ouro_vermelho += 20;
											break;
										}
										else {
											/* nothing to do */
										}
										strcpy (code_s,"00");
										code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
										code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
										code_s[4] = (char)(((int)'0')+hexagon_selected->i);
										code_s[5] = (char)(((int)'0')+hexagon_selected->j);
										enviar_msg(Sclient,code_s);
										mover_soldado(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
										pontos_jogador1 -= 3;
										if (pontos_jogador1<3) {
											minha_vez = 0;
											pontos_jogador1 = 20;
											coleta_minerio(pais_serv, minerio_vermelho);
											coleta_ouro(pais_serv, ouro_vermelho);
											coleta_comida(pais_serv, comida_vermelha);
										}
										else {
											/* nothing to do */
										}
										break;
										}
									else {
										blit_tela(screen,0);
										blit_cima(pais_serv,screen);
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
						//verifica_derrota(screen);
						blit_tela(screen,0);
						blit_cima(pais_serv,screen);
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
					cout << "Entrei aqui 2" << endl;
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
				SDL_Flip(screen);
			}
			else {
				blit_cima(pais_serv,screen);
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
				SDL_Thread *thread_mouse = SDL_CreateThread(eventos2,NULL);
				receber_msg(Sclient,code_recv);
				SDL_KillThread(thread_mouse);
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
				if (pontos_jogador2<3) {
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
		blit_cima(pais_client,screen);
		minha_vez = 0;
		red = 0;
		green = 200;
		blue = 200;
		int start12;
		while(1) {
			start12 = SDL_GetTicks();
			if (minha_vez == 0) {

				blit_cima(pais_client,screen);
				string palavra = "Vez do outro jogador.";
				blit_tela(screen,0);
				desenha_texto(palavra,screen,845, 38, 25);
				SDL_Flip(screen);
				vetor = get_Input();
				char code_recv[100];
				screen1 = screen;
				SDL_Thread *thread_mouse = SDL_CreateThread(eventos2,NULL);
				receber_msg(Cserver,code_recv);
				SDL_KillThread(thread_mouse);
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
				if (pontos_jogador1<3) {
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
				blit_cima(pais_client,screen);
				desenha_pontos(pontos_jogador2, screen);
				vetor = get_Input();
				string palavra = "Sua vez.";
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
						if (possui_unidade("azul")) {
							blit_cima(pais_client,screen);
							blit_tela(screen,1);
							blit_selecao(screen);
							blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
								while(1) {
									start1 = SDL_GetTicks();
									blit_cima(pais_client,screen);
									vetor = get_Input();
									if (vetor->click == 1) {
										verifica_hexagono(vetor->x,vetor->y);
										if (possui_unidade("azul") || (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier && hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type != "helicoptero")) {
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
											//cout << "animei attack" << endl;
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
											if (pontos_jogador2<3) {
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
											if (hexagons[hexagon_selected->i][hexagon_selected->j]->mine == 1) {
												if (hexagons[2][8]->building->conquered == 1) {
													break;
												}
												else {
												/* nothing to do */
												}
												minerio_vermelho += 20;
												ouro_vermelho += 20;
												break;
											}
											else {
												/* nothing to do */
											}
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
											if (pontos_jogador2<3) {
												minha_vez = 0;
												pontos_jogador2 = 20;
												coleta_minerio(pais_client, minerio_vermelho);
												coleta_ouro(pais_client, ouro_vermelho);
												coleta_comida(pais_client, comida_vermelha);
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
											 /*nothing to do */
											}
											break;
										}
										else {
												blit_tela(screen,0);
												blit_cima(pais_client,screen);
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
						blit_cima(pais_client,screen);
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
				else {
					/* nothing to do */
				}
				SDL_Flip(screen);
			}
			frame_delay(start12);
		}
	}
}

/* make the atack's code */
void codifica_ataque(char code_s[])
{
	strcpy(code_s,"01");
	code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
	code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
	code_s[4] = (char)(((int)'0')+hexagon_selected->i);
	code_s[5] = (char)(((int)'0')+hexagon_selected->j);
	/*code_s[6] = hp1/1000;
	code_s[7] = ((hp1%1000) - (hp1%100))/100;
	code_s[8] = ((hp1%100) - (hp1%10))/10;
	code_s[9] = hp1%10;
	code_s[10] = hp2/1000;
	code_s[11] = ((hp2%1000) - (hp2%100))/100;
	code_s[12] = ((hp2%100) - (hp2%10))/10;
	code_s[13] = hp2%10;*/
}

/* allow the partner to make a move */
void amigo_movimenta(char code_recv[],
					 SDL_Surface * screen,
					 int totalElapsedTime,
					 int delay,
					 int lastdt)
{
	if (code_recv[0] == '0' && code_recv[1] == '0') {
	hexagon_selected->i_before = code_recv[2] - 48;
	hexagon_selected->j_before = code_recv[3] - 48;
	hexagon_selected->i = code_recv[4] - 48;
	hexagon_selected->j = code_recv[5] - 48;
	mover_soldado(screen,
				  hexagons[hexagon_selected->i][hexagon_selected->j]->x,
				  hexagons[hexagon_selected->i][hexagon_selected->j]->y,
				  totalElapsedTime,
				  delay,
				  lastdt);
	blit_tela(screen,0);
	}
	else if (code_recv[0] == '0' && code_recv[1] == '1') {
		hexagon_selected->i_before = code_recv[2] - 48;
		hexagon_selected->j_before = code_recv[3] - 48;
		hexagon_selected->i = code_recv[4] - 48;
		hexagon_selected->j = code_recv[5] - 48;
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
	}
		blit_tela(screen,0);

}

/* draws the points on the screen */
void desenha_pontos(int number, SDL_Surface *screen)
{
	string points;
	points = convertInt(number);
	desenha_texto(points,screen, 1125, 20, 30);
}

/* selects the blit */
void blit_selecao(SDL_Surface *screen)
{
	if (hexagons[hexagon_selected->i][hexagon_selected->j]->unit->unit_type.compare("quartel")!=0 ) {
		if (hexagons[hexagon_selected->i][hexagon_selected->j]->unit->unit_type.compare("metralhadora")!=0 ) {
			string caminho = "source/GameFeatures/Jogar/Fase1/images/alcance_fundoVerde.png";
			SDL_Surface *selecao = load_Image(caminho, screen);
			if (hexagon_selected->i%2==1) {
				BlitImage(screen,
						  selecao,
						  hexagons[hexagon_selected->i][hexagon_selected->j]->x-45,
						  hexagons[hexagon_selected->i][hexagon_selected->j]->y-47);
			}
			else {
					BlitImage(screen,
							  selecao,
							  hexagons[hexagon_selected->i][hexagon_selected->j]->x-49,
							  hexagons[hexagon_selected->i][hexagon_selected->j]->y-49);
			}
		}
		else {
			/* nothing to do */
		}
	}
	else {
		/* nothing to do */
	}
}
