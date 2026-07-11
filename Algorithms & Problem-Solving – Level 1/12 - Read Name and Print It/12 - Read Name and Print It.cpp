

#include <iostream>
#include <string>
using namespace std;

void readNumbers(int& num1, int& num2)
{
    cout << "please enter the num 1" << endl;
    cin >> num1;
    cout << "please enter the num 2" << endl;
    cin >> num2;
}

int maxOf2Numbers(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}

void printResult(int max)
{
    cout << "\n the maximum number is : " << max << endl;
}

int main()
{
    int num1, num2;

    readNumbers(num1, num2);
    printResult(maxOf2Numbers(num1, num2));

    return 0;
}

