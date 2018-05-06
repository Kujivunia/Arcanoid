#include <iostream>
#include "gameObjectClass.h"
#include "Brick.h"
#include "Ball.h"
#include "Bat.h"
#include "gameLoop.h"
#include <cmath>
#include "windows.h"
#include "MyLibrary.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
gameLoop a;
	a.setColumnCountB(12);
	a.setRowCountB(3);
	a.setRowCountF(20);
	a.setColumnCountF(12*3);
	a.init();
	a.gameStep();
	a.render();
	
	while (true){
		a.render();
		a.gameStep();
	}
	
	//b[1].renderMe(13,54,9);

/*	
while (true){
	a.render();
}
*/	
	return 0;
}
