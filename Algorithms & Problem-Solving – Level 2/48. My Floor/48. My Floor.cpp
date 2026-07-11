

#include <iostream>
using namespace std;

float MyFloor(float number)
{
    if (number > 0)
    {
        return int(number);
    }
    else
    {
        return int(number) - 1;

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

    cout << "\nMy floor result  : " << MyFloor(number);
    cout << "\nc++ floor result : " << floor(number) << endl;;

    return 0;
}
