#include "GMaterial.h"

#include "MatManager.h"

GMaterial::GMaterial()
{
	posX = 0;
	posY = 0;
	color = BLANK;
	stationary = false;
	flamable = false;
	liquid = false;
	density = 0;
	type = AIR;
}


GMaterial::GMaterial(int X, int Y)
{
	posX = X;
	posY = Y;
	color = BLANK;
	stationary = false;
	flamable = false;
	liquid = false;
	density = 0;
	type = AIR;
}


GMaterial::~GMaterial()
{}

void GMaterial::Update(GMaterial***, int, int, MatManager&){}