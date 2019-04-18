#pragma once
#include <SDL.h>
#include <iostream>

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};