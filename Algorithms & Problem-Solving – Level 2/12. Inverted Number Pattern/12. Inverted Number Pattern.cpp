

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

void PrintInverteddNumberPattern(int number)
{
    cout << endl;

    for (int i = number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }
}

int main()
{
    PrintInverteddNumberPattern(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

