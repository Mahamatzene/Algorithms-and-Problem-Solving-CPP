

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

int ReverseNumber(int number)
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

bool IsPalindromeNumber(int number)
{
    return number == ReverseNumber(number);
}

int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("please enter a positie number?")))
    {
        cout << "yes, is a palindrome number ";
    }
    else
    {
        cout << "no, is not a palindrome number " << endl;
    }
    return 0;
}

