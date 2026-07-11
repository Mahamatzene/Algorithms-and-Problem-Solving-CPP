
#include <iostream>
using namespace std;

void ReadNumbers(float& a, float& h)
{
	cout << "please enter the number of a" << endl;
	cin >> a;
	cout << "please enter the number of h" << endl;
	cin >> h;
}

float TriangleArea(float a, float h)
{
	float area = (a / 2) * h;

	return area;
}

void PrintResult(float area)
{
	cout << "\n triangle area = " << area << endl;
}

int main()
{
	float a, h;

	ReadNumbers(a, h);
	PrintResult(TriangleArea(a, h));

	return 0;
}