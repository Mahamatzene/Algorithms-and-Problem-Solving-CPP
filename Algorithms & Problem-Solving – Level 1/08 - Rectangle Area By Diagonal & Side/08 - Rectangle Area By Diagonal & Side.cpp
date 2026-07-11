

#include <iostream>
#include <string>
using namespace std;

enum enPassOrFail { pass = 1, fail = 2 };

int readMark()
{
	int mark;

	cout << "please enter your mark" << endl;
	cin >> mark;
	return mark;
}

enPassOrFail checkMark(int mark)
{
	if (mark >= 50)
		return enPassOrFail::pass;
	else
		return enPassOrFail::fail;
}
void printResult(int mark)
{
	if (checkMark(mark) == enPassOrFail::pass)
		cout << "\n you passed" << endl;
	else
		cout << "\n you failed" << endl;
}

int main()
{
	printResult(readMark());

	return 0;
}

