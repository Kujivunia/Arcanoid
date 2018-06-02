#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "gameObjectClass.h"
#include "Brick.h"
#include "Ball.h"
#include "Bat.h"
#include <fstream>
#include "MyLibrary.h"
class gameLoop

    {
 public:
  gameLoop();
  ~gameLoop();
  void init();
  void render(int, int);
  void gameStep();
  void control();  //”правление с клавиатуры
  void setRowCountB(int);
  void setColumnCountB(int);
  void setRowCountF(int);
  void setColumnCountF(int);
  bool getGameOver();
  void setGameOver(bool);
  void setScore(int);
  int getScore();
  void save();
  void load();
  void setFieldX(int);
  int getFieldX();
  void setFieldY(int);
  int getFieldY();
  bool getBorderOn();
  void setBorderOn(bool);
  void borderLine(int, int);

  // void mapLoading(char* fileName);
 private:
  int fieldX;
  int fieldY;
  int score;
  bool gameStart;
  bool borderOn;
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
  struct strSave{
  	Brick **lvlMap;
  	Bat bat;
  	Ball ball;
	};
  // FILE* mapFile;
};

#endif
