

#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

int CountDigitFrequency(short digitToCheck, int number)
{
    int freqCount = 0, remainder = 0;

    while (number > 0) // if we entered number 1223222 this is grater then 0 program will start.
    {
        remainder = number % 10; //this is will take the last number 1223222 % 10 = 122322(2) and save it to the remainder.
        number = number / 10; // thia will delet the last number and the number will became 122322

        if (digitToCheck == remainder) //this will check as example if we entered 2 to the digits is the number 2 equal the number in remainder?
        {
            freqCount++; //if it's equal will add to freqCount 1 and restart the program tell the end
        }

    }
    return freqCount;
    
}

int main()
{
    int number = ReadPositiveNumber("please enter the main number");
    short digitToCheck = ReadPositiveNumber("please enter one digit to check");

    cout << "\ndigit " << digitToCheck << " frequency is " << CountDigitFrequency(digitToCheck, number) << " time(s).\n";

    return 0;
}

