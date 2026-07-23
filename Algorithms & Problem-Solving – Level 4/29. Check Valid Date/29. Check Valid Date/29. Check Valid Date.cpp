
#include <iostream>
using namespace std;

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
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
    cout << endl;
    date.Year = ReadYear();
    date.Month = ReadMonth();
    date.Day = ReadDay();

    return date;
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

bool IsValidDate(stDate date) {
    if (date.Day <= NumberOfDaysInMonth(date.Year, date.Month)) {
        if (date.Month >= 1 || date.Month <= 12) {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stDate date = ReadFullDate();

    if (IsValidDate(date))
        cout << "\nYes, date is a valide date." << endl;
    else
        cout << "\nNo, date is NOT a valide date." << endl;

    return 0;

}