
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

short ReadVacationDays() {
    short day = 0;

    cout << "\nPlease enter vacation days : ";
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

bool IsWeekEnd(stDate date) {
    //Weekends are Sat and Sun
    short DayIndex = DayOfWeekOrder(date);
    return (DayIndex == 6 || DayIndex == 0);
}

bool IsBusinessDay(stDate date) {
    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(date);
}

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{

    short WeekEndCounter = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //here we increase the vacation dates to add all weekends to it.

    for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
    {

        if (IsWeekEnd(DateFrom))
            WeekEndCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //in case the return date is week end keep adding one day util you reach business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);


    }

    return DateFrom;
}

int main()
{
    cout << "\nVacation Start : " << endl;
    stDate VacationStartDate = ReadFullDate();
    short countDays = ReadVacationDays();
    
    VacationStartDate = CalculateVacationReturnDate(VacationStartDate, countDays);
    cout << "\nReturn date : " << DayShortName(DayOfWeekOrder(VacationStartDate)) << ", " << VacationStartDate.Day << "/" << VacationStartDate.Month << "/" << VacationStartDate.Year << endl;
  
    return 0;

}