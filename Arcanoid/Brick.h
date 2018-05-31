#ifndef BRICK_H
#define BRICK_H

#include "gameObjectClass.h"
#include "Ball.h"

class Brick : public gameObjectClass
{
	public:
		Brick();
		~Brick();
		void renderMe(int x, int y, int color);
		void delRenderMe(int x, int y, int color);

		void setBrickWide(int);
		int getBrickWide();
		void collision(Ball);
		
		bool getOnScreen();
		void setOnScreen(bool);
	protected:
	int brickWide;
	bool onScreen;
	private:
		
};

#endif


//x*y_lenght+z
