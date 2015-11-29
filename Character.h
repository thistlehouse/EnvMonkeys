#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Sprite.h"
//#include "DrawEngine.h"

class Character : public Sprite
{
public:

	Character(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1, int i_lives = 3,
				char upKey = 'w', char downKey = 's', char leftKey = 'a',
				char rightKey = 'd');

	virtual bool KeyPress(char c);
	virtual void AddLives(int num = 1);


protected:

	char upKey;
	char downKey;
	char leftKey;
	char rightKey;

};

#endif
