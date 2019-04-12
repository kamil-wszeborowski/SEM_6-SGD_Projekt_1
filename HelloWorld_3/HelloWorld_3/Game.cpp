#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* enymy;
Map* map;


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
	*/

	//playerTex = TextureManager::LoadTexture("assets/player.png", renderer);

	player = new GameObject("assets/player.png", 0, 0);
	enymy = new GameObject("assets/enymy.png", 116, 116);
	map = new Map();
}

void Game::handleEvents()
{
	SDL_Event event;
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
	player->Update();
	enymy->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	// tu mo¿emy dodwaæ rzyczy do renderowania
	map->DrawMap();
	player->Render();
	enymy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned !" << std::endl;
}
