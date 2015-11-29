#ifndef _MAGE_H_
#define _MAGE_H_

#include "DrawEngine.h"
#include "Character.h"

class Mage : public Character
{
public:

	Mage(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1, int i_lives = 3,
		char spellKey = ' ', char upKey = 'w', char downKey = 's', char leftKey = 'a', char rightKey = 'd');

	bool KeyPress(char c);


protected:

	void CastSpell(void);

private:

	char spellKey;

};


#endif