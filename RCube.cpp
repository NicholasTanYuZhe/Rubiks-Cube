#include "RCube.h"

RCube::RCube()
{
	int num = 0;
	for(int i=0; i<54; i++)
	{
		if(i % 9 == 0)
			num++;
		cube[i] = num;
	}
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

void RCube::reset(vector<int>& sequence)
{
	int num = 0;
	for(int i=0; i<54; i++)
	{
		if(i % 9 == 0)
			num++;
		cube[i] = num;
	}
	sequence.clear();
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
}

void RCube::displayTurn(vector<int> sequence)
{
	for(int i=0; i<sequence.size(); i++)
	{
		if(sequence[i] == 0)
			cout << "U";
		else if(sequence[i] == 1)
			cout << "D";
		else if(sequence[i] == 2)
			cout << "L";
		else if(sequence[i] == 3)
			cout << "R";
		else if(sequence[i] == 4)
			cout << "F";
		else if(sequence[i] == 5)
			cout << "B";
		else if(sequence[i] == 6)
			cout << "M";
		else if(sequence[i] == 7)
			cout << "E";
		else if(sequence[i] == 8)
			cout << "S";
		else if(sequence[i] == 9)
			cout << "U'";
		else if(sequence[i] == 10)
			cout << "D'";
		else if(sequence[i] == 11)
			cout << "L'";
		else if(sequence[i] == 12)
			cout << "R'";
		else if(sequence[i] == 13)
			cout << "F'";
		else if(sequence[i] == 14)
			cout << "B'";
		else if(sequence[i] == 15)
			cout << "M'";
		else if(sequence[i] == 16)
			cout << "E'";
		else if(sequence[i] == 17)
			cout << "S'";
		else if(sequence[i] == 18)
			cout << "U2";
		else if(sequence[i] == 19)
			cout << "D2";
		else if(sequence[i] == 20)
			cout << "L2";
		else if(sequence[i] == 21)
			cout << "R2";
		else if(sequence[i] == 22)
			cout << "F2";
		else if(sequence[i] == 23)
			cout << "B2";
		else if(sequence[i] == 24)
			cout << "M2";
		else if(sequence[i] == 25)
			cout << "E2";
		else if(sequence[i] == 26)
			cout << "S2";
		else if(sequence[i] == 27)
			cout << "X";
		else if(sequence[i] == 28)
			cout << "X'";
		else if(sequence[i] == 29)
			cout << "Y";
		else if(sequence[i] == 30)
			cout << "Y'";
		else if(sequence[i] == 31)
			cout << "Z";
		else if(sequence[i] == 32)
			cout << "Z'";
		else if(sequence[i] == 33)
			cout << "X2";
		else if(sequence[i] == 34)
			cout << "Y2";
		else if(sequence[i] == 35)
			cout << "Z2";
	}
	cout << "\n";
}

void RCube::reduce(vector<int>& sequence)
{
	for(int i=0; i<sequence.size()-1; i++)
	{
		if((sequence[i]+9 == sequence[i+1]) && sequence[i] < 9) //To reduce clockwise with anti-clockwise
		{
			sequence.erase(sequence.begin()+i);
			sequence.erase(sequence.begin()+i);
		}

		if((sequence[i]+1 == sequence[i+1]) && sequence[i] > 26 && sequence[i] < 33) //X X' Y Y' Z Z'
		{
			sequence.erase(sequence.begin()+i);
			sequence.erase(sequence.begin()+i);
		}
	}
	for(int i=0; i<sequence.size()-3; i++)
	{
		if((sequence[i] == sequence[i+1]) && (sequence[i] == sequence[i+2]) && (sequence[i] == sequence[i+3])) //Remove 4 same move
		{
			sequence.erase(sequence.begin()+i);
			sequence.erase(sequence.begin()+i);
			sequence.erase(sequence.begin()+i);
			sequence.erase(sequence.begin()+i);
		}
	}
	for(int i=0; i<sequence.size()-1; i++)
	{
		if(sequence[i] == sequence[i+1] && sequence[i] < 9) //To merge 2 same move (Clockwise)
		{
			sequence.erase(sequence.begin()+i);
			sequence[i] = sequence[i] + 18;
		}
		if(sequence[i] == sequence[i+1] && sequence[i] > 8 && sequence[i] < 18) //To merge 2 same move (Counter Clockwise)
		{
			sequence.erase(sequence.begin()+i);
			sequence[i] = sequence[i] + 9;
		}
		if(sequence[i] == sequence[i+1] && sequence[i] > 26 && sequence[i] < 33) //To merge 2 same move (X Y Z)
		{
			sequence.erase(sequence.begin()+i);
			if(sequence[i] == 27)
				sequence[i] = sequence[i] + 6;
			else if(sequence[i] == 28 || sequence[i] == 29)
				sequence[i] = sequence[i] + 5;
			else if(sequence[i] == 30 || sequence[i] == 31)
				sequence[i] = sequence[i] + 4;
			else if(sequence[i] == 32)
				sequence[i] = sequence[i] + 3;
		}
	}
}

void RCube::scramble(int times)
{
	srand(time(NULL));
	vector<int> scrambleArray;
	for(int i=0; i<times; i++)
	{
		int random = rand()%12;
		if(random > 5)
			random = random + 3;
		scrambleArray.push_back(random);
	}
	reduce(scrambleArray);
	displayTurn(scrambleArray);

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
	}
	cout << "End of scramble\n\n\n\n\n";
}

