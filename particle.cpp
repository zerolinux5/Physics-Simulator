class Particle{
	int xPos;
	int yPos;
	int mass;
	int xVel;
	int yVel;
   public:
	Particle(int, int, int, int, int);
	int getxPos(){return xPos;}
	int getyPos(){return yPos;}
	int getMass(){return mass;}
	int getxVel(){return xVel;}
	int getyVel(){return yVel;}
	void bounce(int, int);
	void move();
};

Particle::Particle(int x, int y, int newMass, int newXVel, int newYVel){
	xPos = x;
	yPos = y;
	mass = newMass;
	xVel = newXVel;
	yVel = newYVel;
}

void Particle::move(){
	xPos += xVel;
	yPos += yVel;
}

void Particle::bounce(int newX, int newY){
	xVel += newX;
	yVel += newY;
}
