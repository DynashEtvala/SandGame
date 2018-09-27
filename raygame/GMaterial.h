#pragma once
#include"Global.h"

class GMaterial
{
public:
	int posX;
	int posY;
	Color color;
	bool liquid;
	bool flamable;
	bool updated;
	float density;
	MatType type;
	GMaterial();
	GMaterial(int, int);
	~GMaterial();
	virtual void Update(GMaterial***, int, int, class MatManager&);
};

