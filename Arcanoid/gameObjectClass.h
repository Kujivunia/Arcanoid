#ifndef GAMEOBJECTCLASS_H
#define GAMEOBJECTCLASS_H

class gameObjectClass
{
	public:
		gameObjectClass();
		~gameObjectClass();
	int getX();
	int getY();
	void setX(int); 
	void setY(int);	
	double getAlphAngle();
	void setAlphaAngle(double);
	double getSpeed();
	void setSpeed(double);
	int getHealth();
	void setHealth(int);
	unsigned char getID();
	void setID(unsigned char);
	int getColor();
	void setColor(int);
	void setExist(bool);
	bool getExist();
	void collision();
	void renderMe();
	void moveMe();
	double getMovX();
	void setMovX(double); 
	double getMovY();
	void setMovY(double); 
		
	protected:
		unsigned char ID;
		int x;
		int y;
		double alphAngle;
		double movX;
		double movY;
		double speed;
		int health;	
		int color;
		bool exist;
};



#endif
