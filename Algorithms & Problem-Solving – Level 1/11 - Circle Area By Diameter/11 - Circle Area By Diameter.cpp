

#include <iostream>
using namespace std;

enum enPassOFail { pass = 1, fail = 2 };

void readMarks(int& num1, int& num2, int& num3)
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

enPassOFail checkAvreage(float average)
{
    if (average >= 50)
        return enPassOFail::pass;
    else
        return enPassOFail::fail;
}

void printResult(float average)
{
    cout << "\n your average is : " << average << endl;

    if (checkAvreage(average) == enPassOFail::pass)
        cout << "\n you passed" << endl;
    else
        cout << "\n you failed" << endl;
}

int main()
{
    int num1, num2, num3;
    readMarks(num1, num2, num3);
    printResult(calculateAverage(num1, num2, num3));

    return 0;

}