

#include <iostream>
using namespace std;

float MyAbs(float number)
{
    if (number > 0)
    {
        return number;
    }
    else
        return number * -1;
}

float ReadNumber()
{
    float number;

    cout << "\nEnter a number ?\n";
    cin >> number;

    return number;
}

int main()
{
    float number = ReadNumber();

    cout << "\nMy abs result : " << MyAbs(number);
    cout << "\nc++ abs result : " << abs(number) << endl;
}

