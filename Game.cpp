#include <conio.h>
#include <windows.h>
#include <iostream>

#include "DrawEngine.h"
#include "Game.h"



using namespace std;

#define GAME_SPEED 33.333

Game::Game()
{
	
}

bool Game::Run(void)
{
	level  = new Level(&drawArea, 30, 20);
	
	drawArea.CreateBackgroundTile(TILE_EMPTY, ' ');
	drawArea.CreateBackgroundTile(TILE_WALL, 219);

	drawArea.CreateSprite(SPRITE_PLAYER, 1);
	drawArea.CreateSprite(SPRITE_ENEMY, '$');
	drawArea.CreateSprite(SPRITE_FIREBALL, '*');

	player = new Mage(level, &drawArea, 0);	

	level->Draw();
	level->AddPlayer(player);
	level->AddEnemies(3);

	char key = ' ';

	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;
	posX = 0;

	player->Move(0, 0);

	while (key != 'q')
	{
		while (!GetInput(&key))
		{
			TimeUpdate();
		}	

		level->KeyPress(key);
	}

	delete player;

	return true;
}

bool Game::GetInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();

		return true;
	}

	return false;
}

void Game::TimeUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;

	if (currentTime < GAME_SPEED)	
		return;

	level->Update();

	frameCount++;	
	lastTime = timeGetTime();
}

