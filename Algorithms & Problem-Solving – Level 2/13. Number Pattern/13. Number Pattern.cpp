

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

void PrintInvertedPattern(int number)
{
    cout << "\n";

    for (int i = 1; i <= number; i++)
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
    PrintInvertedPattern(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

