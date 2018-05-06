#ifndef BRICK_H
#define BRICK_H

#include "gameObjectClass.h"

class Brick : public gameObjectClass
{
	public:
		Brick();
		~Brick();
		void renderMe(int x, int y, int color);
		void setBrickWide(int);
		void collision();
	protected:
	int brickWide;
	private:
		
};

#endif


//x*y_lenght+z
