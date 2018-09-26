#include "MatManager.h"

#include"MaterialIncludes.h"

MatManager::MatManager()
{
	changesReady = 0;
}


MatManager::~MatManager()
{}


void MatManager::PrepChange(int X, int Y, MatType T)
{
	newMat[changesReady] = T;
	newPosX[changesReady] = X;
	newPosY[changesReady] = Y;
	changesReady++;
}

void MatManager::ExecuteChanges(GMaterial*** matList)
{
	for (int i = 0; i < changesReady; i++)
	{
		switch (newMat[i])
		{
		case AIR:
		default:
			delete matList[newPosY[i]][newPosX[i]];
			matList[newPosY[i]][newPosX[i]] = new GMaterial(newPosX[i], newPosY[i]);
			break;
		case WALL:
			delete matList[newPosY[i]][newPosX[i]];
			matList[newPosY[i]][newPosX[i]] = new Wall(newPosX[i], newPosY[i]);
			break;
		case WATER:
			delete matList[newPosY[i]][newPosX[i]];
			matList[newPosY[i]][newPosX[i]] = new Water(newPosX[i], newPosY[i]);
			break;
		case SAND:
			delete matList[newPosY[i]][newPosX[i]];
			matList[newPosY[i]][newPosX[i]] = new Sand(newPosX[i], newPosY[i]);
			break;
		}
	}
	changesReady = 0;
}