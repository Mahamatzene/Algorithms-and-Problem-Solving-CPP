

#include <iostream>
using namespace std;


int ReadTotalSales()
{
	int totalSales;

	cout << "please enter the total sales" << endl;
	cin >> totalSales;

	return totalSales;
}

float GetComissionPercentage(float totalSales)
{
	if (totalSales >= 1000000)
		return 0.01;
	else if (totalSales >= 500000)
		return 0.02;
	else if (totalSales >= 100000)
		return 0.03;
	else if (totalSales >= 50000)
		return 0.05;
	else
		return 0.00;
}

float CalculateTotalComission(float totalSales)
{
	return GetComissionPercentage(totalSales) * totalSales;
}

int main()
{
	int totalSales = ReadTotalSales();

	cout << endl << "comission percentage = " << GetComissionPercentage(totalSales) << endl;
	cout << endl << "total comission = " << CalculateTotalComission(totalSales) << endl;

	return 0;
}

