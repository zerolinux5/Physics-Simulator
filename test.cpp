#include <iostream>
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	Particle p1(5, 6);
	cout << "X: " << p1.getxPos() << endl;
	cout << "Y: " << p1.getyPos() << endl;
	cout << "Mass: " << p1.getMass() << endl;
	cout << "X vel: " << p1.getxVel() << endl;
	cout << "Y vel: " << p1.getyVel() << endl;

	for(int i = 0; i < 5;i++){
		p1.move();
		cout << "X: " << p1.getxPos() << endl;
		cout << "Y: " << p1.getyPos() << endl << endl;
	}

	cout << "*********************" << endl;

	for(int i = 0; i < 5;i++){
		int newX = rand() % 5;
		newX -= rand() % 5;
		int newY = rand() % 5;
		newY -= rand() % 5;

		p1.bounce(newX, newY);
		cout << "X: " << p1.getxVel() << endl;
		cout << "Y: " << p1.getyVel() << endl << endl;
	}

	return 0;
}
