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

stDate DecreaseDateByOneDay(stDate date) {

    if (date.day == 1)
    {
        if (date.month == 1)
        {
            date.month = 12;
            date.day = 31;
            date.year--;
        }
        else
        {
            date.month--;
            date.day = NumberOfDaysInMonth(date.month, date.year);
        }
    }
    else
    {
        date.day--;
    }

    return date;
}

stDate DecreaseDateByXDays(stDate date, short howManyDays) {

    for (short i = 1; i <= howManyDays; i++) {
        date = DecreaseDateByOneDay(date);
    }

    return date;
}

stDate DecreaseDateByOneWeek(stDate date) {
    for (short i = 1; i <= 7; i++) {

        date = DecreaseDateByOneDay(date);
    }

    return date;
}

stDate DecreaseDateByXWeeks(stDate date, short howManyWeeks) {
    for (short i = 1; i <= howManyWeeks; i++) {

        date = DecreaseDateByOneWeek(date);
    }

    return date;
}

stDate DecreaseDateByOneMonth(stDate date) {
    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
        date.month--;

    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should
    //not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.year, date.month);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }

    return date;
}

stDate DecreaseDateByXMonth(stDate date, short howManyMonths) {
    for (short i = 1; i <= howManyMonths; i++) {
        date = DecreaseDateByOneMonth(date);
    }

    return date;
}

stDate DecreaseDateByOneYear(stDate date) {
    date.year--;
    return date;
}

stDate DecreaseDateByXYears(stDate date, short howManyYears) {
    for (short i = 1; i <= howManyYears; i++) {
        date = DecreaseDateByOneYear(date);
    }

    return date;
}

stDate DecreaseDateByXYearsFaster(stDate date, short howManyYears) {
    date.year -= howManyYears;
    return date;
    return date;
}

stDate DecreaseDateByOneDecade(stDate date) {
    //Period of 10 years
    date.year -= 10;
    return date;
}

stDate DecreaseDateByXDecade(stDate date, short howManyDecades) {
    for (short i = 1; i <= howManyDecades; i++) {
        date = DecreaseDateByOneDecade(date);
    }

    return date;
}

stDate DecreaseDateByXDecadeFaster(stDate date, short howManyDecades) {
    date.year -= howManyDecades * 10;
    return date;
}

stDate DecreaseDateByOneCentury(stDate date) {
    //Period of 100 years
    date.year -= 100;
    return date;
}

stDate DecreaseDateByOneMillennium(stDate date) {
    //Period of 1000 years
    date.year -= 1000;
    return date;
}

int main()
{
    stDate date = ReadFullDate();

    cout << "\nDate After : \n";

    date = DecreaseDateByOneDay(date);
    cout << "\n01 - Subtracting one day is            : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXDays(date, 10);
    cout << "\n02 - Subtracting 10 days is            : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneWeek(date);
    cout << "\n03 - Subtracting one week is           : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXWeeks(date, 10);
    cout << "\n04 - Subtracting 10 week is            : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneMonth(date);
    cout << "\n05 - Subtracting one month is          : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXMonth(date, 5);
    cout << "\n06 - Subtracting 5 month is            : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneYear(date);
    cout << "\n07 - Subtracting one year is           : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXYears(date, 10);
    cout << "\n08 - Subtracting 10 year is            : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXYearsFaster(date, 10);
    cout << "\n09 - Subtracting 10 year is (Faster)   : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneDecade(date);
    cout << "\n10 - Subtracting one decade is         : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXDecade(date, 10);
    cout << "\n11 - Subtracting 10 decade is          : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByXDecadeFaster(date, 10);
    cout << "\n12 - Subtracting 10 decade is (Faster) : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneCentury(date);
    cout << "\n13 - Subtracting one century           : " << date.day << "/" << date.month << "/" << date.year;

    date = DecreaseDateByOneMillennium(date);
    cout << "\n14 - Subtracting one millennium        : " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;

}