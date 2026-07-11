

#include <iostream>
#include <cmath>
using namespace std;

float ReadRadious()
{
	float r;

	cout << "please enter radious r?" << endl;
	cin >> r;

	return r;
}

float CircleArea(float r)
{
	const float PI = 3.141592653589793238;

	float area = pow(r, 2) * PI;
	return area;
}

void PrintResult(float area)
{
	cout << "\n circle area = " << area << endl;
}

int main()
{
	PrintResult(CircleArea(ReadRadious()));

	return 0;
  
}


