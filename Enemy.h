#ifndef _ENEMY_H_
#define _ENEMY_H_


#include "Sprite.h"

class Level;
class Character;

class Enemy : public Sprite
{
	
public:

	Enemy(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1,
		int i_lives = 1);
		
	void AddGoal(Character *g);
	
	bool Move(float x, float y);
	
	void IdleUpdate(void);
	
protected:

	void SimulateAI(void);
	
	Character *goal;
		
};


#endif
