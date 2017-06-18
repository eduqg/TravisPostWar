#ifndef _GAMEFEATURES_H_
#define _GAMEFEATURES_H_

#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <map>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

typedef struct _Unit {
	SDL_Surface *attack;
	SDL_Surface *down_attack;
	SDL_Surface *up_attack;
	SDL_Surface *name;
	SDL_Surface *lateral_image;
	int health_points;
	int attack_points;
	int deffense_points;
	int attack_range;
	int gold_coins;
	int food;
	int minerals;
	string color;
	string unit_type;
	int x;
	int y;
	int id;
} Unit;

typedef struct _Building {
	SDL_Surface *name;
	string unit_type;
	int profit;
	int conquered;
} Building;

typedef struct _Hexagons {
	int x;
	int y;
	int index;
	bool contains_unit : 1;
	bool barrier : 1;
	int mine;
	Unit *unit;
	Building *building;
	int center_in_x;
	int center_in_y;
	int radius;
} Hexagons;


typedef struct _Hexagon_selected {
	int i;
	int j;
	int i_before;
	int j_before;
} Hexagon_selected;

typedef struct _Nation {
	int gold_coins;
	int food;
	int minerals;
	string name;
	string color;
} Nation;

extern char code_s[100];
extern SDL_Rect cutBox;
extern Hexagon_selected *hexagon_selected;
extern vector<vector <Hexagons *> > hexagons;
extern vector<Unit *> blue_units;
extern vector<Unit *> red_units;
extern SDL_Surface *mesh;
extern SDL_Surface *heads_up_display;
extern SDL_Surface *without_mesh;
extern SDL_Surface *with_mesh;
extern TCPsocket Sclient;
extern TCPsocket Cserver;
extern char texto_global[100];
extern int qual_vez;
extern int red, green, blue;
extern SDL_Surface *hud2;
extern string derrotado;
extern int vermelhoperde;
extern int azulperde;
extern int vermelhoganha;
extern int azulganha;
extern string cor2;
extern string cor1;
extern int minerio_vermelho;
extern int minerio_azul;
extern int ouro_vermelho;
extern int ouro_azul;
extern int comida_vermelha;
extern int comida_azul;
extern int pontos_jogador1;
extern int pontos_jogador2;
extern int start;
extern int FPS;
extern int id;
extern SDL_Surface *menu_meio;
extern SDL_Surface *menu_menor;
extern SDL_Surface *voltar_jogo_sel;
extern SDL_Surface *opcoes_sel;
extern SDL_Surface *sair_sel;
extern int valida;
extern SDL_Surface *screen1;
extern void desenha_texto (string texto,
						   SDL_Surface* dst,
						   int x,
						   int y,
						   int size);
extern void load_menu (SDL_Surface *screen);
extern void inicio (SDL_Surface *screen);
extern void opcoes (SDL_Surface *screen);
extern void creditos (SDL_Surface *screen);
extern void fase1 (SDL_Surface *screen,
				   string zuera,
				   Nation *pais,
				   Nation *pais1);
extern void fase2 (SDL_Surface *screen,string qual_maquina);
extern void fase3 (SDL_Surface *screen,string qual_maquina);
extern void fase4 (SDL_Surface *screen,string qual_maquina);
extern void fase5 (SDL_Surface *screen,string qual_maquina);
extern void carregar_fase1 (SDL_Surface *screen);
extern void carregar_fase2 (SDL_Surface *screen);
extern void carregar_fase3 (SDL_Surface *screen);
extern void carregar_fase4 (SDL_Surface *screen);
extern void carregar_fase5 (SDL_Surface *screen);
extern void carrega_china (SDL_Surface *screen);
extern void carrega_china_azul (SDL_Surface *screen);
extern void carrega_franca (SDL_Surface *screen);
extern void carrega_eua (SDL_Surface *screen);
extern void carrega_uk (SDL_Surface *screen);
extern void carrega_urss (SDL_Surface *screen);
extern void blit_tela (SDL_Surface *screen,int i);
extern void blit_tela_ataque (SDL_Surface *screen,
							  int tela,
							  int id,
							  int x,
							  int y);
