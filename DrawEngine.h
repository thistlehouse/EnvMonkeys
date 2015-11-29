#ifndef _DRAWENGINE_H_
#define _DRAWENGINE_H_



class DrawEngine
{

public:

	DrawEngine(int xSize = 30, int ySize = 20);
	~DrawEngine();

	int CreateSprite(int index, char c);
	void DeleteSprite(int index);

	void EraseSprite(int posX, int posY);
	void DrawSprite(int index, int posX, int posY);
	
	void CreateBackgroundTile(int index, char c);
	void SetMap(char **);
	void DrawBackground(void);


protected:

	char **map;

	int screenWidth, screenHeight;

	char spriteImage[16];
	char tileImage[16];


private:

	void GoToXY(int x, int y);
	void CursorVisibility(bool visibility);
};

#endif
