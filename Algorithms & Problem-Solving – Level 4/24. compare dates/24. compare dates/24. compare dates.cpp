
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

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

int main()
{
    cout << "Please enter date 1" << endl;
    stDate date1 = ReadFullDate();
    
    cout << "\nPlease enter date 2" << endl;
    stDate date2 = ReadFullDate();

    cout << "\nCompare result : " << CompareDates(date1, date2) << endl;

    return 0;

}