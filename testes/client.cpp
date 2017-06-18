#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip, "localhost", 1234);

	TCPsocket client = SDLNet_TCP_Open(&ip);

	char text[100];

	while (1) {
		cout << "O servidor vai digitar..." << endl;
		SDLNet_TCP_Recv(client, text, 100);
		cout << "O servidor diz: " << text << endl;
		cout << "Digite AGORA" << endl;
		cin.getline(text, 100);
		SDLNet_TCP_Send(client, &text, 100);
		if (strcmp(text, "sair") == 0) {
			break;
		}
	}

	/* precisa fechar porque senão, não dá pra usar a mesma porta denovo */
	SDLNet_TCP_Close(client);

	SDLNet_Quit();
	SDL_Quit();
}
