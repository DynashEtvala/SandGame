#include "Liquid.h"

#include "MatManager.h"

Liquid::Liquid(int X, int Y) : GMaterial(X, Y)
{
	density = 1.0f;
}


Liquid::~Liquid()
{}


void Liquid::Update(GMaterial*** matList, int bottom, int side, MatManager& m)
{
	if (posY == bottom - 1)
	{
		m.PrepChange(posX, posY, AIR);
	}
	else if (matList[posY + 1][posX]->type == AIR)
	{
		m.PrepChange(posX, posY + 1, type);
		m.PrepChange(posX, posY, AIR);
	}
	else if ((matList[posY + 1][posX + 1]->type == AIR && matList[posY][posX + 1]->type == AIR) || (matList[posY + 1][posX - 1]->type == AIR && matList[posY][posX - 1]->type == AIR))
	{
		if (matList[posY + 1][posX + 1]->type == AIR && matList[posY + 1][posX - 1]->type != AIR)
		{
			m.PrepChange(posX + 1, posY + 1, type);
			m.PrepChange(posX, posY, AIR);
		}
		else if (matList[posY + 1][posX + 1]->type != AIR && matList[posY + 1][posX - 1]->type == AIR)
		{
			m.PrepChange(posX - 1, posY + 1, type);
			m.PrepChange(posX, posY, AIR);
		}
		else
		{
			if (GetRandomValue(0, 1))
			{
				m.PrepChange(posX + 1, posY + 1, type);
				m.PrepChange(posX, posY, AIR);
			}
			else
			{
				m.PrepChange(posX - 1, posY + 1, type);
				m.PrepChange(posX, posY, AIR);
			}
		}
	}
	else
	{
		int leftMove = 0;
		int rightMove = 0;
		for (int i = 0; i < side - posX; i++)
		{
			if (matList[posY + 1][posX + i]->type == AIR)
			{
				rightMove = i;
				for (int j = 0; j < i; j++)
				{
					if (matList[posY][posX + i - j]->type != AIR && !matList[posY][posX + i - j]->liquid)
					{
						rightMove = 0;
						break;
					}
				}
				break;
			}
		}
		if (matList[posY][posX + 1]->type != AIR)
		{
			rightMove = 0;
		}
		for (int i = 0; i < posX; i++)
		{
			if (matList[posY + 1][posX - i]->type == AIR)
			{
				leftMove = i;
				for (int j = 0; j < i; j++)
				{
					if (matList[posY][posX - i + j]->type != AIR && !matList[posY][posX - i + j]->liquid)
					{
						leftMove = 0;
						break;
					}
				}
				break;
			}
		}
		if (matList[posY][posX - 1]->type != AIR && matList[posY][posX - 2]->type != AIR)
		{
			leftMove = 0;
		}
		if (rightMove < leftMove && rightMove != 0 && leftMove != 0)
		{
			m.PrepChange(posX + 1, posY, type);
			m.PrepChange(posX, posY, AIR);
		}
		else if (rightMove > leftMove && leftMove != 0 && rightMove != 0)
		{
			m.PrepChange(posX - 1, posY, type);
			m.PrepChange(posX, posY, AIR);
		}
		else if (rightMove == leftMove && rightMove != 0)
		{
			if (GetRandomValue(0, 1))
			{
				m.PrepChange(posX + 1, posY, type);
				m.PrepChange(posX, posY, AIR);
			}
			else
			{
				m.PrepChange(posX - 1, posY, type);
				m.PrepChange(posX, posY, AIR);
			}
		}
	}
}
