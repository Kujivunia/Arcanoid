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
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
/*unsigned char c;
for (int i = 0; i<255; i++){
	c = i;
	cout << i<<' '<<c <<';';
}
getch();
*/
gameLoop a;
MyTimer Timer;
	a.setColumnCountB(11);
	a.setRowCountB(5);
	
	a.setRowCountF(20);
	a.setColumnCountF(11*3);
	
	a.init();
	a.gameStep();
	a.render(1,1);
	
	while (a.getGameOver()==false){
	Timer.timerBegin();
		a.render(1,1);
		a.gameStep();
	Timer.timerEnd();
	Timer.timerDelay(16);
	}

	return 0;
}
