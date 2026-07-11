

#include <iostream>
using namespace std;

float GetFractionPart(float number)
{
    return number - int(number);
}

float MyRound(float number)
{
    int IntPart;
    IntPart = int(number);

    float FractionPart = GetFractionPart(number);

    if (abs(FractionPart) > 0.5)
    {
        if (number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;

    }
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

    cout << "\nMy round result  : " << MyRound(number);
    cout << "\nc++ round result : " << round(number) << endl;;

    return 0;
}
