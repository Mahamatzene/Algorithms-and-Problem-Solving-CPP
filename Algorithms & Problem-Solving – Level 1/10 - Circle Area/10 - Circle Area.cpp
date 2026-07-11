

#include <iostream>
using namespace std;

void readMarks(int &num1, int &num2, int &num3)
{
    cout << "please enter your mark number 1" << endl;
    cin >> num1;
    cout << "please enter your mark number 2" << endl;
    cin >> num2;
    cout << "please enter your mark number 3" << endl;
    cin >> num3;
}

int sumOf3Marks(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

float calculateAverage(int num1, int num2, int num3)
{
    return (float)sumOf3Marks(num1, num2, num3) / 3;
}

void printResult(int total)
{
    cout << "\n your total sum is : " << total << endl;
}

int main()
{
    int num1, num2, num3;
    readMarks(num1, num2, num3);
    printResult(calculateAverage(num1, num2, num3));

    return 0;

}
