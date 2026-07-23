
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
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
    date.Year = ReadYear();
    date.Month = ReadMonth();
    date.Day = ReadDay();

    return date;
}

stPeriod ReadPeriod() {
    stPeriod period;

    cout << "Please enter Start date : " << endl;
    period.startDat = ReadFullDate();
    cout << "Please enter End date : " << endl;
    period.endDate = ReadFullDate();

    return period;
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

    return (CompareDates(period2.endDate, period1.startDat) ==  enDateCompare::Before || 
        CompareDates(period2.startDat, period1.endDate) == enDateCompare::Before) ? false : true;
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stPeriod period1 = ReadPeriod();
    
    cout << "\nPlease enter Period 2" << endl;
    stPeriod period2 = ReadPeriod();


    if (IsOverlapPeriods(period1, period2))
        cout << "\nYes, Period Pverlap\n";
    else
        cout << "\nNo, Period it's NOT Overlap\n";

    return 0;

}