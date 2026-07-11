
#include <iostream>
using namespace std;

enum enOddOrEven { odd = 1, even = 2 };

int ReadNumber()
{
    int number;
    cout << "please enter the number of n" << endl;
    cin >> number;

    return number;
}

enOddOrEven CheckOddOrEven(int number)
{
    if (number % 2 != 0)
        return enOddOrEven::odd;
    else
        return enOddOrEven::even;
}

int SumOddNumbersFrom1toN_UsingWhile(int n)
{
    int counter = 0;
    int sum = 0;

    cout << "sum odd numbers using while statement" << endl;

    while (counter < n)
    {
        counter++;
        if (CheckOddOrEven(counter) == enOddOrEven::odd)
        {
            sum += counter;
        }
    }
    return sum;
}

int SumOddNumbersFrom1toN_UsingDoWhile(int n)
{
    int counter = 0;
    int sum = 0;

    cout << "sum odd numbers using do while statement" << endl;

    do
    {
        counter++;
        if (CheckOddOrEven(counter) == enOddOrEven::odd)
        {
            sum += counter;
        }
    } while (counter < n);

    return sum;
}

int SumOddNumbersFrom1toN_UsingFor(int n)
{
    int sum = 0;

    cout << "sum odd number using for statement" << endl;

    for (int counter = 1; counter <= n; counter++)
    {
        if (CheckOddOrEven(counter) == enOddOrEven::odd)
        {
            sum += counter;
        }
    }

    return sum;
}

int main()
{
    int n = ReadNumber();

    cout << SumOddNumbersFrom1toN_UsingWhile(n) << endl;
    cout << SumOddNumbersFrom1toN_UsingDoWhile(n) << endl;
    cout << SumOddNumbersFrom1toN_UsingFor(n) << endl;


    return 0;
}


