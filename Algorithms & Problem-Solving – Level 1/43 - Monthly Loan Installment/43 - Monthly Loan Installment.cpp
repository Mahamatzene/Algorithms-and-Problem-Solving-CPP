

#include <iostream>
#include <cmath>
using namespace std;

struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string message)
{
	int number = 0;

	do
	{
		cout << message << endl;
		cin >> number;

	} while (number <= 0);

	return number;
}

strTaskDuration SecondsToTaskDuration(int totalSeconds)
{
	strTaskDuration taskDuration;
	const int secondPerDay = 24 * 60 * 60;
	const int secondPerHours = 60 * 60;
	const int secondPerMinute = 60;

	int reminder = 0;

	taskDuration.NumberOfDays = floor(totalSeconds / secondPerDay);
	reminder = totalSeconds % secondPerDay;
	taskDuration.NumberOfHours = floor(reminder / secondPerHours);
	reminder = reminder % secondPerHours;
	taskDuration.NumberOfMinutes = floor(reminder / secondPerMinute);
	reminder = reminder % secondPerMinute;
	taskDuration.NumberOfSeconds = reminder;

	return taskDuration;
}

void PrintTaskDuration(strTaskDuration taskDuration)
{
	cout << "\n";
	cout << taskDuration.NumberOfDays << " : "
	 	 << taskDuration.NumberOfHours << " : " 
		 << taskDuration.NumberOfMinutes <<" : " 
		 << taskDuration.NumberOfSeconds;
}

int main()
{
	int totalSeconds = ReadPositiveNumber("please enter total seconds");
	PrintTaskDuration(SecondsToTaskDuration(totalSeconds));

	return 0;

}
