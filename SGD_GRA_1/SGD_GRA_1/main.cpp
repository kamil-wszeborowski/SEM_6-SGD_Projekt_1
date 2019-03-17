
#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <vector>
#include <SDL.h>


// check for errors
#define errcheck(e)                                                            \
  {                                                                            \
    if (e) {                                                                   \
      cout << SDL_GetError() << endl;                                          \
      SDL_Quit();                                                              \
      return -1;                                                               \
    }                                                                          \
  }

int main(int, char **) {
	using namespace std;
	using namespace std::chrono;
	const int width = 640;
	const int height = 480;


	errcheck(SDL_Init(SDL_INIT_VIDEO) != 0);

	SDL_Window *window = SDL_CreateWindow(
		"My Next Superawesome Game", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	errcheck(window == nullptr);

	SDL_Renderer *renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE); // SDL_RENDERER_PRESENTVSYNC

	errcheck(renderer == nullptr);

	//Put your own bmp image here
	SDL_Surface *bmpSurf = SDL_LoadBMP("Texture.bmp");
	std::cout << SDL_GetError() << endl;
	SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(renderer, bmpSurf);
	SDL_FreeSurface(bmpSurf);

	//Make a target texture to render too
	SDL_Texture *texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, width, height);

	//auto dt = 15ms;
	milliseconds dt(15);

	steady_clock::time_point current_time = steady_clock::now(); // remember current time
	for (bool game_active = true; game_active;) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) { // check if there are some events
			if (event.type == SDL_QUIT)
				game_active = false;

		}

		//Now render to the texture
		SDL_SetRenderTarget(renderer, texTarget);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bmpTex, NULL, NULL);
		//Detach the texture
		SDL_SetRenderTarget(renderer, NULL);

		//Now render the texture target to our screen, but upside down
		SDL_RenderClear(renderer);
		SDL_RenderCopyEx(renderer, texTarget, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

		SDL_RenderPresent(renderer); // draw frame to screen

		this_thread::sleep_until(current_time = current_time + dt);
	}

	SDL_Delay(1000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}


/*
#include "stdafx.h"
#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[])
{
if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
std::cout << "SDL could not initialise! SDL Error: " << SDL_GetError() << std::endl;
};

return EXIT_SUCCESS;
}
*/
