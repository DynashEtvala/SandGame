#include "Water.h"



Water::Water(int X, int Y) : Liquid(X, Y)
{
	color = BLUE;
	stationary = false;
	flamable = false;
	liquid = true;
	density = 1.0;
	type = WATER;
}


Water::~Water()
{}
