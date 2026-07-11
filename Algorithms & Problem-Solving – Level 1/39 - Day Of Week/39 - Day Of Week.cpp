

#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
	float number = 0;

	cout << message << endl;
	cin >> number;

	return number;
}

float CalculateRemainder(float totalBill, float totalCashPaid)
{
	return totalCashPaid - totalBill;
}

int main()
{
	float totalBill = ReadPositiveNumber("please enter the total bill");
	float totalCashPaid = ReadPositiveNumber("please enter the total cash paid ?");

	cout << endl;
	cout << "total bill = " << totalBill << endl;
	cout << "total cash paid = " << totalCashPaid << endl;
	cout << "***************************\n";
	cout << "remainder = " << CalculateRemainder(totalCashPaid, totalBill);

	return 0;
}
