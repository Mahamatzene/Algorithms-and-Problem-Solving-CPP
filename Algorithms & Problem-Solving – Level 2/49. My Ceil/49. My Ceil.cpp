

#include <iostream>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyCeil(float number)
{
    if (abs(GetFractionPart(number)) > 0)
    {
        if (number > 0)
            return int(number) + 1;
        else
            return int(number);
    }
    return number;
}

float ReadNumber()
{
    float number;

    cout << "\nPlease enter a number\n";
    cin >> number;

    return number;
}

int main()
{
    float number = ReadNumber();

    cout << "\nMy ceil result  : " << MyCeil(number);
    cout << "\nc++ ceil result : " << ceil(number) << endl;;

    return 0;
}
