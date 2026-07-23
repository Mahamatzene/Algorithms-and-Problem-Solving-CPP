
#include <iostream>
using namespace std;

struct stDate {
    short year = 0;
    short month = 0;
    short day = 0;
};

struct stPeriod {
    stDate startDat;
    stDate endDate;
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
    date.year = ReadYear();
    date.month = ReadMonth();
    date.day = ReadDay();

    return date;
}

stPeriod ReadPeriod() {
    stPeriod period;

    cout << "Please enter Start date : " << endl;
    period.startDat = ReadFullDate();
    cout << "\nPlease enter End date : " << endl;
    period.endDate = ReadFullDate();

    return period;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

short GetDaysDifference(stDate date1, stDate date2, bool includingEndDay = false) {
    short counter = 0;

    while (IsDate1BeforeDate2(date1, date2)) {
        counter++;
        date1 = IncreaseDateByOneDay(date1);
    }

    return includingEndDay ? ++counter : counter;
}

short PeriodLengthInDays(stPeriod period, bool includingEndDay = false) {
    return GetDaysDifference(period.startDat, period.endDate, includingEndDay);
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stPeriod period1 = ReadPeriod();

    cout << "\nPeriod length is : " << PeriodLengthInDays(period1) << "\n";
    cout << "\nPeriod length (Including End Day) is: " << PeriodLengthInDays(period1, true) << "\n";

    return 0;

}