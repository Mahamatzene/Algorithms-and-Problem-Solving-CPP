

#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{
	int number;

	cout << "please enter the number?" << endl;
	cin >> number;

	return number;
}

int ReadPower()
{
	int number;

	cout << "please enter the power?" << endl;
	cin >> number;

	return number;
}


int PowerOfM(int number, int M)
{
	if (M == 0)
	{
		// any number powered to zero gives 1
		return 1;
	}

	int p = 1;

	for (int i = 1; i <= M; i++)
	{
		p = p * number;
	}

	return p;
	
}

int main()
{
	cout << endl << "result = " << PowerOfM(ReadNumber(), ReadPower());

	return 0;

}


