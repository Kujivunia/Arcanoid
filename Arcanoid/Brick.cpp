#include "Brick.h"
#include <iostream>
#include "Ball.h"
#include "MyLibrary.h"
Brick::Brick()
{
	
}
void Brick::renderMe(int x, int y, int color){
	//for (int i = 0; i<brickWide; i++) std::cout<<ID;
	//std::cout<<' ';
	if (exist == true){	
	systemSetupML();
	setTextColorML(color);
	gotoCursXY(x,y);
	ID = 200;//201
	std::cout<<ID;
	ID = 205;
	std::cout<<ID;
	ID = 188;//187
	std::cout<<ID;	
	} else{
	systemSetupML();
	setTextColorML(color);
	gotoCursXY(x,y);
	ID = ' ';
	std::cout<<ID<<ID<<ID;		
	}
}

void Brick::delRenderMe(int x, int y, int color){
	systemSetupML();
	setTextColorML(color);
	gotoCursXY(x,y);
	ID = ' ';
	std::cout<<ID<<ID<<ID;
}

void Brick::setBrickWide(int a){
	brickWide = a;
}
int Brick::getBrickWide(){
	return brickWide;
}
void Brick::setOnScreen(bool a){
	onScreen = a;
}
bool Brick::getOnScreen(){
	return onScreen;
}
void Brick::collision(Ball ball){
	

	
}

Brick::~Brick()
{
}

