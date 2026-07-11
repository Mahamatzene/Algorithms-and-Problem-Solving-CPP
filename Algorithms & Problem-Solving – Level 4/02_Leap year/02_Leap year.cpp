

#include <iostream>
using namespace std;

int ReadYear() {
    int year = 0;

    cout << "Please enter a year yo cheack if it's Leap Year or NOT : ";
    cin >> year;

    return year;
}

bool IsLeapYear(short Year){
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    return 0;
}