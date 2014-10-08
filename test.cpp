#include <iostream>
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

//Two particles collide
void collision(Particle &p1, Particle &p2){
	//Need to make this smaller
	int x1Bounce = p1.getxVel()*p1.getMass() - p2.getxVel()*p2.getMass();
	int y1Bounce = p1.getyVel()*p1.getMass() - p2.getyVel()*p2.getMass();

	int x2Bounce = x1Bounce * -1;
	int y2Bounce = y1Bounce * -1;

	p1.bounce(x1Bounce, y1Bounce);
	p2.bounce(x2Bounce, y2Bounce);
}

//Method to run simulation
void update(int numTimes){

}

int main()
{
	//Using random seed generator here to have the clock make different numbers
	srand(time(NULL));

	//variable generation
	int posx1 = rand() % 31;
	int posx2 = rand() % 31;
	int posx3 = rand() % 31;
	int posy1 = rand() % 31;
	int posy2 = rand() % 31;
	int posy3 = rand() % 31;
	int mass1 = rand() % 10 + 1;
	int mass2 = rand() % 10 + 1;
	int mass3 = rand() % 10 + 1;
	int xVel1 = rand() % 30 + 5;
	int yVel1 = rand() % 30 + 5;
	int xVel2 = rand() % 30 + 5;
	int yVel2 = rand() % 30 + 5;
	int xVel3 = rand() % 30 + 5;
	int yVel3 = rand() % 30 + 5;


	//This is debugging code and will change for final project
	Particle p1(posx1, posy1, mass1, xVel1, yVel1);
	Particle p2(posx2, posy2, mass2, xVel2, yVel2);
	Particle p3(posx2, posy3, mass3, xVel3, yVel3);
	cout << "Particle 1" << "     Particle 2" << "     Particle 3" << endl;
	cout << "X: " << p1.getxPos() << "          X: " << p2.getxPos() << "          X: " << p3.getxPos() << endl;		
	cout << "Y: " << p1.getyPos() << "          Y: " << p2.getyPos() << "          Y: " << p3.getxPos() << endl;	
	cout << "Mass: " << p1.getMass() << "     Mass: " << p2.getMass() << "     Mass: " << p3.getMass() << endl;
	cout << "X vel: " << p1.getxVel() << "     X vel: " << p2.getxVel() << "     X vel: " << p3.getxVel() << endl;
	cout << "Y vel: " << p1.getyVel() << "     Y vel: " << p2.getyVel() << "     Y vel: " << p3.getyVel() << endl << endl;

	for(int i = 0; i < 100;i++){
		cout << "P1 X: " << p1.getxPos() << "     P2 X: " << p2.getxPos() << "     P3 X: " << p3.getxPos() << endl;
		cout << "P1 Y: " << p1.getyPos() << "     P2 Y: " << p2.getyPos() << "     P3 Y: " << p3.getyPos() << endl << endl;

		p1.move();
		p2.move();
		p3.move();
	}

	cout << "P1 collision count:" << p1.getCrashCount() << "     P2 collision count:" << p2.getCrashCount() << "     P3 collision count:" << p3.getCrashCount() << "     " << endl;

	return 0;
}
