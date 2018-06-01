#include "Ball.h"
#include "MyLibrary.h"
#include <iostream>
#include <cmath>
void Ball::renderMe(int x, int y, int color) {
  if (exist == true) {
    systemSetupML();
    setTextColorML(color);
    gotoCursXY(x, y);
    ID = 219;  // 254
    std::cout << ID;
  }
}
void Ball::DelRenderMe(int x, int y, int color) {
  if (exist == true) {
    systemSetupML();
    setTextColorML(color);

    gotoCursXY(x, y);
    std::cout << ' ';
  }
}

void Ball::changeMoveAngleTo(double a) {
  movY = (this->speed * sin(a));
  movX = (this->speed * cos(a));
}

double Ball::getX() { return x; }
void Ball::setX(double a) { x = a; }
double Ball::getY() { return y; }
void Ball::setY(double a) { y = a; }
void Ball::moveStep() {
  this->setOldX(this->getX());
  this->setOldY(this->getY());
  this->setX(this->getX() + this->getMovX());
  this->setY(this->getY() - this->getMovY());
}

double Ball::getOldX() { return oldX; }
void Ball::setOldX(double a) { oldX = a; }
double Ball::getOldY() { return oldY; }
void Ball::setOldY(double a) { oldY = a; }