void RCube::solve(vector<int>& sequence)
{
	bool finish = false, step1 = false, step2 = false, step3 = false, step4 = false, step5 = false, step6 = false, step7 = false;
	int diff, diff2, temp;
	int currentSide[] = {2, 3, 4, 5};
	int i = 1, counter;

	//Start timer
	auto start = chrono::system_clock::now();

	//Step 1: Solve white cross
	while(!step1)
	{
		//Check is white cross and corresponding color match
		if(cube[46] == 6 && cube[48] == 6 && cube[50] == 6 && cube[52] == 6)
		{
			bool side1 = false, side2 = false, side3 = false, side4 = false;
			for(int j=0; j<4; j++)
			{
				if(cube[16] == currentSide[j] && cube[13] == currentSide[j])
				{
					side1 = true;
					break;
				}
				else
					side1 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(cube[25] == currentSide[j] && cube[22] == currentSide[j])
				{
					side2 = true;
					break;
				}
				else
					side2 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(cube[34] == currentSide[j] && cube[31] == currentSide[j])
				{
					side3 = true;
					break;
				}
				else
					side3 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(cube[43] == currentSide[j] && cube[40] == currentSide[j])
				{
					side4 = true;
					break;
				}
				else
					side4 = false;
			}
			if(side1 && side2 && side3 && side4)
				step1 = true;
		}
		if(!step1)
		{
			while(!finish)
			{
				//Checking white cross
				if(cube[46] == 6 && cube[48] == 6 && cube[50] == 6 && cube[52] == 6)
						finish = true;
				else
				{
					//Check top
					if(cube[1] == 6) //First edge
					{
						diff = currentSide[i] - cube[37];
						if(diff == 1 || diff == -3)
						{
							turnCUp();
							turnLeft2();
							sequence.push_back(9);
							sequence.push_back(20);
						}
						else if(diff == 0)
						{
							turnUp2();
							turnFront2();
							sequence.push_back(18);
							sequence.push_back(22);
						}
						else if(diff == -1 || diff == 3)
						{
							turnUp();
							turnRight2();
							sequence.push_back(0);
							sequence.push_back(21);
						}
						else if(diff == -2 || diff == 2)
						{
							turnBack2();
							sequence.push_back(23);
						}
					}
					else if(cube[3] == 6) //Second edge
					{
						diff = currentSide[i] - cube[10];
						if(diff == 1 || diff == -3)
						{
							turnLeft2();
							sequence.push_back(20);
						}
						else if(diff == 0)
						{
							turnCUp();
							turnFront2();
							sequence.push_back(9);
							sequence.push_back(22);
						}
						else if(diff == -1 || diff == 3)
						{
							turnUp2();
							turnRight2();
							sequence.push_back(18);
							sequence.push_back(21);
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp();
							turnBack2();
							sequence.push_back(0);
							sequence.push_back(23);
						}
					}
					else if(cube[5] == 6) //Third edge
					{
						diff = currentSide[i] - cube[28];
						if(diff == 1 || diff == -3)
						{
							turnUp2();
							turnLeft2();
							sequence.push_back(18);
							sequence.push_back(20);
						}
						else if(diff == 0)
						{
							turnUp();
							turnFront2();
							sequence.push_back(0);
							sequence.push_back(22);
						}
						else if(diff == -1 || diff == 3)
						{
							turnRight2();
							sequence.push_back(21);
						}
						else if(diff == -2 || diff == 2)
						{
							turnCUp();
							turnBack2();
							sequence.push_back(9);
							sequence.push_back(23);
						}
					}
					else if(cube[7] == 6) //Fourth edge
					{
						diff = currentSide[i] - cube[19];
						if(diff == 1 || diff == -3)
						{
							turnUp();
							turnLeft2();
							sequence.push_back(0);
							sequence.push_back(20);
						}
						else if(diff == 0)
						{
							turnFront2();
							sequence.push_back(22);
						}
						else if(diff == -1 || diff == 3)
						{
							turnCUp();
							turnRight2();
							sequence.push_back(9);
							sequence.push_back(21);
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp2();
							turnBack2();
							sequence.push_back(18);
							sequence.push_back(23);
						}
					}
					else if(cube[19] == 6) //Check side first edge
					{
						diff = currentSide[i] - cube[7];
						if(diff == 0)
						{
							turnUp();
							turnLeft();
							turnCFront();
							turnCLeft();
							turnCUp();
							int array[] = {0,2,13,11,9};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == -1 || diff == 3)
						{
							turnFront();
							turnCRight();
							turnCFront();
							int array[] = {4,12,13};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if(diff == 1 || diff == -3)
						{
							turnCFront();
							turnLeft();
							turnFront();
							int array[] = {13,2,4};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if(diff == -2 || diff == 2)
						{
							turnUp();
							turnCLeft();
							turnBack();
							turnLeft();
							turnCUp();
							int array[] = {0,11,5,2,9};
							sequence.insert(sequence.end(), array, array+5);
						}
					}
					else if(cube[21] == 6) //Second edge
					{
						diff = currentSide[i] - cube[14];
						if(diff == 0)
						{
							turnCLeft();
							turnCUp();
							turnFront2();
							turnUp();
							turnLeft();
							int array[] = {11,9,22,0,2};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == 1 || diff == -3)
						{
							turnLeft();
							sequence.push_back(2);
						}
						else if(diff == -1 || diff == 3)
						{
							turnCLeft();
							turnUp2();
							turnRight2();
							turnUp2();
							turnLeft();
							int array[] = {11,18,21,18,2};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == -2 || diff == 2)
						{
							turnCLeft();
							turnUp();
							turnBack2();
							turnCUp();
							turnLeft();
							int array[] = {11,0,23,9,2};
							sequence.insert(sequence.end(), array, array+5);
						}
					}
					else if(cube[23] == 6) //Third edge
					{
						diff = currentSide[i] - cube[30];
						if(diff == 0)
						{
							turnRight();
							turnUp();
							turnFront2();
							turnCUp();
							turnCRight();
							int array[] = {3,0,22,9,12};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == 1 || diff == -3)
						{
							turnRight();
							turnUp2();
							turnLeft2();
							turnUp2();
							turnCRight();
							int array[] = {3,18,20,18,12};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == -1 || diff == 3)
						{
							turnCRight();
							sequence.push_back(12);
						}
						else if(diff == -2 || diff == 2)
						{
							turnRight();
							turnCUp();
							turnBack2();
							turnUp();
							turnCRight();
							int array[] = {3,9,23,0,12};
							sequence.insert(sequence.end(), array, array+5);
						}
					}
					else if(cube[25] == 6) //Fourth edge
					{
						diff = currentSide[i] - cube[46];
						if(diff == 0)
						{
							turnCFront();
							turnRight();
							turnUp();
							turnFront2();
							turnCRight();
							int array[] = {13,3,0,22,12};
							sequence.insert(sequence.end(), array, array+5);
						}
						else if(diff == 1 || diff == -3)
						{
							turnFront();
							turnLeft();
							turnCFront();
							int array[] = {4,2,13};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if(diff == -1 || diff == 3)
						{
							turnCFront();
							turnCRight();
							turnFront();
							int array[] = {13,12,4};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if(diff == -2 || diff == 2)
						{
							turnCFront();
							turnRight();
							turnCUp();
							turnBack2();
							turnCRight();
							int array[] = {13,3,9,23,12};
							sequence.insert(sequence.end(), array, array+5);
						}
					}
					turnCubeToLeft();
					sequence.push_back(29);
					i++;
					if(i == 4)
						i = 0;
				}
			}
			if(finish)
			{
				//Check bottom
				if(cube[25] != cube[22])
				{
					diff = cube[22] - cube[25];
					if(diff == 1 || diff == -3)
					{
						turnCMiddle();
						turnStanding();
						turnUp();
						turnCStanding();
						turnUp2();
						turnMiddle();
						int array[] = {15,8,0,17,18,6};
						sequence.insert(sequence.end(), array, array+6);
					}
					else if(diff == -1 || diff == 3)
					{
						turnCMiddle();
						turnCStanding();
						turnCUp();
						turnStanding();
						turnUp2();
						turnMiddle();
						int array[] = {15,17,9,8,18,6};
						sequence.insert(sequence.end(), array, array+6);
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
						int array[] = {15,0,24,0,24,0,6};
						sequence.insert(sequence.end(), array, array+7);
					}
				}
				turnCubeToLeft();
				sequence.push_back(29);
			}
		}
	}
	finish = false;

	//Step 2: Solve white corners
	//To make white side on top
	turnCubeSideToLeft();
	turnCubeSideToLeft();
	sequence.push_back(32);
	sequence.push_back(32);

	while(!step2)
	{
		if(cube[0] == 6 && cube[2] == 6 && cube[6] == 6 && cube[8] == 6)
		{
			bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
			for(int j = 0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if((cube[38] == currentSide[temp]) && (cube[9] == currentSide[j]) && (cube[10] == currentSide[j]))
				{
					corner1 = true;
					break;
				}
				else
					corner1 = false;
			}
			for(int j = 0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if((cube[29] == currentSide[temp]) && (cube[36] == currentSide[j]) && (cube[37] == currentSide[j]))
				{
					corner2 = true;
					break;
				}
				else
					corner2 = false;
			}
			for(int j = 0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if((cube[11] == currentSide[temp]) && (cube[18] == currentSide[j]) && (cube[19] == currentSide[j]))
				{
					corner3 = true;
					break;
				}
				else
					corner3 = false;
			}
			for(int j = 0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if((cube[20] == currentSide[temp]) && (cube[27] == currentSide[j]) && (cube[28] == currentSide[j]))
				{
					corner4 = true;
					break;
				}
				else
					corner4 = false;
			}
			if(corner1 && corner2 && corner3 && corner4)
				step2 = true;	
		}
		if(!step2)
		{
			while(!finish)
			{
				if(cube[0] == 6 && cube[2] == 6 && cube[6] == 6 && cube[8] == 6)
					finish = true;
				else
				{
					//Make orange side the front
					if(cube[45] == 6) //Top first corner
					{
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
							int array[] = {1,12,19,3,1,12,10,3};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {19,14,19,5,1,14,10,5};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {10,11,19,2,1,11,10,2};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {13,19,4,1,13,10,4};
							sequence.insert(sequence.end(), array, array+7);
						}
					}
					else if(cube[47] == 6) //Top second corner
					{
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
							int array[] = {12,19,3,1,12,10,3};
							sequence.insert(sequence.end(), array, array+7);
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
							int array[] = {1,14,19,5,1,14,10,5};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {19,11,19,2,1,11,10,2};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {10,2,19,11,10,2,1,11};
							sequence.insert(sequence.end(), array, array+8);
						}
					}
					else if(cube[51] == 6) //Top third corner
					{
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
							int array[] = {19,12,19,3,1,12,10,3};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {10,3,10,12,19,3,1,12};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {11,19,2,1,11,10,2};
							sequence.insert(sequence.end(), array, array+7);
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
							int array[] = {1,2,19,11,10,2,1,11};
							sequence.insert(sequence.end(), array, array+8);
						}
					}
					else if(cube[53] == 6) //Top fourth corner
					{
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
							int array[] = {10,12,19,3,1,12,10,3};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {3,19,12,10,3,1,12};
							sequence.insert(sequence.end(), array, array+7);
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
							int array[] = {1,5,19,14,10,5,1,14};
							sequence.insert(sequence.end(), array, array+8);
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
							int array[] = {19,2,19,11,10,2,1,11};
							sequence.insert(sequence.end(), array, array+8);
						}
					}
					else if(cube[18] == 6) //Side first corner
					{
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
							int array[] = {2,10,11,1,2,10,11};
							sequence.insert(sequence.end(), array, array+7);
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
							int array[] = {2,10,11,1,12,10,3};
							sequence.insert(sequence.end(), array, array+7);
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
							int array[] = {2,10,11,19,14,10,5};
							sequence.insert(sequence.end(), array, array+7);
						}
						else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
						{
							turnLeft();
							turnCDown();
							turnCLeft();
							turnBack();
							turnCDown();
							turnCBack();
							int array[] = {2,10,11,5,10,14};
							sequence.insert(sequence.end(), array, array+6);
						}
					}
					else if(cube[20] == 6) //Side second corner
					{
						diff = currentSide[i] - cube[8];
						diff2 = currentSide[i] - cube[27];

						if((diff == 1 && diff2 == 0) || (diff == -1 && diff2 == 0) || (diff == -3 && diff2 == 0))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCDown();
							turnCRight();
							turnDown();
							turnRight();
							int array[] = {12,1,3,10,12,1,3};
							sequence.insert(sequence.end(), array, array+7);
						}
						else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCBack();
							turnDown();
							turnBack();
							int array[] = {12,1,3,14,1,5};
							sequence.insert(sequence.end(), array, array+6);
						}
						else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 & diff2 == 2))
						{
							turnCRight();
							turnDown();
							turnRight();
							turnCLeft();
							turnDown2();
							turnLeft();
							int array[] = {12,1,3,11,19,2};
							sequence.insert(sequence.end(), array, array+6);
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
							int array[] = {12,1,3,10,2,1,11};
							sequence.insert(sequence.end(), array, array+7);
						}
					}
					else if(cube[24] == 6) //Side third corner
					{
						diff = currentSide[i] - cube[45];
						diff2 = currentSide[i] - cube[17];

						if((diff == 1 && diff2 == 0) || (diff == -3 && diff2 == 0))
						{
							turnDown();
							turnCRight();
							turnCDown();
							turnRight();
							int array[] = {1,12,10,3};
							sequence.insert(sequence.end(), array, array+4);
						}
						else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
						{
							turnDown2();
							turnCBack();
							turnCDown();
							turnBack();
							int array[] = {19,14,10,5};
							sequence.insert(sequence.end(), array, array+4);
						}
						else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
						{
							turnCDown();
							turnCLeft();
							turnCDown();
							turnLeft();
							int array[] = {10,11,10,2};
							sequence.insert(sequence.end(), array, array+4);
						}
						else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3))
						{
							turnDown();
							turnLeft();
							turnCDown();
							turnCLeft();
							int array[] = {1,2,10,11};
							sequence.insert(sequence.end(), array, array+4);
						}
					}
					else if(cube[26] == 6) //Side fourth corner
					{
						diff = currentSide[i] - cube[47];
						diff2 = currentSide[i] - cube[33];

						if((diff == 0 && diff2 == 1) || (diff == 0 && diff2 == -3))
						{
							turnCDown();
							turnCRight();
							turnDown();
							turnRight();
							int array[] = {10,12,1,3};
							sequence.insert(sequence.end(), array, array+4);
						}
						else if((diff == 1 && diff2 == -2) || (diff == 1 && diff2 == 2) || (diff == -3 && diff2 == -2))
						{
							turnCBack();
							turnDown();
							turnBack();
							int array[] = {14,1,5};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
						{
							turnCLeft();
							turnDown2();
							turnLeft();
							int array[] = {11,19,2};
							sequence.insert(sequence.end(), array, array+3);
						}
						else if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
						{
							turnCDown();
							turnLeft();
							turnDown();
							turnCLeft();
							int array[] = {10, 2, 1, 11};
							sequence.insert(sequence.end(), array, array+4);
						}
					}
					turnCubeToLeft();
					sequence.push_back(29);
					i--;
					if(i == -1)
						i = 3;
				}
			}
			if(finish)
			{
				//Orient the corners
				finish = false;

				if(i+1 == 4)
					temp = 0;
				else
					temp = i+1;

				if(cube[18] != cube[22] && cube[11] != cube[13])
				{
					diff = cube[22] - cube[18];
					diff2 = cube[22] - cube[11];

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
						int array[] = {2,1,11,12,10,3,2,1,11};
						sequence.insert(sequence.end(), array, array+9);
					}
					else if((diff == -2 && diff2 == 1) || (diff == -2 && diff2 == -3) || (diff == 2 && diff2 == 1) || (diff == 2 && diff2 == -3))
					{
						turnLeft();
						turnRight();
						turnDown2();
						turnCLeft();
						turnCRight();
						int array[] = {2,3,19,11,12};
						sequence.insert(sequence.end(), array, array+5);
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
						int array[] = {2,19,11,1,11,10,2,19,2,1,11};
						sequence.insert(sequence.end(), array, array+11);
					}
				}
				turnCubeToLeft();
				sequence.push_back(29);
				i--;
				if(i == -1)
					i = 3;
			}
		}
	}
	finish = false;

	//Step 3: Solve second layers
	counter = 1;
	while(!step3)
	{
		if((cube[12] == cube[13] && cube[14] == cube[13]) && (cube[21] == cube[22] && cube[23] == cube[22]) && (cube[30] == cube[31] && cube[32] == cube[31]) && (cube[39] == cube[40] && cube[41] == cube[40]))
			step3 = true;

		if(!step3)
		{
			if((cube[25] != 1) && (cube[46] != 1)) //Must not be yellow
			{
				counter = 1;
				while(cube[25] != cube[22])
				{
					turnCubeToLeft();
					turnDown();
					sequence.push_back(29);
					sequence.push_back(1);
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
					int array[] = {10,12,1,3,1,4,10,13};
					sequence.insert(sequence.end(), array, array+8);
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
					int array[] = {1,2,10,11,10,13,1,4};
					sequence.insert(sequence.end(), array, array+8);
				}
			}
			else
			{
				turnCubeToLeft();
				sequence.push_back(29);
				counter++;
				if(counter == 5)
				{
					turnCDown();
					turnCRight();
					turnDown();
					turnRight();
					turnDown();
					turnFront();
					turnCDown();
					turnCFront();
					int array[] = {10,12,1,3,1,4,10,13};
					sequence.insert(sequence.end(), array, array+8);
					counter = 1;
				}
			}
		}
	}

	//Step 4: Solve yellow cross
	//Make yellow side on top
	turnCubeSideToLeft();
	turnCubeSideToLeft();
	sequence.push_back(32);
	sequence.push_back(32);

	while(!step4)
	{
		if(cube[1] == 1 && cube[3] == 1 && cube[5] == 1 && cube[7] == 1) //Yellow cross
			step4 = true;
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
				int array[] = {4,3,0,12,9,13};
				sequence.insert(sequence.end(), array, array+6);
			}
			else //Yellow line or L is facing wrong direction
			{
				turnCubeToLeft();
				sequence.push_back(29);
			}
		}
	}

	//Step 5: Fix yellow edges
	counter = 1;
	while(!step5)
	{
		if(cube[10] == cube[13] && cube[19] == cube[22] && cube[28] == cube[31] && cube[37] == cube[40])
			step5 = true;
		else
		{
			if(counter == 3)
			{
				turnUp2();
				sequence.push_back(18);
				counter = 0;
			}
			if((cube[19] != cube[22]) && (cube[10] != cube[13]))
			{
				turnRight();
				turnUp();
				turnCRight();
				turnUp();
				turnRight();
				turnUp2();
				turnCRight();
				turnUp();
				int array[] = {3,0,12,0,3,18,12,0};
				sequence.insert(sequence.end(), array, array+8);
				counter++;
			}
			else if((cube[10] == cube[13]) && (cube[19] != cube[22]) && (cube[28] == cube[31]) && (cube[37] != cube[40]))
			{
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
				int array[] = {3,0,12,0,3,18,12,0,18,3,0,12,0,3,18,12};
				sequence.insert(sequence.end(), array, array+16);
			}
			else
			{
				turnCubeToRight();
				sequence.push_back(30);
			}
		}
	}
	
	i = 1;
	//To reset the orange side as the front
	while(cube[22] != currentSide[1])
	{
		turnCubeToLeft();
		sequence.push_back(29);
	}

	finish =false;
	//Step 6: Position yellow corner
	while(!step6)
	{
		bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
		int pos, pos1 = -1, pos2 = -1, pos3 = -1, pos4 = -1;
		for(int j=0; j<4; j++)
		{
			if(j+1 == 4)
				temp = 0;
			else
				temp = j+1;
			if(((cube[8] == 1 && cube[20] == currentSide[j] && cube[27] == currentSide[temp]) || (cube[8] == currentSide[temp] && cube[20] == 1 && cube[27] == currentSide[j]) || (cube[8] == currentSide[j] && cube[20] == currentSide[temp] && cube[27] == 1)) && cube[22] == currentSide[j])
			{
				corner1 = true;
				pos1 = j;
				break;
			}
			else
				corner1 = false;
		}
		for(int j=0; j<4; j++)
		{
			if(j+1 == 4)
				temp = 0;
			else
				temp = j+1;
			if(((cube[2] == 1 && cube[29] == currentSide[j] && cube[36] == currentSide[temp]) || (cube[2] == currentSide[temp] && cube[29] == 1 && cube[36] == currentSide[j]) || (cube[2] == currentSide[j] && cube[29] == currentSide[temp] && cube[36] == 1)) && cube[31] == currentSide[j])
			{
				corner2 = true;
				pos2 = j;
				break;
			}
			else
				corner2 = false;
		}
		for(int j=0; j<4; j++)
		{
			if(j+1 == 4)
				temp = 0;
			else
				temp = j+1;
			if(((cube[0] == 1 && cube[38] == currentSide[j] && cube[9] == currentSide[temp]) || (cube[0] == currentSide[temp] && cube[38] == 1 && cube[9] == currentSide[j]) || (cube[0] == currentSide[j] && cube[38] == currentSide[temp] && cube[9] == 1)) && cube[40] == currentSide[j])
			{
				corner3 = true;
				pos3 = j;
				break;
			}
			else
				corner3 = false;
		}
		for(int j=0; j<4; j++)
		{
			if(j+1 == 4)
				temp = 0;
			else
				temp = j+1;
			if(((cube[6] == 1 && cube[11] == currentSide[j] && cube[18] == currentSide[temp]) || (cube[6] == currentSide[temp] && cube[11] == 1 && cube[18] == currentSide[j]) || (cube[6] == currentSide[j] && cube[11] == currentSide[temp] && cube[18] == 1)) && cube[13] == currentSide[j])
			{
				corner4 = true;
				pos4 = j;
				break;
			}
			else
				corner4 = false;
		}
		if(corner1 && corner2 && corner3 && corner4) //All corner is position correctly
			step6 = true;
		else if(!corner1 && !corner2 && !corner3 && !corner4) //All corner is position incorrectly
		{
			turnUp();
			turnRight();
			turnCUp();
			turnCLeft();
			turnUp();
			turnCRight();
			turnCUp();
			turnLeft();
			int array[] = {0,3,9,11,0,12,9,2};
			sequence.insert(sequence.end(), array, array+8);
		}
		else if(corner1 || corner2 || corner3 || corner4)
		{
			while(!finish)
			{
				if(corner1)
					pos = pos1;
				else if(corner2)
					pos = pos2;
				else if(corner3)
					pos = pos3;
				else if(corner4)
					pos = pos4;

				if(i-1 == -1)
					temp = 3;
				else
					temp = i-1;
				if(i-pos == 0)
				{
					turnUp();
					turnRight();
					turnCUp();
					turnCLeft();
					turnUp();
					turnCRight();
					turnCUp();
					turnLeft();
					int array[] = {0,3,9,11,0,12,9,2};
					sequence.insert(sequence.end(), array, array+8);

					for(int j=0; j<4; j++)
					{
						if(j+1 == 4)
							temp = 0;
						else
							temp = j+1;
						if(((cube[8] == 1 && cube[20] == currentSide[j] && cube[27] == currentSide[temp]) || (cube[8] == currentSide[temp] && cube[20] == 1 && cube[27] == currentSide[j]) || (cube[8] == currentSide[j] && cube[20] == currentSide[temp] && cube[27] == 1)) && cube[22] == currentSide[j])
						{
							corner1 = true;
							pos1 = j;
							break;
						}
						else
							corner1 = false;
					}
					for(int j=0; j<4; j++)
					{
						if(j+1 == 4)
							temp = 0;
						else
							temp = j+1;
						if(((cube[2] == 1 && cube[29] == currentSide[j] && cube[36] == currentSide[temp]) || (cube[2] == currentSide[temp] && cube[29] == 1 && cube[36] == currentSide[j]) || (cube[2] == currentSide[j] && cube[29] == currentSide[temp] && cube[36] == 1)) && cube[31] == currentSide[j])
						{
							corner2 = true;
							pos2 = j;
							break;
						}
						else
							corner2 = false;
					}
					for(int j=0; j<4; j++)
					{
						if(j+1 == 4)
							temp = 0;
						else
							temp = j+1;
						if(((cube[0] == 1 && cube[38] == currentSide[j] && cube[9] == currentSide[temp]) || (cube[0] == currentSide[temp] && cube[38] == 1 && cube[9] == currentSide[j]) || (cube[0] == currentSide[j] && cube[38] == currentSide[temp] && cube[9] == 1)) && cube[40] == currentSide[j])
						{
							corner3 = true;
							pos3 = j;
							break;
						}
						else
							corner3 = false;
					}
					for(int j=0; j<4; j++)
					{
						if(j+1 == 4)
							temp = 0;
						else
							temp = j+1;
						if(((cube[6] == 1 && cube[11] == currentSide[j] && cube[18] == currentSide[temp]) || (cube[6] == currentSide[temp] && cube[11] == 1 && cube[18] == currentSide[j]) || (cube[6] == currentSide[j] && cube[11] == currentSide[temp] && cube[18] == 1)) && cube[13] == currentSide[j])
						{
							corner4 = true;
							pos4 = j;
							break;
						}
						else
							corner4 = false;
					}
					if(corner1 && corner2 && corner3 && corner4) //All corner is position correctly
						finish = true;
				}
				else
				{
					turnCubeToLeft();
					sequence.push_back(29);
					i++;
					if(i == 4)
						i = 0;
				}
			}
		}
	}
	finish = false;
	
	//Step 7: Orient yellow corner
	while(!step7)
	{
		if(cube[0] == 1 && cube[2] == 1 && cube[6] == 1 && cube[8] == 1)
		{
			bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
			for(int j=0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if(cube[20] == currentSide[j] && cube[27] == currentSide[temp] && cube[22] == currentSide[j])
				{
					corner1 = true;
					break;
				}
				else
					corner1 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if(cube[29] == currentSide[j] && cube[36] == currentSide[temp] && cube[31] == currentSide[j])
				{
					corner2 = true;
					break;
				}
				else
					corner2 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if(cube[38] == currentSide[j] && cube[9] == currentSide[temp] && cube[40] == currentSide[j])
				{
					corner3 = true;
					break;
				}
				else
					corner3 = false;
			}
			for(int j=0; j<4; j++)
			{
				if(j+1 == 4)
					temp = 0;
				else
					temp = j+1;
				if(cube[11] == currentSide[j] && cube[18] == currentSide[temp] && cube[13] == currentSide[j])
				{
					corner4 = true;
					break;
				}
				else
					corner4 = false;
			}
			if(corner1 && corner2 && corner3 && corner4)
				step7 = true;
		}
		if(!step7)
		{
			if(cube[8] != 1)
			{
				turnCRight();
				turnCDown();
				turnRight();
				turnDown();
				int array[] = {12,10,3,1};
				sequence.insert(sequence.end(), array, array+4);
			}
			else
			{
				turnCUp();
				sequence.push_back(9);
			}
		}
	}
	cout << "Completed\n";

	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Time elapsed: " << duration.count() << "s\n";
}