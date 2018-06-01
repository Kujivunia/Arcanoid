#ifndef BALL_H
#define BALL_H

#include "gameObjectClass.h"

class Ball : public gameObjectClass {
 public:
  void renderMe(int x, int y, int color);
  void DelRenderMe(int x, int y, int color);
  double getX();
  void setX(double);
  double getY();
  void setY(double);

  double getOldY();
  void setOldY(double);

  double getOldX();
  void setOldX(double);
  void changeMoveAngleTo(double);

  void moveStep();

 protected:
  double x;
  double y;
  double oldX;
  double oldY;
};

#endif
