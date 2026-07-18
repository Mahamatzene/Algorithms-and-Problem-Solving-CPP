#include <iostream>
#include <iomanip>
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

bool IsDate1BeforeDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

int main()
{
    stDate date1 = ReadFullDate();
    cout << endl;
    stDate date2 = ReadFullDate();

    if (IsDate1BeforeDate2(date1, date2))
        cout << "\nYes, Date 1 is less then date 2";
    else
        cout << "\nNo, Date 1 is NOT less then date 2";

    return 0;

}