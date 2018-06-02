#include <iostream>
#include "gameObjectClass.h"
#include "Brick.h"
#include "Ball.h"
#include "Bat.h"
#include "gameLoop.h"
#include <cmath>
#include "windows.h"
#include "MyLibrary.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <locale>
#include <map>
using namespace std;
gameLoop::gameLoop() {}

bool gameLoop::getGameOver() { return gameOver; }
void gameLoop::setGameOver(bool a) { gameOver = a; }

bool gameLoop::getBorderOn() { return this->borderOn; }
void gameLoop::setBorderOn(bool a) { this->borderOn = a; }

void gameLoop::setScore(int a) { score = a; }
int gameLoop::getScore() { return score; }
void gameLoop::setRowCountB(int a) { rowCountB = a; }
void gameLoop::setColumnCountB(int a) { columnCountB = a; }
void gameLoop::setRowCountF(int a) { rowCountF = a; }
void gameLoop::setColumnCountF(int a) { columnCountF = a; }

void gameLoop::setFieldX(int a) { this->fieldX = a; }
int gameLoop::getFieldX() { return this->fieldX; }

void gameLoop::setFieldY(int a) { this->fieldY = a; }
int gameLoop::getFieldY() { return this->fieldY; }

void gameLoop::init() {
  srand(time(0));
  this->setGameOver(false);
  this->fieldX = 0;
  this->fieldY = 0;
  this->oldXB = 0;
  this->oldYB = 0;
  this->playerHealth = 3;
  this->score = 0;
  borderOn = false;
  gameStart - false;
  ball.setExist(true);
  ball.setX(columnCountF / 2);
  ball.setY(rowCountF - 2);
  ball.setOldX(columnCountF / 2 - 1);
  ball.setOldY(rowCountF - 2);
  ball.setSpeed(0.16);
  ball.setColor(15);

  ball.setAlphaAngle(degToRad(-90));

  ball.setMovY(ball.getSpeed() * sin(ball.getAlphAngle()));
  ball.setMovX(ball.getSpeed() * cos(ball.getAlphAngle()));
  bat.setSize(5);
  bat.setX(columnCountF / 2);
  bat.setY(rowCountF - 1);
  bat.setColor(14);
  lvlMap = new Brick*[rowCountB];
  srand(time(0));
  for (int i = 0; i < rowCountB; i++) {
    lvlMap[i] = new Brick[columnCountB];
  }

  for (int i = 0; i < rowCountB; i++) {
    for (int j = 0; j < columnCountB; j++) {
      lvlMap[i][j].setX(j * 3);
      lvlMap[i][j].setY(i);
      lvlMap[i][j].setHealth(1);
      lvlMap[i][j].setID(0);
      lvlMap[i][j].setColor(i + 11);
      lvlMap[i][j].setBrickWide(2);
      lvlMap[i][j].setExist(true);
      lvlMap[i][j].setOnScreen(false);
    }
  }
}

void gameLoop::borderLine(int fieldX, int fieldY) {
  unsigned char leftTop = 201;
  unsigned char horizontal = 205;
  unsigned char rightTop = 187;
  unsigned char vertical = 186;
  unsigned char leftBot = 200;
  unsigned char rightBot = 188;

  if (borderOn == false) {
    systemSetupML();
    setTextColorML(15);

    gotoCursXY(fieldX - 1, fieldY - 1);
    std::cout << leftTop;
    for (int i = 0; i < columnCountF; i++) std::cout << horizontal;
    std::cout << rightTop;
    gotoCursXY(fieldX - 1, fieldY + rowCountF);
    std::cout << leftBot;
    for (int i = 0; i < columnCountF; i++) std::cout << horizontal;
    std::cout << rightBot;

    for (int i = fieldY; i < rowCountF + fieldY; i++) {
      gotoCursXY(fieldX - 1, i);
      std::cout << vertical;
      gotoCursXY(fieldX + columnCountF, i);
      std::cout << vertical;
    }

    gotoCursXY(columnCountF + 1 + fieldX, fieldY - 1);
    for (int i = 0; i < 9; i++) {
      std::cout << horizontal;
    }

    std::cout << rightTop;
    gotoCursXY(columnCountF + 1 + fieldX, fieldY);
    std::cout << " SCORE:";

    gotoCursXY(columnCountF + 1 + fieldX, rowCountF + fieldY);
    for (int i = 0; i < 9; i++) {
      std::cout << horizontal;
    }
    std::cout << rightBot;

    for (int i = fieldY; i < rowCountF + fieldY; i++) {
      gotoCursXY(fieldX + columnCountF + 10, i);
      std::cout << vertical;
    }

    borderOn = true;
  }
}

