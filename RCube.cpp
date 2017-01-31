#include "RCube.h"

RCube::RCube()
{
	reset();
}

void RCube::display()
{
	for(int i=0; i<54; i++)
	{
		if(i == 0 || i == 3 || i == 6 || i == 45 || i == 48 || i == 51)
			cout << "      ";
		if(i < 9)
			cout << cube[i] << " ";
		else if(i < 18)
		{
			int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
			for(int j=0; j<12; j++)
				cout << cube[i+array[j]] << " ";
			i+=2;
			if(i == 17)
				i = 44;
			else
				cout << "\n";
		}
		else
			cout << cube[i] << " ";
		if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
			cout << "\n";	
	}
	cout << "\n";
}

void RCube::reset()
{
	int num = 0;
	for(int i=0; i<54; i++)
	{
		if(i % 9 == 0)
			num++;
		cube[i] = num;
	}
	/*for(int i=0; i<54; i++)
		cube[i] = i;*/
}

void RCube::setup()
{
	//int sequence[] = {1,2,4,5,1,3,2,4,1,4,2,1,5,2,5,5,2,2,5,1,2,1,3,1,3,3,3,3,4,5,3,4,1,4,4,5,1,3,3,2,5,4,2,5,4,6,6,6,6,6,6,6,6,6};
	//int sequence[] = {1,4,3,3,1,2,4,5,2,5,4,1,5,2,4,5,2,2,3,2,1,1,3,1,3,3,3,5,3,1,3,4,1,4,4,5,2,1,4,2,5,4,2,5,4,6,6,6,6,6,6,6,6,6};
	int sequence[] = {1,1,5,1,1,5,4,2,3,4,4,3,2,2,2,2,5,6,6,1,2,6,3,3,5,4,4,6,1,1,4,4,5,5,5,1,4,3,3,2,5,3,2,3,3,2,6,6,4,6,6,1,6,5};

	for(int i=0; i<54; i++)
		cube[i] = sequence[i];
}

void RCube::turnUp()
{
	int temp = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[7];
	cube[7] = cube[5];
	cube[5] = temp;
	temp = cube[0];
	cube[0] = cube[6];
	cube[6] = cube[8];
	cube[8] = cube[2];
	cube[2] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[9+i];
		cube[9+i] = cube[18+i];
		cube[18+i] = cube[27+i];
		cube[27+i] = cube[36+i];
		cube[36+i] = temp;
	}
	cout << "Turn Up\n";
}

void RCube::turnDown()
{
	int temp = cube[46];
	cube[46] = cube[48];
	cube[48] = cube[52];
	cube[52] = cube[50];
	cube[50] = temp;
	temp = cube[45];
	cube[45] = cube[51];
	cube[51] = cube[53];
	cube[53] = cube[47];
	cube[47] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[15+i];
		cube[15+i] = cube[42+i];
		cube[42+i] = cube[33+i];
		cube[33+i] = cube[24+i];
		cube[24+i] = temp;
	}
	cout << "Turn Down\n";
}

void RCube::turnLeft()
{
	int temp = cube[10];
	cube[10] = cube[12];
	cube[12] = cube[16];
	cube[16] = cube[14];
	cube[14] = temp;
	temp = cube[9];
	cube[9] = cube[15];
	cube[15] = cube[17];
	cube[17] = cube[11];
	cube[11] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[0+(i*3)];
		cube[0+(i*3)] = cube[44-(i*3)];
		cube[44-(i*3)] = cube[45+(i*3)];
		cube[45+(i*3)] = cube[18+(i*3)];
		cube[18+(i*3)] = temp;
	}
	cout << "Turn Left\n";
}

void RCube::turnRight()
{
	int temp = cube[28];
	cube[28] = cube[30];
	cube[30] = cube[34];
	cube[34] = cube[32];
	cube[32] = temp;
	temp = cube[27];
	cube[27] = cube[33];
	cube[33] = cube[35];
	cube[35] = cube[29];
	cube[29] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[2+(i*3)];
		cube[2+(i*3)] = cube[20+(i*3)];
		cube[20+(i*3)] = cube[47+(i*3)];
		cube[47+(i*3)] = cube[42-(i*3)];
		cube[42-(i*3)] = temp;
	}
	cout << "Turn Right\n";
}

void RCube::turnFront()
{
	int temp = cube[19];
	cube[19] = cube[21];
	cube[21] = cube[25];
	cube[25] = cube[23];
	cube[23] = temp;
	temp = cube[18];
	cube[18] = cube[24];
	cube[24] = cube[26];
	cube[26] = cube[20];
	cube[20] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[6+i];
		cube[6+i] = cube[17-(i*3)];
		cube[17-(i*3)] = cube[47-i];
		cube[47-i] = cube[27+(i*3)];
		cube[27+(i*3)] = temp;
	}
	cout << "Turn Front\n";
}

void RCube::turnBack()
{
	int temp = cube[37];
	cube[37] = cube[39];
	cube[39] = cube[43];
	cube[43] = cube[41];
	cube[41] = temp;
	temp = cube[36];
	cube[36] = cube[42];
	cube[42] = cube[44];
	cube[44] = cube[38];
	cube[38] = temp;

	for(int i=0; i<3; i++)
	{
		temp = cube[0+i];
		cube[0+i] = cube[29+(i*3)];
		cube[29+(i*3)] = cube[53-i];
		cube[53-i] = cube[15-(i*3)];
		cube[15-(i*3)] = temp;
	}
	cout << "Turn Back\n";
}

void RCube::turnMiddle()
{
	turnCubeToDown();
	turnRight();
	turnCLeft();
}

void RCube::turnEquator()
{
	turnCubeToRight();
	turnUp();
	turnCDown();
}

