
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrixElements(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            printf("%0*d\t", 2, arr[i][j]);
        }

        cout << endl;
    }
}

int SumOfMatrix(int arr[3][3], short row, short col) {
    int sum = 0;

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "Matrix 1 :\n";
    PrintMatrixElements(arr, 3, 3);

    cout << "\nSum of matrix 1 is = " << SumOfMatrix(arr, 3, 3);

    return 0;

}