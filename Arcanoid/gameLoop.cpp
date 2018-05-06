#include "gameLoop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
	ball.setAlphaAngle(degToRad(160));
	ball.setColor(15);
	
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
	std::cout<<ball.getAlphAngle()<<' '<<ball.getX()<<' '<<ball.getY();
		
	//ball.DelRenderMe(round(ball.getOldX()),round(ball.getOldY()),ball.getColor());
	ball.renderMe(round(ball.getX()),round(ball.getY()),ball.getColor());
}	

void gameLoop::gameStep(){
		ball.setOldX(ball.getX());
		ball.setOldY(ball.getY());
		ball.setY(ball.getY()-ball.getSpeed()*sin(ball.getAlphAngle()) );
		ball.setX(ball.getX()+ball.getSpeed()*cos(ball.getAlphAngle()) );
		if ( round(ball.getY()) <= 0 || round(ball.getY()) >= rowCountF )  ball.setAlphaAngle(asin(ball.getSpeed()/-sin(ball.getAlphAngle())));
	if( round(ball.getX()) <= 0 || round(ball.getX()) >= columnCountF) ball.setAlphaAngle(acos(ball.getSpeed()/-cos(ball.getAlphAngle())));
}


gameLoop::~gameLoop()
{
}
