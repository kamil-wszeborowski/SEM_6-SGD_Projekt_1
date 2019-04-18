#pragma once
#include "Game.h"


class Player {
public:
	Player(const char* texturesheet, int x, int y);
	~Player();

	void Update();
	void Render();

	void SetRec(SDL_Rect srcRect,SDL_Rect destRect);
	SDL_Rect GetRec();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};