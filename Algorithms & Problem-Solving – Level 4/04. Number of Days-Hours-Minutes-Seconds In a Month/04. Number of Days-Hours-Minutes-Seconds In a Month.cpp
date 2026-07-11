

#include <iostream>
using namespace std;

int ReadYear(string message) {
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

    if (month == 2) {
        return IsLeapYear(year) ? 29 : 28;
    }

    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

    for (short i = 0; i < 7; i++) {
        if (arr31Days[i] == month)
            return 31;
    }
    
    return 30;
}

int NumberOfHoursInMonth(short year, short month) {
    return NumberOfDaysInMonth(year, month) * 24;
}

int NumberOfMinutesInMonth(short year, short month) {
    return NumberOfHoursInMonth(year, month) * 60;
}

int NumberOfSecondsInMonth(short year, short month) {
    return NumberOfMinutesInMonth(year, month) * 60;
}

int main()
{
    short Year = ReadYear("Please enter a year yo cheack if it's Leap Year or NOT : ");
    short month = ReadYear("Please enter a month to check : ");
    cout << "\nNumber of Days in month [" << month << "] is    : " << NumberOfDaysInMonth(Year, month) << endl;
    cout << "Number of Hours in month [" << month << "] is   : " << NumberOfHoursInMonth(Year, month) << endl;
    cout << "Number of Minutes in month [" << month << "] is : " << NumberOfMinutesInMonth(Year, month) << endl;
    cout << "Number of Seconds in month [" << month << "] is : " << NumberOfSecondsInMonth(Year, month) << endl;

    return 0;
}