//Check the number is odd or even


#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2};

int ReadNumber()
{
    int Number;

    cout << "Please enter the number : " << endl;
    cin >> Number;

    return Number;
}

enNumberType CheckNumber(int Number)
{
    int Result = Number % 2;

    if (Result == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}

void PrintNumberType(enNumberType NumberType)
{
    if (NumberType == enNumberType::Even)
        cout << "\nYour number is even" << endl;
    else
        cout << "\nyour number is odd" << endl;
}

int main()
{
    PrintNumberType(CheckNumber(ReadNumber()));

    return 0;
}

