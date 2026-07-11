#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "please enter a number?" << endl;
	cin >> Number;

	return Number;
}

void powerOf2_3_4(int Number)
{
	int a, b, c;

	a = Number * Number;
	b = Number * Number * Number;
	c = Number * Number * Number * Number;

	cout << a << " " << b << " " << c << endl;
}

int main()
{
	powerOf2_3_4(ReadNumber());

	return 0;

}