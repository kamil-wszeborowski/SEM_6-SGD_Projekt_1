#include "Player.h"
#include "TextureManager.h"

Player::Player(const char* texturesheet, int x, int y) {
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void Player::Update()
{

	//xpos++;
	//ypos++;

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			ypos = -10;
			break;
		case SDLK_a:
			xpos = -10;
			break;
		case SDLK_d:
			xpos = 10;
			break;
		case SDLK_s:
			ypos = 10;
			break;
		default:
			break;
		}
	}

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

	
	
	
	/*
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			ypos = 0;
			break;
		case SDLK_a:
			xpos = 0;
			break;
		case SDLK_d:
			xpos = 0;
			break;
		case SDLK_s:
			ypos = 0;
			break;
		default:
			break;
		}
	}*/
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
