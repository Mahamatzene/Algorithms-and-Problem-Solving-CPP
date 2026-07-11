

#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
	int number = 0;

	do
	{
		cout << message << endl;
		cin >> number;

	} while (number <= 0);

	return number;
}

float MonthlyInstallment(float loanAmount, float howManyMonth)
{
	return (float)loanAmount / howManyMonth;
}

int main()
{
	float loanAmount = ReadPositiveNumber("please enter how much loan amount do you need?");
	float howManyMonths = ReadPositiveNumber("please enter how many months you need to settle the loan?");

	cout << "\n monthly installment = " << MonthlyInstallment(loanAmount, howManyMonths) << endl;

	return 0;
}
