#pragma once
#include "Game.h"

class GameObject {
public:
	 GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	 void Update();
	 void Render();

	 void SetRec(SDL_Rect v_destRect);
	 void SetDestX(int setX);
	 void SetDestY(int setY);

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};