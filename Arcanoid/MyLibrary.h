#ifndef MYLIBRARY_H
#define MYLIBRARY_H
#include <ctime>
void systemSetupML();
void gotoCursXY(int x, int y);
void setTextColorML(int i);
double degToRad(double a);
class MyTimer {
 public:
  void timerBegin();
  void timerEnd();
  void timerDelay(int);

 private:
  int timerMS;
  time_t begin;
  time_t end;
};

#endif
