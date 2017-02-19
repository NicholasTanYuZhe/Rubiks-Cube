/*Write a program to solve the Rubik’s cube problem.
You program must provide a main interface to let user to view the current six dimensional cubes (4m).
The program has key features such as scramble the Rubik’s cube (2m),
and shows the steps to solve the problem (5m).
Conduct experimental tests to evaluate the effectiveness (measures the running time) of the program (5m).  */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <sstream>
#include "RCube.h"
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void startCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double getCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void saveCSV(int first, int second, int third, vector<double> timer1, vector<double> timer2, vector<double> timer3)
{
	ofstream save;
	double sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i=0; i<timer1.size(); i++)
	{
		sum1 = sum1 + timer1[i];
		sum2 = sum2 + timer2[i];
		sum3 = sum3 + timer3[i];
	}
	sum1 = sum1/timer1.size();
	sum2 = sum2/timer2.size();
	sum3 = sum3/timer3.size();
	save.open("RunningTime.csv");
	save << "Timer1(" << first << "), " << "Timer2(" << second << "), " << " Timer3(" << third << ")," << " , Average(" << first << "), Average(" << second << "), Average(" << third << ")\n";
	for(int i=0; i<timer1.size(); i++)
	{
		if(i == 0)
		{
			save << timer1[i] << "," << timer2[i] << "," << timer3[i] << "," << "," << sum1 << "," << sum2 << "," << sum3 << "\n";
		}
		else
			save << timer1[i] << "," << timer2[i] << "," << timer3[i] << "\n";
	}
	save.close();	
}

int convertStringToInt(string input)
{
	int output;
	if (!(istringstream(input) >> output))
		output = 0;
	return output;
}

int main()
{
	srand(time(NULL));
	int answer = 0, input, num;
	string answerTemp, s, numTemp, sizeTemp, firstTemp, secondTemp, thirdTemp, tmp;
	RCube cube;
	vector<int> sequence;
	vector<int> seq;
	bool errorChecking = false;
	double interval;
	int first, second, third, size;
	vector<double> timer1;
	vector<double> timer2;
	vector<double> timer3;
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
			 << "1. Manually key in cube and solve\n"
			 << "2. Scramble and solve the Rubik's Cube\n"
			 << "3. Help\n"
			 << "4. Generate CSV\n"
			 << "5. Quit\n"
			 << "Please enter 1 - 5 to continue\n"
			 << "-> ";
		getline(cin, answerTemp);
		answer = convertStringToInt(answerTemp);


		if(answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5)
		{
			cout << "You have type in an invalid input.\n";
			system("pause");
			answer = 0;
		}

		if(answer == 1)
		{
			seq.clear();
			cout << "Straight key in string from top(1) -> left(2) -> front(3) -> right(4) -> back(5) -> down(6)\n"
				 << "Use number to key in\n"
				 << "-> ";
			getline(cin, s);
			if(s.length() != 54)
				cout << "Invalid input. Please make sure you have key in exactly 54 input\n";
			else
			{
				for(int i=0; i<54; i++)
				{
					tmp = s[i];
					seq.push_back(convertStringToInt(tmp));
				}
				cube.setup(seq);
				cube.display();
				bool valid = cube.checkValid();
				if(valid)
				{
					startCounter();
					valid = cube.solve(sequence);
					if(valid)
					{

						interval = getCounter();
						cout << interval << " microseconds\n\n";
						cout << "Step to solve cube: \n";
						cube.reduce(sequence);
						cube.displayTurn(sequence);
						cube.display();
					}
					else
						cout << "Invalid cube. Please fix the cube\n";
				}
				else
					cout << "Invalid cube. Please fix the cube\n";
			}
			answer = 0;
			system("pause");
		}
		else if(answer == 2)
		{
			cube.display();
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "How many times to scramble the Rubik's Cube?\n"
					 << "-> ";
				getline(cin, numTemp);
				num = convertStringToInt(numTemp);
				if(num < 1)
					cout << "Please enter at least 1\n";
				else
					errorChecking = true;
			}
			cout << "\n" << "Move to scramble:\n";
			cube.scramble(num);
			cout << "After scramble: \n";
			cube.display();
			cout << "End of scramble\n\n";
			startCounter();
			cube.solve(sequence);
			cout << "Solve complete\n";
			interval = getCounter();
			cout << interval << " microseconds\n\n";
			cout << "Step to solve cube: \n";
			cube.reduce(sequence);
			cube.displayTurn(sequence);
			cube.display();
			answer = 0;
			system("pause");
		}
		else if(answer == 3)
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
		else if(answer == 4)
		{
			cube.reset(sequence);
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "How many entry to save: ";
				getline(cin, sizeTemp);
				size = convertStringToInt(sizeTemp);
				if(size < 1)
					cout << "Please enter at least 1\n";
				else
					errorChecking = true;
			}
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "Scramble how many times for timer 1: ";
				getline(cin, firstTemp);
				first = convertStringToInt(firstTemp);
				if(first < 1)
					cout << "Please enter at least 1\n";
				else
					errorChecking = true;
			}
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "Scramble how many times for timer 2: ";
				getline(cin, secondTemp);
				second = convertStringToInt(secondTemp);
				if(second < 1)
					cout << "Please enter at least 1\n";
				else
					errorChecking = true;
			}
			errorChecking = false;
			while(!errorChecking)
			{
				cout << "Scramble how many times for timer 3: ";
				getline(cin, thirdTemp);
				third = convertStringToInt(thirdTemp);
				if(third < 1)
					cout << "Please enter at least 1\n";
				else
					errorChecking = true;
			}

			for(int i=0; i<size; i++)
			{
				cout << "Time " << i << ": ";
				cube.reset(sequence);
				cube.scramble(first);
				startCounter();
				cube.solve(sequence);
				timer1.push_back(getCounter());
			}
			for(int i=0; i<size; i++)
			{
				cout << "Time " << i << ": ";
				cube.reset(sequence);
				cube.scramble(second);
				startCounter();
				cube.solve(sequence);
				timer2.push_back(getCounter());
			}
			for(int i=0; i<size; i++)
			{
				cout << "Time " << i << ": ";
				cube.reset(sequence);
				cube.scramble(third);
				startCounter();
				cube.solve(sequence);
				timer3.push_back(getCounter());
			}
			saveCSV(first, second, third, timer1, timer2, timer3);
			system("pause");
			answer = 0;
		}
		else if(answer == 5)
			return 0;
	}
	return 0;
}