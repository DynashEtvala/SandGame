#include "Salt.h"



Salt::Salt(int X, int Y) : Grain(X, Y)
{
	color = LIGHTGRAY;
	flamable = false;
	liquid = false;
	type = SALT;
}


Salt::~Salt()
{}
