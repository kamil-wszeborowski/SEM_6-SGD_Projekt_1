#include "Player.h"
#include "TextureManager.h"
#include "Collision.h"

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
			ypos = (ypos-32);
			break;
		case SDLK_a:
			xpos = (xpos-32);
			objTexture = TextureManager::LoadTexture("assets/player_left_border.png");
			break;
		case SDLK_d:
			xpos = (xpos+32);
			objTexture = TextureManager::LoadTexture("assets/player_right_border.png");
			break;
		case SDLK_s:
			ypos = (ypos+32);
			break;
		default:
			break;
		}
	}

	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			ypos = ypos;
			objTexture = TextureManager::LoadTexture("assets/player_stop_border.png");
			break;
		case SDLK_a:
			xpos = xpos;
			objTexture = TextureManager::LoadTexture("assets/player_stop_border.png");
			break;
		case SDLK_d:
			xpos = xpos;
			objTexture = TextureManager::LoadTexture("assets/player_stop_border.png");
			break;
		case SDLK_s:
			ypos = ypos;
			objTexture = TextureManager::LoadTexture("assets/player_stop_border.png");
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
	
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void Player::SetRec(SDL_Rect srcRect, SDL_Rect destRect){
	srcRect = srcRect;
	destRect = destRect;
};

SDL_Rect Player::GetRec() {
	return srcRect, destRect;
};