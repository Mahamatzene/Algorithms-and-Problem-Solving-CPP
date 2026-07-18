#include <iostream>
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

bool IsLastDayInMonth(stDate date) {
    return (date.day == NumberOfDaysInMonth(date.year, date.month));
}

bool IsLastMonthInYear(short month) {
    return (month == 12);
}

stDate IncreaseDateByOneDay(stDate date) {

    if (IsLastDayInMonth(date)) {
        if (IsLastMonthInYear(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else {
        date.day++;
    }

    return date;
}

bool IsDate1BeforeDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool IsDate1EqualToDate2(stDate date1, stDate date2) {
    return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

short GetDaysDifference(stDate date1, stDate date2, bool includingEndDay = false) {
    short counter = 0;
    
    while (IsDate1BeforeDate2(date1, date2)) {
        counter++;
        date1 = IncreaseDateByOneDay(date1);
    }

    return includingEndDay ? ++counter : counter;
}

int main()
{
    stDate date1 = ReadFullDate();
    cout << endl;
    stDate date2 = ReadFullDate();

    cout << "\nDifference is : " << GetDaysDifference(date1, date2) << " Day(s)\n";
    cout << "\nDifference (Including End Day) is: " << GetDaysDifference(date1, date2, true) << " Day(s)\n";
    

    return 0;

}