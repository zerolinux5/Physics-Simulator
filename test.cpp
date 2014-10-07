#include <iostream>
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

void collision(Particle &p1, Particle &p2){
	//Need to make this smaller
	int x1Bounce = p1.getxVel()*p1.getMass() - p2.getxVel()*p2.getMass();
	int y1Bounce = p1.getyVel()*p1.getMass() - p2.getyVel()*p2.getMass();

	int x2Bounce = x1Bounce * -1;
	int y2Bounce = y1Bounce * -1;

	p1.bounce(x1Bounce, y1Bounce);
	p2.bounce(x2Bounce, y2Bounce);
}

int main()
{
	//Using random seed generator here to have the clock make different numbers
	srand(time(NULL));
	int mass1 = rand() % 10 + 1;
	int mass2 = rand() % 10 + 1;
	int xVel1 = rand() % 7 + 1;
	int yVel1 = rand() % 7 + 1;
	int xVel2 = rand() % 7 + 1;
	int yVel2 = rand() % 7 + 1;


	//This is debugging code and will change for final project
	Particle p1(5, 6, mass1, xVel1, yVel1);
	Particle p2(7, 8, mass2, xVel2, yVel2);
	cout << "Particle 1" << endl;
	cout << "X: " << p1.getxPos() << endl;
	cout << "Y: " << p1.getyPos() << endl;
	cout << "Mass: " << p1.getMass() << endl;
	cout << "X vel: " << p1.getxVel() << endl;
	cout << "Y vel: " << p1.getyVel() << endl << endl;

	cout << "Particle 2" << endl;
	cout << "X: " << p2.getxPos() << endl;
	cout << "Y: " << p2.getyPos() << endl;
	cout << "Mass: " << p2.getMass() << endl;
	cout << "X vel: " << p2.getxVel() << endl;
	cout << "Y vel: " << p2.getyVel() << endl << endl;

	for(int i = 0; i < 5;i++){
		p1.move();
		p2.move();
		cout << "Before collision P1 X: " << p1.getxVel() << endl;
		cout << "Before collision P1 Y: " << p1.getyVel() << endl;
		cout << "Before collision P2 X: " << p2.getxVel() << endl;
		cout << "Before collision P2 Y: " << p2.getyVel() << endl << endl;

		collision(p1,p2);
		cout << "P1 X: " << p1.getxVel() << endl;
		cout << "P1 Y: " << p1.getyVel() << endl;
		cout << "P2 X: " << p2.getxVel() << endl;
		cout << "P2 Y: " << p2.getyVel() << endl << endl;
	}

	return 0;
}
