

#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
	float number = 0;

	do
	{
		cout << message << endl;
		cin >> number;

	} while (number <= 0);

	return number;
}

float TotalBillAfterServiceFeeAndTax(float totalBill)
{
	totalBill = totalBill * 1.1;
	totalBill = totalBill * 1.16;

	return totalBill;
}

int main()
{
	float totalBill = ReadPositiveNumber("please enter the total bill");

	cout << endl;
	cout << "total bill = " << totalBill << endl;
	cout << "your total bill after servise fee and tax = " << TotalBillAfterServiceFeeAndTax(totalBill) << endl;

	return 0;
}