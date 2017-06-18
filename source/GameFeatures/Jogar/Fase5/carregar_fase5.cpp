#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase5(SDL_Surface *screen){


    hexagon_selected = new Hexagon_selected();

    string caminho = "source/GameFeatures/Jogar/Fase5/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fase_5.png";
    without_mesh = load_Image(caminho, screen);
    BlitImage(screen,without_mesh,0,0);

    caminho = "source/GameFeatures/Jogar/Fase5/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase5/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fase_5_malha.png";
    with_mesh = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase5/images/FundoHUD.png";
    heads_up_display = load_Image(caminho, screen);
    BlitImage(screen, heads_up_display, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase5/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagons[19][1]->barrier =1;
    hexagons[19][6]->barrier =1;
    hexagons[3][9]->barrier =1;
    hexagons[6][11]->barrier =1;


        carrega_franca(screen);


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

