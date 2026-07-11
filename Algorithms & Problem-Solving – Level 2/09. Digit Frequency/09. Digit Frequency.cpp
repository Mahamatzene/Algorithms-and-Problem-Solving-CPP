

#include <iostream>
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

    while (number > 0) 
    {
        remainder = number % 10; 
        number = number / 10; 
        
        if (digitToCheck == remainder) 
        {
            freqCount++; 
        }
    }

    return freqCount;
}

void PrintAllDigitsFrequency(int number)
{
    cout << endl;


    for (int i = 0; i < 10; i++)
    {
        short digitToCheck = 0;
        digitToCheck = CountDigitFrequency(i, number);

        if (digitToCheck > 0)
        {

            cout << "digit " << i << " frequency " << digitToCheck << " time(s)" << endl;
        }
    }
}

int main()
{
    int number = ReadPositiveNumber("please enter the number");
    PrintAllDigitsFrequency(number);

    return 0;
}


