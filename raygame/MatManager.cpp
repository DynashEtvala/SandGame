#include "MatManager.h"

#include"MaterialIncludes.h"

MatManager::MatManager()
{
	changesReady = 0;
	height = -1;
	width = -1;
}

MatManager::MatManager(int h, int w)
{
	changesReady = 0;
	height = h;
	width = w;
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
		if (newPosX[i] >= 0 && newPosX[i] < width && newPosY[i] >= 0 && newPosY[i] < height)
		{
			bool frameHold = matList[newPosY[i]][newPosX[i]]->updatedFrame;
			delete matList[newPosY[i]][newPosX[i]];
			switch (newMat[i])
			{
			case AIR:
			default:
				matList[newPosY[i]][newPosX[i]] = new GMaterial(newPosX[i], newPosY[i]);
				break;
			case WALL:
				matList[newPosY[i]][newPosX[i]] = new Wall(newPosX[i], newPosY[i]);
				break;
			case WATER:
				matList[newPosY[i]][newPosX[i]] = new Water(newPosX[i], newPosY[i]);
				matList[newPosY[i]][newPosX[i]]->updatedLine = true;
				break;
			case SAND:
				matList[newPosY[i]][newPosX[i]] = new Sand(newPosX[i], newPosY[i]);
				matList[newPosY[i]][newPosX[i]]->updatedLine = true;
				break;
			case OIL:
				matList[newPosY[i]][newPosX[i]] = new Oil(newPosX[i], newPosY[i]);
				matList[newPosY[i]][newPosX[i]]->updatedLine = true;
				break;
			}
			if (matList[newPosY[i]][newPosX[i]]->liquid || matList[newPosY[i]][newPosX[i]]->grain)
			{
				matList[newPosY[i]][newPosX[i]]->updatedFrame = frameHold;
			}
		}
	}
	changesReady = 0;
}

void MatManager::ClearUpdatesLine(GMaterial*** matList, int row, int side)
{
	for (int j = 0; j < side; j++)
	{
		matList[row][j]->updatedLine = false;
	}
}

void MatManager::ClearUpdatesFrame(GMaterial*** matList, int bottom, int side)
{
	for (int i = 0; i < bottom; i++)
	{
		for (int j = 0; j < side; j++)
		{
			matList[i][j]->updatedFrame = false;
		}
	}
}

void MatManager::PaintMaterial(GMaterial*** matList, int X, int Y, MatType type)
{
	if (X >= 0 && X < width && Y >= 0 && Y < height)
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
}

void MatManager::PrintMatInfo(GMaterial*** matList, int X, int Y)
{
	
}