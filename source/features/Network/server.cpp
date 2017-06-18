#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <cstring>
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

TCPsocket Sclient;

TCPsocket server;
int criar_servidor()
{
	IPaddress ip;
	if (SDLNet_ResolveHost(&ip, NULL, 1234) < 0) {
		cout << "deu ruim" << endl;
		return 1;
	}

	server = SDLNet_TCP_Open(&ip);
	if (!server) {
		cout<<"deu r"<<endl;
		return 1;
	}

	while (1) {

		Sclient = SDLNet_TCP_Accept(server);

		if (Sclient) {
			return 0;
		}
		if ((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000 / FPS)) {
			SDL_Delay((1000 / FPS) - (SDL_GetTicks() - start));
		}
	}
}
