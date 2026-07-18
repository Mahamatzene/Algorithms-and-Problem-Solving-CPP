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

    date.year = ReadYear();
    date.month = ReadMonth();
    date.day = ReadDay();

    return date;
}

bool IsDate1EqualToDate2(stDate date1, stDate date2) {
    return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

int main()
{
    stDate date1 = ReadFullDate();
    cout << endl;
    stDate date2 = ReadFullDate();

    if (IsDate1EqualToDate2(date1, date2))
        cout << "\nYes, Date 1 is Equal to date 2";
    else
        cout << "\nNo, Date 1 is NOT Equal to date 2";

    return 0;

}