
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

float TotalMonth(float loanAmount, float monthlyInstallment)
{
	return (float)loanAmount / monthlyInstallment;
}
int main()
{
	float loanAmount = ReadPositiveNumber("please enter a number of loan amount");
	float monthiyInstallment = ReadPositiveNumber("please enter a number of monthlt installment");

	cout << "\n total month to pay = " << TotalMonth(loanAmount, monthiyInstallment);

	return 0;

}
