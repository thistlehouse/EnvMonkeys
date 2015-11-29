#include "Sprite.h"

Sprite::Sprite(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives)
{
	drawArea = de;

	pos.x = x;
	pos.y = y;

	spriteIndex = s_index;
	numLives = i_lives;

	facingPosition.x = 1;
	facingPosition.y = 0;

	classID = SPRITE_CLASSID;

	level = l;
}

Sprite::~Sprite()
{
	Erase(pos.x, pos.y);
}

Vector Sprite::GetPosition(void)
{
	return pos;
}

float Sprite::GetX(void)
{
	return pos.x;
}

float Sprite::GetY(void)
{
	return pos.y;
}

void Sprite::AddLives(int num)
{
	numLives += num;
}

int Sprite::GetLives(void)
{
	return numLives;
}

bool Sprite::IsAlive(void)
{
	return (numLives > 0);
}

bool Sprite::Move(float x, float y)
{
	int xPos = (int)pos.x + x;
	int yPos = (int)pos.y + y;

	if (IsValidLevelMove(xPos, yPos))
	{
		Erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;
		facingPosition.x = x;
		facingPosition.y = y;

		Draw(pos.x, pos.y);

		return true;
	}

	return false;
}

void Sprite::Draw(float x, float y)
{
	drawArea->DrawSprite(spriteIndex, (int) x, (int) y);
}

void Sprite::Erase(float x, float y)
{
	drawArea->EraseSprite((int) x, (int) y);
}

bool Sprite::IsValidLevelMove(int xPos, int yPos)
{
	if (level->level[xPos][yPos] != TILE_WALL)
		return true;

	return false;
}

void Sprite::IdleUpdate(void)
{
	
}
