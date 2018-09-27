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
		delete matList[newPosY[i]][newPosX[i]];
		switch (newMat[i])
		{
		case AIR:
		default:
			matList[newPosY[i]][newPosX[i]] = new GMaterial(newPosX[i], newPosY[i]);
			break;
		case WALL:
			matList[newPosY[i]][newPosX[i]] = new Wall(newPosX[i], newPosY[i]);
			matList[newPosY[i]][newPosX[i]]->updated = true;
			break;
		case WATER:
			matList[newPosY[i]][newPosX[i]] = new Water(newPosX[i], newPosY[i]);
			matList[newPosY[i]][newPosX[i]]->updated = true;
			break;
		case SAND:
			matList[newPosY[i]][newPosX[i]] = new Sand(newPosX[i], newPosY[i]);
			matList[newPosY[i]][newPosX[i]]->updated = true;
			break;
		case OIL:
			matList[newPosY[i]][newPosX[i]] = new Oil(newPosX[i], newPosY[i]);
			matList[newPosY[i]][newPosX[i]]->updated = true;
			break;
		}
	}
	changesReady = 0;
}

void MatManager::ClearUpdates(GMaterial*** matList, int bottom, int side)
{
	for (int i = 0; i < bottom; i++)
	{
		for (int j = 0; j < side; j++)
		{
			matList[i][j]->updated = false;
		}
	}
}

void MatManager::PaintMaterial(GMaterial*** matList, int X, int Y, MatType type)
{
	delete matList[Y][X];
	switch (type)
	{
	case AIR:
	default:
		matList[Y][X] = new GMaterial(X, Y);
		break;
	case WALL:
		matList[Y][X] = new Wall(X, Y);
		break;
	case WATER:
		matList[Y][X] = new Water(X, Y);
		break;
	case SAND:
		matList[Y][X] = new Sand(X, Y);
		break;
	case OIL:
		matList[Y][X] = new Oil(X, Y);
		break;
	}
}

void MatManager::PrintMatInfo(GMaterial*** matList, int X, int Y)
{
	
}