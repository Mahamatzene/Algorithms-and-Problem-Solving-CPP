
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

float HoursToDays(float NumberOfHours)
{
	return (float)NumberOfHours / 24;
}

float HoursToWeek(float NumberOfHours)
{
	return (float)NumberOfHours / 24 / 7;
}

float DaysToWeek(float NumberOfDays)
{
	return (float)NumberOfDays / 7;
}

int main()
{
	float NumberOfHours = ReadPositiveNumber("please enter the number of hours ?");
	float NumberOfDays = HoursToDays(NumberOfHours);
	float NumberOfWeeks = DaysToWeek(NumberOfDays);

	cout << endl;
	cout << "total hours = " << NumberOfHours << endl;
	cout << "total days = " << NumberOfDays << endl;
	cout << "total weeks = " << HoursToWeek(NumberOfHours) << endl;

	return 0;
}

