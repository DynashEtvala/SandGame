#pragma once
#include"Global.h"

class MatManager
{
private:
	MatType newMat[9];
	int height;
	int width;
	int newPosX[9];
	int newPosY[9];
	int changesReady;
public:
	MatManager();
	MatManager(int, int);
	~MatManager();
	void PrepChange(int, int, MatType);
	void ExecuteChanges(class GMaterial***);
	void ClearUpdatesLine(class GMaterial***, int, int);
	void ClearUpdatesFrame(class GMaterial***, int, int);
	void PaintMaterial(class GMaterial***, int, int, MatType);
	void PrintMatInfo(class GMaterial***, int, int);
};

