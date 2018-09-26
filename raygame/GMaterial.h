#pragma once
#include"Global.h"

class GMaterial
{
public:
	int posX;
	int posY;
	Color color;
	bool stationary;
	bool liquid;
	bool flamable;
	float density;
	MatType type;
	GMaterial();
	GMaterial(int, int);
	~GMaterial();
	virtual void Update(GMaterial***, int, int, class MatManager&);
};

