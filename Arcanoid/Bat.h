#ifndef BAT_H
#define BAT_H

#include "gameObjectClass.h"

class Bat : public gameObjectClass
{
	public:
	int getSize();
	void setSize(int);
			void renderMe(int x, int y, int color);
			void DelRenderMe(int x, int y, int color);
		void setOldX(int);
		int getOldX();
	protected:
	int size;	
	int oldX;
	int oldY;
};

#endif
