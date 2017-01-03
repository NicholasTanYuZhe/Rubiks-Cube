#include "RCube.h"

RCube::RCube()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			up[i][j] = 1;
			down[i][j] = 6;
			left[i][j] = 2;
			right[i][j] = 4;
			front[i][j] = 3;
			back[i][j] = 5;
		}
	}
}

void RCube::display()
{
	for(int k=0; k<3; k++)
	{
		int count = 1;
		for(int i=0; i<3; i++)
		{
			if(k == 0 || k == 2)
				cout << "      ";
			for(int j=0; j<3; j++)
			{
				if(k == 0)
					cout << up[i][j] << " ";
				else if(k == 1)
				{
					if(count == 1)
						cout << left[i][j] << " ";
					else if(count == 2)
						cout << front[i][j] << " ";
					else if(count == 3)
						cout << right[i][j] << " ";
					else if(count == 4)
						cout << back[i][j] << " ";
				}
				else if(k == 2)
					cout << down[i][j] << " ";
			}
			if(k == 1 && count != 5)
			{
				i--;
				count++;
			}
			if(k == 0 || k == 2 || (k == 1 && count == 5))
				cout << "\n";
			if(k == 1 && count == 5)
			{
				count = 1;
				i++;
			}
		}
	}
	cout << "\n";
}

void RCube::turnUp()
{
	int temp = up[0][1];
	up[0][1] = up[1][0];
	up[1][0] = up[2][1];
	up[2][1] = up[1][2];
	up[1][2] = temp;
	temp = up[0][0];
	up[0][0] = up[2][0];
	up[2][0] = up[2][2];
	up[2][2] = up[0][2];
	up[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = left[0][i];
		left[0][i] = front[0][i];
		front[0][i] = right[0][i];
		right[0][i] = back[0][i];
		back[0][i] = temp;
	}
}

void RCube::turnDown()
{
	int temp = down[0][1];
	down[0][1] = down[1][0];
	down[1][0] = down[2][1];
	down[2][1] = down[1][2];
	down[1][2] = temp;
	temp = down[0][0];
	down[0][0] = down[2][0];
	down[2][0] = down[2][2];
	down[2][2] = down[0][2];
	down[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = back[2][i];
		back[2][i] = right[2][i];
		right[2][i] = front[2][i];
		front[2][i] = left [2][i];
		left[2][i] = temp;
	}
}

void RCube::turnLeft()
{
	int temp = left[0][1];
	left[0][1] = left[1][0];
	left[1][0] = left[2][1];
	left[2][1] = left[1][2];
	left[1][2] = temp;
	temp = left[0][0];
	left[0][0] = left[2][0];
	left[2][0] = left[2][2];
	left[2][2] = left[0][2];
	left[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = up[i][0];
		up[i][0] = back[2-i][2];
		back[2-i][2] = down[i][0];
		down[i][0] = front[i][0];
		front[i][0] = temp;
	}
}

void RCube::turnRight()
{
	int temp = right[0][1];
	right[0][1] = right[1][0];
	right[1][0] = right[2][1];
	right[2][1] = right[1][2];
	right[1][2] = temp;
	temp = right[0][0];
	right[0][0] = right[2][0];
	right[2][0] = right[2][2];
	right[2][2] = right[0][2];
	right[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = up[i][2];
		up[i][2] = front[i][2];
		front[i][2] = down[i][2];
		down[i][2] = back[2-i][0];
		back[2-i][0] = temp;
	}
}

void RCube::turnFront()
{
	int temp = front[0][1];
	front[0][1] = front[1][0];
	front[1][0] = front[2][1];
	front[2][1] = front[1][2];
	front[1][2] = temp;
	temp = front[0][0];
	front[0][0] = front[2][0];
	front[2][0] = front[2][2];
	front[2][2] = front[0][2];
	front[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = up[2][i];
		up[2][i] = left[2-i][2];
		left[2-i][2] = down[0][2-i];
		down[0][2-i] = right[i][0];
		right[i][0] = temp;
	}
}

void RCube::turnBack()
{
	int temp = back[0][1];
	back[0][1] = back[1][0];
	back[1][0] = back[2][1];
	back[2][1] = back[1][2];
	back[1][2] = temp;
	temp = back[0][0];
	back[0][0] = back[2][0];
	back[2][0] = back[2][2];
	back[2][2] = back[0][2];
	back[0][2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = up[0][i];
		up[0][i] = right[i][2];
		right[i][2] = down[2][2-i];
		down[2][2-i] = left[2-i][0];
		left[2-i][0] = temp;
	}
}

void RCube::scramble()
{
	for(int i=0; i<5; i++)
	{
		int x = rand() % 6;
		cout << x << " ";
		if(x == 0)
			turnUp();
		else if(x == 1)
			turnDown();
		else if(x == 2)
			turnLeft();
		else if(x == 3)
			turnRight();
		else if(x == 4)
			turnFront();
		else if(x == 5)
			turnBack();
	}
	cout << "\n";
}