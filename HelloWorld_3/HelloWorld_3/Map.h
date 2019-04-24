#pragma once
#include "Game.h"
#include <vector>

class Map
{
public:
	
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

	//SDL_Rect GetPositionOfBarrier();
	std::vector<SDL_Rect> FillVectorMap();
	
	SDL_Rect GetPositionOfBarrier(int vectorDestId,int vectorSrcId);
	int GetSizeOfVectorMap();
	
private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
	std::vector<SDL_Rect> vectorMap;
	
};