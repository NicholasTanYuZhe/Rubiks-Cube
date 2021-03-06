#ifndef RCUBE_H
#define RCUBE_H

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class RCube
{
	int cube[54];
public:
	RCube();
	void display();
	void reset(vector<int>& sequence);
	void setup(vector<int> seq);
	bool checkValid();
	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();
	void turnFront();
	void turnBack();
	void turnMiddle();
	void turnEquator();
	void turnStanding();
	void turnCUp();
	void turnCDown();
	void turnCLeft();
	void turnCRight();
	void turnCFront();
	void turnCBack();
	void turnCMiddle();
	void turnCEquator();
	void turnCStanding();
	void turnUp2();
	void turnDown2();
	void turnLeft2();
	void turnRight2();
	void turnFront2();
	void turnBack2();
	void turnMiddle2();
	void turnEquator2();
	void turnStanding2();
	void turnCubeToLeft();
	void turnCubeToRight();
	void turnCubeToUp();
	void turnCubeToDown();
	void turnCubeSideToLeft();
	void turnCubeSideToRight();
	void displayTurn(vector<int> sequence);
	void reduce(vector<int>& sequence);
	void scramble(int times);
	bool solve(vector<int>& sequence);
};

#include "RCube.cpp"
#endif