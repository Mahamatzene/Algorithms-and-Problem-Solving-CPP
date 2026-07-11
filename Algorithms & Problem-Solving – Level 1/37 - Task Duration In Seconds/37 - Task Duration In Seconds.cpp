

#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string message)
{
	float number = 0;

	cout << message << endl;
	cin >> number;

	return number;
}

float SumNumbers()
{
	int sum = 0, number = 0, counter = 1;

	do
	{
		number = ReadNumber("please enter nummber " + to_string(counter));

		if (number == -99)
		{
			break;
		}

		sum += number;
		counter++;
	} while (number != -99);

	return sum;
}

int main()
{
	cout << endl << "result = " << SumNumbers() << endl;

	return 0;
}

