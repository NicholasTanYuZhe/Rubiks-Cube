/*Write a program to solve the Rubik’s cube problem.
You program must provide a main interface to let user to view the current six dimensional cubes (4m).
The program has key features such as scramble the Rubik’s cube (2m),
and shows the steps to solve the problem (5m).
Conduct experimental tests to evaluate the effectiveness (measures the running time) of the program (5m).  */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "RCube.h"
using namespace std;

int main()
{
	int answer = 0, input, num;
	RCube cube;
	vector<int> sequence;
	bool errorChecking = false;
	while(answer == 0)
	{
		system("CLS");
		cube.reset(sequence);
		cout << "==========================================================\n"
			 << "|   TCP2101 - Algorithm Design and Analysis Assignment   |\n"
			 << "|                Rubik's Cube Simulation                 |\n"
			 << "==========================================================\n"
			 << "Section: TC02 TT04\n\n"
			 << "Prepared by:\n"
			 << "Name: Nicholas Tan Yu Zhe\tID: 1142701655\n"
			 << "Name: Liew Soon Pang\t\tID: 1142700808\n\n"
			 << "1. Scramble and solve the Rubik's Cube\n"
			 << "2. Help\n"
			 << "Please enter 1 - 2 to continue\n"
			 << "-> ";
		cin >> answer;

		if(answer != 1 && answer != 2)
		{
			cout << "You have type in an invalid input.\n";
			system("pause");
			answer = 0;
		}

		if(answer == 1)
		{
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "How many times to scramble the Rubik's Cube?\n"
					 << "-> ";
				cin >> num;
				if(num < 0)
					cout << "Please enter more than 1\n";
				else
					errorChecking = true;
			}
			cube.scramble(num);
			cube.display();
			cube.solve(sequence);
			cube.display();
			cube.displayTurn(sequence);
			int a = sequence.size();
			cout << "Size =  " << a << "\n\n\n\n";
			cube.reduce(sequence);
			cube.displayTurn(sequence);
			int b = sequence.size();
			cout << "Size after reduce=  " << b << "\n\n\n";
			cout << "Diff = " << a-b << "\n";
			answer = 0;
			system("pause");
		}
		else if(answer == 2)
		{
			system("CLS");
			cout << "==========================================================\n"
			 	 << "|                       Help Page                        |\n"
				 << "|                Rubik's Cube Simulation                 |\n"
				 << "==========================================================\n"
				 << "Legend:\n\n"
				 << "A single letter means to turn that particular face in clockwise 90 degrees.\n"
				 << "A letter that followed by an apostrophe means to turn that particular face in counterclockwise 90 degrees.\n"
				 << "A letter followed by the number 2 means to turn that particular face 180 degrees.\n\n"
				 << "F = Front\n"
				 << "B = Back\n"
				 << "L = Left\n"
				 << "R = Right\n"
				 << "U = Up\n"
				 << "D = Down\n"
				 << "M = Middle (The layer between L and R, turn direction as L)\n"
				 << "E = Equator (The layer between U and D, turn direction as D)\n"
				 << "S = Standing (The layer between F and B, turn direction as F)\n"
				 << "X = Rotate the entire Rubik's Cube to Up, turn direction as R\n"
				 << "Y = Rotate the entire Rubik's Cube to Left, turn direction as U\n"
				 << "Z = Rotate the entire Rubik's Cube to Side Right, turn direction as F\n\n";
			answer = 0;
			system("pause");
		}
	}
	return 0;
}