
#include <iostream>
using namespace std;

int ReadAge()
{
    int age;

    cout << "please enter age between 18 and 45" << endl;
    cin >> age;

    return age;
}

bool ValidateNumberInRange(int number, int from, int to)
{
    return (number >= from && number <= to);
}

int ReadUntilAgeBetween(int from, int to)
{
    int age = 0;

    do
    {
        age = ReadAge();

    } while (!ValidateNumberInRange(age, from, to));

    return age;
}

void PrintResult(int age)
{
    cout << "\n your age is : " << age << endl;
}

int main()
{
    PrintResult(ReadUntilAgeBetween(18, 45));

    return 0;
}

