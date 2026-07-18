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
    cout << endl;
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

stDate IncreaseDateByXDays(stDate date, short howManyDays) {

    for (short i = 1; i <= howManyDays; i++) {
        date = IncreaseDateByOneDay(date);
    }

    return date;
}

stDate IncreaseDateByOneWeek(stDate date) {
    for (short i = 1; i <= 7; i++) {

        date = IncreaseDateByOneDay(date);
    }

    return date;
}

stDate IncreaseDateByXWeeks(stDate date, short howManyWeeks) {
    for (short i = 1; i <= howManyWeeks; i++) {

        date = IncreaseDateByOneWeek(date);
    }

    return date;
}

stDate IncreaseDateByOneMonth(stDate date) {
    if (IsLastMonthInYear(date.month)) {
        date.month = 1;
        date.year++;
    }
    else {
        date.month++;
    }

    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should
    //not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }

    return date;
}

stDate IncreaseDateByXMonth(stDate date, short howManyMonths) {
    for (short i = 1; i <= howManyMonths; i++) {
        date = IncreaseDateByOneMonth(date);
    }

    return date;
}

stDate IncreaseDateByOneYear(stDate date) {
    date.year++;
    return date;
}

stDate IncreaseDateByXYears(stDate date, short howManyYears) {
    for (short i = 1; i <= howManyYears; i++) {
        date = IncreaseDateByOneYear(date);
    }

    return date;
}

stDate IncreaseDateByXYearsFaster(stDate date, short howManyYears) {
    date.year += howManyYears;
    return date;
    return date;
}

stDate IncreaseDateByOneDecade(stDate date) {
    //Period of 10 years
    date.year += 10;
    return date;
}

stDate IncreaseDateByXDecade(stDate date, short howManyDecades) {
    for (short i = 1; i <= howManyDecades; i++) {
        date = IncreaseDateByOneDecade(date);
    }

    return date;
}

stDate IncreaseDateByXDecadeFaster(stDate date, short howManyDecades) {
    date.year += howManyDecades * 10;
    return date;
}

stDate IncreaseDateByOneCentury(stDate date) {
    //Period of 100 years
    date.year += 100;
    return date;
}

stDate IncreaseDateByOneMillennium(stDate date) {
    //Period of 1000 years
    date.year += 1000;
    return date;
}

int main()
{
    stDate date = ReadFullDate();

    cout << "\nDate After : \n";

    date = IncreaseDateByOneDay(date);
    cout << "\n01 - Adding one day is            : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXDays(date, 10);
    cout << "\n02 - Adding 10 days is            : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneWeek(date);
    cout << "\n03 - Adding one week is           : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXWeeks(date, 10);
    cout << "\n04 - Adding 10 week is            : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneMonth(date);
    cout << "\n05 - Adding one month is          : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXMonth(date, 5);
    cout << "\n06 - Adding 5 month is            : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneYear(date);
    cout << "\n07 - Adding one year is           : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXYears(date, 10);
    cout << "\n08 - Adding 10 year is            : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXYearsFaster(date, 10);
    cout << "\n09 - Adding 10 year is (Faster)   : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneDecade(date);
    cout << "\n10 - Adding one decade is         : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXDecade(date, 10);
    cout << "\n11 - Adding 10 decade is          : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByXDecadeFaster(date, 10);
    cout << "\n12 - Adding 10 decade is (Faster) : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneCentury(date);
    cout << "\n13 - Adding one century           : " << date.day << "/" << date.month << "/" << date.year;

    date = IncreaseDateByOneMillennium(date);
    cout << "\n14 - Adding one millennium        : " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;

}