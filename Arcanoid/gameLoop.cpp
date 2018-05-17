#include "gameLoop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include "MyLibrary.h"
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
	this->setGameOver(false);
	this->fieldX = 0;
	this->fieldY = 0;
	this->score = 0;
	borderOn = false;
	ball.setExist(true);
	ball.setX(10);
	ball.setY(10);
	ball.setSpeed(0.1);
	ball.setColor(15);
	ball.setAlphaAngle(degToRad(30));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	bat.setSize(7);
	bat.setX(4);
	bat.setY(19);
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
	
	gotoCursXY(columnCountF+2,fieldY-1);
	for (int i = 0; i<9; i++){
		std::cout<<horizontal;
	}
	std::cout<<rightTop;
	gotoCursXY(columnCountF+2,fieldY);
	std::cout<<" SCORE:";
	
	gotoCursXY(columnCountF+2,rowCountF+fieldY);
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
	
	ball.DelRenderMe(round(ball.getOldX()+fieldX),round(ball.getOldY()+fieldY),ball.getColor());
	ball.renderMe(round(ball.getX()+fieldX),round(ball.getY()+fieldY),ball.getColor());
	
}	

void gameLoop::gameStep(){

		ball.moveStep();
		bat.setOldX(bat.getX());
		int bx; 
		int by;
		by = round(ball.getY());
		bx = round(ball.getX())/3;
	if ( round(ball.getY())<rowCountB){
	if (lvlMap[by][bx].getExist() == true){
		lvlMap[by][bx].setExist(false);
		ball.setMovY(-ball.getMovY());//temp	
		score++;	
	}
	}		
	if (round(ball.getY()) >= bat.getY() - 1  && ( round(ball.getX()) >= bat.getX()-(bat.getSize()-1)/2 && round(ball.getX()) <= bat.getX()+(bat.getSize()-1)/2)){
	ball.setMovY(-ball.getMovY());

	if (round(ball.getX()) == bat.getX()-(bat.getSize()-1)/2 ){
	ball.setAlphaAngle(degToRad(150));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	}	
	if (round(ball.getX()) == 1 + bat.getX()-(bat.getSize()-1)/2 ){
	ball.setAlphaAngle(degToRad(120));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	}		
	if (round(ball.getX()) == 2 + bat.getX()-(bat.getSize()-1)/2 ){
	ball.setAlphaAngle(degToRad(90));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	}
	if (round(ball.getX()) == 3 + bat.getX()-(bat.getSize()-1)/2 ){
	ball.setAlphaAngle(degToRad(60));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	}
	if (round(ball.getX()) == 4 + bat.getX()-(bat.getSize()-1)/2 ){
	ball.setAlphaAngle(degToRad(30));
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	}
	
	}
		//ball.setY(ball.getY()-ball.getSpeed()*sin(ball.getAlphAngle()) );
		//ball.setX(ball.getX()+ball.getSpeed()*cos(ball.getAlphAngle()) );

	if ( round(ball.getY()) <= 0) ball.setMovY(-ball.getMovY()) ;
	if( round(ball.getX()) <= 0 || round(ball.getX()) >= columnCountF-1) ball.setMovX(-ball.getMovX()) ;
	if(round(ball.getY()) >= rowCountF ){
	setGameOver(true);	
	} 
	
	if(GetAsyncKeyState(VK_LEFT))
	{
		//keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
		if (bat.getX()>fieldX+2+1) bat.setX(bat.getX()-1);
	}
	if(GetAsyncKeyState(VK_RIGHT))
	{
		//keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
		if (bat.getX()<columnCountF+fieldX-2-2) bat.setX(bat.getX()+1);	
	}
		if(GetAsyncKeyState(VK_UP))
	{
		keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			
	}
	
}

gameLoop::~gameLoop()
{
}
