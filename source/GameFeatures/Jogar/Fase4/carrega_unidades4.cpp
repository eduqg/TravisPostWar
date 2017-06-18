#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void carrega_china_azul(SDL_Surface *screen){

    string lado2("cliente");
    string cor2 = "azul";

    for(int i=0;i<10;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque.png";
        SDL_Surface *soldado_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_baixo.png";
        SDL_Surface *soldado_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_cima.png";
        SDL_Surface *soldado_ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral.png";
        SDL_Surface *soldado_lateral_v = load_Image(caminho, screen);
        Unit *soldado = new Unit();
        string unit = "soldado";
        setar_soldado(soldado, cor2, unit, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima,soldado_lateral_v, id);
        id++;
        red_units.push_back(soldado);

        SDL_Rect dst;
        dst.x = hexagons[i*2][12]->x;
        dst.y = hexagons[i*2][12]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(red_units[i]->name, &cutBox,  screen, &dst);
        //BlitImage(screen,red_units[0]->name,hexagons[2][12]->x,hexagons[2][12]->y);
        hexagons[i*2][12]->unit = red_units[i];
        hexagons[i*2][12]->contains_unit = 1;
        red_units[0]->x = hexagons[i*2][12]->x;
        red_units[0]->y = hexagons[i*2][12]->y;

    }


    for (int i=10;i<11;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_azul_ataque.png";
        SDL_Surface *metrapalhadora_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/barraLateral_azul.png";
        SDL_Surface *metrapalhadora_lateral = load_Image(caminho, screen);
        Unit *metralhadora = new Unit();
        string unidade2 = "metralhadora";
        setar_metralhadora(metralhadora, cor2, unidade2, metrapalhadora1, metrapalhadora_ataque, metrapalhadora_lateral, id);
        id++;
        red_units.push_back(metralhadora);

        BlitImage(screen,red_units[i]->name,hexagons[2][13]->x,hexagons[2][13]->y);
        hexagons[2][13]->unit = red_units[i];
        hexagons[2][13]->contains_unit = 1;
        hexagons[3][13]->unit = red_units[i];
        hexagons[3][13]->contains_unit = 1;
        hexagons[4][13]->unit = red_units[i];
        hexagons[4][13]->contains_unit = 1;
        hexagons[5][13]->unit = red_units[i];
        hexagons[5][13]->contains_unit = 1;
        hexagons[6][13]->unit = red_units[i];
        hexagons[6][13]->contains_unit = 1;
    }

    ///Carregar os sprites do quartel azul
    string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
    SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
    Unit *quartel_a = new Unit();
    string quarte = "quartel";
    setar_quartel(quartel_a,cor2,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
    id++;
    BlitImage(screen,quartel_azul_cabana,hexagons[7][13]->x,hexagons[7][13]->y);
    hexagons[7][13]->unit = quartel_a;
    hexagons[7][13]->contains_unit= 1;
    hexagons[7][14]->unit = quartel_a;
    hexagons[7][14]->contains_unit= 1;
    hexagons[8][14]->unit = quartel_a;
    hexagons[8][14]->contains_unit= 1;
    hexagons[9][13]->unit = quartel_a;
    hexagons[9][13]->contains_unit= 1;
    hexagons[9][14]->unit = quartel_a;
    hexagons[9][14]->contains_unit= 1;
    hexagons[10][14]->unit = quartel_a;
    hexagons[10][14]->contains_unit= 1;
    red_units.push_back(quartel_a);

    /*BlitImage(screen,red_units[5]->name,hexagons[14][12]->x,hexagons[14][12]->y);
    hexagons[14][12]->unit = red_units[5];
    hexagons[14][12]->contains_unit = 1;
    red_units[5]->x = hexagons[14][12]->x;
    red_units[5]->y = hexagons[14][12]->y;*/


}




