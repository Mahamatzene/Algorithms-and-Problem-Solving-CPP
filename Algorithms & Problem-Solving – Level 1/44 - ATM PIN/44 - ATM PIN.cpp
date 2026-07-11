
#include <iostream>
#include <string>
using namespace std;

enum enDayOfWeek { sat = 1, sun = 2, mun = 3, tue = 4, wed = 5, thr = 6, fri = 7};

int ReadNumberInRange(string message, int from, int to)
{
	int number = 0;

	do
	{
		cout << message << endl;
		cin >> number;

	} while (number < from || number > to);

	return number;
}

enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange("please enter day number: sat = 1, sun = 2, mun = 3, tue = 4, wed = 5, thr = 6, fri = 7", 1, 7);
}

string GetDayOfWeek(enDayOfWeek day)
{
	switch (day)
	{
	case enDayOfWeek::sat:
		return "saturday";
	case enDayOfWeek::sun:
		return "sunday";
	case enDayOfWeek::mun:
		return "munday";
	case enDayOfWeek::tue:
		return "tuesday";
	case enDayOfWeek::wed:
		return "wendesday";
	case enDayOfWeek::thr:
		return "thursday";
	case enDayOfWeek::fri:
		return "friday";
	default:
		return "not a valid day";
	}
}

int main()
{
	cout << GetDayOfWeek(ReadDayOfWeek()) << endl;

	return 0;
}