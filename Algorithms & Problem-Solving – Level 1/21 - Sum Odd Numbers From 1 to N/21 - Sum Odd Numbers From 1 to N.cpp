

#include <iostream>
#include <cmath>
using namespace std;

float ReadCircumference()
{
	float L;

	cout << "please enter the num of L?" << endl;
	cin >> L;

	return L;
}

float CircleAreaByCircumference(float L)
{

	const float PI = 3.141592653589793238;

	float area = pow(L, 2) / (4 * PI);

	return area;
}

void PrintResult(float area)
{
	cout << "\n circle area = " << area << endl;
}

int main()
{
	PrintResult(CircleAreaByCircumference(ReadCircumference()));
	
	return 0;
}
