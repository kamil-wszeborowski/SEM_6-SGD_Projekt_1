#pragma once
#include "Game.h"


class Player {
public:
	Player(const char* texturesheet, int x, int y);
	~Player();

	void Update();
	void Render();

	SDL_Rect GetRec();
	int GetDestX();
	int GetDestY();

	void SetRec(SDL_Rect v_destRect);
	void SetDestX(int setX);
	void SetDestY(int setY);

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};