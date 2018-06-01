#include "Bat.h"
#include "MyLibrary.h"
#include <iostream>
#include <cmath>

void Bat::renderMe(int x, int y, int color) {
  systemSetupML();
  setTextColorML(color);
  gotoCursXY(x - ((size - 1) / 2), y);
  ID = 223;  // 205
  for (int i = 0; i < size; i++) {
    std::cout << ID;
  }
}

void Bat::DelRenderMe(int x, int y, int color) {
  systemSetupML();
  setTextColorML(color);

  gotoCursXY(x - ((size - 1) / 2), y);
  for (int i = 0; i < size; i++) {
    std::cout << ' ';
  }
}

void Bat::setSize(int a) { size = a; }

int Bat::getSize() { return size; }

int Bat::getOldX() { return oldX; }
void Bat::setOldX(int a) { oldX = a; }
