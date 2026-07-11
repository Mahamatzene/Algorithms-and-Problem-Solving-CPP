

#include <iostream>
#include <iomanip>
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

bool IsLeapYear(int Year) {
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

int NumberOfDaysInMonth(short year, short month) {
    if (month < 1 || month > 12)
        return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalender(short month, short year) {

    int numberOfDays = NumberOfDaysInMonth(year, month);
    int current = DayOfWeekOrder(1, month, year);

    printf("\n _______________%s_______________\n\n", MonthShortName(month).c_str());
    printf("%5s%5s%5s%5s%5s%5s%5s\n",
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

    int i;

    for (i = 0; i < current; i++)
        printf("%5s", "");

    for (int j = 1; j <= numberOfDays; j++) {

        printf("%5d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }

    printf("\n ___________________________________\n");
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short numberOfDays = NumberOfDaysInMonth(Year, Month);
    
    PrintMonthCalender(Month, Year);
    return 0;
}