#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

/* loads level 2 */
void carregar_fase2(SDL_Surface *screen)
{
	hexagon_selected = new Hexagon_selected();

	string caminho = "source/GameFeatures/Jogar/Fase2/images/Loading.png";
	SDL_Surface *loading = load_Image(caminho, screen);
	BlitImage(screen, loading, 0, 0);
	SDL_Flip(screen);

	caminho = "source/GameFeatures/Jogar/Fase2/images/fase_2.png";
	without_mesh = load_Image(caminho, screen);
	BlitImage(screen,without_mesh,0,0);

	caminho = "source/GameFeatures/Jogar/Fase2/images/menu_meio_jogo.png";
	menu_meio = load_Image(caminho,screen);
	BlitImage(screen,menu_meio,568,78);

	caminho = "source/GameFeatures/Jogar/Fase2/images/fundo_menuPartida.png";
	menu_menor = load_Image(caminho,screen);


	caminho = "source/GameFeatures/Jogar/Fase2/images/voltar_jogo_selecionado.png";
	voltar_jogo_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase2/images/opcoes_selecionado.png";
	opcoes_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase2/images/sair_selecionado.png";
	sair_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase2/images/fase_2_malha.png";
	with_mesh = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase2/images/FundoHUD.png";
	heads_up_display = load_Image(caminho, screen);
	BlitImage(screen, heads_up_display, 0, 0);

	caminho = "source/GameFeatures/Jogar/Fase2/images/painel_status.png";
	hud2 = load_Image(caminho, screen);
	mapeia_hexagono();
	hexagons[19][3]->barrier =1;
	hexagons[2][3]->barrier =1;
	hexagons[5][4]->barrier =1;
	hexagons[6][5]->barrier =1;
	hexagons[5][7]->barrier =1;
	hexagons[19][6]->barrier =1;
	hexagons[3][10]->barrier =1;
	hexagons[16][9]->barrier =1;
	hexagons[19][10]->barrier =1;
	hexagons[8][11]->barrier =1;
	hexagons[9][10]->barrier =1;
	hexagons[18][9]->barrier =1;
	hexagons[2][10]->barrier =1;
	hexagons[14][4]->barrier =1;
	hexagons[10][11]->barrier =1;
	carrega_franca(screen);
	carrega_uk(screen);
	carrega_construcoes(screen);
	SDL_Flip(screen);
}
