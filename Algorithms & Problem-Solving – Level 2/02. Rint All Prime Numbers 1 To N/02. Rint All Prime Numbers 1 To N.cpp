//print the prime number from 1 to n


#include <iostream>
using namespace std;

enum enPrimeOrNotPrime { prime = 1, notPrime = 2 };

float ReadPositiveNumber(string message)
{
    float number = 0;

    do
    {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

enPrimeOrNotPrime CheckPrime(int number)
{
    int m = round(number / 2);

    for (int counter = 2; counter <= m; counter++)
    {
        if (number % counter == 0)
        {
            return enPrimeOrNotPrime::notPrime;
        }
    }

    return enPrimeOrNotPrime::prime;
}

void PrintNumberType(int number)
{
    switch (CheckPrime(number))
    {
    case enPrimeOrNotPrime::prime:
        cout << "the number is prime\n";
        break;
    case enPrimeOrNotPrime::notPrime:
        cout << "the number is not prime\n";
        break;
    }
}

void PrintPrimeNumberFrom1toN(int number)
{
    cout << endl;

    cout << "the prime number from 1 to " << number;
    cout << "\nare :" << endl;

    for (int i = 1; i <= number; i++)
    {
        if (CheckPrime(i) == enPrimeOrNotPrime::prime)
        {
            cout << i << endl;
        }

    }
}

int main()
{
    PrintPrimeNumberFrom1toN(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