void RCube::turnStanding()
{
	turnCubeSideToRight();
	turnCFront();
	turnBack();
}

void RCube::turnCUp()
{
	turnUp();
	turnUp();
	turnUp();
}

void RCube::turnCDown()
{
	turnDown();
	turnDown();
	turnDown();
}

void RCube::turnCLeft()
{
	turnLeft();
	turnLeft();
	turnLeft();
}

void RCube::turnCRight()
{
	turnRight();
	turnRight();
	turnRight();
}

void RCube::turnCFront()
{
	turnFront();
	turnFront();
	turnFront();
}

void RCube::turnCBack()
{
	turnBack();
	turnBack();
	turnBack();
}

void RCube::turnCMiddle()
{
	turnMiddle();
	turnMiddle();
	turnMiddle();
}

void RCube::turnCEquator()
{
	turnEquator();
	turnEquator();
	turnEquator();
}

void RCube::turnCStanding()
{
	turnStanding();
	turnStanding();
	turnStanding();
}

void RCube::turnUp2()
{
	turnUp();
	turnUp();
}

void RCube::turnDown2()
{
	turnDown();
	turnDown();
}

void RCube::turnLeft2()
{
	turnLeft();
	turnLeft();
}

void RCube::turnRight2()
{
	turnRight();
	turnRight();
}

void RCube::turnFront2()
{
	turnFront();
	turnFront();
}

void RCube::turnBack2()
{
	turnBack();
	turnBack();
}

void RCube::turnMiddle2()
{
	turnMiddle();
	turnMiddle();
}

void RCube::turnEquator2()
{
	turnEquator();
	turnEquator();
}

void RCube::turnStanding2()
{
	turnStanding();
	turnStanding();
}

void RCube::turnCubeToLeft()
{
	//Turn up
	int temp = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[7];
	cube[7] = cube[5];
	cube[5] = temp;
	temp = cube[0];
	cube[0] = cube[6];
	cube[6] = cube[8];
	cube[8] = cube[2];
	cube[2] = temp;

	//Turn down'
	temp = cube[46];
	cube[46] = cube[48];
	cube[48] = cube[52];
	cube[52] = cube[50];
	cube[50] = temp;
	temp = cube[45];
	cube[45] = cube[51];
	cube[51] = cube[53];
	cube[53] = cube[47];
	cube[47] = temp;

	temp = cube[46];
	cube[46] = cube[48];
	cube[48] = cube[52];
	cube[52] = cube[50];
	cube[50] = temp;
	temp = cube[45];
	cube[45] = cube[51];
	cube[51] = cube[53];
	cube[53] = cube[47];
	cube[47] = temp;

	temp = cube[46];
	cube[46] = cube[48];
	cube[48] = cube[52];
	cube[52] = cube[50];
	cube[50] = temp;
	temp = cube[45];
	cube[45] = cube[51];
	cube[51] = cube[53];
	cube[53] = cube[47];
	cube[47] = temp;

	//Turn rest to left
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[9+i+(j*3)];
			cube[9+i+(j*3)] = cube[18+i+(j*3)];
			cube[18+i+(j*3)] = cube[27+i+(j*3)];
			cube[27+i+(j*3)] = cube[36+i+(j*3)];
			cube[36+i+(j*3)] = temp;
		}
	}
	cout << "Turn Cube To Left\n";
}

void RCube::turnCubeToRight()
{
	//Turn up'
	int temp = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[7];
	cube[7] = cube[5];
	cube[5] = temp;
	temp = cube[0];
	cube[0] = cube[6];
	cube[6] = cube[8];
	cube[8] = cube[2];
	cube[2] = temp;

	temp = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[7];
	cube[7] = cube[5];
	cube[5] = temp;
	temp = cube[0];
	cube[0] = cube[6];
	cube[6] = cube[8];
	cube[8] = cube[2];
	cube[2] = temp;

	temp = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[7];
	cube[7] = cube[5];
	cube[5] = temp;
	temp = cube[0];
	cube[0] = cube[6];
	cube[6] = cube[8];
	cube[8] = cube[2];
	cube[2] = temp;

	//Turn down
	temp = cube[46];
	cube[46] = cube[48];
	cube[48] = cube[52];
	cube[52] = cube[50];
	cube[50] = temp;
	temp = cube[45];
	cube[45] = cube[51];
	cube[51] = cube[53];
	cube[53] = cube[47];
	cube[47] = temp;

	//Turn rest to right
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[15+i-(j*3)];
			cube[15+i-(j*3)] = cube[42+i-(j*3)];
			cube[42+i-(j*3)] = cube[33+i-(j*3)];
			cube[33+i-(j*3)] = cube[24+i-(j*3)];
			cube[24+i-(j*3)] = temp;
		}
	}
	cout << "Turn Cube To Right\n";
}

