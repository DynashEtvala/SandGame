#include "Sand.h"



Sand::Sand(int X, int Y) : Grain(X, Y)
{
	color = BEIGE;
	stationary = false;
	flamable = false;
	liquid = false;
	density = 0;
	type = SAND;
}


Sand::~Sand()
{}
