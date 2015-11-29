#include "FireBall.h"

FireBall::FireBall(Level *l, DrawEngine *de, int s_index, float x, float y, float xDir, float yDir, int i_lives)
	: Sprite(l, de, s_index, x, y, i_lives)
{
	facingPosition.x = xDir;
	facingPosition.y = yDir;

	classID = FIREBALL_CLASSID;
}

void FireBall::IdleUpdate(void)
{
	if (Sprite::Move(facingPosition.x, facingPosition.y))
	{
		list<Sprite *>::iterator Iter;

		for (Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			if ((*Iter)->classID != classID && (int)(*Iter)->GetX() == (int)pos.x &&
				(int)(*Iter)->GetY() == (int)pos.y)
			{
				(*Iter)->AddLives(-1);

				AddLives(-1);
			}
		}
	}
	else
	{
		AddLives(-1);
	}
}