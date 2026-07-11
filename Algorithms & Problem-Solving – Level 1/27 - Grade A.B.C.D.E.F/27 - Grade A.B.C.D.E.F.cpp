
#include <iostream>
using namespace std;

int ReadNumber()
{
	int n;

	cout << "please enter the number of n" << endl;
	cin >> n;

	return n;
}

void PrintRangeFromNto1Using_While(int n)
{
	int counter = n + 1;
	cout << "range using while statement" << endl;
	
	while (counter > 1)
	{
		counter--;
		cout << counter << endl;
		
	}
}

void PrintRangeFromNto1Using_DoWhile(int n)
{
	cout << "range using do while statement" << endl;
	int counter = n + 1;

	do
	{
		counter--;
		cout << counter << endl;
		
	} while (counter > 1);
}

void PrintRangeFromNto1Using_For(int n)
{
	cout << "range using for statement" << endl;

	for (int counter = n; counter >= 1; counter--)
	{
		cout << counter << endl;
	}
		
}

int main()
{
	int n = ReadNumber();

	
	PrintRangeFromNto1Using_While(n);
	PrintRangeFromNto1Using_DoWhile(n);
	PrintRangeFromNto1Using_For(n);

	

	return 0;
}


