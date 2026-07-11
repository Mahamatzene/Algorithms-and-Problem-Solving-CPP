

#include <iostream>
using namespace std;

int ReadYear() {
    int year = 0;

    cout << "Please enter a year yo cheack if it's Leap Year or NOT : ";
    cin >> year;

    return year;
}

bool IsLeapYear(int Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInYear(short year) {
    return IsLeapYear(year) ? 365 : 366;
}

int NumberOfHoursInYear(short year) {
    return NumberOfDaysInYear(year) * 24;
}

int NumberOfMinutesInYear(short year) {
    return NumberOfHoursInYear(year) * 60;
}

int NumberOfSecondsInYear(short year) {
    return NumberOfMinutesInYear(year) * 60;
}

int main()
{
    int Year = ReadYear();

    cout << "\nNumber of Days in year [" << Year << "] is    : " << NumberOfDaysInYear(Year) << endl;
    cout << "Number of Hours in year [" << Year << "] is   : " << NumberOfHoursInYear(Year) << endl;
    cout << "Number of Minutes in year [" << Year << "] is : " << NumberOfMinutesInYear(Year) << endl;
    cout << "Number of Seconds in year [" << Year << "] is : " << NumberOfMinutesInYear(Year) << endl;

    return 0;
}