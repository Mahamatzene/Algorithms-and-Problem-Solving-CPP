

#include <iostream>
#include <cmath>
using namespace std;

float ReadSquareSide()
{
	float A;

	cout << "please enter the num of A?" << endl;
	cin >> A;

	return A;
}

float CircleAreaInscribedInSquare(float A)
{

	const double PI = 3.141592653589793238;

	float area = (PI * pow(A, 2)) / 4;

	return area;
}

void PrintResult(float area)
{
	cout << "\ncircle area = " << area << endl;
}

int main()
{
	PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

	return 0;
}
