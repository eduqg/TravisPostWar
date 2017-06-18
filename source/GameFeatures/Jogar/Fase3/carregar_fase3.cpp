#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase3(SDL_Surface *screen){


    hexagon_selected = new Hexagon_selected();

    string caminho = "source/GameFeatures/Jogar/Fase3/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fase_3.png";
    without_mesh = load_Image(caminho, screen);
    BlitImage(screen,without_mesh,0,0);

    caminho = "source/GameFeatures/Jogar/Fase3/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase3/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fase_3_malha.png";
    with_mesh = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase3/images/FundoHUD.png";
    heads_up_display = load_Image(caminho, screen);
    BlitImage(screen, heads_up_display, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase3/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagons[1][7]->barrier =1;
    hexagons[3][8]->barrier =1;
    hexagons[3][9]->barrier =1;
    hexagons[4][9]->barrier =1;
    hexagons[1][7]->barrier =1;
    hexagons[0][8]->barrier =1;
    hexagons[0][9]->barrier =1;
    hexagons[5][8]->barrier =1;
    hexagons[8][9]->barrier =1;
    hexagons[9][8]->barrier =1;
    hexagons[10][9]->barrier =1;
    hexagons[11][8]->barrier =1;
    hexagons[12][8]->barrier =1;
    hexagons[13][8]->barrier =1;
    hexagons[15][8]->barrier =1;
    hexagons[17][8]->barrier =1;
    hexagons[19][8]->barrier =1;
    hexagons[4][10]->barrier =1;
    hexagons[6][10]->barrier =1;
    hexagons[9][9]->barrier =1;
    hexagons[11][9]->barrier =1;
    hexagons[12][10]->barrier =1;
    hexagons[13][9]->barrier =1;
    hexagons[14][9]->barrier =1;
    hexagons[15][10]->barrier =1;
    hexagons[16][9]->barrier =1;
    hexagons[17][9]->barrier =1;
    hexagons[13][10]->barrier =1;
    hexagons[13][10]->barrier =1;
    hexagons[14][10]->barrier =1;
    hexagons[15][10]->barrier =1;
    hexagons[16][10]->barrier =1;
    hexagons[17][10]->barrier =1;
    hexagons[14][11]->barrier =1;
    hexagons[18][11]->barrier =1;
    hexagons[17][11]->barrier =1;
    hexagons[15][4]->barrier =1;
    hexagons[14][5]->barrier =1;
    hexagons[13][5]->barrier =1;
    hexagons[13][6]->barrier =1;
    hexagons[12][7]->barrier =1;
    hexagons[15][6]->barrier =1;
    hexagons[16][7]->barrier =1;

        carrega_urss(screen);


        carrega_uk(screen);
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

