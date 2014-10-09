#include <iostream>
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

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

int main(int argc, char **argv)
{
	ofstream myfile;
	myfile.open ("data.txt");
	//Using random seed generator here to have the clock make different numbers
	srand(time(NULL));

	int particleNum;
	if(argc > 1){
		particleNum = atoi(argv[1]);
	} else {
		cout << "Enter number of particles to use:" << endl;
		cin >> particleNum;
	}

	vector<Particle> particleVector;

	for(int i = 0; i < particleNum; i++){
		//Generate numbers and make a new particle
		int posx = rand() % 31;
		int posy = rand() % 31;
		int mass = rand() % 10 + 1;
		int xVel = rand() % 30 + 5;
		int yVel = rand() % 30 + 5;
		Particle p1(posx, posy, mass, xVel, yVel);
		particleVector.push_back(p1);

		//Show Particle information
		cout << "Particle " << (i+1) << endl;
		cout << "X: " << p1.getxPos() << endl;
		cout << "Y: " << p1.getyPos() << endl;
		cout << "Mass: " << p1.getMass() << endl;
		cout << "X Velocity: " << p1.getxVel() << endl;
		cout << "Y Velocity: " << p1.getyVel() << endl << endl;
	}

	
	//Number of times to execute movement
	for(int j = 0; j < 36; j++){
		//Display x and y position at each moment in time
		for(int i = 0; i < particleNum;i++){
			Particle* particlePointer;
			particlePointer = &particleVector.at(i);
			myfile << "P" << (i+1) << " X: " << particlePointer->getxPos() << "     ";
			myfile << "P" << (i+1) << " Y: " << particlePointer->getyPos() << endl;

			particlePointer->move();
		}
		myfile << endl;
	}

	//myfile << "P1 collision count:" << p1.getCrashCount();
	myfile.close();
	return 0;
}
