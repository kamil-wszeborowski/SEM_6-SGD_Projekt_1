#pragma once
#include "Game.h"


class Player {
public:
	Player(const char* texturesheet, int x, int y);
	~Player();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};