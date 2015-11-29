#ifndef _GAME_H_
#define _GAME_H_

#include "DrawEngine.h"
#include "Character.h"
#include "Level.h"
#include "Mage.h"

class Game
{
public:

	Game();
	bool Run(void);
	

protected:

	bool GetInput(char *c);
	void TimeUpdate(void);

private:
	
	Level *level;
	Mage *player;

	double frameCount;
	double startTime;
	double lastTime;
	
	int posX;

	DrawEngine drawArea;
};

#endif
