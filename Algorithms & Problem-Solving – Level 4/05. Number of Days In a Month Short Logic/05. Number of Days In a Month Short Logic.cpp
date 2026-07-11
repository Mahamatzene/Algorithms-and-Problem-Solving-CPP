

#include <iostream>
using namespace std;

int ReadNumber(string message) {
    int year = 0;

    cout << message;
    cin >> year;

    return year;
}

bool IsLeapYear(int Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(short year, short month) {
    if (month < 1 || month > 12)
        return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

int main()
{
    short Year = ReadNumber("Please enter a year yo cheack if it's Leap Year or NOT : ");
    short month = ReadNumber("Please enter a month to check : ");

    cout << "\nNumber of Days in month [" << month << "] is    : " << NumberOfDaysInMonth(Year, month) << endl;


    return 0;
}