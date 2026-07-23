
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate date1, stDate date2) {
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

enDateCompare CompareDates(stDate date1, stDate date2) {

    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::After;

    if (IsDate1BeforeDate2(date1, date2))
        return enDateCompare::Before;

    /*if (IsDate1EqualDate2(date1, date2))
        return enDateCompare::Equal;*/

        //This is faster
    return enDateCompare::Equal;
}

bool IsDateWithinPeriod(stPeriod period, stDate dateToCheck) {

    return !(CompareDates(dateToCheck, period.startDat) == enDateCompare::Before || CompareDates(dateToCheck, period.endDate) == enDateCompare::After);
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stPeriod period1 = ReadPeriod();

    cout << "\nPLease enter date to check :" << endl;
    stDate dateToCheck = ReadFullDate();

    if (IsDateWithinPeriod(period1, dateToCheck))
        cout << "\nYes, date is within period..." << endl;
    else
        cout << "\nNo, date is NOT within period..." << endl;

    return 0;

}