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


void fase4(SDL_Surface *screen,string qual_maquina){

    FPS = 150;
    Nation *urss = new Nation();
    string name = "URSS";
    string color = "vermelho";
    setar_pais(urss, 50, 100, 40, name, color);
    Nation *china = new Nation();
    name = "China";
    color = "azul";
    setar_pais(china, 50, 100, 50, name, color);

    char pais_serv[100] = "urss";
    char pais_client[100] = "china";


    carregar_fase4(screen);
    int lastdt = SDL_GetTicks();
    int totalElapsedTime = 0;
    int delay = 200;

    int minha_vez;

    Vetor_mouse *vetor = new Vetor_mouse();
    blit_tela(screen,0);
    SDL_Flip(screen);

    //string opcao = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_mouse.png";
    //SDL_Surface *mouse = load_Image(opcao, screen);
    int start1 =0;
    if(qual_maquina.compare("cliente")){
        minha_vez=1;

        while(1){
            start = SDL_GetTicks();
            //memset (code_s,'0',100);
            if(minha_vez){

                blit_cima(urss,screen); //verifica_hexagono.cpp
                desenha_pontos(pontos_jogador1, screen); //fase1.cpp
                vetor = get_Input();
                string palavra = "Sua vez.";
                red = 255;
                green = 0;
                blue = 0;
                desenha_texto(palavra,screen,850, 38, 35);

                if(vetor->click == 1){

                    if(compara_selecao(568,647,vetor->x,78,111,vetor->y)){
                        clica_menu_menor(screen);
                    }

                    if(verifica_hexagono(vetor->x,vetor->y)){

                    //if(compara_selecao(red_units[0]->x, red_units[0]->x+32, vetor->x, red_units[0]->y, red_units[0]->y+32, vetor->y)){
                        hexagon_selected->i_before = hexagon_selected->i;
                        hexagon_selected->j_before = hexagon_selected->j;
                        if(possui_unidade("vermelho") && !hexagons[hexagon_selected->i][hexagon_selected->j]->barrier){
                            blit_tela(screen,1);
                            blit_selecao(screen);
                            blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
                            blit_cima(urss,screen);
                            while(1){
                                start1 = SDL_GetTicks();
                                vetor = get_Input();
                                if(vetor->click == 1){
                                    //cout<<"What?"<<endl;
                                    verifica_hexagono(vetor->x,vetor->y);

                                    if(possui_unidade("vermelho") || (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier && hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type != "helicoptero")){
                                        //cout<<"VÉSH"<<endl;
                                        break;
                                    }
                                    if(alcance_ataque_soldado()){

                                        codifica_ataque(code_s);
                                        //cout << "passei codifica" << endl;
                                        enviar_msg(Sclient,code_s);
                                        ataque_unidade(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
                                        dano_ataque(screen);
                                        //cout << "enviei" << endl;
                                        //cout << "animei attack" << endl;
                                        if(derrotado.compare(cor1) == 0){
                                            vermelhoperde = 1;
                                            vermelhoganha = 0;
                                            azulganha = 1;
                                            azulperde = 0;
                                        }
                                        if(derrotado.compare(cor2) == 0){
                                            cout << "Entrei aqui 1" << endl;
                                            azulperde = 1;
                                            azulganha = 0;
                                            vermelhoganha = 1;
                                            vermelhoperde = 0;
                                        }

                                        pontos_jogador1 -= 6;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            pontos_jogador1 = 20;
                                        }
                                        if(vermelhoperde == 1 && azulganha == 1){
                                            perdeu_jogo(screen);
                                        }
                                        if(azulganha == 1 && vermelhoganha == 1){
                                            venceu_jogo(screen);
                                        }
                                        break;
                                    }

                                    if(alcance_movimento_soldado()){
                                        strcpy (code_s,"00");
                                        code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
                                        code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
                                        code_s[4] = (char)(((int)'0')+hexagon_selected->i);
                                        code_s[5] = (char)(((int)'0')+hexagon_selected->j);
                                        //cout<<"Enviando msg..."<<endl;
                                        enviar_msg(Sclient,code_s);
                                        //cout<<"A mensagem enviada foi: "<<code_s  <<endl;
                                        mover_soldado(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
                                        pontos_jogador1 -= 3;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            pontos_jogador1 = 20;
                                            coleta_minerio(urss, minerio_vermelho);
                                            coleta_ouro(urss, ouro_vermelho);
                                            coleta_comida(urss, comida_vermelha);
                                        }
                                        break;
                                    }
                                        else{
                                            blit_tela(screen,0);
                                            blit_cima(urss,screen);
                                            break;
                                        }
                                }
                                frame_delay(start1);
                            }
                        }
                        //verifica_derrota(screen);
                        blit_tela(screen,0);
                        blit_cima(urss,screen);
                    }


                }

                if(derrotado.compare(cor1) == 0){
                    vermelhoperde = 1;
                    vermelhoganha = 0;
                    azulganha = 1;
                    azulperde = 0;
                }
                if(derrotado.compare(cor2) == 0){
                    cout << "Entrei aqui 2" << endl;
                    azulperde = 1;
                    azulganha = 0;
                    vermelhoganha = 1;
                    vermelhoperde = 0;
                }


                if(azulganha == 1 && vermelhoperde == 1){
                    perdeu_jogo(screen);
                }
                if(vermelhoganha == 1 && azulperde == 1){
                    venceu_jogo(screen);
                }
            if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
            }
            SDL_Flip(screen);
            }

                else{

                    blit_cima(urss,screen);
                    string palavra = "Vez do outro jogador.";
                    blit_tela(screen,0);
                    desenha_texto(palavra,screen,845, 38, 25);
                    if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                        SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
                    }
                    SDL_Flip(screen);
                    char code_recv[100];
                    receber_msg(Sclient,code_recv);
                    //cout<<"Recebi a msg: "<<code_recv<<endl;
                    amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
                    if(code_recv[0] == '0' && code_recv[1] == '0'){
                        pontos_jogador2 -=3;
                    }
                    if(code_recv[0] == '0' && code_recv[1] == '1'){
                        pontos_jogador2 -=6;
                    }
                    if(derrotado.compare(cor1) == 0){
                        vermelhoperde = 1;
                        vermelhoganha = 0;
                        azulganha = 1;
                        azulperde = 0;
                    }
                    if(derrotado.compare(cor2) == 0){
                        azulperde = 1;
                        azulganha = 0;
                        vermelhoganha = 1;
                        vermelhoperde = 0;
                    }

                    if(pontos_jogador2<3){
                        minha_vez = 1;
                        pontos_jogador2 = 20;
                    }
                    if(vermelhoperde == 1 && azulganha == 1){
                        perdeu_jogo(screen);
                    }
                    if(azulganha == 1 && vermelhoperde == 1){
                        venceu_jogo(screen);
                    }
                }
            frame_delay(start);
        }

    }


    else{
        blit_cima(china,screen);
        minha_vez = 0;
        red = 0;
        green = 200;
        blue = 200;

        while(1){
            start1 = SDL_GetTicks();
            if(minha_vez == 0){

                blit_cima(china,screen);
                string palavra = "Vez do outro jogador.";
                blit_tela(screen,0);
                desenha_texto(palavra,screen,845, 38, 25);
                frame_delay(start);
                SDL_Flip(screen);
                //cout<<"Sou cliente"<<endl;
                vetor = get_Input();


                char code_recv[100];
                receber_msg(Cserver,code_recv);
                //cout<<"Recebi a msg: "<<code_recv<<endl;
                amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
                //cout<<"opa!! cheguei aqui"<<endl;
                if(code_recv[0] == '0' && code_recv[1] == '0'){
                        pontos_jogador1 -=3;
                }
                if(code_recv[0] == '0' && code_recv[1] == '1'){
                    pontos_jogador1 -=6;
                }
                if(derrotado.compare(cor1) == 0){
                    vermelhoperde = 1;
                    vermelhoganha = 0;
                    azulganha = 1;
                    azulperde = 0;
                }
                if(derrotado.compare(cor2) == 0){
                    vermelhoganha = 1;
                    vermelhoperde = 0;
                    azulperde = 1;
                    azulganha = 0;
                }

                if(pontos_jogador1<3){
                    minha_vez = 1;
                    pontos_jogador1 = 20;
                }
                if(azulperde == 1 && vermelhoganha == 1){
                    perdeu_jogo(screen);
                }
                if(vermelhoperde == 1 && azulganha == 1){
                    venceu_jogo(screen);
                }

            }
            else{

                blit_cima(china,screen);
                desenha_pontos(pontos_jogador2, screen);
                //cout<<"eu cliente, fui até aqui"<<endl;
                vetor = get_Input();
                string palavra = "Sua vez.";
                desenha_texto(palavra,screen,850, 38, 35);

                if(vetor->click == 1){

                    if(verifica_hexagono(vetor->x,vetor->y)){

                        if(compara_selecao(568,647,vetor->x,78,111,vetor->y)){
                            clica_menu_menor(screen);
                        }

                        hexagon_selected->i_before = hexagon_selected->i;
                        hexagon_selected->j_before = hexagon_selected->j;
                        if(possui_unidade("azul")){
                            blit_cima(china,screen);
                            blit_tela(screen,1);
                            blit_selecao(screen);
                            blit_lateral(hexagons[hexagon_selected->i][hexagon_selected->j]->unit,screen);
                                    while(1){
                                        int start2 = SDL_GetTicks();
                                        blit_cima(china,screen);
                                        vetor = get_Input();
                                        if(vetor->click == 1){
                                            verifica_hexagono(vetor->x,vetor->y);
                                            if(possui_unidade("azul") || (hexagons[hexagon_selected->i][hexagon_selected->j]->barrier && hexagons[hexagon_selected->i_before][hexagon_selected->j_before]->unit->unit_type != "helicoptero")){
                                                break;
                                            }
                                            if(alcance_ataque_soldado()){

                                                codifica_ataque(code_s);
                                                //cout << "passei codifica" << endl;
                                                enviar_msg(Cserver,code_s);
                                                //cout << "enviei" << endl;
                                                ataque_unidade(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
                                                dano_ataque(screen);
                                                //cout << "animei attack" << endl;
                                                if(derrotado.compare(cor1) == 0){
                                                    vermelhoperde = 1;
                                                    vermelhoganha = 0;
                                                    azulganha = 1;
                                                    azulperde = 0;
                                                }
                                                if(derrotado.compare(cor2) == 0){
                                                    vermelhoganha = 1;
                                                    vermelhoperde = 0;
                                                    azulperde = 1;
                                                    azulganha = 0;
                                                }

                                                pontos_jogador2 -= 6;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    pontos_jogador2 = 20;
                                                }
                                                break;
                                            }



                                            if(alcance_movimento_soldado()){

                                                strcpy (code_s,"00");
                                                code_s[2] = (char)(((int)'0')+hexagon_selected->i_before);
                                                code_s[3] = (char)(((int)'0')+hexagon_selected->j_before);
                                                code_s[4] = (char)(((int)'0')+hexagon_selected->i);
                                                code_s[5] = (char)(((int)'0')+hexagon_selected->j);
                                                //cout<<"Enviando msg..."<<endl;
                                                enviar_msg(Cserver,code_s);
                                                //cout<<"A mensagem enviada foi: "<<code_s  <<endl;

                                                mover_soldado(screen, hexagons[hexagon_selected->i][hexagon_selected->j]->x,hexagons[hexagon_selected->i][hexagon_selected->j]->y, totalElapsedTime, delay, lastdt);
                                                pontos_jogador2 -= 3;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    pontos_jogador2 = 20;
                                                    coleta_minerio(china, minerio_azul);
                                                    coleta_ouro(china, ouro_azul);
                                                    coleta_comida(china, comida_azul);
                                                }
                                                if((azulganha == 1) && (vermelhoperde == 1)){
                                                    venceu_jogo(screen);
                                                }
                                                if((vermelhoperde == 1) && (azulganha == 1)){
                                                    perdeu_jogo(screen);
                                                }
                                                break;
                                            }
                                                else{
                                                        blit_tela(screen,0);
                                                        blit_cima(china,screen);
                                                        break;
                                                }

                                        }
                                        frame_delay(start2);

                                    }
                        }
                        blit_tela(screen,0);
                        blit_cima(china,screen);

                    }

                }

                if((azulganha == 1) && (vermelhoperde == 1)){
                    venceu_jogo(screen);
                }
                if((vermelhoperde == 1) && (azulganha == 1)){
                    perdeu_jogo(screen);
                }
                //blit_tela(screen);
                //BlitImage(screen,mouse,vetor->x-13,vetor->y-13 );
                frame_delay(start);
                SDL_Flip(screen);
            }
            frame_delay(start1);
        }
    }


}






