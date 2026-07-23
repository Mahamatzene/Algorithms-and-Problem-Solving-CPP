
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

bool IsLeapYear(int Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
        Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
            Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int NumberOfDaysInMonth(short year, short month) {
    if (month < 1 || month > 12)
        return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(stDate date)
{
    short a, y, m;
    a = (14 - date.Month) / 12;
    y = date.Year - a;
    m = date.Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
    "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate date) {
    return DayOfWeekOrder(date) == 0;
}

bool IsWeekEnd(stDate date) {
    //Weekends are Sat and Sun
    short DayIndex = DayOfWeekOrder(date);
    return (DayIndex == 6 || DayIndex == 0);
}

bool IsBusinessDay(stDate date) {
    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(date);
}

short DaysUntilTheEndOfWeek(stDate date) {
    return (7 - DayOfWeekOrder(date)) % 7;
}

short DaysUntilTheEndOfMonth(stDate date) {
    stDate EndOfMontDate;
    EndOfMontDate.Day = NumberOfDaysInMonth(date.Year, date.Month);
    EndOfMontDate.Month = date.Month;
    EndOfMontDate.Year = date.Year;
    return GetDifferenceInDays(date, EndOfMontDate, true);
}

short DaysUntilTheEndOfYear(stDate date) {
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = date.Year;
    return GetDifferenceInDays(date, EndOfYearDate, true);
}

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

int main()
{
    stDate date = GetSystemDate();

    string dayInOrder = DayShortName(DayOfWeekOrder(date));

    cout << "\nToday is " << dayInOrder << ", " << date.Day << "/" << date.Month << "/" << date.Year << endl;

    cout << "\nIs End of Week ?" << endl;
    if (IsEndOfWeek(date))
        cout << "Yes, it's End of Week...\n";
    else
        cout << "No, it's NOT End of Week...\n";

    cout << "\nIs it Weekend ?" << endl;
    if (IsWeekEnd(date))
        cout << "Yes, it's Week End...\n";
    else
        cout << "No today is " << DayShortName(DayOfWeekOrder(date)) << " NOT a Weekend...\n";

    cout << "\nIs it Business day ?" << endl;
    if (IsBusinessDay(date))
        cout << "Yes, it's a Business Day...\n";
    else
        cout << "No, it's NOT a Business Day...\n";

    cout << "\nDays until end of week  : " << DaysUntilTheEndOfWeek(date) << " Day(s)\n";
    cout << "\nDays until end of month : " << DaysUntilTheEndOfMonth(date) << " Day(s)\n";
    cout << "\nDays until end of year  : " << DaysUntilTheEndOfYear(date) << " Day(s)\n";

    return 0;

}