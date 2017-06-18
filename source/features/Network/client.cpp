#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <cstring>
#include "../../../include/loop.h"

using namespace std;

TCPsocket Cserver;

int conectar(char ip_text[])
{
	IPaddress ip;

	if (SDLNet_ResolveHost(&ip,ip_text,1234) < 0) {
		return 1;
	}

	Cserver = SDLNet_TCP_Open(&ip);

	if (!Cserver) {
		return 1;
	}

	return 0;
}
