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

void gameLoop::init(){
		int I;
	int J;
	I=rowCountB;
	J=columnCountB;
	
	ball.setExist(true);
	ball.setX(10);
	ball.setY(10);
	ball.setSpeed(0.1);
	ball.setAlphaAngle(degToRad(30));
	ball.setColor(15);
	ball.setMovY(ball.getSpeed()*sin(ball.getAlphAngle()));
	ball.setMovX(ball.getSpeed()*cos(ball.getAlphAngle()));
	bat.setSize(5);
	bat.setX(4);
	bat.setY(19);
	bat.setColor(14);
	lvlMap=new Brick*[I];
	srand(time(0));
	for (int i=0;i<I;i++){
		lvlMap[i] = new Brick [J];
	}		
	
	for (int i=0;i<I;i++){	
		for (int j=0;j<J;j++){
			lvlMap[i][j].setX(j*3);
			lvlMap[i][j].setY(i);
			lvlMap[i][j].setHealth(1);
			lvlMap[i][j].setID(0);
			lvlMap[i][j].setColor(i+11);
			lvlMap[i][j].setBrickWide(2);
			lvlMap[i][j].setExist(true);
		}
	}	
}
void gameLoop::render()
{
	
	int I;
	int J;
	I=rowCountB;
	J=columnCountB;
	
	for (int i=0;i<I;i++){	
		for (int j=0;j<J;j++){
			lvlMap[i][j].renderMe(lvlMap[i][j].getX(),lvlMap[i][j].getY(),lvlMap[i][j].getColor());
		}
	}	
	
	bat.DelRenderMe(bat.getOldX(),bat.getY(),ball.getColor());
	bat.renderMe(bat.getX(),bat.getY(),bat.getColor());
	ball.DelRenderMe(round(ball.getOldX()),round(ball.getOldY()),ball.getColor());
	ball.renderMe(round(ball.getX()),round(ball.getY()),ball.getColor());
	
}	

void gameLoop::gameStep(){
		ball.setOldX(ball.getX());
		ball.setOldY(ball.getY());
		
		bat.setOldX(bat.getX());
		
		//ball.setY(ball.getY()-ball.getSpeed()*sin(ball.getAlphAngle()) );
		//ball.setX(ball.getX()+ball.getSpeed()*cos(ball.getAlphAngle()) );
		ball.setX(ball.getX()+ball.getMovX());
		ball.setY(ball.getY()-ball.getMovY());
		if ( round(ball.getY()) <= 0) ball.setMovY(-ball.getMovY()) ;
	if( round(ball.getX()) <= 0 || round(ball.getX()) >= columnCountF) ball.setMovX(-ball.getMovX()) ;
	if(round(ball.getY()) >= rowCountF ) --playerHealth;
	
	if(GetAsyncKeyState(VK_LEFT))
	{
		keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
		bat.setX(bat.getX()-1);
	}
	if(GetAsyncKeyState(VK_RIGHT))
	{
		keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
		bat.setX(bat.getX()+1);	
	}
		if(GetAsyncKeyState(VK_UP))
	{
		keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			
	}
	
}


gameLoop::~gameLoop()
{
}
