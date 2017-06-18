#include <iostream>
#include "../include/draw.h"
#include "../include/video.h"
#include "../include/gamefeatures.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

extern void update_time();
extern void get_Input();
extern void get_Network_Messages();
extern void simulated_World();
extern void collision_Step();
extern void update_Objects();
extern SDL_Surface *render_World();
extern void misc_Tasks();

int main()
{
	SDL_Surface *screen = render_World();
	load_menu(screen);
	/*
	 * while (1) {
	 *     update_time();
	 *     get_Input();
	 *	   get_Network_Messages();
	 *	   simulated_World();
	 *	   collision_Step();
	 *	   update_Objects();
	 *	   render_World();
	 *     misc_Tasks();
	 *	   menu(screen);
	 *	   return 0;
	 * }
	 */
}
