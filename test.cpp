#include <iostream>
#include "particle.cpp"

using namespace std;

int main()
{
	Particle p1(5, 6);
	cout << p1.getxPos() << endl;
	cout << p1.getyPos() << endl;
	cout << p1.getMass() << endl;
	cout << p1.getxVel() << endl;
	cout << p1.getyVel() << endl;

	return 0;
}
