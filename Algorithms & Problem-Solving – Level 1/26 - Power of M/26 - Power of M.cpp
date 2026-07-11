

#include <iostream>
using namespace std;

int ReadNumber()
{
	int number;
	cout << "please enter the number" << endl;
	cin >> number;

	return number;
}

void PrintRangeFrom1To10Using_While(int number)
{
	int counter = 0;

	cout << "range printed using while statement" << endl;

	while (counter < number)
	{
		counter++;
		cout << counter << endl;
		
	}
}

void PrintRangeFrom1To10Using_DoWhile(int number)
{
	int counter = 0;

	cout << "range printed using do while statement" << endl;

	do
	{
		counter++;
		cout << counter << endl;
	} while (counter < number);
}

void PrintRangeFrom1To10Using_for(int number)
{
	cout << "range printed using for statemente" << endl;

	for (int counter = 1; counter <= number; counter++)
	{
		cout << counter << endl;
	}
}

int main()
{
	int number = ReadNumber();

	PrintRangeFrom1To10Using_While(number);
	PrintRangeFrom1To10Using_DoWhile(number);
	PrintRangeFrom1To10Using_for(number);

	return 0;
}