void gameLoop::render(int fieldX, int fieldY) {
	this->fieldX = fieldX;
	this->fieldY = fieldY;
  borderLine(fieldX, fieldY);
  gotoCursXY(fieldX + columnCountF + 2, fieldY + 1);
  std::cout << score;

  for (int i = 0; i < rowCountB; i++) {
    for (int j = 0; j < columnCountB; j++) {
      if (lvlMap[i][j].getOnScreen() == false &&
          lvlMap[i][j].getExist() == true) {
        lvlMap[i][j].renderMe(lvlMap[i][j].getX() + fieldX,
                              lvlMap[i][j].getY() + fieldY,
                              lvlMap[i][j].getColor());
        lvlMap[i][j].setOnScreen(true);
      }
      if (lvlMap[i][j].getExist() == false) {
        lvlMap[i][j].delRenderMe(lvlMap[i][j].getX() + fieldX,
                                 lvlMap[i][j].getY() + fieldY,
                                 lvlMap[i][j].getColor());
        lvlMap[i][j].setOnScreen(false);
      }
    }
  }
  if (bat.getX() == bat.getOldX()) {
  } else {
    bat.DelRenderMe(bat.getOldX() + fieldX, bat.getY() + fieldY,
                    bat.getColor());
    bat.renderMe(bat.getX() + fieldX, bat.getY() + fieldY, bat.getColor());
  }

  if (ball.getX() == ball.getOldX() && ball.getY() == ball.getOldY()) {
  } else {
    ball.DelRenderMe(round(ball.getOldX() + fieldX),
                     round(ball.getOldY() + fieldY), ball.getColor());
    ball.renderMe(round(ball.getX() + fieldX), round(ball.getY() + fieldY),
                  ball.getColor());
  }
  if (gameStart == false)
    bat.renderMe(bat.getX() + fieldX, bat.getY() + fieldY, bat.getColor());
}

