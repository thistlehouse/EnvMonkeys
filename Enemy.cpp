#include "Enemy.h"
#include "Character.h"
#include "Sprite.h"

#include <math.h>
#include <stdlib.h>

Enemy::Enemy(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives)
	: Sprite(l, de, s_index, x, y, i_lives)
{
	goal = 0;
	classID = ENEMY_CLASID;
}

bool Enemy::Move(float x, float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);
	
	if (IsValidLevelMove(xpos, ypos))
	{
		list<Sprite *>::iterator Iter;

		for (Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			if ((*Iter) != this && (int)(*Iter)->GetX() == xpos && (int)(*Iter)->GetY() == ypos)
			{
				return false;
			}
		}

		Erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;
		facingPosition.x = x;
		facingPosition.y = y;

		Draw(pos.x, pos.y);

		if ((int)goal->GetX() == xpos && (int)goal->GetY() == ypos)
			goal->AddLives(-1);

		return true;
	}
	
	return false;
}

void Enemy::IdleUpdate(void)
{
	if (goal)
	{
		SimulateAI();
	}
}

void Enemy::AddGoal(Character *g)
{
	goal = g;
}

void Enemy::SimulateAI(void)
{
	Vector goal_pos = goal->GetPosition();
	
	Vector direction;
	
	direction.x = goal_pos.x - pos.x;
	direction.y = goal_pos.y - pos.y;
	
	float mag = sqrt(direction.x * direction.x + direction.y * direction.y);
	
	direction.x = direction.x / (mag * 5);
	direction.y = direction.y / (mag * 5);
	
	if (!Move(direction.x, direction.y))
	{
		while(!Move(float(rand() % 3 - 1), float(rand() % 3 - 1)))
		{
			
		}
	}
}