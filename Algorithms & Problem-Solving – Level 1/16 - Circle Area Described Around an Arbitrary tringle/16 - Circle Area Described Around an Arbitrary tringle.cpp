

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ٌRadNumbers(float &a, float &d)
{
    cout << "please enter the num of a?" << endl;
    cin >> a;
    cout << "please enter the num of d?" << endl;
    cin >> d;
}

float RectangleAreaBySideAndDiagonal(float a, float d)
{
    float area = a * sqrt(pow(d, 2) - pow(a, 2));
    return area;
}

void PrintResult(float area)
{
    cout << "\n regtanle area = " << area << endl;
}

int main()
{
    float a, d;

    ٌRadNumbers(a, d);
    PrintResult(RectangleAreaBySideAndDiagonal(a, d));

    return 0;
}


