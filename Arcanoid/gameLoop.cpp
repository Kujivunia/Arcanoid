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
gameLoop::gameLoop()
{	
}

		bool gameLoop::getGameOver(){
			return gameOver;
		}
		void gameLoop::setGameOver(bool a){
			gameOver = a;
		}

		bool gameLoop::getBorderOn(){
			return this->borderOn;
		}
		void gameLoop::setBorderOn(bool a){
			this->borderOn = a;
		}

		void gameLoop::setScore(int a){
			score = a;
		}
		int gameLoop::getScore(){
		return score;
		}
		void gameLoop::setRowCountB(int a){
			rowCountB = a;
		}
		void gameLoop::setColumnCountB(int a){
			columnCountB = a;
		}
		void gameLoop::setRowCountF(int a){
			rowCountF = a;
		}
		void gameLoop::setColumnCountF(int a){
			columnCountF = a;
		}
		
		void gameLoop::setFieldX(int a){
	 	this->fieldX = a;
		}
		int gameLoop::getFieldX(){
		return this->fieldX;
		}
		
		void gameLoop::setFieldY(int a){
		this->fieldY = a;
		
		}
		int gameLoop::getFieldY(){
		return this->fieldY;
		}
		
void gameLoop::init(){
	srand(time(0));
	this->setGameOver(false);
	this->fieldX = 0;
	this->fieldY = 0;
	this->score = 0;
	borderOn = false;
	gameStart - false;
	ball.setExist(true);
	ball.setX(columnCountF/2);
	ball.setY(rowCountF-2);
	ball.setOldX(columnCountF/2-1);
	ball.setOldY(rowCountF-2);
	ball.setSpeed(0.16);
	ball.setColor(15);
	
	ball.setAlphaAngle(degToRad(-90));
	
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	bat.setSize(5);
	bat.setX(columnCountF/2);
	bat.setY(rowCountF-1);
	bat.setColor(14);
	lvlMap=new Brick*[rowCountB];
	srand(time(0));
	for (int i=0;i<rowCountB; i++){
		lvlMap[i] = new Brick [columnCountB];
	}		
	
	for (int i=0;i<rowCountB;i++){	
		for (int j=0;j<columnCountB;j++){
			lvlMap[i][j].setX(j*3);
			lvlMap[i][j].setY(i);
			lvlMap[i][j].setHealth(1);
			lvlMap[i][j].setID(0);
			lvlMap[i][j].setColor(i+11);
			lvlMap[i][j].setBrickWide(2);
			lvlMap[i][j].setExist(true);
			lvlMap[i][j].setOnScreen(false);
		}
	}	
}

void gameLoop::borderLine(int fieldX, int fieldY){
	unsigned char leftTop = 201;
unsigned char horizontal = 205;
unsigned char rightTop = 187;
unsigned char vertical = 186;
unsigned char leftBot = 200;
unsigned char rightBot = 188;

if (borderOn == false){
	systemSetupML();
	setTextColorML(15);

	gotoCursXY(fieldX-1,fieldY-1);
	std::cout<<leftTop;
	for (int i = 0; i<columnCountF; i++) std::cout<<horizontal;
	std::cout<<rightTop;
	gotoCursXY(fieldX-1,fieldY+rowCountF);
	std::cout<<leftBot;
	for (int i = 0; i<columnCountF; i++) std::cout<<horizontal;	
	std::cout<<rightBot;
	
	for (int i = fieldY; i<rowCountF+fieldY; i++) {
			gotoCursXY(fieldX-1, i);
			std::cout<<vertical;
			gotoCursXY(fieldX+columnCountF, i);
			std::cout<<vertical;
			
	}
	
	gotoCursXY(columnCountF+1+fieldX,fieldY-1);
	for (int i = 0; i<9; i++){
		std::cout<<horizontal;
	}
	
	std::cout<<rightTop;
	gotoCursXY(columnCountF+1+fieldX,fieldY);
	std::cout<<" SCORE:";
	
	gotoCursXY(columnCountF+1+fieldX,rowCountF+fieldY);
	for (int i = 0; i<9; i++){
		std::cout<<horizontal;
	}
	std::cout<<rightBot;
	
	for (int i = fieldY; i<rowCountF+fieldY; i++) {
			gotoCursXY(fieldX+columnCountF+10, i);
			std::cout<<vertical;			
	}	
	
	
	borderOn = true;
}
	
}