void RCube::turnCubeToUp()
{
	//Turn right
	int temp = cube[28];
	cube[28] = cube[30];
	cube[30] = cube[34];
	cube[34] = cube[32];
	cube[32] = temp;
	temp = cube[27];
	cube[27] = cube[33];
	cube[33] = cube[35];
	cube[35] = cube[29];
	cube[29] = temp;

	//Turn left'
	temp = cube[10];
	cube[10] = cube[12];
	cube[12] = cube[16];
	cube[16] = cube[14];
	cube[14] = temp;
	temp = cube[9];
	cube[9] = cube[15];
	cube[15] = cube[17];
	cube[17] = cube[11];
	cube[11] = temp;

	temp = cube[10];
	cube[10] = cube[12];
	cube[12] = cube[16];
	cube[16] = cube[14];
	cube[14] = temp;
	temp = cube[9];
	cube[9] = cube[15];
	cube[15] = cube[17];
	cube[17] = cube[11];
	cube[11] = temp;

	temp = cube[10];
	cube[10] = cube[12];
	cube[12] = cube[16];
	cube[16] = cube[14];
	cube[14] = temp;
	temp = cube[9];
	cube[9] = cube[15];
	cube[15] = cube[17];
	cube[17] = cube[11];
	cube[11] = temp;

	//Turn the rest to up
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[2+(i*3)-j];
			cube[2+(i*3)-j] = cube[20+(i*3)-j];
			cube[20+(i*3)-j] = cube[47+(i*3)-j];
			cube[47+(i*3)-j] = cube[42-(i*3)+j];
			cube[42-(i*3)+j] = temp;
		}
	}
	cout << "Turn cube to top\n";
}

void RCube::turnCubeToDown()
{
	//Turn left
	int temp = cube[10];
	cube[10] = cube[12];
	cube[12] = cube[16];
	cube[16] = cube[14];
	cube[14] = temp;
	temp = cube[9];
	cube[9] = cube[15];
	cube[15] = cube[17];
	cube[17] = cube[11];
	cube[11] = temp;

	//Turn right'
	temp = cube[28];
	cube[28] = cube[30];
	cube[30] = cube[34];
	cube[34] = cube[32];
	cube[32] = temp;
	temp = cube[27];
	cube[27] = cube[33];
	cube[33] = cube[35];
	cube[35] = cube[29];
	cube[29] = temp;

	temp = cube[28];
	cube[28] = cube[30];
	cube[30] = cube[34];
	cube[34] = cube[32];
	cube[32] = temp;
	temp = cube[27];
	cube[27] = cube[33];
	cube[33] = cube[35];
	cube[35] = cube[29];
	cube[29] = temp;

	temp = cube[28];
	cube[28] = cube[30];
	cube[30] = cube[34];
	cube[34] = cube[32];
	cube[32] = temp;
	temp = cube[27];
	cube[27] = cube[33];
	cube[33] = cube[35];
	cube[35] = cube[29];
	cube[29] = temp;

	//Turn the rest to down
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[0+(i*3)+j];
			cube[0+(i*3)+j] = cube[44-(i*3)-j];
			cube[44-(i*3)-j] = cube[45+(i*3)+j];
			cube[45+(i*3)+j] = cube[18+(i*3)+j];
			cube[18+(i*3)+j] = temp;
		}
	}
	cout << "Turn cube to down\n";
}

void RCube::turnCubeSideToLeft()
{
	//Turn front'
	int temp = cube[19];
	cube[19] = cube[21];
	cube[21] = cube[25];
	cube[25] = cube[23];
	cube[23] = temp;
	temp = cube[18];
	cube[18] = cube[24];
	cube[24] = cube[26];
	cube[26] = cube[20];
	cube[20] = temp;

	temp = cube[19];
	cube[19] = cube[21];
	cube[21] = cube[25];
	cube[25] = cube[23];
	cube[23] = temp;
	temp = cube[18];
	cube[18] = cube[24];
	cube[24] = cube[26];
	cube[26] = cube[20];
	cube[20] = temp;

	temp = cube[19];
	cube[19] = cube[21];
	cube[21] = cube[25];
	cube[25] = cube[23];
	cube[23] = temp;
	temp = cube[18];
	cube[18] = cube[24];
	cube[24] = cube[26];
	cube[26] = cube[20];
	cube[20] = temp;

	//Turn back
	temp = cube[37];
	cube[37] = cube[39];
	cube[39] = cube[43];
	cube[43] = cube[41];
	cube[41] = temp;
	temp = cube[36];
	cube[36] = cube[42];
	cube[42] = cube[44];
	cube[44] = cube[38];
	cube[38] = temp;

	//Turn the rest to side left
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[0+i+(j*3)];
			cube[0+i+(j*3)] = cube[29+(i*3)-j];
			cube[29+(i*3)-j] = cube[53-i-(j*3)];
			cube[53-i-(j*3)] = cube[15-(i*3)+j];
			cube[15-(i*3)+j] = temp;
		}
	}
	cout << "Turn cube to side left\n";
}

void RCube::turnCubeSideToRight()
{
	//Turn front
	int temp = cube[19];
	cube[19] = cube[21];
	cube[21] = cube[25];
	cube[25] = cube[23];
	cube[23] = temp;
	temp = cube[18];
	cube[18] = cube[24];
	cube[24] = cube[26];
	cube[26] = cube[20];
	cube[20] = temp;

	//Turn back'
	temp = cube[37];
	cube[37] = cube[39];
	cube[39] = cube[43];
	cube[43] = cube[41];
	cube[41] = temp;
	temp = cube[36];
	cube[36] = cube[42];
	cube[42] = cube[44];
	cube[44] = cube[38];
	cube[38] = temp;

	temp = cube[37];
	cube[37] = cube[39];
	cube[39] = cube[43];
	cube[43] = cube[41];
	cube[41] = temp;
	temp = cube[36];
	cube[36] = cube[42];
	cube[42] = cube[44];
	cube[44] = cube[38];
	cube[38] = temp;

	temp = cube[37];
	cube[37] = cube[39];
	cube[39] = cube[43];
	cube[43] = cube[41];
	cube[41] = temp;
	temp = cube[36];
	cube[36] = cube[42];
	cube[42] = cube[44];
	cube[44] = cube[38];
	cube[38] = temp;

	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = cube[6+i-(j*3)];
			cube[6+i-(j*3)] = cube[17-(i*3)-j];
			cube[17-(i*3)-j] = cube[47-i+(j*3)];
			cube[47-i+(j*3)] = cube[27+(i*3)+j];
			cube[27+(i*3)+j] = temp;
		}
	}
	cout << "Turn cube to side right\n";
}

