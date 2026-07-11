

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

int ReverseTheNumber(int number)
{
    int remainder = 0;
    int number2 = 0;

    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }

    return number2;
}

int main()
{
    cout << "\nReverse is = "
         << ReverseTheNumber(ReadPositiveNumber("please enter a positive number"))
         << "\n";

    return 0;
}

