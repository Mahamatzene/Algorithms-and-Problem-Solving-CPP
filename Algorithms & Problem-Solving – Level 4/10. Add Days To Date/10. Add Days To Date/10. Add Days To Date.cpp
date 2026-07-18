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

stDate ReadFullDate() {
    stDate date;

    date.year = ReadYear();
    date.month = ReadMonth();
    date.day = ReadDay();

    return date;
}

short ReadDaysToAdd() {
    short day = 0;

    cout << "Please enter how many days do you want to add : ";
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

stDate GetDateFromDayOrderInYear(short daysToAdd, stDate date) {
    short remainingDays = daysToAdd + CalculateHowManyDayFromTheBeginOfYear(date.day, date.month, date.year);
    short monthDays = 0;
    date.month = 1;

    while (true) {
        monthDays = NumberOfDaysInMonth(date.year, date.month);

        if (remainingDays > monthDays) {
            remainingDays -= monthDays;
            date.month++;

            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
        else {
            date.day = remainingDays;
            break;
        }
    }

    return date;
}

int main()
{
    stDate date = ReadFullDate();
    short daysToAdd = ReadDaysToAdd();

    date = GetDateFromDayOrderInYear(daysToAdd, date);


    cout << "Date after adding [" << daysToAdd << "] days is : " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;

}