#include <math.h>

const int MAX = 30;

class Particle{
	int xPos;
	int yPos;
	int mass;
	int xVel;
	int yVel;
	int crash;
   public:
	Particle(int, int, int, int, int);
	int getxPos(){return xPos;}
	int getyPos(){return yPos;}
	int getMass(){return mass;}
	int getxVel(){return xVel;}
	int getyVel(){return yVel;}
	int getCrashCount(){return crash;}
	int outOfBounds();
	void bounce(int, int);
	void move();
};

Particle::Particle(int x, int y, int newMass, int newXVel, int newYVel){
	xPos = x;
	yPos = y;
	mass = newMass;
	xVel = newXVel;
	yVel = newYVel;
	crash = 0;
}

void Particle::move(){
	if(xPos + xVel > MAX){
		int bounce = MAX - (xPos + xVel);
		xPos = (MAX + bounce);
		xVel *= -1;
		crash++;
	} else if(xPos + xVel < 0){
		int bounce = xPos + xVel;
		xPos = (bounce * -1);
		xVel *= -1;
		crash++;
	} else {
		xPos += xVel;
	}

	if(yPos + yVel > MAX){
		int bounce = MAX - (yPos + yVel);
		yPos = (MAX + bounce);
		yVel *= -1;
		crash++;
	} else if(yPos + yVel < 0){
		int bounce = yPos + yVel;
		yPos = (bounce * -1);
		yVel *= -1;
		crash++;
	} else {
		yPos += yVel;
	}

	//Need to make a more realistic modifier
	if(xVel > 0){
		xVel--;
	} else if(xVel == 0) {
	} else {
		xVel++;
	}
	if (yVel > 0){
		yVel--;
	} else if(yVel == 0) {
	} else {
		yVel++;
	}
}

void Particle::bounce(int newX, int newY){
	xVel = newX;
	yVel = newY;
}

//Return numbers based on out of bounds
int Particle::outOfBounds(){
	if(xPos <= 0 || xPos >= MAX){
		return 1;
	}
	if(yPos <= 0 || yPos >= MAX){
		return 2;
	}
	return 0;
}
