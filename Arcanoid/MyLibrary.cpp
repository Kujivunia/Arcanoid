#include "MyLibrary.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <ctype.h>
HANDLE consoleHandle;
HANDLE handle;
COORD cursorCoord;
const double PI = 3.14159265358979;
void systemSetupML () {
	srand(time(0));
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO structCursorInfo;
GetConsoleCursorInfo(handle,&structCursorInfo);
structCursorInfo.bVisible = FALSE;
SetConsoleCursorInfo( handle, &structCursorInfo );

}

void gotoCursXY(int x,int y){
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
double degToRad(double a){
	
	return (a*PI/180);

}

void setTextColorML(int i){
	i = i % 16;
		SetConsoleTextAttribute(consoleHandle, i);
}

	void MyTimer::timerBegin(){
		this->begin = time(0);
	}
	
	void MyTimer::timerEnd(){
		this->end = time(0);
	}
	
	void MyTimer::timerDelay(int delay){
			
			Sleep( delay - ( end - begin ) );
	
	}
	
	
	
