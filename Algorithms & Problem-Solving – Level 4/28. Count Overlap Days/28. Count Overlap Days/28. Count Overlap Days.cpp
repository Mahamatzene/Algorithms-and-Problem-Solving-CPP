
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

struct stPeriod {
    stDate startDate;
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
    date.Year = ReadYear();
    date.Month = ReadMonth();
    date.Day = ReadDay();

    return date;
}

stPeriod ReadPeriod() {
    stPeriod period;

    cout << "Please enter Start date : " << endl;
    period.startDate = ReadFullDate();
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
    return (date.Day == NumberOfDaysInMonth(date.Year, date.Month));
}

bool IsLastMonthInYear(short month) {
    return (month == 12);
}

stDate IncreaseDateByOneDay(stDate date) {

    if (IsLastDayInMonth(date)) {
        if (IsLastMonthInYear(date.Month)) {
            date.Day = 1;
            date.Month = 1;
            date.Year++;
        }
        else {
            date.Day = 1;
            date.Month++;
        }
    }
    else {
        date.Day++;
    }

    return date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
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

bool IsOverlapPeriods(stPeriod period1, stPeriod period2) {

    return (CompareDates(period2.endDate, period1.startDate) == enDateCompare::Before ||
        CompareDates(period2.startDate, period1.endDate) == enDateCompare::After) ? false : true;
}

bool IsDateWithinPeriod(stPeriod period, stDate dateToCheck) {

    return !(CompareDates(dateToCheck, period.startDate) == enDateCompare::Before || CompareDates(dateToCheck, period.endDate) == enDateCompare::After);
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
    return GetDaysDifference(period.startDate, period.endDate, includingEndDay);
}

short CountOverlapDays(stPeriod period1, stPeriod period2) {
    short period1Length = 0;
    short period2Length = 0;
    short countOverlapDays = 0;

    // First, check whether the periods overlap.
    // This avoids unnecessary iterations when there is no overlap. 
    if (!IsOverlapPeriods(period1, period2))
        return 0;

    period1Length = PeriodLengthInDays(period1, true);
    period2Length = PeriodLengthInDays(period2, true);

    // Determine which period is shorter.
    // Iterating through the shorter period reduces the number of iterations. 
    if (period1Length < period2Length) {
        while (IsDate1BeforeDate2(period1.startDate, period1.endDate)) {
            if (IsDateWithinPeriod(period2, period1.startDate))
                countOverlapDays++;

            period1.startDate = IncreaseDateByOneDay(period1.startDate);
        }
    }
    else {
        while (IsDate1BeforeDate2(period2.startDate, period2.endDate)) {
            if (IsDateWithinPeriod(period1, period2.startDate))
                countOverlapDays++;

            period2.startDate = IncreaseDateByOneDay(period2.startDate);
        }
    }

    while (IsDateWithinPeriod(period1, period2.startDate)) {

        if (CompareDates(period2.startDate, period1.endDate) == enDateCompare::Before) {
            countOverlapDays++;
            period2.startDate = IncreaseDateByOneDay(period2.startDate);
        }
        else if (CompareDates(period2.startDate, period1.endDate) == enDateCompare::Equal)
            break;

    }

    return countOverlapDays;
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stPeriod period1 = ReadPeriod();

    cout << "\nPlease enter Period 2" << endl;
    stPeriod period2 = ReadPeriod();


    cout << "\nOverlap days count is : " << CountOverlapDays(period1, period2) << endl;

    return 0;

}