extern int verifica_hexagono (int x, int y);
extern void mover_soldado (SDL_Surface *screen, int i, int x, int y);
extern void ataque_unidade (SDL_Surface *screen,
	                        int x,
	                        int y,
	                        int totalElapsedTime,
	                        int delay,
	                        int lastdt);
extern int possui_unidade (string color);
extern int alcance_movimento_soldado ();
extern int alcance_ataque_soldado ();
extern void dano_ataque (SDL_Surface *screen);
extern void enviar_msg (TCPsocket maquina, char text[]);
extern void receber_msg (TCPsocket maquina,char *texto);
extern void amigo_movimenta (char code_recv[],
							 SDL_Surface *screen,
							 int totalElapsedTime,
							 int delay,
							 int lastdt);
extern void codifica_ataque (char codigo[]);
extern void verifica_derrota (SDL_Surface *screen);
extern void blit_lateral (Unit *lateral,SDL_Surface *screen);
extern void blit_cima (Nation *pais, SDL_Surface *screen);
extern void setar_pais (Nation *pais,
						int gold_coins,
						int food,
						int minerals,
						string name,
						string color);
extern void setar_soldado (Unit *soldado,
						   string color,
						   string unit_type,
						   SDL_Surface *name,
						   SDL_Surface *attack,
						   SDL_Surface *down_attack,
						   SDL_Surface *up_attack,
						   SDL_Surface *soldado_lateral,
						   int id);
extern void setar_helicoptero (Unit *helicoptero,
							   string color,
							   string unit_type,
							   SDL_Surface *name,
							   SDL_Surface *attack,
							   SDL_Surface *down_attack,
							   SDL_Surface *up_attack,
							   SDL_Surface *helicoptero_lateral,
							   int id);
extern void setar_metralhadora (Unit *metralhadora,
								string color,
								string unit_type,
								SDL_Surface *name,
								SDL_Surface *attack,
								SDL_Surface *lateral,
								int id);
extern void setar_tanque (Unit *tanque,
						  string color,
						  string unit_type,
						  SDL_Surface *name,
						  SDL_Surface *attack,
						  SDL_Surface *down_attack,
						  SDL_Surface *up_attack,
						  SDL_Surface *tanque_lateral,
						  int id);
extern void setar_quartel (Unit *quartel,
						   string color,
						   string unit_type,
						   SDL_Surface *name,
						   SDL_Surface *attack,
						   SDL_Surface *lateral,
						   int id);
extern void setar_pais (Nation *pais,
						int gold_coins,
						int food,
						int minerals,
						string name,
						string color);
extern void setar_construcao (Building *building,
							  SDL_Surface *name,
							  string unit_type,
							  int profit);
extern void carrega_eua (SDL_Surface *screen,string lado);
extern string convertInt (int number);
extern void blit_lateral (Unit *unit,SDL_Surface *screen);
extern void blit_cima (Nation *pais, SDL_Surface *screen);
extern void mapeia_hexagono ();
extern void carrega_construcoes (SDL_Surface *screen);
extern string convertInt (int number);
extern void desenha_pontos (int number, SDL_Surface *screen);
extern void perdeu_jogo (SDL_Surface *screen);
extern void venceu_jogo (SDL_Surface *screen);
extern void blit_selecao (SDL_Surface *screen);
extern void evolucao_soldado (Nation *pais);
extern void evolucao_quartel (Nation *pais);
extern void coleta_ouro (Nation *pais, int valor_coleta_ouro);
extern void coleta_minerio (Nation *pais, int valor_coleta_minerio);
extern void coleta_comida (Nation *pais, int valor_coleta_comida);
extern void explode_unidade (SDL_Surface *screen,
							 int x,
							 int y,
							 int totalElapsedTime,
							 int delay,
							 int lastdt);
extern void clica_menu_menor (SDL_Surface *screen);
extern void frame_delay (int start);
extern void escolha_mapa (SDL_Surface *screen);
extern void blit_selecao (SDL_Surface *screen);
extern void desenha_pontos (int number,
							SDL_Surface *screen);
extern void amigo_movimenta (char code_recv[],
							 SDL_Surface *screen,
							 int totalElapsedTime,
							 int delay,
							 int lastdt);
extern void codifica_ataque (char code_s[]);
extern void eventos (void *);
extern int eventos2 (void *);

#endif