void RCube::displayTurn(vector<int> array)
{
	for(int i=0; i<array.size(); i++)
	{
		if(array[i] == 0)
			cout << "Turn Up\n";
		else if(array[i] == 1)
			cout << "Turn Down\n";
		else if(array[i] == 2)
			cout << "Turn Left\n";
		else if(array[i] == 3)
			cout << "Turn Right\n";
		else if(array[i] == 4)
			cout << "Turn Front\n";
		else if(array[i] == 5)
			cout << "Turn Back\n";
		else if(array[i] == 6)
			cout << "Turn Up'\n";
		else if(array[i] == 7)
			cout << "Turn Down'\n";
		else if(array[i] == 8)
			cout << "Turn Left'\n";
		else if(array[i] == 9)
			cout << "Turn Right'\n";
		else if(array[i] == 10)
			cout << "Turn Front'\n";
		else if(array[i] == 11)
			cout << "Turn Back'\n";
	}
	cout << "\n";
}

void RCube::scramble(int times)
{
	srand(time(NULL));
	vector<int> scrambleArray;
	for(int i=0; i<times; i++)
		scrambleArray.push_back(rand() % 12);
	//cout << "Before pruning Size: " << scrambleArray.size() << "\n";
	//displayTurn(scrambleArray);
	/*for(int i=0; i<scrambleArray.size()-2; i++)
	{
		if(scrambleArray[i] == scrambleArray[i+1] && scrambleArray[i] == scrambleArray[i+2])
		{
			scrambleArray.erase(scrambleArray.begin()+i+2);
			scrambleArray.erase(scrambleArray.begin()+i+1);
			if(scrambleArray[i] == 0)
				scrambleArray[i] = 6;
			else if(scrambleArray[i] == 1)
				scrambleArray[i] = 7;
			else if(scrambleArray[i] == 2)
				scrambleArray[i] = 8;
			else if(scrambleArray[i] == 3)
				scrambleArray[i] = 9;
			else if(scrambleArray[i] == 4)
				scrambleArray[i] = 10;
			else if(scrambleArray[i] == 5)
				scrambleArray[i] = 11;
		}
	}*/
	//cout << "After pruning: " << scrambleArray.size() << "\n";
	//displayTurn(scrambleArray);
	/*for(int i=0; i<scrambleArray.size()-1; i++)
	{
		if(scrambleArray[i] == scrambleArray[i+1]+6 || scrambleArray[i] == scrambleArray[i+1]-6)
		{
			scrambleArray.erase(scrambleArray.begin()+i+1);
			scrambleArray.erase(scrambleArray.begin()+i);
		}
	}*/
	//cout << "After pruning + remove duplicates: " << scrambleArray.size() << "\n";
	//displayTurn(scrambleArray);
	for(int i=0; i<scrambleArray.size(); i++)
	{
		if(scrambleArray[i] == 0)
			turnUp();
		else if(scrambleArray[i] == 1)
			turnDown();
		else if(scrambleArray[i] == 2)
			turnLeft();
		else if(scrambleArray[i] == 3)
			turnRight();
		else if(scrambleArray[i] == 4)
			turnFront();
		else if(scrambleArray[i] == 5)
			turnBack();
		else if(scrambleArray[i] == 6)
			turnCUp();
		else if(scrambleArray[i] == 7)
			turnCDown();
		else if(scrambleArray[i] == 8)
			turnCLeft();
		else if(scrambleArray[i] == 9)
			turnCRight();
		else if(scrambleArray[i] == 10)
			turnCFront();
		else if(scrambleArray[i] == 11)
			turnCBack();
		//display();
	}
	cout << "End of scramble\n\n\n\n\n";
}

