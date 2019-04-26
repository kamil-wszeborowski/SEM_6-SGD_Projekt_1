#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render(int startLoop);
	void clean();

	bool running() { return isRunning; };

	static SDL_Event event;
	static SDL_Renderer *renderer;

private:
	int startLoop = 0;
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
	bool gameWin;
};