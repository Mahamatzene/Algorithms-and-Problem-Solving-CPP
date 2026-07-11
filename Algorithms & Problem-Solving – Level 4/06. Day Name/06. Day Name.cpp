

#include <iostream>
using namespace std;

short ReadYear() {
    short Year = 0;

    cout << "Please enter a year : ";
    cin >> Year;

    return Year;
}

short ReadMonth() {
    short Month = 0;

    cout << "Please enter a month : ";
    cin >> Month;

    return Month;
}

short ReadDay() {
    short Day = 0;

    cout << "Please enter a day : ";
    cin >> Day;

    return Day;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
        / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
    "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\nDate :" << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;

    return 0;
}