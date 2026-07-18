

#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
    short year = 0;
    short month = 0;
    short day = 0;
};

short ReadYear() {
    short Year = 0;

    cout << "Please enter a year : ";
    cin >> Year;

    return Year;
}

short ReadMonth() {
    short month = 0;

    cout << "Please enter a month : ";
    cin >> month;

    return month;
}

short ReadDay() {
    short day = 0;

    cout << "Please enter a day : ";
    cin >> day;

    return day;
}

bool IsLeapYear(short Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short year, short month) {
    if (month < 1 || month > 12)
        return 0;
    short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}

short CalculateHowManyDayFromTheBeginOfYear(short day, short month, short year) {
    short daysInYear = 0;
    for (short i = 1; i <= month - 1; i++) {

        daysInYear += NumberOfDaysInMonth(year, i);

    }

    return daysInYear + day;
}

stDate GetDateFromDayOrderInYear(short totalDays, short year) {
    stDate date;
    short reminingDays = totalDays;
    short monthDays = 0;
    date.year = year;
    date.month = 1;


    while (true) {
        monthDays = NumberOfDaysInMonth(year, date.month);

        if (reminingDays > monthDays) {
            reminingDays -= monthDays;
            date.month++;
        }
        else {
            date.day = reminingDays;
            break;
        }
    }

    return date;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();
    stDate date;
    short totalDays = CalculateHowManyDayFromTheBeginOfYear(day, month, year);
    date = GetDateFromDayOrderInYear(totalDays, year);

    cout << "\nNumber of days from the begining of the year is : " << totalDays << endl;

    cout << "Date for [" << totalDays << "] is " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}