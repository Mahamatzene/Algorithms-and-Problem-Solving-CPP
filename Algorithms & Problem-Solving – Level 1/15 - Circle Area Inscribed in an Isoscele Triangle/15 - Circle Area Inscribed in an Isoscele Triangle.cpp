
#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(float &a, float &b)
{
	cout << "please enter the num of a ?" << endl;
	cin >> a;
	cout << "please enter the num of b ?" << endl;
	cin >> b;

}

float calculateRectangleArea(float a, float b)
{
	return a * b;
}

void PrintRseult(float area)
{
	cout << "\n rectangle area = " << area << endl;
}

int main()
{
	float a, b;
	ReadNumbers(a, b);
	PrintRseult(calculateRectangleArea(a, b));

	return 0;
}
