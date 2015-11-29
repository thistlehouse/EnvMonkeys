#ifndef _FIREBALL_H_
#define _FIREBALL_H_

#include "Sprite.h"

class FireBall : public Sprite
{
public:

	FireBall(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1,
			float xDir = 0, float yDir = 0, int i_lives = 1);

	void IdleUpdate(void);

protected:



};

#endif