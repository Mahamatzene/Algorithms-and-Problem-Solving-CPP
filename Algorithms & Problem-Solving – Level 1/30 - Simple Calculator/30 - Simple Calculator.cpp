

#include <iostream>
using namespace std;

int ReadPositiveNumber(string message)
{
	int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number < 0);

	return number;
}

int Factorial(int n)
{
	int f = 1;

	for (int counter = n; counter >= 1; counter--)
	{
		f = f * counter;
	}

	return f;
}

int main()
{
	cout << Factorial(ReadPositiveNumber("please enter a positive number")) << endl;

	return 0;
}