#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <list>
#include "DrawEngine.h"

using std::list;

enum
{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL
};

enum
{
	TILE_EMPTY,
	TILE_WALL,

};

class Sprite;
class Character;


class Level
{

public:

	Level(DrawEngine *de, int width = 30, int height = 20);
	~Level();

	void AddPlayer(Character *p);
	void Update(void);
	void Draw(void);

	bool KeyPress(char c);
	
	void AddEnemies(int num);
	void AddNPC(Sprite *spr);

	friend class Sprite;

protected:

	void CreateLevel(void);


private:

	int width;
	int height;

	char **level;

	Character *player;
	DrawEngine *drawArea;
	
public:
	
	list<Sprite*> npc;
	list<Sprite*>::iterator Iter;

};

#endif
