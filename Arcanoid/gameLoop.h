#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "gameObjectClass.h"
#include "Brick.h"
#include "Ball.h"
#include "Bat.h"
#include <fstream>
class gameLoop

{
	public:
		gameLoop();
		~gameLoop();
		void init();
		void render();
		void gameStep();//16ms
		void control(); //”правление с клавиатуры
		void setRowCountB(int);
		void setColumnCountB(int);
		void setRowCountF(int);
		void setColumnCountF(int);
		bool getGameOver();
		void setGameOver(bool);
		void setScore(int);
		int getScore();
		
		//void mapLoading(char* fileName);
	private:
		int score;
		bool gameOver;
		int rowCountB;
		int columnCountB;
		int rowCountF;
		int columnCountF;
		int oldXB;
		int playerHealth;
		int oldYB;
		Ball ball;
		Brick **lvlMap;
		Bat bat;
		//FILE* mapFile;
};

#endif