void RCube::solve()
{
	cout << "Now solving the cube\n";
	bool finish = false, step1 = false, step2 = false, step3 = false, step4 = false, step5 = false, step6 = false, step7 = false;
	int diff, diff2;
	int currentSide[] = {2, 3, 4, 5};
	int i = 1;
	//Step 1: Solve white cross
	while(!step1)
	{
		//Check is white cross and corresponding color match
		if(cube[46] == 6 && cube[48] == 6 && cube[50] == 6 && cube[52] == 6)
		{
			cout << "Checking white cross\n";
			bool side1 = false, side2 = false, side3 = false, side4 = false;
			for(int i=0; i<4; i++)
			{
				if(cube[16] == currentSide[i] && cube[13] == currentSide[i])
				{
					side1 = true;
					break;
				}
				else
					side1 = false;
			}
			for(int i=0; i<4; i++)
			{
				if(cube[25] == currentSide[i] && cube[22] == currentSide[i])
				{
					side2 = true;
					break;
				}
				else
					side2 = false;
			}
			for(int i=0; i<4; i++)
			{
				if(cube[34] == currentSide[i] && cube[31] == currentSide[i])
				{
					side3 = true;
					break;
				}
				else
					side3 = false;
			}
			for(int i=0; i<4; i++)
			{
				if(cube[43] == currentSide[i] && cube[40] == currentSide[i])
				{
					side4 = true;
					break;
				}
				else
					side4 = false;
			}
			if(side1 && side2 && side3 && side4)
				step1 = true;
			else
				cout << "White cross = FALSE\n";
		}
		if(!step1)
		{
			cout << "Now continue solving the cube\n";
			while(!finish)
			{
				cout << "Now check top and side for white edges\n";
				//Checking white cross
				if(cube[46] == 6 && cube[48] == 6 && cube[50] == 6 && cube[52] == 6)
						finish = true;
				else
				{
					cout << "Now check for top side\n";
					//Check top
					if(cube[1] == 6) //First edge
					{
						diff = currentSide[i] - cube[37];
						if(diff == 1 || diff == -3)
						{
							turnCUp();
							turnLeft2();
						}
						else if(diff == 0)
						{
							turnUp2();
							turnFront2();
						}
						else if(diff == -1 || diff == 3)
						{
							turnUp();
							turnRight2();
						}
						else if(diff == -2 || diff == 2)
						{
							turnBack2();
						}
					}
					else if(cube[3] == 6) //Second edge
					{
						diff = currentSide[i] - cube[10];
						if(diff == 1 || diff == -3)
						{
							turnLeft2();
						}
						else if(diff == 0)
						{
							turnCUp();
							turnFront2();
						}
						else if(diff == -1 || diff == 3)
						{
							turnUp2();
							turnRight2();
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp();
							turnBack2();
						}
					}
					else if(cube[5] == 6) //Third edge
					{
						diff = currentSide[i] - cube[28];
						if(diff == 1 || diff == -3)
						{
							turnUp2();
							turnLeft2();
						}
						else if(diff == 0)
						{
							turnUp();
							turnFront2();
						}
						else if(diff == -1 || diff == 3)
						{
							turnRight2();
						}
						else if(diff == -2 || diff == 2)
						{
							turnCUp();
							turnBack2();
						}
					}
					else if(cube[7] == 6) //Fourth edge
					{
						diff = currentSide[i] - cube[19];
						if(diff == 1 || diff == -3)
						{
							turnUp();
							turnLeft2();
						}
						else if(diff == 0)
						{
							turnFront2();
						}
						else if(diff == -1 || diff == 3)
						{
							turnCUp();
							turnRight2();
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp2();
							turnBack2();
						}
					}
					else if(cube[19] == 6) //Check side first edge
					{
						cout << "Now check for side edges\n";
						cout << "Go in first one\n";
						diff = currentSide[i] - cube[7];
						if(diff == 0)
						{
							turnUp();
							turnLeft();
							turnCFront();
							turnCLeft();
							turnCUp();
						}
						else if(diff == -1 || diff == 3)
						{
							turnFront();
							turnCRight();
							turnCFront();
						}
						else if(diff == 1 || diff == -3)
						{
							turnCFront();
							turnLeft();
							turnFront();
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp();
							turnCLeft();
							turnBack();
							turnLeft();
							turnCUp();
						}
					}
					else if(cube[21] == 6) //Second edge
					{
						cout << "Go in second\n";
						diff = currentSide[i] - cube[14];
						if(diff == 0)
						{
							turnCLeft();
							turnCUp();
							turnFront2();
							turnUp();
							turnLeft();
						}
						else if(diff == 1 || diff == -3)
						{
							turnLeft();
						}
						else if(diff == -1 || diff == 3)
						{
							turnCLeft();
							turnUp2();
							turnRight2();
							turnUp2();
							turnLeft();
						}
						else if(diff == -2 || diff == 2)
						{
							turnCLeft();
							turnUp();
							turnBack2();
							turnCUp();
							turnLeft();
						}
					}
					else if(cube[23] == 6) //Third edge
					{
						cout << "Go in third\n";
						diff = currentSide[i] - cube[30];
						if(diff == 0)
						{
							turnRight();
							turnUp();
							turnFront2();
							turnCUp();
							turnCRight();
						}
						else if(diff == 1 || diff == -3)
						{
							turnRight();
							turnUp2();
							turnLeft2();
							turnUp2();
							turnCRight();
						}
						else if(diff == -1 || diff == 3)
						{
							turnCRight();
						}
						else if(diff == -2 || diff == 2)
						{
							turnRight();
							turnCUp();
							turnBack2();
							turnUp();
							turnCRight();
						}
					}
					else if(cube[25] == 6) //Fourth edge
					{
						cout << "Go in fourth\n";
						diff = currentSide[i] - cube[46];
						if(diff == 0)
						{
							turnCFront();
							turnRight();
							turnUp();
							turnFront2();
							turnCRight();
						}
						else if(diff == 1 || diff == -3)
						{
							turnFront();
							turnLeft();
							turnCFront();
						}
						else if(diff == -1 || diff == 3)
						{
							turnCFront();
							turnCRight();
							turnFront();
						}
						else if(diff == -2 || diff == 2)
						{
							turnCFront();
							turnRight();
							turnCUp();
							turnBack2();
							turnCRight();
						}
					}
					turnCubeToLeft();
					i++;
					if(i == 4)
						i = 0;
					display();
				}
			}
			if(finish)
			{
				//Check bottom
				cout << "Check Bottom\n";

				cout << "Go in fifth\n";
				if(cube[25] != currentSide[i])
				{
					diff = currentSide[i] - cube[25];
					if(diff == 1 || diff == -3)
					{
						turnCMiddle();
						turnStanding();
						turnUp();
						turnCStanding();
						turnUp2();
						turnMiddle();
					}
					else if(diff == -1 || diff == 3)
					{
						turnCMiddle();
						turnCStanding();
						turnCUp();
						turnStanding();
						turnUp2();
						turnMiddle();
					}
					else if(diff == 2 || diff == -2)
					{
						turnCMiddle();
						turnUp();
						turnMiddle2();
						turnUp();
						turnMiddle2();
						turnUp();
						turnMiddle();
					}
				}
				turnCubeToLeft();
				i++;
				if(i == 4)
					i = 0;
				display();
			}
		}
	}
	cout << "Solve Step 1\n";
	finish = false;

	//Step 2: Solve white corners
	//To make white side on top
	turnCubeSideToLeft();
	turnCubeSideToLeft();
	//display();
	/*i = 1;
	//To reset the orange side as the front
	while(cube[22] != currentSide[1])
	{
		turnCubeToLeft();
		cout << "Turn Cube\n";
		display();
	}*/
	while(!step2)
	{
		if(cube[0] == 6 && cube[2] == 6 && cube[6] == 6 && cube[8] == 6)
		{
			cout << "Checking white corners\n";

			bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
			int temp;

			for(int i = 0; i<4; i++)
			{
				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;
				if((cube[38] == currentSide[temp]) && (cube[9] == currentSide[i]) && (cube[10] == currentSide[i]))
				{
					corner1 = true;
					break;
				}
				else
					corner1 = false;
			}
			for(int i = 0; i<4; i++)
			{
				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;
				if((cube[29] == currentSide[temp]) && (cube[36] == currentSide[i]) && (cube[37] == currentSide[i]))
				{
					corner2 = true;
					break;
				}
				else
					corner2 = false;
			}
			for(int i = 0; i<4; i++)
			{
				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;
				if((cube[11] == currentSide[temp]) && (cube[18] == currentSide[i]) && (cube[19] == currentSide[i]))
				{
					corner3 = true;
					break;
				}
				else
					corner3 = false;
			}
			for(int i = 0; i<4; i++)
			{
				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;
				if((cube[20] == currentSide[temp]) && (cube[27] == currentSide[i]) && (cube[28] == currentSide[i]))
				{
					corner4 = true;
					break;
				}
				else
					corner4 = false;
			}
			if(corner1 && corner2 && corner3 && corner4)
				step2 = true;
			else
				cout << "White corner = FALSE\n";			
		}
		if(!step2)
		{
			cout << "Now continue solving the cube\n";
			
			while(!finish)
			{
				cout << "Now checking top and side for white corners\n";
				if(cube[0] == 6 && cube[2] == 6 && cube[6] == 6 && cube[8] == 6)
					finish = true;
				else
				{
					//Make orange side the front
					cout << "Now check for top side (Down side)\n";
					if(cube[45] == 6) //Top first corner
					{
						cout << "Top First Corner\n";
						diff = currentSide[i] - cube[24];
						diff2 = currentSide[i] - cube[17];

						if(diff == 0 && diff2 == 1)
						{
							turnDown();
							turnCRight();
							turnDown2();
							turnRight();
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == 1 && diff2 == 2) || (diff == 1 && diff2 == -2))
						{
							turnDown2();
							turnCBack();
							turnDown2();
							turnBack();
							turnDown();
							turnCBack();
							turnCDown();
							turnBack();
						}
						else if((diff == 2 && diff2 == -1) || (diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3))
						{
							turnCDown();
							turnCLeft();
							turnDown2();
							turnLeft();
							turnDown();
							turnCLeft();
							turnCDown();
							turnLeft();
						}
						else if(diff == -1 && diff2 == 0)
						{
							turnCFront();
							turnDown2();
							turnFront();
							turnDown();
							turnCFront();
							turnCDown();
							turnFront();
						}
					}
					else if(cube[47] == 6) //Top second corner
					{
						cout << "Top second corner\n";
						diff = currentSide[i] - cube[26];
						diff2 = currentSide[i] - cube[33];

						if(diff == 1 && diff2 == 0)
						{
							turnCRight();
							turnDown2();
							turnRight();
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1))
						{
							turnDown();
							turnCBack();
							turnDown2();
							turnBack();
							turnDown();
							turnCBack();
							turnCDown();
							turnBack();
						}
						else if((diff == -1 && diff2 == -2) || (diff == -1 && diff2 == 2))
						{
							turnDown2();
							turnCLeft();
							turnDown2();
							turnLeft();
							turnDown();
							turnCLeft();
							turnCDown();
							turnLeft();
						}
						else if(diff == 0 && diff2 == -1)
						{
							turnCDown();
							turnLeft();
							turnDown2();
							turnCLeft();
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();
						}
					}
					else if(cube[51] == 6) //Top third corner
					{
						cout << "Top third corner\n";
						diff = currentSide[i] - cube[44];
						diff2 = currentSide[i] - cube[15];

						if((diff == 1 && diff2 == 0) || (diff == -1 && diff2 == 0))
						{
							turnDown2();
							turnCRight();
							turnDown2();
							turnRight();
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == -2 && diff2 == 1) || (diff == -2 && diff2 == -3) || (diff == 2 && diff2 == 1))
						{
							turnCDown();
							turnRight();
							turnCDown();
							turnCRight();
							turnDown2();
							turnRight();
							turnDown();
							turnCRight();
						}
						else if((diff == -2 && diff2 == -2) || (diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
						{
							turnCLeft();
							turnDown2();
							turnLeft();
							turnDown();
							turnCLeft();
							turnCDown();
							turnLeft();
						}
						else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3))
						{
							turnDown();
							turnLeft();
							turnDown2();
							turnCLeft();
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();
						}
					}
					else if(cube[53] == 6) //Top fourth corner
					{
						cout << "Top fourth corner\n";
						diff = currentSide[i] - cube[42];
						diff2 = currentSide[i] - cube[35];

						if((diff == 0 && diff2 == 1) || (diff == 0 && diff2 == -3))
						{
							turnCDown();
							turnCRight();
							turnDown2();
							turnRight();
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == 1 && diff2 == -2) || (diff == -3 && diff2 == -2) || (diff == 1 && diff2 == 2))
						{
							turnRight();
							turnDown2();
							turnCRight();
							turnCDown();
							turnRight();
							turnDown();
							turnCRight();
						}
						else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
						{
							turnDown();
							turnBack();
							turnDown2();
							turnCBack();
							turnCDown();
							turnBack();
							turnDown();
							turnCBack();
						}
						else if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
						{
							turnDown2();
							turnLeft();
							turnDown2();
							turnCLeft();
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();
						}
					}
					else if(cube[18] == 6) //Side first corner
					{
						cout << "Side first corner\n";
						diff = currentSide[i] - cube[6];
						diff2 = currentSide[i] - cube[11];

						if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
						{
							turnLeft();
							turnCDown();
							turnCLeft();
							turnDown();
							turnLeft();
							turnCDown();
							turnCLeft();
						}
						else if((diff == 0 && diff2 == 1) || (diff == 0 & diff2 == -3))
						{
							turnLeft();
							turnCDown();
							turnCLeft();
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == 1 && diff2 == -2) || (diff == 1 && diff2 == 2) || (diff == -3 && diff2 == -2))
						{
							turnLeft();
							turnCDown();
							turnCLeft();
							turnDown2();
							turnCBack();
							turnCDown();
							turnBack();
						}
						else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
						{
							turnLeft();
							turnCDown();
							turnCLeft();
							turnBack();
							turnCDown();
							turnCBack();
						}
					}
					else if(cube[20] == 6) //Side second corner
					{
						cout << "Side second corner\n";
						diff = currentSide[i] - cube[8];
						diff2 = currentSide[i] - cube[27];

						if((diff == 1 && diff2 == 0) || (diff == -1 && diff2 == 0) || (diff == -3 && diff2 == 0))
						{
							turnCRight();
							turnDown();  // This whole part double check
							turnRight();
							turnCDown();
							turnCRight();
							turnDown();
							turnRight();
						}
						else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCBack();
							turnDown();
							turnBack();
						}
						else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 & diff2 == 2))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCLeft();
							turnDown2();
							turnLeft();
						}
						else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3) || (diff == 0 && diff2 == 1))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();
						}
					}
					else if(cube[24] == 6) //Side third corner
					{
						cout << "Side third corner\n";
						diff = currentSide[i] - cube[45];
						diff2 = currentSide[i] - cube[17];

						if((diff == 1 && diff2 == 0) || (diff == -3 && diff2 == 0))
						{
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
						}
						else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
						{
							turnDown2();
							turnCBack();
							turnCDown();
							turnBack();
						}
						else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
						{
							turnCDown();
							turnCLeft();
							turnCDown();
							turnLeft();
						}
						else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3))
						{
							/*turnRight();
							turnDown2();
							turnCRight();*/
							turnDown();
							turnLeft();
							turnCDown();
							turnCLeft();
						}
					}
					else if(cube[26] == 6) //Side fourth corner
					{
						cout << "Side fourth corner\n";
						diff = currentSide[i] - cube[47];
						diff2 = currentSide[i] - cube[33];

						if((diff == 0 && diff2 == 1) || (diff == 0 && diff2 == -3))
						{
							turnCDown();
							turnCRight();
							turnDown();
							turnRight();
						}
						else if((diff == 1 && diff2 == -2) || (diff == 1 && diff2 == 2) || (diff == -3 && diff2 == -2))
						{
							turnCBack();
							turnDown();
							turnBack();
						}
						else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
						{
							turnCLeft();
							turnDown2();
							turnLeft();
						}
						else if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
						{
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();

							/*turnDown2();
							turnCFront();
							turnDown();
							turnFront();*/
						}
					}
					turnCubeToLeft();
					i--;
					if(i == -1)
						i = 3;
					//display();
					cout << "Current Side = " << currentSide[i] << "\n";
				}
			}
			if(finish)
			{
				/*if(cube[0] == 6 && cube[2] == 6 && cube[6] == 6 && cube[8] == 6)
				{
					cout << "Checking white corners\n";

					bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
					int temp;

					for(int i = 0; i<4; i++)
					{
						if(i+1 == 4)
							temp = 0;
						else
							temp = i+1;
						if((cube[38] == currentSide[temp]) && (cube[9] == currentSide[i]) && (cube[10] == currentSide[i]))
						{
							corner1 = true;
							break;
						}
						else
							corner1 = false;
					}
					for(int i = 0; i<4; i++)
					{
						if(i+1 == 4)
							temp = 0;
						else
							temp = i+1;
						if((cube[29] == currentSide[temp]) && (cube[36] == currentSide[i]) && (cube[37] == currentSide[i]))
						{
							corner2 = true;
							break;
						}
						else
							corner2 = false;
					}
					for(int i = 0; i<4; i++)
					{
						if(i+1 == 4)
							temp = 0;
						else
							temp = i+1;
						if((cube[11] == currentSide[temp]) && (cube[18] == currentSide[i]) && (cube[19] == currentSide[i]))
						{
							corner3 = true;
							break;
						}
						else
							corner3 = false;
					}
					for(int i = 0; i<4; i++)
					{
						if(i+1 == 4)
							temp = 0;
						else
							temp = i+1;
						if((cube[20] == currentSide[temp]) && (cube[27] == currentSide[i]) && (cube[28] == currentSide[i]))
						{
							corner4 = true;
							break;
						}
						else
							corner4 = false;
					}
					if(corner1 && corner2 && corner3 && corner4)
						finish = true;
					else
						cout << "White corner = FALSE\n";			
				}*/

				//Orient the corners
				cout << "Orient corners\n";
				finish = false;
				int temp;

				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;
				cout << "Current Side = " << currentSide[i] << " Next Side = " << currentSide[temp] << "\n";

				if(cube[18] != currentSide[i] && cube[11] != currentSide[temp])
				{
					diff = currentSide[i] - cube[18];
					diff2 = currentSide[i] - cube[11];

					cout << "DIFF = " << diff << "\n";
					cout << "DIFF2 = " << diff2 << "\n";

					if((diff == 1 && diff2 == 0) || (diff == -3 && diff2 == 0))
					{
						turnLeft();
						turnDown();
						turnCLeft();
						turnCRight();
						turnCDown();
						turnRight();
						turnLeft();
						turnDown();
						turnCLeft();
					}
					else if((diff == -2 && diff2 == 1) || (diff == -2 && diff2 == -3) || (diff == 2 && diff2 == 1) || (diff == 2 && diff2 == -3))
					{
						turnLeft();
						turnRight();
						turnDown2();
						turnCLeft();
						turnCRight();
					}
					else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
					{
						turnLeft();
						turnDown2();
						turnCLeft();
						turnDown();
						turnCLeft();
						turnCDown();
						turnLeft();
						turnDown2();
						turnLeft();
						turnDown();
						turnCLeft();
					}
				}
				turnCubeToLeft();
				i--;
				if(i == -1)
					i = 3;
				display();
			}
		}
	}
	cout << "Solve Step 2\n";
	finish = false;

	//Step 3: Solve second layers
	i = 1;
	while(!step3)
	{
		if((cube[12] == cube[13] && cube[14] == cube[13]) && (cube[21] == cube[22] && cube[23] == cube[22]) && (cube[30] == cube[31] && cube[32] == cube[31]) && (cube[39] == cube[40] && cube[41] == cube[40]))
			step3 = true;
		else
			cout << "Second layer = FALSE\n";

		if(!step3)
		{
			cout << "Entered\n";
			if((cube[25] != 1) && (cube[46] != 1)) //Must not be yellow
			{
				cout << "Entered if loop\n";
				i = 1;
				while(cube[25] != cube[22])
				{
					turnCubeToLeft();
					turnDown();
				}
				if((cube[46] != cube[13]) && (cube[46] == cube[31])) //Right side
				{
					turnCDown();
					turnCRight();
					turnDown();
					turnRight();
					turnDown();
					turnFront();
					turnCDown();
					turnCFront();
				}
				else if((cube[46] == cube[13]) && (cube[46] != cube[31])) //Left side
				{
					turnDown();
					turnLeft();
					turnCDown();
					turnCLeft();
					turnCDown();
					turnCFront();
					turnDown();
					turnFront();
				}
			}
			else
			{
				turnCubeToLeft();
				i++;
				if(i == 5)
				{
					turnCDown();
					turnCRight();
					turnDown();
					turnRight();
					turnDown();
					turnFront();
					turnCDown();
					turnCFront();
					i = 1;
				}
			}
		}
	}
	cout << "Solve step 3\n";

	//Step 4: Solve yellow cross
	//Make yellow side on top
	turnCubeSideToLeft();
	turnCubeSideToLeft();
	i = 1;
	while(!step4)
	{
		if(cube[1] == 1 && cube[3] == 1 && cube[5] == 1 && cube[7] == 1) //Yellow cross
		{
			step4 = true;
		}
		else
		{
			//Yellow Line, yellow L, yellow dot
			if((cube[3] == 1 && cube[5] == 1) || (cube[1] == 1 && cube[3] == 1) || (cube[1] != 1 && cube[3] != 1 && cube[5] != 1 && cube[7] != 1))
			{
				turnFront();
				turnRight();
				turnUp();
				turnCRight();
				turnCUp();
				turnCFront();
			}
			else //Yellow line or L is facing wrong direction
			{
				turnCubeToLeft();
			}
		}
	}
	cout << "Solve step 4\n";
	
	i = 1;
	//To reset the orange side as the front
	while(cube[22] != currentSide[1])
	{
		turnCubeToLeft();
		cout << "Turn Cube\n";
		display();
	}
	display();


	//Step 5: Fix yellow edges
	int counter = 1;
	while(!step5)
	{
		if(cube[10] == cube[13] && cube[19] == cube[22] && cube[28] == cube[31] && cube[37] == cube[40])
			step5 = true;
		else
		{
			if(counter == 3)
			{
				turnUp2();
				counter = 0;
			}
			if((cube[19] != cube[22]) && (cube[10] != cube[13]))
			{
				cout << "Case 1\n";
				turnRight();
				turnUp();
				turnCRight();
				turnUp();
				turnRight();
				turnUp2();
				turnCRight();
				turnUp();
				display();
				counter++;
			}
			else if((cube[10] == cube[13]) && (cube[19] != cube[22]) && (cube[28] == cube[31]) && (cube[37] != cube[40]))
			{
				cout << "Case 2\n";
				turnRight();
				turnUp();
				turnCRight();
				turnUp();
				turnRight();
				turnUp2();
				turnCRight();
				turnUp();
				turnUp2();
				turnRight();
				turnUp();
				turnCRight();
				turnUp();
				turnRight();
				turnUp2();
				turnCRight();
				display();
			}
			else
				turnCubeToRight();
		}
	}
	cout << "Solve step 5\n";
	cout << "\7";
	
	i = 1;
	//To reset the orange side as the front
	while(cube[22] != currentSide[1])
	{
		turnCubeToLeft();
		cout << "Turn Cube\n";
		display();
	}
	display();


	//Step 6: Position yellow corner
	while(!step6)
	{
		if(cube[0] == 1 && cube[2] == 1 && cube[6] == 1 && cube[8] == 1)
		{
			if((cube[20] == cube[22]) && (cube[27] == cube[31]))
		}
		else
		{

		}
	}
	/*
	//Step 7: Orient yellow corner
	while(!step7)
	{

	}*/
}