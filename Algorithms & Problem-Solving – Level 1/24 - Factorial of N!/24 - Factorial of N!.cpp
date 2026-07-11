

#include <iostream>
using namespace std;


int ReadAge()
{
    int age;

    cout << "please enter your age" << endl;
    cin >> age;

    return age;
}

bool ValidateNumberInRange(int number, int from, int to)
{
    return (number >= from && number <= to);
}

void PrintResult(int age)
{
    if (ValidateNumberInRange(age, 18, 45))
        cout << age << " is a valid age \n";
    else
        cout << age << " is invalid age \n";
}

int main()
{
    PrintResult(ReadAge());

    return 0;
}

