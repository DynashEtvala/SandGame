#include "Wall.h"



Wall::Wall(int X, int Y) : GMaterial(X, Y)
{
	posX = X;
	posY = Y;
	color = GRAY;
	stationary = true;
	flamable = false;
	liquid = false;
	density = 0;
	type = WALL;
}


Wall::~Wall()
{}