#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void mapeia_hexagono()
{

	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	int ia=0;
	int ja=124;
	int ie=44;
	int je=136;
	int contador=0;
	while (ja<500) {
		vector <Hexagons *> hex_temp;
		for (ia=35, ie=44;ia<1050;ia+=68,ie+=68) {

			//BlitImage(screen,blue_units[0]->name,ia,ja);
			Hexagons *hexagon = new Hexagons;
			hexagon->center_in_x = ie;
			hexagon->center_in_y = je;
			hexagon->radius = 20;
			hexagon->x = ia;
			hexagon->y = ja;
			hexagon->index = contador;
			hexagon->contains_unit=0;
			hexagon->barrier=0;
			hexagon->barrier = 0;
			if (contador==132) {
				//string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
				//SDL_Surface *soldado1 = load_Image(caminho, screen);
			   // BlitImage(screen,soldado1,ie,je);
			}
			else {
				/* nothing to do */
			}

			hex_temp.push_back(hexagon);
			contador++;
		}
		hexagons.push_back(hex_temp);
		ja+=19;
		je+=20;
		vector <Hexagons *> hex_temp2;
		for (ia=65,ie=78;ia<1050;ia+=68,ie+=68) {

			//BlitImage(screen,blue_units[0]->name,ia,ja);

			Hexagons *hexagon = new Hexagons;
			hexagon->x = ia;
			hexagon->y = ja;
			hexagon->barrier = 0;
			hexagon->center_in_x = ie;
			hexagon->center_in_y = je;
			hexagon->index = contador;
			hexagon->radius = 20;
			hexagon->barrier=0;
			hexagon->contains_unit=0;
			hex_temp2.push_back(hexagon);
			contador++;
		}
		hexagons.push_back(hex_temp2);
		ja+=20;
		je+=20;
	}
	/*
	string bora="0";
	string bora1="0";
	for(int i=0; i<hexagons.size();i++){
		for(int j=0; j<hexagons[i].size();j++){
			bora[0]+=i;
			bora1[0] += j;
			//cout<<"bora: "<<bora1<<endl;
			desenha_texto(bora,screen,hexagons[i][j]->x,hexagons[i][j]->y,20);
			desenha_texto(bora1,screen,hexagons[i][j]->x+10,hexagons[i][j]->y,20);
			bora="0";
			bora1="0";
		}
	}*/


}

void carregar_fase1(SDL_Surface *screen)
{
	hexagon_selected = new Hexagon_selected();

	string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
	SDL_Surface *loading = load_Image(caminho, screen);
	BlitImage(screen, loading, 0, 0);
	SDL_Flip(screen);

	caminho = "source/GameFeatures/Jogar/Fase1/images/malha1.png";
	without_mesh = load_Image(caminho, screen);
	BlitImage(screen,without_mesh,0,0);

	caminho = "source/GameFeatures/Jogar/Fase1/images/menu_meio_jogo.png";
	menu_meio = load_Image(caminho,screen);
	BlitImage(screen,menu_meio,568,78);

	caminho = "source/GameFeatures/Jogar/Fase1/images/fundo_menuPartida.png";
	menu_menor = load_Image(caminho,screen);


	caminho = "source/GameFeatures/Jogar/Fase1/images/voltar_jogo_selecionado.png";
	voltar_jogo_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase1/images/opcoes_selecionado.png";
	opcoes_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase1/images/sair_selecionado.png";
	sair_sel = load_Image(caminho, screen);

	caminho = "source/GameFeatures/Jogar/Fase1/images/mesh.png";
	with_mesh = load_Image(caminho, screen);



	caminho = "source/GameFeatures/Jogar/Fase1/images/FundoHUD.png";
	heads_up_display = load_Image(caminho, screen);
	BlitImage(screen, heads_up_display, 0, 0);

	caminho = "source/GameFeatures/Jogar/Fase1/images/painel_status.png";
	hud2 = load_Image(caminho, screen);
	//BlitImage(screen, hud2, 977, 236);

	mapeia_hexagono();

	hexagons[1][12]->barrier =1;
	hexagons[1][3]->barrier =1;
	hexagons[10][6]->barrier =1;
	hexagons[11][10]->barrier =1;
	hexagons[12][11]->barrier =1;
	hexagons[12][0]->barrier =1;
	hexagons[13][0]->barrier =1;

	carrega_china(screen);
	carrega_eua(screen);
	carrega_construcoes(screen);
/*
	for(int i=0; i<hexagons.size();i++){
		for(int j=0; j<hexagons[i].size();j++){
		BlitImage(screen,red_units[0]->name,hexagons[i][j]->x,hexagons[i][j]->y);
		cout<<hexagons[i][j]->index<<" ";
		}
		cout<<endl;
	}*/
	SDL_Flip(screen);
}
