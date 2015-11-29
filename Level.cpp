#include "Level.h"
#include "Character.h"
#include "Enemy.h"

#include <stdlib.h>

Level::Level(DrawEngine *de, int w, int h)
{
	drawArea = de;
	width = w;
	height = h;

	player = 0;

	// create memory for the level
	level = new char *[width];
	
	/*  
	* map grid with pointers (level memory)
	*
	*	->		|0| |1| |2| |3| |4| |5|
	*			=======================
	*		->	|0| |0| |0| |0| |0| |0|
	*			|1| |1| |1| |1| |1| |1|
	*			|2| |2| |2| |2| |2| |2|
	*			|3| |3| |3| |3| |3| |3|
	*
	*/
	for (int x = 0; x < width; x++)
	{
		level[x] = new char[height];
	}

	// create the level
	CreateLevel();

	drawArea->SetMap(level);
}

Level::~Level()
{
	for (int x = 0; x < width; x++)
	{
		delete[] level[x];
	}

	delete[] level;

	for (Iter = npc.begin(); Iter != npc.end(); Iter++)
	{
		delete (*Iter);
	}
}

void Level::CreateLevel(void)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int random = rand() % 100;

			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				level[x][y] = TILE_WALL;
			}
			else
			{
				if (random < 90 || (x < 3 && y < 3))
					level[x][y] = TILE_EMPTY;
				else
					level[x][y] = TILE_WALL;
			}			
		}
	}
}

void Level::Draw(void)
{
	drawArea->DrawBackground();
}

void Level::AddPlayer(Character *p)
{
	player = p;
}

bool Level::KeyPress(char c)
{
	if (player)
		if (player->KeyPress(c))
			return true;

	return false;
}

void Level::Update(void)
{
	for (Iter = npc.begin(); Iter != npc.end(); Iter++)
	{
		(*Iter)->IdleUpdate();

		if ((*Iter)->IsAlive() == false)
		{
			Sprite *temp = *Iter;

			Iter--;
			
			delete temp;

			npc.remove(temp);
		}
	}
}

void Level::AddEnemies(int num)
{
	int i = num;
	
	while (i > 0)
	{
		int xpos = int((float(rand() % 100) / 100 * (width - 2) + 1));
		int ypos = int((float(rand() % 100) / 100 * (height - 2) + 1));
		
		if (level[xpos][ypos] != TILE_WALL)
		{
			Enemy *temp = new Enemy(this, drawArea, SPRITE_ENEMY, (float) xpos, (float)ypos);
			
			temp->AddGoal(player);
			
			AddNPC((Sprite *)temp);
			
			i--;
		}
	}
}

void Level::AddNPC(Sprite *spr)
{
	npc.push_back(spr);
}
