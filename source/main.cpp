#include <iostream>

using namespace std;

extern void update_time();
extern int get_Input();
extern void get_Network_Messages();
extern void simulated_World();
extern void collision_Step();
extern void update_Objects();
extern void render_World(int op);
extern void misc_Tasks();

int main()
{

	int retorno_input;

	while (1) {
		update_time();
		retorno_input = get_Input();
		get_Network_Messages();
		simulated_World();
		collision_Step();
		update_Objects();
		render_World(retorno_input);
		misc_Tasks();
		/* return 0; */
	}
}
