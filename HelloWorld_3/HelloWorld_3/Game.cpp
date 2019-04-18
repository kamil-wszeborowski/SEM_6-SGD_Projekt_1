#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Collision.h"

GameObject* one;
GameObject* two;
GameObject* three;
GameObject* start;

Player* player;
Collision* collision;

GameObject* end;
Map* map;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags=0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised! ..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window,-1,0);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	/*
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	playerTex = TextureManager::LoadTexture("assets/player.png", renderer);
	*/

	three = new GameObject("assets/3.png", 384, 304);
	two = new GameObject("assets/2.png", 384, 304);
	one = new GameObject("assets/1.png", 384, 304);
	start = new GameObject("assets/go.png", 384, 304);
	end = new GameObject("assets/game_over.png", 350, 270);

	player = new Player("assets/player_stop_border.png", 0, 0);
	//player = new GameObject("assets/player.png", 0, 0);
	
	map = new Map();

	collision = new Collision();

	//collision->AABB(player->GetRec, map->GetPositionOfBarrier);
}

void Game::handleEvents()
{
	//SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	//SDL_Rect beforeCollision;
	//SDL_Rect beforeCollision;
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 32;
	srcrect.h = 32;
	dstrect.x = 640 / 2;
	dstrect.y = 480 / 2;
	dstrect.w = 32;
	dstrect.h = 32;


	three->Update();
	two->Update();
	one->Update();
	start->Update();
	end->Update();
	
	//beforeCollision = player->GetRec();
	player->Update();
	if (collision->AABB(player->GetRec(), map->GetPositionOfBarrier())) {
		player->SetRec(srcrect,dstrect);
	}
	
}

void Game::render(int startLoop)
{
//	SDL_RenderClear(renderer);
	// tu mo¿emy dodwaæ rzyczy do renderowania
	int timeOfDealy = 1000;

	switch (startLoop)
	{
	case 0:
		SDL_RenderClear(renderer);
			map->DrawMap();
			three->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 1:
		SDL_RenderClear(renderer);
			map->DrawMap();
			two->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 2:
		SDL_RenderClear(renderer);
			map->DrawMap();
			one->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 3:	
		SDL_RenderClear(renderer);
			map->DrawMap();
			start->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 4:
		SDL_RenderClear(renderer);
			map->DrawMap();
			end->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	default:
		SDL_RenderClear(renderer);
			map->DrawMap();
			player->Render();
		SDL_RenderPresent(renderer);
		break;
	}
	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned !" << std::endl;
}
