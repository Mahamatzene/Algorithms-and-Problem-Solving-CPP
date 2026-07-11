

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

bool isPerfectNumber(int number)
{
    int sum = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return number == sum;
}

void PrintPerfectNumber(int number)
{
    cout << endl;

    cout << "the perfect number of " << number;
    cout << "\nare : " << endl;

    for (int i = 1; i <= number; i++)
    {
        if (isPerfectNumber(i))
        {
            cout << i << endl;
        }
    }
}

int main()
{
    PrintPerfectNumber(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

