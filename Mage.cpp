#include "Mage.h"
#include "FireBall.h"

Mage::Mage(Level *l, 
		DrawEngine *de, 
		int s_index, 
		float x, 
		float y, 
		int i_lives,
		char _spellKey, 
		char upKey, 
		char downKey, 
		char leftKey, 
		char rightKey)
	: Character(l, de, s_index, x, y, i_lives, upKey, downKey, leftKey, rightKey)
{
	spellKey = _spellKey;
	classID = MAGE_CLASSID;
}

bool Mage::KeyPress(char c)
{
	bool val = Character::KeyPress(c);

	if (val == false)
	{
		if (c == spellKey)
		{
			CastSpell();
			
			return true;
		}
	}

	return val;
}

void Mage::CastSpell(void)
{
	FireBall *temp = new FireBall(level, 
								drawArea, 
								SPRITE_FIREBALL, 
								(int) pos.x + facingPosition.x,
								(int) pos.y + facingPosition.y, 
								facingPosition.x, 
								facingPosition.y);

	level->AddNPC((Sprite *)temp);
}