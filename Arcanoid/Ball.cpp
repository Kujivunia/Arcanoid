#include "Ball.h"
#include "MyLibrary.h"
#include <iostream>
#include <cmath>
void Ball::renderMe(int x, int y, int color){
	if (exist == true){	
	systemSetupML();
	setTextColorML(color);
	gotoCursXY(x,y);
	ID = 254;
	std::cout<<ID;
	} 
}
void Ball::DelRenderMe(int x, int y, int color){
	if (exist == true){	
	systemSetupML();
	gotoCursXY(x,y);
	std::cout<<' ';
	} 
}	
	double	Ball::getX(){
	return x;
	}
	void	Ball::setX(double a){
		x = a;
	}
	double	Ball::getY(){
		return y;
	}
	void	Ball::setY(double a){
		y = a;
	}
	
		double	Ball::getOldX(){
	return oldX;
	}
	void	Ball::setOldX(double a){
		oldX = a;
	}
	double	Ball::getOldY(){
		return oldY;
	}
	void	Ball::setOldY(double a){
		oldY = a;
	}
	