void gameLoop::gameStep() {
  if (gameStart == true) ball.moveStep();

  bat.setOldX(bat.getX());
  int bx;
  int by;
  by = round(ball.getY());
  bx = round(ball.getX()) / 3;

  if (round(ball.getY()) < rowCountB) {
    if (lvlMap[by][bx].getExist() == true) {
      lvlMap[by][bx].setExist(false);
      if (round(ball.getOldY()) == by &&
          (ball.getOldX() < bx || ball.getOldX() > bx)) {
        ball.setMovX(-ball.getMovX());
      } else
        ball.setMovY(-ball.getMovY());

      score += lvlMap[by][bx].getColor() * 2;
    }
  }

  if (ball.getY() >= bat.getY() - 1 &&
      (ball.getX() >= bat.getX() - (bat.getSize() - 1) / 2 &&
       ball.getX() <= bat.getX() + (bat.getSize() - 1) / 2) &
          (gameStart == true)) {
    ball.setMovY(-ball.getMovY());

    if (round(ball.getX()) == bat.getX() - (bat.getSize() - 1) / 2) {
      ball.changeMoveAngleTo(degToRad(150));
    }
    if (round(ball.getX()) == bat.getX() - (bat.getSize() - 1) / 2 + 1) {
      ball.changeMoveAngleTo(degToRad(120));
    }
    if (round(ball.getX()) == bat.getX() - (bat.getSize() - 1) / 2 + 2) {
      ball.setX(round(ball.getX()));
      ball.changeMoveAngleTo(degToRad(90));
    }
    if (round(ball.getX()) == bat.getX() - (bat.getSize() - 1) / 2 + 3) {
      ball.changeMoveAngleTo(degToRad(60));
    }
    if (round(ball.getX()) == bat.getX() - (bat.getSize() - 1) / 2 + 4) {
      ball.changeMoveAngleTo(degToRad(30));
    }
  }

  if (ball.getY() <= 0) ball.setMovY(-ball.getMovY());
  if (ball.getX() <= 0 || ball.getX() >= columnCountF - 1)
    ball.setMovX(-ball.getMovX());
  if (ball.getY() >= rowCountF) {
    setGameOver(true);
  }

  if (GetAsyncKeyState(VK_LEFT)) {
    if (gameStart == false) keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
    if (bat.getX() > 2) bat.setX(bat.getX() - 1);
  }
  if (GetAsyncKeyState(VK_RIGHT)) {
    if (gameStart == false) keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
    if (bat.getX() < columnCountF - 3) bat.setX(bat.getX() + 1);
  }
  if (GetAsyncKeyState(VK_UP)) {
    keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
    gameStart = true;
  }
  if (GetAsyncKeyState(VK_SHIFT)) {
  keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
    save();
  }
  if (GetAsyncKeyState(VK_SPACE)) {
  keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
    load();
  }
}
void gameLoop::save() {
  /* Brick e[rowCountB][columnCountB];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 11; j++) {
      e[i][j] = lvlMap[i][j];
    }
  }
  FILE* f = fopen("ARC_SAVE.MAP", "wb");
  fwrite(e, 1, sizeof(e), f);

  fclose(f);
  */
  ofstream fout;
  fout.open("ASF.txt",ios::out);
  if (fout !=NULL)
	 {  
		/*
		fout
		<<"borderOn:"<<this->borderOn<<'\n'
		<<"columnCountB:"<<this->columnCountB<<'\n'
		<<"columnCountF:"<<this->columnCountF<<'\n'
		<<"fieldX:"<<this->fieldX<<'\n'
		<<"fieldY:"<<this->fieldY<<'\n'
		<<"gameOver:"<<this->gameOver<<'\n'
		<<"gameStart:"<<this->gameStart<<'\n'
		<<"oldXB:"<<this->oldXB<<'\n'
		<<"oldYB:"<<this->oldYB<<'\n'
		<<"playerHealth:"<<this->playerHealth<<'\n'
		<<"rowCountB:"<<this->rowCountB<<'\n'
		<<"rowCountF:"<<this->rowCountF<<'\n'
		<<"score:"<<this->score<<'\n'
		<<"ball.getX():"<<this->ball.getX()<<'\n'
		<<"ball.getY():"<<this->ball.getY()<<'\n'
		<<"ball.getOldX():"<<this->ball.getOldX()<<'\n'
		<<"ball.getOldY():"<<this->ball.getOldY()<<'\n'
		<<"ball.getAlphAngle():"<<this->ball.getAlphAngle()<<'\n'
		<<"ball.getSpeed():"<<this->ball.getSpeed()<<'\n'
		<<"bat.getX():"<<this->bat.getX()<<'\n'
		<<"bat.getY():"<<this->bat.getY()<<'\n'
		<<"bat.getOldX():"<<this->bat.getOldX()<<'\n'
		<<"{END BLOCK}"<<'\n'
		;
		*/
	fout
	<<borderOn<<' '
	<<columnCountB<<' '
	<<columnCountF	<<' '
	<<fieldX<<' '
	<<fieldY<<' '
	<<gameOver<<' '
	<<gameStart<<' '
	<<oldXB<<' '
	<<oldYB<<' '
	<<playerHealth<<' '
	<<rowCountB<<' '
	<<rowCountF<<' '
	<<score<<' '
	<<this->ball.getX()<<' '
	<<this->ball.getY()<<' '
	<<this->ball.getOldX()<<' '
	<<this->ball.getOldY()<<' '
	<<this->ball.getAlphAngle()<<' '
	<<this->ball.getSpeed()<<' '
	<<this->bat.getX()<<' '
	<<this->bat.getY()<<' '
	<<this->bat.getOldX()
	<<'\n'
	;
	
	
	
		
		for (int i = 0; i<rowCountB;++i){
			for (int j = 0; j<columnCountB;++j){
				fout
				<<this->lvlMap[i][j].getExist()
				<<' '
				<<this->lvlMap[i][j].getOnScreen()
				<<' '
				;
			}
		}
	}
  fout.close();
}
void gameLoop::load() 
{
  ifstream fin;
  char c = 'b';
  double d;
  int i;
  bool b;
  fin.open("ASF.txt",ios::in);
  if (fin !=NULL)
	{ 
	/* 
		while (c!=':') fin>>c; fin>>this->borderOn;
		while (c!=':') fin>>c; fin>>this->columnCountB; 
		while (c!=':') fin>>c; fin>>this->columnCountF; 
		while (c!=':') fin>>c; fin>>this->fieldX; 
		while (c!=':') fin>>c; fin>>this->fieldY; 
		while (c!=':') fin>>c; fin>>this->gameOver; 
		while (c!=':') fin>>c; fin>>this->gameStart; 
		while (c!=':') fin>>c; fin>>this->oldXB; 
		while (c!=':') fin>>c; fin>>this->oldYB; 
		while (c!=':') fin>>c; fin>>this->playerHealth;
		while (c!=':') fin>>c; fin>>this->rowCountB; 
		while (c!=':') fin>>c; fin>>this->rowCountF;
		while (c!=':') fin>>c; fin>>this->score;
		while (c!=':') fin>>c; fin>>d; this->ball.setX(d); 
		while (c!=':') fin>>c; fin>>d; this->ball.setY(d);
		while (c!=':') fin>>c; fin>>d; this->ball.setOldX(d);
		while (c!=':') fin>>c; fin>>d; this->ball.setOldY(d);
		while (c!=':') fin>>c; fin>>d; this->ball.setAlphaAngle(d);
		while (c!=':') fin>>c; fin>>d; this->ball.setSpeed(d);
		while (c!=':') fin>>c; fin>>d; this->bat.setX(d);
		while (c!=':') fin>>c; fin>>d; this->bat.setY(d);
		while (c!=':') fin>>c; fin>>i; this->bat.setOldX(i);
		while (c!='}') fin>>c; fin>>c;
		
		for (int i = 0; i<rowCountB; i++){
			for (int j = 0; j<columnCountB; j++){
					fin>>c;
					fin>>b;
					lvlMap[i][j].setExist(b);
					fin>>c;
					fin>>b;
					lvlMap[i][j].setOnScreen(b);
					fin>>c;
			}				
		}
		*/
	fin
	>>borderOn
	>>columnCountB
	>>columnCountF
	>>fieldX
	>>fieldY
	>>gameOver
	>>gameStart
	>>oldXB
	>>oldYB
	>>playerHealth
	>>rowCountB
	>>rowCountF
	>>score
	;
	fin>>d;	this->ball.setX(d);
	fin>>d;	this->ball.setY(d);
	fin>>d;	this->ball.setOldX(d);
	fin>>d;	this->ball.setOldY(d);
	fin>>d;	this->ball.setAlphaAngle(d);
	fin>>d;	this->ball.setSpeed(d);
	fin>>i;	this->bat.setX(i);
	fin>>i;	this->bat.setY(i);
	fin>>i;	this->bat.setOldX(i);
	
		
		for (int i = 0; i<rowCountB;++i){
			for (int j = 0; j<columnCountB;++j){
				
				fin>>b;
				this->lvlMap[i][j].setExist(b);
				fin>>b;
				this->lvlMap[i][j].setOnScreen(b);
				
			}
		}
	}
  fin.close();
	

}
gameLoop::~gameLoop() {}





