#include <iostream>
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

struct Point{
	int x;
	int y;
};

struct Line{
	double slope;
	double yIntercept;
	Point first;
	Point second;
};

//Make a line from 2 points
void lineMaker(Point pointA, Point pointB, Line &returnLine){
	double slope = 1.0*(pointB.y - pointA.y)/(pointB.x - pointA.x);
	returnLine.slope = slope;
	double yInt = 0.0 + pointA.y - slope*pointA.x;
	returnLine.yIntercept = yInt;

	//Keeping the points since it'll be a line segment
	returnLine.first = pointA;
	returnLine.second = pointB;
}

//Check to see if 2 lines collide, 1 for yes 0 for no
int lineCollision(Line lineA, Line lineB){
	//Test to see if they are parallel
	if(lineA.slope == lineB.slope){
		return 0;
	}
	//Find x value from slopes and intercepts, then y value from
	//derived x value
	double newIntercept = lineB.yIntercept - lineA.yIntercept;
	double newSlope = lineA.slope - lineB.slope;
	double x = newIntercept/newSlope;

	//Check to see if x matters
	int passFlag = 0;
	if((x >= lineA.first.x && x <= lineA.second.x) || (x <= lineA.first.x && x >= lineA.second.x)){
		if((x >= lineB.first.x && x <= lineB.second.x) || (x <= lineB.first.x && x >= lineB.second.x)){
			passFlag = 1;
		}
	}
	if(passFlag){
		passFlag = 0;
		int y = (lineA.slope*x + lineA.yIntercept);
		if((y >= lineA.first.y && y <= lineA.second.y) || (y <= lineA.first.y && y >= lineA.second.y)){
			if((y >= lineB.first.y && y <= lineB.second.y) || (y <= lineB.first.y && y >= lineB.second.y)){
				passFlag = 1;
			}
		}
	}

	if(passFlag){
		return 1;
	} else {
		return 0;
	}
}

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


int main(int argc, char **argv)
{
/*	Debug test for line collision
	Point p1, p2, p3, p4;

	p1.x = 3;
	p1.y = 3;
	p2.x = 5;
	p2.y = 5;

	p3.x = 2;
	p3.y = 10;
	p4.x = 5;
	p4.y = 3;

	Line l1, l2;

	lineMaker(p1, p2, l1);
	lineMaker(p3, p4, l2);

	cout << "L1 " << l1.slope << " " << l1.yIntercept << " " << l1.first.x << " " << l1.first.y << " " << l1.second.x << " " << l1.second.y << endl;
	cout << "L2 " << l2.slope << " " << l2.yIntercept << " " << l2.first.x << " " << l2.first.y << " " << l2.second.x << " " << l2.second.y << endl;

	cout << lineCollision(l1, l2) << endl;*/

	
	//Start of final code
	int collisionCount = 0;
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

	
	vector<Point> before;
	vector<Point> after;
	vector<Line> lineSegments;
	//Number of times to execute movement
	for(int j = 0; j < 36; j++){
		//Display x and y position at each moment in time
		for(int i = 0; i < particleNum;i++){
			Particle* particlePointer;
			particlePointer = &particleVector.at(i);
			myfile << "P" << (i+1) << " X: " << particlePointer->getxPos() << "     ";
			myfile << "P" << (i+1) << " Y: " << particlePointer->getyPos() << endl;

			//Make a point from before move
			Point old;
			old.x = particlePointer->getxPos();
			old.y = particlePointer->getyPos();
			before.push_back(old);

			//Move particle
			particlePointer->move();

			//Make a point for after
			Point newPoint;
			newPoint.x = particlePointer->getxPos();
			newPoint.y = particlePointer->getyPos();
			after.push_back(newPoint);
		}

		//make the lines and set them into vector
		for(int i = 0; i < particleNum; i++){
			Point* pointOld;
			Point* pointNew;
			pointOld = &before.at(i);
			pointNew = &after.at(i);

			Line particleLine;
			lineMaker(*pointOld, *pointNew, particleLine);
			lineSegments.push_back(particleLine);
		}

		//compare each line to eachother to see if collision
		for(int i = 0; i < (particleNum - 1); i++){
			for(int l = i+1; l < particleNum; l++){
				if (lineCollision(lineSegments.at(i), lineSegments.at(l))){
					collisionCount++;
				}
			}
		}

		//Newline to show different rounds
		myfile << endl;
	}

	//myfile << "P1 collision count:" << p1.getCrashCount();
	cout << "Number of collisions between particles:" << collisionCount << endl;
	myfile.close();
	
	return 0;
}
