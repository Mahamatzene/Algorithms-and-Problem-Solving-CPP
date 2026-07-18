

#include <iostream>
#include <iomanip>
using namespace std;

int ReadYear() {
    int Year = 0;

    cout << "Please enter a year : ";
    cin >> Year;

    return Year;
}

int ReadMonth() {
    int month = 0;

    cout << "Please enter a month : ";
    cin >> month;

    return month;
}

int ReadDay() {
    int day = 0;

    cout << "Please enter a day : ";
    cin >> day;

    return day;
}

bool IsLeapYear(int Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int year, int month) {
    if (month < 1 || month > 12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}

int CalculateHowManyDayFromTheBeginOfYear(int day, int month, int year) {
    int daysInYear = 0;
    for (int i = 1; i <= month - 1; i++) {

        daysInYear += NumberOfDaysInMonth(year, i);

    }

    return daysInYear + day;
}

int main()
{
    int year = ReadYear();
    int month = ReadMonth();
    int day = ReadDay();

    cout << "\nNumber of days from the begining of the year is : " << CalculateHowManyDayFromTheBeginOfYear(day, month, year) << endl;
    return 0;
}