void gameLoop::render(int fieldX, int fieldY)
{

	borderLine(fieldX, fieldY);
	gotoCursXY(fieldX+columnCountF+2,fieldY+1);
	std::cout<<score;
	
	for (int i=0;i<rowCountB;i++){	
		for (int j=0;j<columnCountB;j++){
			if (lvlMap[i][j].getOnScreen() == false && lvlMap[i][j].getExist() == true)
				{
					lvlMap[i][j].renderMe(lvlMap[i][j].getX()+fieldX,lvlMap[i][j].getY()+fieldY,lvlMap[i][j].getColor());
					lvlMap[i][j].setOnScreen(true);
				}
			if (lvlMap[i][j].getExist() == false)
				{
					lvlMap[i][j].delRenderMe(lvlMap[i][j].getX()+fieldX,lvlMap[i][j].getY()+fieldY,lvlMap[i][j].getColor());
					lvlMap[i][j].setOnScreen(false);
				}			
		}
	}	
	if (bat.getX() == bat.getOldX())
	{} 
	else
	{
		bat.DelRenderMe(	bat.getOldX()+fieldX,	bat.getY()+fieldY,	bat.getColor()	);
		bat.renderMe(bat.getX()+fieldX,bat.getY()+fieldY,bat.getColor());		
	}
	
	if (ball.getX() == ball.getOldX() && ball.getY() == ball.getOldY())
	{} 
	else
	{
	ball.DelRenderMe(round(ball.getOldX()+fieldX),round(ball.getOldY()+fieldY),ball.getColor());
	ball.renderMe(round(ball.getX()+fieldX),round(ball.getY()+fieldY),ball.getColor());
	}
		if (gameStart == false) bat.renderMe(bat.getX()+fieldX,bat.getY()+fieldY,bat.getColor());

	
}	

void gameLoop::gameStep(){
		if (gameStart == true) ball.moveStep();
		
		bat.setOldX(bat.getX());
		int bx; 
		int by;
		by = round(ball.getY());
		bx = round(ball.getX())/3;
		
	if ( round(ball.getY())<rowCountB)
	{ 
		if (lvlMap[by][bx].getExist() == true)
		{
			lvlMap[by][bx].setExist(false);
				if (round(ball.getOldY()) == by && (ball.getOldX() < bx || ball.getOldX() > bx ))
				{
					ball.setMovX(-ball.getMovX());
				}
				else
			ball.setMovY(-ball.getMovY());
				
			score+=lvlMap[by][bx].getColor()*2;
		}
	}
	  
	if (ball.getY() >= bat.getY() - 1  && ( ball.getX() >= bat.getX()-(bat.getSize()-1)/2 && ball.getX() <= bat.getX()+(bat.getSize()-1)/2) & ( gameStart == true )){
	ball.setMovY(-ball.getMovY());
	
	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 ){
	ball.changeMoveAngleTo(degToRad(150));
	}	
	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 + 1 ){
	ball.changeMoveAngleTo(degToRad(120));
	}		
	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 + 2 ){
	ball.setX(round(ball.getX()));	
	ball.changeMoveAngleTo(degToRad(90));
	}
	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 + 3 ){
ball.changeMoveAngleTo(degToRad(60));
	}
	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 + 4 ){
ball.changeMoveAngleTo(degToRad(30));
	}
	
	} 
		
	if ( ball.getY() <= 0) ball.setMovY(-ball.getMovY()) ;
	if( ball.getX() <= 0 || ball.getX() >= columnCountF-1) ball.setMovX(-ball.getMovX()) ;
	if(ball.getY() >= rowCountF ){
	setGameOver(true);	
	} 
	
	if(GetAsyncKeyState(VK_LEFT))
	{
		if (gameStart == false) keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
		if (bat.getX()>fieldX+2) bat.setX(bat.getX()-1);
	}
	if(GetAsyncKeyState(VK_RIGHT))
	{
		if (gameStart == false) keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
		if (bat.getX()<columnCountF+fieldX-3) bat.setX(bat.getX()+1);	
	}
		if(GetAsyncKeyState(VK_UP))
	{
		keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
		gameStart = true;
	}
			if(GetAsyncKeyState(VK_SHIFT))
	{save();
	}
			if(GetAsyncKeyState(VK_SPACE))
	{load();	}
}
void gameLoop::save(){
	
	Brick e[rowCountB][columnCountB];
	for (int i =0;i<5;i++){
		for(int j=0;j<11;j++){
			e[i][j]=lvlMap[i][j];
		}
	}
		FILE* f = fopen("ARC_SAVE.MAP","wb");
			fwrite(e,1,sizeof(e),f);
	
	fclose(f);
}
void gameLoop::load(){
	Brick e[rowCountB][columnCountB];
	
	FILE* f = fopen("ARC_SAVE.MAP","rb");
			fread(e,1,sizeof(e),f);
	for (int i =0;i<5;i++){
		for(int j=0;j<11;j++){
			lvlMap[i][j]=e[i][j];
		}
	}
	fclose(f);
}
gameLoop::~gameLoop()
{
}
