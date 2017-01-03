#ifndef RCUBE_H
#define RCUBE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class RCube
{
	int up[3][3];
	int down[3][3];
	int left[3][3];
	int right[3][3];
	int front[3][3];
	int back[3][3];
public:
	RCube();
	void display();
	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();
	void turnFront();
	void turnBack();
	void scramble();
};

#include "RCube.cpp"
#endif