

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

int SumOfDigit(int number)
{
    int remainder = 0;
    int sum = 0;

    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        sum = sum + remainder;
    }

    return sum;
}

int main()
{
    cout << "\nsum of digit = " 
         << SumOfDigit(ReadPositiveNumber("please enter a positive number"))
         << "\n";

    return 0;
}

