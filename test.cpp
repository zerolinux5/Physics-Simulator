#include <iostream>
#include "particle.cpp"

using namespace std;

int main()
{
	Particle p1(5, 6);
	cout << "X: " << p1.getxPos() << endl;
	cout << "Y: " << p1.getyPos() << endl;
	cout << "Mass: " << p1.getMass() << endl;
	cout << "X vel: " << p1.getxVel() << endl;
	cout << "Y vel: " << p1.getyVel() << endl;

	for(int i = 0; i < 5;i++){
		p1.move();
		cout << p1.getxPos() << endl;
		cout << p1.getyPos() << endl << endl;
	}

	return 0;
}
