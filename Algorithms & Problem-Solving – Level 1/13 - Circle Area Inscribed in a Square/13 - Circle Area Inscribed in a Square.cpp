#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(int& A, int& B, int &C)
{
    cout << "please enter the A" << endl;
    cin >> A;
    cout << "please enter the B" << endl;
    cin >> B;
    cout << "please enter the C" << endl;
    cin >> C;
}

int MaxOf3Numbers(int A, int B, int C)
{
    if (A > B)
        if (A > C)
            return A;
        else
            return C;

    else
        if (B > C)
            return B;
        else
            return C;
}

void printResult(int max)
{
    cout << "\n the maximum number is : " << max << endl;
}

int main()
{
    int A, B, C;

    ReadNumbers(A, B, C);
    printResult(MaxOf3Numbers(A, B, C));

    return 0;
}