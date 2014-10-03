#include <stdlib.h>
#include <time.h>

class Particle{
	int xPos;
	int yPos;
	int mass;
	int xVel;
	int yVel;
   public:
	Particle(int, int);
	int getxPos(){return xPos;}
	int getyPos(){return yPos;}
	int getMass(){return mass;}
	int getxVel(){return xVel;}
	int getyVel(){return yVel;}
	void move();
};

Particle::Particle(int x, int y){
	srand(time(NULL));
	xPos = x;
	yPos = y;
	mass = (rand() % 10 + 1);
	xVel = (rand() % 5 + 1);
	yVel = (rand() % 5 + 1);
}

void Particle::move(){
	xPos += xVel;
	yPos += yVel;
}
