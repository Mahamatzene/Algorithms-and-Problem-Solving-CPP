

#include <iostream>
#include <cmath>
using namespace std;

float ReadDiameter()
{
	float D;

	cout << "please enter radious D ?" << endl;
	cin >> D;

	return D;
}

float CircleAreaByDiameter(float D)
{
	const double PI = 3.141592653589793238;
	
	float area = (pow(D, 2) * PI) / 4;

	return area;
}

void PrintResult(float area)
{
	cout << "\n circle area = " << area << endl;
}

int main()
{
	PrintResult(CircleAreaByDiameter(ReadDiameter()));

	return 0;
}