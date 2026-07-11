

#include <iostream>
#include <cmath>
using namespace std;

struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinuets, NumberOfSecounds;
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

strTaskDuration ReadTaskDuration()
{
	strTaskDuration taskDuration;

	taskDuration.NumberOfDays = ReadPositiveNumber("please enter the number of days ?");
	taskDuration.NumberOfHours = ReadPositiveNumber("please enter the number of hours ?");
	taskDuration.NumberOfMinuets = ReadPositiveNumber("please enter the number of minute ?");
	taskDuration.NumberOfSecounds = ReadPositiveNumber("please enter the number of secound ?");

	return taskDuration;
}

int TaskDurationInSeconds(strTaskDuration taskDuration)
{
	int DurationInSeconds = 0;

	DurationInSeconds = taskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSeconds += taskDuration.NumberOfHours * 60 * 60;
	DurationInSeconds += taskDuration.NumberOfMinuets * 60;
	DurationInSeconds += taskDuration.NumberOfSecounds;

	return DurationInSeconds;
}

int main()
{
	cout << "\n task duration in second: " << TaskDurationInSeconds(ReadTaskDuration());

	return 0;
}