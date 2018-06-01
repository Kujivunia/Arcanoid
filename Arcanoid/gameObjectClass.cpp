#include <iostream>
#include "gameObjectClass.h"
gameObjectClass::gameObjectClass() {}

void gameObjectClass::setX(int a) { x = a; }
void gameObjectClass::setY(int a) { y = a; }
void gameObjectClass::setAlphaAngle(double a) { alphAngle = a; }
void gameObjectClass::setSpeed(double a) { speed = a; }
void gameObjectClass::setHealth(int a) { health = a; }
void gameObjectClass::setID(unsigned char a) { ID = a; }
void gameObjectClass::setColor(int a) { color = a; }
void gameObjectClass::setExist(bool a) { exist = a; }

bool gameObjectClass::getExist() { return exist; }

int gameObjectClass::getColor() { return color; }
int gameObjectClass::getX() { return x; }
int gameObjectClass::getY() { return y; }
double gameObjectClass::getAlphAngle() { return alphAngle; }
double gameObjectClass::getSpeed() { return speed; }
int gameObjectClass::getHealth() { return health; }
unsigned char gameObjectClass::getID() { return ID; }

double gameObjectClass::getMovX() { return movX; }

void gameObjectClass::setMovX(double a) { movX = a; }

double gameObjectClass::getMovY() { return movY; }

void gameObjectClass::setMovY(double a) { movY = a; }

gameObjectClass::~gameObjectClass() {}

