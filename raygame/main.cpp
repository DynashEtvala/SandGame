/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "Global.h"

#include "MaterialIncludes.h"
#include "MatManager.h"
int ExpoGrow(int val, int exp)
{
	int result = 1;
	while (exp > 0)
	{
		result *= val;
		exp--;
	}
	return result;
}
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 400;
	int screenHeight = 500;
	int playHeight = screenHeight - 100; 
	int brushSize = 3;

	int speed = 0;
	int frameCount = 0;

	MatType currBrush = WALL;

	GMaterial*** matList = new GMaterial**[playHeight];

	for (int i = 0; i < playHeight; i++)
	{
		matList[i] = new GMaterial*[screenWidth];
	}

	for (int i = playHeight - 1; i >= 0; i--)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			matList[i][j] = new GMaterial(j, i);
		}
	}

	MatManager mMan = MatManager(playHeight, screenWidth);

	InitWindow(screenWidth, screenHeight, "Sand Game");

	HideCursor();

	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		Vector2 mpos = GetMousePosition();
		int x = mpos.x;
		int y = mpos.y;
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			mMan.PaintMaterial(matList, x, y, currBrush);
			mMan.PaintMaterial(matList, x, y + 1, currBrush);
			mMan.PaintMaterial(matList, x, y - 1, currBrush);
			mMan.PaintMaterial(matList, x + 1, y, currBrush);
			mMan.PaintMaterial(matList, x + 1, y + 1, currBrush);
			mMan.PaintMaterial(matList, x + 1, y - 1, currBrush);
			mMan.PaintMaterial(matList, x - 1, y, currBrush);
			mMan.PaintMaterial(matList, x - 1, y + 1, currBrush);
			mMan.PaintMaterial(matList, x - 1, y - 1, currBrush);
		}
		else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			switch (currBrush)
			{
			default:
			case AIR:
				currBrush = WALL;
				break;
			case WALL:
				currBrush = WATER;
				break;
			case WATER:
				currBrush = SAND;
				break;
			case SAND:
				currBrush = OIL;
				break;
			case OIL:
				currBrush = AIR;
				break;
			}
		}
		
		if (frameCount >= ExpoGrow(2, speed))
		{
			for (int i = playHeight - 1; i >= 0; i--)
			//for (int i = 0; i <playHeight; i++)
			{

				for (int j = 0; j < screenWidth; j++)
				{
					matList[i][j]->Update(matList, playHeight, screenWidth, mMan);
					mMan.ExecuteChanges(matList);
				}
				mMan.ClearUpdatesLine(matList, i, screenWidth); 
				
				for (int j = screenWidth - 1; j >= 0; j--)
				{
					matList[i][j]->Update(matList, playHeight, screenWidth, mMan);
					mMan.ExecuteChanges(matList);
				}
				mMan.ClearUpdatesLine(matList, i, screenWidth);
			}
			mMan.ClearUpdatesFrame(matList, playHeight, screenWidth);
			frameCount = 0;
		}
		else
		{
			frameCount++;
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		for (int i = 0; i < playHeight; i++)
		{
			for (int j = 0; j < screenWidth; j++)
			{
				DrawPixel(matList[i][j]->posX, matList[i][j]->posY, matList[i][j]->color);
			}
		}

		DrawPixel(x, y, WHITE);

		mMan.PrintMatInfo(matList, x, y);
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	for (int i = 0; i < playHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			delete matList[i][j];
		}
		delete[] matList[i];
	}
	delete[] matList;
	//--------------------------------------------------------------------------------------

	return 0;
}