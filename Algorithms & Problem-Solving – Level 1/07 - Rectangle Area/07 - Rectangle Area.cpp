

#include <iostream>
#include <string>
using namespace std;

int readNumber()
{
	int num;

	cout << "please enter a number" << endl;
	cin >> num;
	return num;
}

float calculateHalfNumber(int num)
{
	return (float) num / 2;
}

void printResult(int num)
{
	string result = "half of " + to_string(num) + " is " + to_string(calculateHalfNumber(num));
	cout << endl << result;
}

int main()
{
	printResult(readNumber());

	return 0;
}
