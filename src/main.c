/* Pong
 * A pong game made in C, using the SDL2 framework.
 */
#include <SDL.h>
#include <stdlib.h>
#include "dbg.h"

int main(void)
{
	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;
	
	check(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0,
		"Could not initialize SDL with SDL_INIT_VIDEO and SDL_INIT_EVENTS flag: %s", SDL_GetError());
		
	win = SDL_CreateWindow("Pong", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
	check(win != NULL, "Could not create window: %s", SDL_GetError());
	
	ren = SDL_CreateRenderer(win, -1, 0);
	check(ren != NULL, "Could not create renderer: %s", SDL_GetError());
	
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;

error:
	return 1;
}
