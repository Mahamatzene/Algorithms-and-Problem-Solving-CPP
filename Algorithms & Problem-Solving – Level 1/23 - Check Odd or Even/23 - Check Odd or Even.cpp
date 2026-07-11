

#include <iostream>
#include <cmath>
using namespace std;

void ReadTriangleArea(float& a, float& b, float& c)
{
    cout << "please enter the num of a?" << endl;
    cin >> a;
    cout << "please enter the num of b?" << endl;
    cin >> b;
    cout << "please enter the num of c?" << endl;
    cin >> c;
}

float CircleAreaByATriangle(float a, float b, float c)
{
    const float PI = 3.141592653589793238;

    float P;
    P = (a + b + c) / 2;

    float T;
    T = (a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c)));

    float area = PI * pow(T, 2);

    return area;
}

void PrintReslut(float area)
{
    cout << "\ncircle area = " << area << endl;
}

int main()
{
    float a, b, c;

    ReadTriangleArea(a, b, c);
    PrintReslut(CircleAreaByATriangle(a, b, c));

    return 0;

}


