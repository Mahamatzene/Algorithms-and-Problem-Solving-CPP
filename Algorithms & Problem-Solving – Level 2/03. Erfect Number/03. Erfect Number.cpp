

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

bool IsPerfectNumber(int number)
{
    
    int sum = 0;
    
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        
            sum += i;
            
    }
    return number == sum;
}

void PrintPerfectNumber(int number)
{
    if (IsPerfectNumber(number))
        cout << number << " is perfect number" << endl;
    else
        cout << number << " is not perfect number" << endl;
}

int main()
{
    int number;
    PrintPerfectNumber(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

