
#include <iostream>
using namespace std;

void FibonacciSeries(int N) {
    short prev = 1, prev2 = 0, febNumber = 0;
    cout << "1  ";

    for (short i = 2; i <= N; i++) {
        febNumber = prev + prev2;

        cout << febNumber << "  ";

        prev2 = prev;
        prev = febNumber;
    }

}

int main()
{
    FibonacciSeries(10);

    return 0;
}