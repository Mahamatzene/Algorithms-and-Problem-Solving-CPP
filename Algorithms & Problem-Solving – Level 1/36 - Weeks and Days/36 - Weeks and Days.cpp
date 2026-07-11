
#include <iostream>
using namespace std;

enum enOperationType {add = '+', subtract = '-', multiply = '*', divide = '/' };

float ReadNumber(string message)
{
	float number = 0;

	cout << message << endl;
	cin >> number;

	return number;
}

enOperationType ReadOpType()
{
	char OT = '+';

	cout << "please enter operation type (+, -, *, /) ?" << endl;
	cin >> OT;

	return (enOperationType)OT;
}

float Calculate(float number1, float number2, enOperationType opType)
{
	switch (opType)
	{
	case enOperationType::add:
		return number1 + number2;
	case enOperationType::subtract:
		return number1 - number2;
	case enOperationType::multiply:
		return number1 * number2;
	case enOperationType::divide:
		return number1 / number2;
	default:
		return number1 + number2;
	}
}

int main()
{
	float number1 = ReadNumber("please enter the first number");
	float number2 = ReadNumber("please enter the second number");

	enOperationType opType = ReadOpType();

	cout << endl << "result = " << Calculate(number1, number2, opType);

	return 0;
}