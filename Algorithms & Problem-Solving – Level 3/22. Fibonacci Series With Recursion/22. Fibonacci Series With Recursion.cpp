
#include <iostream>
using namespace std;

void FibonacciSeries(int N, short prev, short prev2) {

    int febNumber = 0;

    if (N > 0) {
        febNumber = prev + prev2;
        prev2 = prev;
        prev = febNumber;
        cout << febNumber << "  ";
        FibonacciSeries(N - 1, prev, prev2);
    }
    
}

int main()
{
    FibonacciSeries(10, 0, 1);

    return 0;
}