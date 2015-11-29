#include <iostream>
#include <windows.h>

#include "DrawEngine.h"

using namespace std;

DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	CursorVisibility(false);

	map = 0;
}

DrawEngine::~DrawEngine()
{
	CursorVisibility(true);

	GoToXY(0, screenHeight);
}

int DrawEngine::CreateSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return index;
	}
	
	return -1;
}

void DrawEngine::DeleteSprite(int index)
{
	// TODO

}

void DrawEngine::DrawSprite(int index, int posX, int posY)
{
	GoToXY(posX, posY);

	cout << spriteImage[index];
}

void DrawEngine::EraseSprite(int posX, int posY)
{
	GoToXY(posX, posY);

	cout << ' ';
}

void DrawEngine::DrawBackground(void)
{
	if (map)
	{
		for (int y = 0; y < screenHeight; y++)
		{
			GoToXY(0, y);

			for (int x = 0; x < screenWidth; x++)
				cout << tileImage[map[x][y]];
		}
	}
}

void DrawEngine::CreateBackgroundTile(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		tileImage[index] = c;
	}
}

void DrawEngine::SetMap(char **data)
{
	map = data;
}

void DrawEngine::GoToXY(int x, int y)
{
	HANDLE outputHandle;
	COORD pos;

	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(outputHandle, pos);
}

void DrawEngine::CursorVisibility(bool visibility)
{
	HANDLE outputHandle;
	CONSOLE_CURSOR_INFO ccInfo;

	ccInfo.bVisible = visibility;
	ccInfo.dwSize = 1;
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);	

	SetConsoleCursorInfo(outputHandle, &ccInfo);
}
