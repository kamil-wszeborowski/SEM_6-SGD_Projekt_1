#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = 
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,2,2,2,2,2,5,2,2,2,2,2,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,2,2,1,1,1,3,1,1,1,2,2,1,1,1,1,1,1,0 },
	{ 0,2,2,2,5,2,2,2,2,1,1,1,3,1,1,1,2,2,1,1,2,2,6,6,0 },
	{ 0,2,2,2,5,2,2,2,2,1,1,1,1,1,1,1,2,2,1,1,2,2,6,6,0 },
	{ 0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,4,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,0,0,0,1,1,1,3,1,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,0,1,1,1,1,3,1,2,2,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	water = TextureManager::LoadTexture("assets/water.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	rock = TextureManager::LoadTexture("assets/rock.png");
	grassMine = TextureManager::LoadTexture("assets/grass_mine.png");
	dirtMine = TextureManager::LoadTexture("assets/dirt_mine.png");
	win = TextureManager::LoadTexture("assets/win.png");

	LoadMap(lvl1);
	
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;

	FillVector();
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) 
	{
		for (int column = 0; column < 25; column++) 
		{
			map[row][column] = arr[row][column];
 		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 3:
				TextureManager::Draw(rock, src, dest);
				break;
			case 4:
				TextureManager::Draw(grass, src, dest);
				break;
			case 5:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 6:
				TextureManager::Draw(win, src, dest);
				break;
			default:
				break;
			}
		}
	}
}
void Map::DrawMapWithMine(){

	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 3:
				TextureManager::Draw(rock, src, dest);
				break;
			case 4:
				TextureManager::Draw(grassMine, src, dest);
				break;
			case 5:
				TextureManager::Draw(dirtMine, src, dest);
				break;
			case 6:
				TextureManager::Draw(win, src, dest);
				break;
			default:
				break;
			}
		}
	}
}
/*
SDL_Rect Map::GetPositionOfBarrier() {
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				  return src, dest;
				break;
			default:
				break;
			}
		}
	}
}
*/

std::vector<SDL_Rect> Map::FillVector() {
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			if (type == 0 || type == 3) {
				vectorMap.push_back(src);
				vectorMap.push_back(dest);
			}

			if (type == 4 || type == 5) {
				vectorMine.push_back(src);
				vectorMine.push_back(dest);
			}
			if (type == 6) {
				vectorWin.push_back(src);
				vectorWin.push_back(dest);
			}
			
		}
	}

	return vectorMap, vectorMine;
}

SDL_Rect Map::GetPositionOfBarrier(int vectorDestId, int vectorSrcId) {
	return vectorMap[vectorDestId],vectorMap[vectorSrcId];
}

SDL_Rect Map::GetPositionOfMine(int vectorDestId, int vectorSrcId) {
	return vectorMine[vectorDestId], vectorMine[vectorSrcId];
}

SDL_Rect Map::GetPositionOfWin(int vectorDestId, int vectorSrcId) {
	return vectorWin[vectorDestId], vectorWin[vectorSrcId];
}

int Map::GetSizeOfVectorMap() {
	return vectorMap.size();
}

int Map::GetSizeOfVectorMine() {
	return vectorMine.size();
}

int Map::GetSizeOfVectorWin() {
	return vectorWin.size();
}