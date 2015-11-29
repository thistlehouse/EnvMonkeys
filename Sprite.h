#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "DrawEngine.h"
#include "Level.h"

enum 
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
	ENEMY_CLASID,
	FIREBALL_CLASSID,
	MAGE_CLASSID
};

struct Vector
{
	float x;
	float y;
};


class Sprite
{

public:

	Sprite(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1, int i_lives = 1);
	~Sprite();

	Vector GetPosition(void);
	float GetX(void);
	float GetY(void);

	virtual void AddLives(int num = 1);
	virtual bool Move(float x, float y);	

	int GetLives(void);
	bool IsAlive(void);	
	
	virtual void IdleUpdate(void);

	int classID;


protected:

	void Draw(float x, float y);
	void Erase(float x, float y);

	bool IsValidLevelMove(int xPos, int yPos);


	Level *level;

	DrawEngine *drawArea;

	Vector pos;
	Vector facingPosition;

	int spriteIndex;
	int numLives;	

};

#endif
