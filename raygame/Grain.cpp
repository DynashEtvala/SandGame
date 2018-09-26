#include "Grain.h"

#include "MatManager.h"

Grain::Grain(int X, int Y) : GMaterial(X, Y)
{}


Grain::~Grain()
{}

void Grain::Update(GMaterial*** matList, int bottom, int side, MatManager& m)
{
	if (posY == bottom - 1)
	{
		m.PrepChange(posX, posY, AIR);
	}
	else if (matList[posY + 1][posX]->type == AIR || matList[posY + 1][posX]->liquid)
	{
		m.PrepChange(posX, posY + 1, type);
		if (matList[posY + 1][posX]->liquid)
		{
			m.PrepChange(posX, posY, matList[posY + 1][posX]->type);
		}
		else
		{
			m.PrepChange(posX, posY, AIR);
		}
	}
	else if (((matList[posY + 1][posX + 1]->type == AIR || matList[posY + 1][posX + 1]->liquid) && (matList[posY][posX + 1]->type == AIR || matList[posY][posX + 1]->liquid)) || ((matList[posY + 1][posX - 1]->type == AIR || matList[posY + 1][posX - 1]->liquid) && (matList[posY][posX - 1]->type == AIR || matList[posY][posX - 1]->liquid)))
	{
		if ((matList[posY + 1][posX + 1]->type == AIR || matList[posY + 1][posX + 1]->liquid) && matList[posY + 1][posX - 1]->type != AIR)
		{
			m.PrepChange(posX + 1, posY + 1, type);
			if (matList[posY + 1][posX + 1]->liquid)
			{
				m.PrepChange(posX, posY, matList[posY + 1][posX + 1]->type);
			}
			else
			{
				m.PrepChange(posX, posY, AIR);
			}
		}
		else if (matList[posY + 1][posX + 1]->type != AIR && (matList[posY + 1][posX - 1]->type == AIR || matList[posY + 1][posX - 1]->liquid))
		{
			m.PrepChange(posX - 1, posY + 1, type);
			if (matList[posY + 1][posX - 1]->liquid)
			{
				m.PrepChange(posX, posY, matList[posY + 1][posX - 1]->type);
			}
			else
			{
				m.PrepChange(posX, posY, AIR);
			}
		}
		else
		{
			if (GetRandomValue(0, 1))
			{
				m.PrepChange(posX + 1, posY + 1, type);
				if (matList[posY + 1][posX + 1]->liquid)
				{
					m.PrepChange(posX, posY, matList[posY + 1][posX + 1]->type);
				}
				else
				{
					m.PrepChange(posX, posY, AIR);
				}
			}
			else
			{
				m.PrepChange(posX - 1, posY + 1, type);
				if (matList[posY + 1][posX - 1]->liquid)
				{
					m.PrepChange(posX, posY, matList[posY + 1][posX - 1]->type);
				}
				else
				{
					m.PrepChange(posX, posY, AIR);
				}
			}
		}
	}
}