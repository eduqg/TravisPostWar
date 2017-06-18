#include <iostream>
#include <stdio.h>
#include <SDL/SDL_net.h>
#include "../../../include/gamefeatures.h"

using namespace std;

void get_Network_Messages()
{

}

void enviar_msg(TCPsocket maquina, char text[])
{
    SDLNet_TCP_Send(maquina,text,strlen(text)+1);
}

void receber_msg(TCPsocket maquina, char *text)
{
    SDLNet_TCP_Recv(maquina, text, 100);
}
