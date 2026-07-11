

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

void PrintDigits(int number)
{
    int remainder = 0;

    while (number > 0) // if the user entered 1234 this is will check if is grater then 0 or not if its not will ask to enter another number.
    {
        remainder = number % 10; // this will do divise the numbers 1234 % 10 and will show the result. and the result is = 123.4, the remainder will take the number 4 and keep the 123.
        number = number / 10; // after the first step, the number will be 123
        cout << remainder << endl; // this will print number 4 after this will print 3 till became 0 and will stop the loop 
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

